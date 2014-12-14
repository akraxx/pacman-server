#include "GraphResponder.h"

GraphResponder::GraphResponder(GraphList* graphs) : Responder(graphs) {

}

GraphResponder::~GraphResponder() {

}

void GraphResponder::respond(FastCgiQt::Request* request) {
    Response* response = NULL;
    this->currentRequest = request;
    QHash<QByteArray, QByteArray> serverData = request->rawValues(ServerData);
    qDebug() << "test";
    /* CHECK IF ITS A BAD FORMAT */
    if((serverData["REQUEST_METHOD"] == "POST" || serverData["REQUEST_METHOD"] == "PUT") && !serverData["CONTENT_TYPE"].startsWith("application/x-www-form-urlencoded"))
        response = new BadFormatGraphResponse();
    else {

        try {
            QHash<QByteArray, QByteArray> postData = request->rawValues(PostData);
            GraphParser parser(serverData["PATH_INFO"], postData);
            parser.parseQuery();
            /* CREATE A GRAPH */
            if(parser.patternInPathinfo("^/graphes$") && serverData["REQUEST_METHOD"] == "POST") {
                this->graphs->addGraph(parser.createGraph());
                response = new HasBeenCreateGraphResponse("/graphes/"+QString::number(this->graphs->getLastInsert()));
            }
            /* GET GRAPH LIST IN JSON */
            else if(parser.patternInPathinfo("^/graphes.js$") && serverData["REQUEST_METHOD"] == "GET") {
                /* IF THE GRAPH LIST IS NOT EMPTY */
                if(this->graphs->getGraphList().size() > 0)
                    response = new GraphListJsonResponse(this->graphs);
                else
                    response = new EmptyGraphListResponse();
            }
            /* GET GRAPH LIST IN XML */
            else if(parser.patternInPathinfo("^/graphes.xml$") && serverData["REQUEST_METHOD"] == "GET") {
                 /* IF THE GRAPH LIST IS NOT EMPTY */
                if(this->graphs->getGraphList().size() > 0)
                    response = new GraphListXmlResponse(this->graphs);
                else
                    response = new EmptyGraphListResponse();
            }
            /* DELETE OR EDIT A GRAPH*/
            else if(parser.patternInPathinfo("^/graphes/([0-9]+)$")) {
                /* GET THE ID */
                int id = parser.extractChainFromPathinfo("^/graphes/([0-9]+)$", 1).toInt();
                /* EDIT GRAPH */
                if(serverData["REQUEST_METHOD"] == "POST" || serverData["REQUEST_METHOD"] == "PUT") {
                    this->graphs->editGraph(id, parser.createGraph());
                    response = new HasBeedEditGraphResponse();
                }
                /* DELETE GRAPH */
                else if(serverData["REQUEST_METHOD"] == "DELETE") {
                    this->graphs->deleteGraph(id);
                    response = new HasBeenDeleteGraphResponse();
                }
            }
            /* GET A GRAPH */
            else if(parser.patternInPathinfo("^/graphes/([0-9]+).(xml|js)$") && serverData["REQUEST_METHOD"] == "GET") {
                /* GET THE ID */
                int id = parser.extractChainFromPathinfo("^/graphes/([0-9]+).(xml|js)$", 1).toInt();
                GraphQt<DEFAULT_TYPEVAL>* graph = this->graphs->getGraph(id);
                /* IF THE GRAPH IS NOT EMPTY */
                if(graph->getOrder() > 0) {
                    /* GET A GRAPH IN JSON */
                    if(parser.getExtension() == "js")
                        response = new GetGraphJsonResponse(id, graph);
                    /* GET A GRAPH IN XML */
                    else if(parser.getExtension() == "xml")
                        response = new GetGraphXmlResponse(id, graph);
                }
                else
                    response = new EmptyGraphResponse();
            }

        }
        /* SOME ARGUMENTS ARE MISSING */
        catch(MissingArgumentGraphParserException& e) {
            response = new BadCreateGraphResponse();
             qDebug() << "test1";
        }
        /* CAN'T FIND THE SPECIFIED GRAPH */
        catch(GraphNotFoundInListException& e) {
            response = new NotFoundGraphResponse();
             qDebug() << "test2";
        }
        /* ERROR HAS BEEN FOUND */
        catch(MyException& e) {
            qDebug() << e.what();
            response = new BadGraphResponse();
             qDebug() << "test3";
        }
        

    }
    /* DELETE ALL THE OBSOLETE GRAPHS */
    this->graphs->deleteObsoleteGraphs();

    /* IF NO RESPONSE HAS BEEN CREATED */
    if(!response)
        response = new BadMethodGraphResponse();

    /* SEND RESPONSE */
    this->send(response);
}
#include "DijkstraResponder.h"

DijkstraResponder::DijkstraResponder(GraphList* graphs) : Responder(graphs) {

}

DijkstraResponder::~DijkstraResponder() {

}

void DijkstraResponder::respond(FastCgiQt::Request* request) {
    Response* response = NULL;
    this->currentRequest = request;
    QHash<QByteArray, QByteArray> serverData = request->rawValues(ServerData);

    /* CHECK IF ITS A BAD FORMAT */
    if((serverData["REQUEST_METHOD"] == "POST" || serverData["REQUEST_METHOD"] == "PUT") && !serverData["CONTENT_TYPE"].startsWith("application/x-www-form-urlencoded"))
        response = new BadFormatGraphResponse();
    else {
        try {
            QHash<QByteArray, QByteArray> postData = request->rawValues(PostData);
            DijkstraParser parser(serverData["PATH_INFO"], postData);
            /* IF ITS A KNOWN METHOD */
            if(parser.patternInPathinfo("^/dijkstra/([0-9]+).(xml|js)$") && (serverData["REQUEST_METHOD"] == "POST" || serverData["REQUEST_METHOD"] == "GET")) {
                int id = parser.extractChainFromPathinfo("^/dijkstra/([0-9]+).(xml|js)$", 1).toInt();
                GraphQt<DEFAULT_TYPEVAL>* graph = this->graphs->getGraph(id);
                parser.parseQuery();
                if(!parser.getData().contains("start") || !parser.getData().contains("goal"))
                    response = new DijkstraBadResponse();

                Dijkstra d(graph);
                QVariantList pathAndCost = d.findShortestPath(parser.getData().value("start").toInt(), parser.getData().value("goal").toInt());
                /* GET A PATH IN JSON */
                if(parser.getExtension() == "js")
                    response = new DijkstraJsonResponse(pathAndCost);
                /* GET A PATH IN XML */
                else if(parser.getExtension() == "xml")
                    response = new DijkstraXmlResponse(pathAndCost);
            }
        }
        /* CAN'T FIND THE SPECIFIED GRAPH */
        catch(GraphNotFoundInListException& e) {
            response = new NotFoundGraphResponse();
        }
        /* CAN'T FIND A NODE FOR DIJKSTRA */
        catch(NodeNotFoundException& e) {
            response = new DijkstraBadResponse();
        }
        /* CAN'T FIND A PATH BETWEEN NODES */
        catch(PathNotFoundException& e) {
            response = new DijkstraNoPathResponse();
        }
    }

    /* IF NO RESPONSE HAS BEEN CREATED */
    if(!response)
        response = new BadMethodGenericResponse();

    /* SEND THE RESPONSE */
    this->send(response);
}

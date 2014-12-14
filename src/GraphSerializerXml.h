/* 
 * File:   GraphParserXml.h
 * Author: isen
 *
 * Created on 16 mars 2011, 12:43
 */

#ifndef GraphPARSERXML_H
#define	GraphPARSERXML_H

#include "utils.h"
#include "GraphSerializer.h"

/* Class GraphSerializerXml
 * ----------------------------------------
 * serialize a graph into xml
 * ----------------------------------------
 */
class GraphSerializerXml : public GraphSerializer {
/* PRIVATE VARIABLES
 * @xml = The main document that will contain the response
 * @parent = A pointer on the current parent
 * @dtd = The dtd of the release document
 * */
private:
    QDomDocument xml;
    QDomElement* parent;
    QString dtd;
public:
    /* CONSTRUCTOR */
    GraphSerializerXml();
    /* DESTRUCTOR */
    ~GraphSerializerXml();

    /* Function serializeGraphList
     * ----------------------------------------
     * it serialize the graphlist into xml
     * ----------------------------------------
     * @graphs = A pointer on graphlist
     */
    void serializeGraphList(GraphList* GraphList);

    /* Function serializeGraph
     * ----------------------------------------
     * it serialize the graph into xml
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id = the id of the graph in list
     */
    void serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph);

    /* Function serializeNode
     * ----------------------------------------
     * it serialize the nodes into xml
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id = the id of the node in graph
     */
    void serializeNode(GraphQt<DEFAULT_TYPEVAL>* graph, int id);

    /* Function serializeEdge
     * ----------------------------------------
     * it serialize the edges into xml
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id1 = the id of the first node
     * @id2 = the id of the second node
     */
    void serializeEdge(GraphQt<DEFAULT_TYPEVAL>* graph, int id1, int id2);

    /* Function serializeEdge
     * ----------------------------------------
     * Transform the serialized graph in a string and return it
     * ----------------------------------------
     * @return = serialized graph in a string
     */
    QString getSerializedGraph();

    /* Function addToParent
     * ----------------------------------------
     * Add a new insert to the parent
     * ----------------------------------------
     * @elem = element to be append to the current parent
     */
    void appendToParent(QDomElement* elem);
};

#endif	/* GraphPARSERXML_H */


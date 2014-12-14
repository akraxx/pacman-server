/* 
 * File:   GraphParserJson.h
 * Author: isen
 *
 * Created on 16 mars 2011, 12:44
 */

#ifndef GraphPARSERJSON_H
#define	GraphPARSERJSON_H

#include "GraphSerializer.h"

/* Class GraphSerializerJson
 * ----------------------------------------
 * serialize a graph into json
 * ----------------------------------------
 */
class GraphSerializerJson : public GraphSerializer {
/* PRIVATE VARIABLES
 * @json = The main variant that will contain the response
 * @parent = A pointer on the current parent
 * */
private:
    QVariant json;
    QVariantHash* parent;
public:
    /* CONSTRUCTOR */
    GraphSerializerJson();
    /* DESTRUCTOR */
    ~GraphSerializerJson();

    /* Function serializeGraphList
     * ----------------------------------------
     * it serialize the graphlist into json
     * ----------------------------------------
     * @graphs = A pointer on graphlist
     */
    void serializeGraphList(GraphList* GraphList);

    /* Function serializeGraph
     * ----------------------------------------
     * it serialize the graph into json
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id = the id of the graph in list
     */
    void serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph);

    /* Function serializeNode
     * ----------------------------------------
     * it serialize the nodes into json
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id = the id of the node in graph
     */
    void serializeNode(GraphQt<DEFAULT_TYPEVAL>* graph, int id);

    /* Function serializeEdge
     * ----------------------------------------
     * it serialize the edges into json
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
     * @name = name of the argument to be added
     * @value = value of the argument to be added
     */
    void addToParent(QString name, QVariant value);
};

#endif	/* GraphPARSERJSON_H */


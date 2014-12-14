/* 
 * File:   GraphParser.h
 * Author: isen
 *
 * Created on 16 mars 2011, 12:43
 */

#ifndef GraphPARSER_H
#define	GraphPARSER_H

#include "utils.h"
#include "GraphList.h"

/* Class GraphSerializer
 * ----------------------------------------
 * serialize a graph into a format
 * ----------------------------------------
 */
class GraphSerializer {
public:
    /* CONSTRUCTOR */
    GraphSerializer();
    /* DESTRUCTOR */
    ~GraphSerializer();

    /* Function serializeGraphList
     * ----------------------------------------
     * Pure virtual methode, it serialize the graphlist into a format
     * ----------------------------------------
     * @graphs = A pointer on graphlist
     */
    virtual void serializeGraphList(GraphList* Graphs) = 0;

    /* Function serializeGraph
     * ----------------------------------------
     * Pure virtual methode, it serialize the graph into a format
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id = the id of the graph in list
     */
    virtual void serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph) = 0;

    /* Function serializeNode
     * ----------------------------------------
     * Pure virtual methode, it serialize the nodes into a format
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id = the id of the node in graph
     */
    virtual void serializeNode(GraphQt<DEFAULT_TYPEVAL>* graph, int id) = 0;

    /* Function serializeEdge
     * ----------------------------------------
     * Pure virtual methode, it serialize the edges into a format
     * ----------------------------------------
     * @graph = A pointer on graph
     * @id1 = the id of the first node
     * @id2 = the id of the second node
     */
    virtual void serializeEdge(GraphQt<DEFAULT_TYPEVAL>* graph, int id1, int id2) = 0;

    /* Function serializeEdge
     * ----------------------------------------
     * Pure virtual methode, Transform the serialized graph in a string and return it
     * ----------------------------------------
     * @return = serialized graph in a string
     */
    virtual QString getSerializedGraph() = 0;
};


#endif	/* GraphPARSER_H */


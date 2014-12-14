/* 
 * File:   GraphList.h
 * Author: isen
 *
 * Created on 16 mars 2011, 12:48
 */

#ifndef GraphLIST_H
#define	GraphLIST_H

#include "utils.h"
#include "GraphQt.h"

/* Class GraphList
 * ----------------------------------------
 * An array of GraphQt
 * ----------------------------------------
 */
class GraphList {
    /* PRIVATE VARIABLES
     * @graphs = An array of GraphQt indexed by his id
     * @lastInsert = The id of the last Graph inserted
     * */
private:
    QHash<int, GraphQt<DEFAULT_TYPEVAL>* > graphs;
    int lastInsert;
public:
    /* CONSTRUCTOR */
    GraphList();
    /* DESTRUCTOR */
    ~GraphList();

    /* GETTERS & SETTERS */
    int getLastInsert() { return lastInsert; };
    QHash<int, GraphQt<DEFAULT_TYPEVAL>* > getGraphList() { return graphs; };

    /* Function GraphExists
     * ----------------------------------------
     * Check if an id exist in the list
     * ----------------------------------------
     * @id = id of the GraphQt
     * ----------------------------------------
     * @return = true if the graph exists, false otherwise
     */
    bool GraphExists(int id);

    /* Function getGraph
     * ----------------------------------------
     * Return the graph
     * ----------------------------------------
     * @id = id of the GraphQt
     * ----------------------------------------
     * Can throw these exceptions :
     *  - GraphNotFoundInListException
     * ----------------------------------------
     * @return = the graph if it exists
     */
    GraphQt<DEFAULT_TYPEVAL>* getGraph(int id);

    /* Function addGraph
     * ----------------------------------------
     * Add a graph to the list
     * ----------------------------------------
     * @graph = the graph which needs to be added
     */
    void addGraph(GraphQt<DEFAULT_TYPEVAL>* graph);

    /* Function GraphExists
     * ----------------------------------------
     * Add a graph to the list
     * ----------------------------------------
     * @graph = the graph which needs to be added
     */
    void deleteGraph(int id);

    /* Function editGraph
     * ----------------------------------------
     * Edit a graph from to the list
     * ----------------------------------------
     * @id = id of the graph which needs to be edited
     * @graph = the new graph
     * ----------------------------------------
     * Can throw these exceptions :
     *  - GraphNotFoundInListException
     */
    void editGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph);

    /* Function deleteObsoleteGraphs
     * ----------------------------------------
     * Delete all the graph wich are obsolete
     * ----------------------------------------
     * @keepalive = time before delete in minute
     */
    void deleteObsoleteGraphs(int keepalive = KEEP_ALIVE);
};

#endif	/* GraphLIST_H */


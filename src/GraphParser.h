/* 
 * File:   UrlParser.h
 * Author: isen
 *
 * Created on 16 mars 2011, 19:08
 */

#ifndef URLPARSER_H
#define	URLPARSER_H

#include "utils.h"
#include "Parser.h"
#include "GraphQt.h"
#include "GraphException.h"

/* Class GraphParser
 * ----------------------------------------
 * Parse the query and the pathinfo into graph informations
 * ----------------------------------------
 */
class GraphParser : public Parser {
public:
    /* Function GraphParser
     * ----------------------------------------
     * Constructor
     * ----------------------------------------
     * @pathinfo = The pathinfo of the thrown request
     * @query = The query of the thrown request
     */
    GraphParser(QByteArray pathinfo, QHash<QByteArray, QByteArray> query);

    /* Function parseQuery
     * ----------------------------------------
     * Parse the query, get back the informations that the graph need
     * ----------------------------------------
     */
    void parseQuery();

    /* Function createGraph
     * ----------------------------------------
     * Create a graph with the data
     * ----------------------------------------
     */
    GraphQt<DEFAULT_TYPEVAL>* createGraph();
};


#endif	/* URLPARSER_H */


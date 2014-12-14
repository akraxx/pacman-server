/* 
 * File:   DijkstraParser.h
 * Author: isen
 *
 * Created on 22 mars 2011, 20:52
 */

#ifndef DIJKSTRAPARSER_H
#define	DIJKSTRAPARSER_H

#include "utils.h"
#include "Parser.h"

/* Class DijkstraResponder, inherit from Responder
 * ----------------------------------------
 * This class is a specialized responder for dijkstra
 * ----------------------------------------
 */
class DijkstraParser : public Parser {
public:
    /* Function DijkstraParser
     * ----------------------------------------
     * Constructor
     * ----------------------------------------
     * @pathinfo = The pathinfo of the thrown request
     * @query = The query of the thrown request
     */
    DijkstraParser(QByteArray pathinfo, QHash<QByteArray, QByteArray> query);

    /* Function parseQuery
     * ----------------------------------------
     * Parse the query, get back the informations that dijkstra need
     * ----------------------------------------
     */
    void parseQuery();
};

#endif	/* DIJKSTRAPARSER_H */


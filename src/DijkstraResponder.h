/* 
 * File:   DijkstraResponder.h
 * Author: isen
 *
 * Created on 22 mars 2011, 20:37
 */

#ifndef DIJKSTRARESPONDER_H
#define	DIJKSTRARESPONDER_H

#include "utils.h"
#include "Responder.h"
#include "DijkstraParser.h"
#include "DijkstraResponse.h"
#include "DijkstraException.h"

/* Class DijkstraResponder, inherit from Responder
 * ----------------------------------------
 * Parse the query and the pathinfo into dijkstra informations
 * ----------------------------------------
 */
class DijkstraResponder : public Responder {
Q_OBJECT
public:
    /* Function DijkstraResponder
     * ----------------------------------------
     * Constructor
     * ----------------------------------------
     * @graphs = A pointer on graphlist
     */
    DijkstraResponder(GraphList* graphs);

    /* Function ~DijkstraResponder
     * ----------------------------------------
     * Destructor
     * ----------------------------------------
     */
    virtual ~DijkstraResponder();
public slots:
    /* Function respond
     * ----------------------------------------
     * Responder that is call by a signal
     * ----------------------------------------
     * @request = The sent request
     */
    void respond(FastCgiQt::Request* request);
};


#endif	/* DIJKSTRARESPONDER_H */


/* 
 * File:   Responder.h
 * Author: isen
 *
 * Created on 17 mars 2011, 15:49
 */

#ifndef RESPONDER_H
#define	RESPONDER_H

#include "utils.h"
#include "GraphResponse.h"

/* Class Responder, inherit QObject
 * ----------------------------------------
 * This class respond to a request
 * ----------------------------------------
 */
class Responder : public QObject {
Q_OBJECT
/* PROTECTED VARIABLES
 * @graphs = A pointer to a graphlist
 * @request = the current request which attempt a respond
 * */
protected:
    GraphList* graphs;
    FastCgiQt::Request* currentRequest;
public:
    /* Function Responder
     * ----------------------------------------
     * Constructor
     * ----------------------------------------
     * @graphs = A pointer on graphlist
     */
    Responder(GraphList* graphs);

    /* Function ~Responder
     * ----------------------------------------
     * Destructor
     * ----------------------------------------
     */
    virtual ~Responder();

    /* Function send
     * ----------------------------------------
     * Send the response generated
     * ----------------------------------------
     * @response = a pointer to teh response to be sent
     */
    void send(Response* response);
};


#endif	/* RESPONDER_H */


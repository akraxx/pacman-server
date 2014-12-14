/* 
 * File:   GraphResponder.h
 * Author: isen
 *
 * Created on 11 mars 2011, 09:51
 */

#ifndef GraphRESPONDER_H
#define	GraphRESPONDER_H

#include "Responder.h"

#include "GraphResponse.h"

#include "GraphParser.h"
#include "GraphSerializerJson.h"
#include "GraphSerializerXml.h"

/* Class GraphResponder, inherit from Responder
 * ----------------------------------------
 * This class is a specialized responder for graphs
 * ----------------------------------------
 */
class GraphResponder : public Responder {
Q_OBJECT
public:
    /* Function GraphResponder
     * ----------------------------------------
     * Constructor
     * ----------------------------------------
     * @graphs = A pointer on graphlist
     */
    GraphResponder(GraphList* graphs);

    /* Function ~GraphResponder
     * ----------------------------------------
     * Destructor
     * ----------------------------------------
     */
    virtual ~GraphResponder();
public slots:
    /* Function respond
     * ----------------------------------------
     * Responder that is call by a signal
     * ----------------------------------------
     * @request = The sent request
     */
    void respond(FastCgiQt::Request* request);
};

#endif	/* GraphRESPONDER_H */


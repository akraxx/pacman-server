/* 
 * File:   DijkstraResponse.h
 * Author: isen
 *
 * Created on 22 mars 2011, 20:40
 */

#ifndef DIJKSTRARESPONSE_H
#define	DIJKSTRARESPONSE_H

#include "Response.h"
#include "DijkstraSerializerJson.h"
#include "DijkstraSerializerXml.h"

/* Class NotImplementedDijkstraParser, inherit from NotImplementedGenericResponse, virtual public NoContentResponse
 * ----------------------------------------
 * Create a 501, without content
 * ----------------------------------------
 */
class NotImplementedDijkstraResponse : virtual public NotImplementedGenericResponse, virtual public NoContentResponse {
public:
    /* CONSTRUCTOR */
    NotImplementedDijkstraResponse();
};

/* CREATE A RESPONSE
 * - 200
 * - CONTENT = SERIALIZE GRAPH IN XML
 * */
class DijkstraXmlResponse : virtual public GoodGenericResponse {
public:
    DijkstraXmlResponse(QVariantList pathAndCost);
};

/* CREATE A RESPONSE
 * - 200
 * - CONTENT = SERIALIZE GRAPH IN JSON
 * */
class DijkstraJsonResponse : virtual public GoodGenericResponse {
public:
    DijkstraJsonResponse(QVariantList pathAndCost);
};

/* CREATE A RESPONSE
 * - 204
 * */
class DijkstraNoPathResponse : virtual public EmptyDataGenericResponse {
public:
    DijkstraNoPathResponse();
};

/* CREATE A RESPONSE
 * - 400
 * - Arg missing
 * */
class DijkstraBadResponse : virtual public BadGenericResponse {
public:
    DijkstraBadResponse();
};
#endif	/* DIJKSTRARESPONSE_H */


/* 
 * File:   GraphResponse.h
 * Author: isen
 *
 * Created on 17 mars 2011, 17:10
 */

#ifndef GraphRESPONSE_H
#define	GraphRESPONSE_H

#include "Response.h"
#include "GraphSerializerJson.h"
#include "GraphSerializerXml.h"
#include "GraphList.h"

/* CREATE A RESPONSE
 * - 204
 * - NO CONTENT
 * */
class EmptyGraphListResponse : virtual public EmptyDataGenericResponse, virtual NoContentResponse {
public:
    EmptyGraphListResponse();
};

/* SERIALIZE A GRAPH OR A GRAPH LIST WITH THE SPECIFIED SERIALIZER */
class GraphSerializerResponse : virtual public Response {
protected:
    GraphSerializer* serializer;
public:
    GraphSerializerResponse();
    ~GraphSerializerResponse();

    void serializeGraphList(GraphList* graphs);
    void serializeGraph(int id, GraphQt<DEFAULT_TYPEVAL>* graph);
};

/* SERIALIZE A GRAPH OR A GRAPH LIST IN XML
 * SET THE CONTENT TYPE TO XML
 * */
class GraphXmlResponse : virtual public XmlContentResponse, virtual public GraphSerializerResponse {
public:
    GraphXmlResponse();
};

/* SERIALIZE A GRAPH OR A GRAPH LIST IN JSON
 * SET THE CONTENT TYPE TO JSON
 * */
class GraphJsonResponse : virtual public JsonContentResponse, virtual public GraphSerializerResponse {
public:
    GraphJsonResponse();
};

/* CREATE A RESPONSE
 * - 200
 * - CONTENT = SERIALIZED GRAPHLIST IN XML
 * */
class GraphListXmlResponse : virtual public GraphXmlResponse, virtual public GoodGenericResponse {
public:
    GraphListXmlResponse(GraphList* Graphs);
};

/* CREATE A RESPONSE
 * - 200
 * - CONTENT = SERIALIZED GRAPHLIST IN JSON
 * */
class GraphListJsonResponse : virtual public GraphJsonResponse, virtual public GoodGenericResponse {
public:
    GraphListJsonResponse(GraphList* Graphs);
};

/* THE RESPONSE HAS NO CONTENT */
class CreateGraphResponse : virtual public NoContentResponse {
public:
    CreateGraphResponse();
};

/* CREATE A RESPONSE
 * - 201
 * */
class HasBeenCreateGraphResponse : virtual public CreateGraphResponse, virtual public CreatedGenericResponse {
public:
    HasBeenCreateGraphResponse(QString Location);
};

/* CREATE A RESPONSE
 * - 400
 * */
class BadCreateGraphResponse : virtual public CreateGraphResponse, virtual public BadGenericResponse {
public:
    BadCreateGraphResponse();
};

/* CREATE A RESPONSE
 * - 415
 * */
class BadFormatGraphResponse : virtual public BadFormatGenericResponse, virtual public NoContentResponse {
public:
    BadFormatGraphResponse();
};

/* CREATE A RESPONSE
 * - 400
 * */
class BadGraphResponse : virtual public NoContentResponse, virtual public BadGenericResponse {
public:
    BadGraphResponse();
};

/* CREATE A RESPONSE
 * - 405
 * */
class BadMethodGraphResponse : virtual public NoContentResponse, virtual public BadMethodGenericResponse {
public:
    BadMethodGraphResponse();
};

/* CREATE A RESPONSE
 * - 404
 * - NO CONTENT
 * */
class NotFoundGraphResponse : virtual public NotFoundGenericResponse, virtual public NoContentResponse {
public:
    NotFoundGraphResponse();
};

/* CREATE A RESPONSE
 * - 200
 * - NO CONTENT
 * */
class HasBeedEditGraphResponse : virtual public GoodGenericResponse, virtual public NoContentResponse {
public:
    HasBeedEditGraphResponse();
};

/* CREATE A RESPONSE
 * - 200
 * - NO CONTENT
 * */
class HasBeenDeleteGraphResponse : virtual public GoodGenericResponse, virtual public NoContentResponse  {
public:
    HasBeenDeleteGraphResponse();
};

/* CREATE A RESPONSE
 * - 200
 * - CONTENT = SERIALIZE GRAPH IN XML
 * */
class GetGraphXmlResponse : virtual public GraphXmlResponse, virtual public GoodGenericResponse {
public:
    GetGraphXmlResponse(int id, GraphQt<DEFAULT_TYPEVAL>* graph);
};

/* CREATE A RESPONSE
 * - 200
 * - CONTENT = SERIALIZE GRAPH IN JSON
 * */
class GetGraphJsonResponse : virtual public GraphJsonResponse, virtual public GoodGenericResponse {
public:
    GetGraphJsonResponse(int id, GraphQt<DEFAULT_TYPEVAL>* graph);
};

/* CREATE A RESPONSE
 * - 204
 * - NO CONTENT
 * */
class EmptyGraphResponse : virtual public NoContentResponse, virtual public EmptyDataGenericResponse {
public:
    EmptyGraphResponse();
};
#endif	/* GraphRESPONSE_H */


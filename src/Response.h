/* 
 * File:   Response.h
 * Author: isen
 *
 * Created on 17 mars 2011, 17:00
 */

#ifndef RESPONSE_H
#define	RESPONSE_H

#include "utils.h"

/* Class Response
 * ----------------------------------------
 * This class is an HTTP response
 * ----------------------------------------
 */
class Response {
/* PROTECTED VARIABLES
 * @responseCode = Http response code : 404, 200 ...
 * @contentType = Http content type : application/xml ...
 * @location = Http location
 * @content = the content response
 * */
protected:
    QString responseCode;
    QString contentType;
    QString location;
    
    QString content;
public:
    /* CONSTRUCTOR */
    Response(QString location = "");
    /* DESTRUCTOR */
    ~Response();

    /* SETTERS & GETTERS */
    QString getResponseCode() { return responseCode; };
    QString getContentType() { return contentType; };
    QString getLocation() { return location; };

    QString getContent() { return content; };

};

/* INIT GENERIC RESPONSE : 200, 404, 400 etc... */
class GenericResponse : virtual public Response {
public:
    GenericResponse(QString responseCode = "");
};

class NotFoundGenericResponse : public GenericResponse {
public:
    NotFoundGenericResponse();
};

class EmptyDataGenericResponse : public GenericResponse {
public:
    EmptyDataGenericResponse();
};

class CreatedGenericResponse : public GenericResponse {
public:
    CreatedGenericResponse();
};

class GoodGenericResponse : public GenericResponse {
public:
    GoodGenericResponse();
};

class BadFormatGenericResponse : public GenericResponse {
public:
    BadFormatGenericResponse();
};

class BadMethodGenericResponse : public GenericResponse {
public:
    BadMethodGenericResponse();
};

class BadGenericResponse : public GenericResponse {
public:
    BadGenericResponse();
};

class NotImplementedGenericResponse : public GenericResponse {
public:
    NotImplementedGenericResponse();
};

/* INIT THE CONTENT TYPE : XML, JSON etc... */
class ContentResponse : virtual public Response {
public:
    ContentResponse(QString contentType = "");
};

class NoContentResponse : public ContentResponse {
public:
    NoContentResponse();

};

class XmlContentResponse : public ContentResponse {
public:
    XmlContentResponse();
};

class JsonContentResponse : public ContentResponse {
public:
    JsonContentResponse();

};
#endif	/* RESPONSE_H */


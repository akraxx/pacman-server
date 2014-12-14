#include "Response.h"

Response::Response(QString location) {
    this->location = location;
}

Response::~Response() {

}

GenericResponse::GenericResponse(QString responseCode) {
    this->responseCode = responseCode;
}

NotFoundGenericResponse::NotFoundGenericResponse() : GenericResponse("404") {

}

EmptyDataGenericResponse::EmptyDataGenericResponse() : GenericResponse("204") {

}

CreatedGenericResponse::CreatedGenericResponse() : GenericResponse("201") {

}

GoodGenericResponse::GoodGenericResponse() : GenericResponse("200") {

}

BadFormatGenericResponse::BadFormatGenericResponse() : GenericResponse("415") {

}

BadMethodGenericResponse::BadMethodGenericResponse() : GenericResponse("405") {

}

BadGenericResponse::BadGenericResponse() : GenericResponse("400") {

}

NotImplementedGenericResponse::NotImplementedGenericResponse() : GenericResponse("501") {

}

ContentResponse::ContentResponse(QString content) {
    this->contentType = content;
}

NoContentResponse::NoContentResponse() : ContentResponse("text/plain") {

}

XmlContentResponse::XmlContentResponse() : ContentResponse(TYPE_XML) {

}

JsonContentResponse::JsonContentResponse() : ContentResponse(TYPE_JSON) {

}

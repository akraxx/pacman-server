#include "Responder.h"

Responder::Responder(GraphList* graphs) {
    this->graphs = graphs;
}

Responder::~Responder() {
    
}

void Responder::send(Response* response) {
    this->currentRequest->setHeader("STATUS", response->getResponseCode().toLocal8Bit());
    this->currentRequest->setHeader("CONTENT-TYPE", response->getContentType().toLocal8Bit());
    /* IF THERE IS A LOCATION */
    if(!response->getLocation().isEmpty())
        this->currentRequest->setHeader("Location", response->getLocation().toLocal8Bit());
    QTextStream out(this->currentRequest);

    out << response->getContent() << endl;
}
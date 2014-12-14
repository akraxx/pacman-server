/* 
 * File:   DijkstraSerializerXml.h
 * Author: isen
 *
 * Created on 2 mai 2011, 14:11
 */

#ifndef DIJKSTRASERIALIZERXML_H
#define	DIJKSTRASERIALIZERXML_H

#include "DijkstraSerializer.h"

class DijkstraSerializerXml : public DijkstraSerializer {
public:
    DijkstraSerializerXml(QVariantList pathAndCost);
    virtual ~DijkstraSerializerXml();

    QString getSerializedDijkstra();
};


#endif	/* DIJKSTRASERIALIZERXML_H */


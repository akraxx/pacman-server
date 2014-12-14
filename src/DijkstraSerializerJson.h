/* 
 * File:   DijkstraSerializerJson.h
 * Author: isen
 *
 * Created on 2 mai 2011, 14:11
 */

#ifndef DIJKSTRASERIALIZERJSON_H
#define	DIJKSTRASERIALIZERJSON_H

#include "DijkstraSerializer.h"

class DijkstraSerializerJson : public DijkstraSerializer {
public:
    DijkstraSerializerJson(QVariantList pathAndCost);
    virtual ~DijkstraSerializerJson();

    QString getSerializedDijkstra();
};

#endif	/* DIJKSTRASERIALIZERJSON_H */


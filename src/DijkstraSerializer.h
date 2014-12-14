/* 
 * File:   DijkstraSerializer.h
 * Author: isen
 *
 * Created on 2 mai 2011, 14:08
 */

#ifndef DIJKSTRASERIALIZER_H
#define	DIJKSTRASERIALIZER_H

#include "Dijkstra.h"

class DijkstraSerializer {
protected:
    int cost;
    QVariantList path;
public:
    DijkstraSerializer(QVariantList pathAndCost);
    virtual ~DijkstraSerializer();

    virtual QString getSerializedDijkstra() = 0;
};


#endif	/* DIJKSTRASERIALIZER_H */


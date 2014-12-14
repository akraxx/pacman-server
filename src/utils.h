/* 
 * File:   utils.h
 * Author: isen
 *
 * Created on 11 mars 2011, 10:04
 */

#ifndef UTILS_H
#define	UTILS_H



#define EDGE_INEXISTENT 0;
#define EDGE_EXIST 1

/* QT NEEDED */
#include <QtCore/QCoreApplication>
#include <QObject>
#include <QDebug>
#include <QDomDocument>
#include <QRegExp>
#include <QStack>

#include <FastCgiQt/Manager.h>
#include <FastCgiQt/PrefixMapper.h>
#include <FastCgiQt/Request.h>
#include <QTextStream>
#include <QStringList>
#include <qjson/serializer.h>
#include <QDateTime>

#define DEFAULT_EXT "xml"
#define TYPE_XML "application/xml"
#define TYPE_JSON "application/json"
using namespace FastCgiQt;

#define GRAPH_UNDEFINED_URL 0
#define GRAPH_GRAPHLISTJSON_URL 1
#define GRAPH_GRAPHLISTXML_URL 2

/* BOTH NEEDED */
#define DEFAULT_TYPEVAL int
#define KEEP_ALIVE 60
#define UNDEFINED_VALUE 0

/* TEST NEEDED */
#define DEFAULT_SINGLETEST_HIERARCHY 7

/* TYPE Graph & MATRIX NEEDED */

#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <unistd.h>

using namespace std;

#endif	/* UTILS_H */


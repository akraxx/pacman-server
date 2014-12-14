/* 
 * File:   Parser.h
 * Author: isen
 *
 * Created on 18 mars 2011, 09:18
 */

#ifndef PARSER_H
#define	PARSER_H

#include "utils.h"

/* Class Parser
 * ----------------------------------------
 * Parse the query and the pathinfo
 * ----------------------------------------
 */
class Parser {
protected:
    QByteArray pathinfo;
    QHash<QByteArray, QByteArray> query;
    QByteArray extension;
    QVariantHash data;
public:
    /* Function Parser
     * ----------------------------------------
     * Constructor
     * ----------------------------------------
     * @pathinfo = The pathinfo of the thrown request
     * @query = The query of the thrown request
     */
    Parser(QByteArray pathinfo, QHash<QByteArray, QByteArray> query);

    /*
     * GETTERS & SETTERS
     * */
    QHash<QByteArray, QByteArray> getQuery() { return query; };
    QByteArray getPathinfo() { return pathinfo; };
    QByteArray getExtension() { return extension; };
    QVariantHash getData() { return data; };

    /* Function patternInPathinfo
     * ----------------------------------------
     * Check if the pattern is in the pathinfo
     * ----------------------------------------
     * @pattern = pattern which have to be found
     * ----------------------------------------
     * @return = true if the pattern has been found, else otherwise
     */
    bool patternInPathinfo(QString pattern);

    /* Function extractChainFromPathinfo
     * ----------------------------------------
     * Extract a variable chain from the pathinfo with the pattern's regex
     * ----------------------------------------
     * @pattern = pattern which have to be found
     * @index = index of the cap
     * ----------------------------------------
     * @return = The searched chain if it has been found, the entire pathinfo otherwise
     */
    QString extractChainFromPathinfo(QString pattern, int index = 0);

    virtual void parseQuery() = 0;
};

#endif	/* PARSER_H */


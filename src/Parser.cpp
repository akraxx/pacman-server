#include "Parser.h"

Parser::Parser(QByteArray pathinfo, QHash<QByteArray, QByteArray> query) {
    this->pathinfo = pathinfo;
    this->query = query;

    /* GET THE EXTENSION OF THE PATHINFO */
    QList<QByteArray> splitedPath = this->pathinfo.split('/');
    if(splitedPath.last().contains("."))
        this->extension = splitedPath.last().split('.').last();
    else
        this->extension = DEFAULT_EXT;
}

bool Parser::patternInPathinfo(QString pattern) {
    QRegExp reg(pattern);
    return (reg.indexIn(pathinfo) > -1);
}

QString Parser::extractChainFromPathinfo(QString pattern, int index ) {
    QRegExp reg(pattern);
    if(reg.indexIn(pathinfo) > -1)
        return reg.cap(index);
    /* IF THERE IS NO PATTERN IN PATHINFO WE RETURN THE ENTIRE PATHINFO */
    else
        return pathinfo;
}

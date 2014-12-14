/* 
 * File:   singleTestHtml.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:06
 */

#ifndef SINGLETESTHTML_H
#define	SINGLETESTHTML_H

#include "SingleTest.h"

/* Class SingleTestHtml inherit from SingleTest
 * ----------------------------------------
 * Create a single test in html format
 * ----------------------------------------
 */
class SingleTestHtml : public SingleTest {
/* PRIVATE VARIABLES
 * @obtainedResult = obtained result in QDomDocument
 * */
private:
    QDomDocument obtainedResult;
public:
    /* CONSTRUCTOR */
    SingleTestHtml(QString title);

    /* SETTERS & GETTERS */
    void setObtainedResult(QDomDocument obtainedResult) {
        this->obtainedResult = obtainedResult;
    }
    QDomDocument getObtainedResult() const {
        return obtainedResult;
    }

    /* Function concatObtainedResult
     * ----------------------------------------
     * Concat a element to the obtainedResult
     * ----------------------------------------
     * @elem = elem to be concat
     */
    void concatObtainedResult(QDomDocument elem) {
        this->obtainedResult.appendChild(elem);
    }

    /* Function exceptionToDom
     * ----------------------------------------
     * Convert QString an exception into a QDomDocument
     * ----------------------------------------
     * @exception = exception to be transformed
     * ----------------------------------------
     * @return the transformed document
     */
    QDomDocument exceptionToDom(QString exception);

    /* Function formatTest
     * ----------------------------------------
     * Format the test and append it to a document
     * ----------------------------------------
     * @doc = pointer on the parent document
     */
    void formatTest(QDomDocument* doc);
};


#endif	/* SINGLETESTHTML_H */


/* 
 * File:   singleTest.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:06
 */

#ifndef SINGLETEST_H
#define	SINGLETEST_H

#include "utils.h"

/* Class SingleTest
 * ----------------------------------------
 * Create a single test
 * ----------------------------------------
 */
class SingleTest {
/* PROTECTED VARIABLES
 * @title = title of the test
 * @intention = intention of the test
 * @expectedResult = expected result
 * @conclusion = conclusion of the test
 * */
protected:
    QString title;
    QString intention;
    QString expectedResult;
    QString conclusion;
public:
    /* CONSTRUCTOR */
    SingleTest(QString title);

    /* SETTERS & GETTERS */
    void setConclusion(QString conclusion = "") { this->conclusion = conclusion; };
    QString getConclusion() const { return conclusion; };

    void setExpectedResult(QString expectedResult = "") { this->expectedResult = expectedResult; };
    QString getExpectedResult() const { return expectedResult; };

    void setIntention(QString intention = "") { this->intention = intention; };
    QString getIntention() const { return intention; };

    void setTitle(QString title = "") { this->title = title; };
    QString getTitle() const { return title; };
};

#endif	/* SINGLETEST_H */


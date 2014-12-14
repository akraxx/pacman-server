/* 
 * File:   SingleTestConsole.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:26
 */

#ifndef SINGLETESTCONSOLE_H
#define	SINGLETESTCONSOLE_H

#include "SingleTest.h"

/* Class SingleTestConsole inherit from SingleTest
 * ----------------------------------------
 * Create a single test in console
 * ----------------------------------------
 */
class SingleTestConsole : public SingleTest {
/* PRIVATE VARIABLES
 * @obtainedResult = obtained result in string
 * */
private:
    QString obtainedResult;
public:
    /* CONSTRUCTOR */
    SingleTestConsole(QString title);

    /* SETTERS & GETTERS */
    void setObtainedResult(QString obtenaidResult) { this->obtainedResult = obtenaidResult; };
    QString getObtainedResult() const { return obtainedResult; };

    /* Function formatTest
     * ----------------------------------------
     * format the test for a console output
     * ----------------------------------------
     * @return = return the formatted test in a string
     */
    QString formatTest();
};

#endif	/* SINGLETESTCONSOLE_H */


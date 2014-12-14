/* 
 * File:   TestObjectifConsole.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:09
 */

#ifndef TESTOBJECTIFCONSOLE_H
#define	TESTOBJECTIFCONSOLE_H

#include "TestObjectif.h"

/* Class TestObjectifConsole, inherit from TestObjectif
 * ----------------------------------------
 * Create an objectif test in console
 * ----------------------------------------
 */
class TestObjectifConsole : public TestObjectif {
/* PROTECTED VARIABLES
 * @out = output is a string
 * */
protected:
    QString out;
public:
    /* CONSTRUCTOR */
    TestObjectifConsole(QString testName);

    /* Function addTitle
     * ----------------------------------------
     * add title to the output
     * ----------------------------------------
     * @title = title to be added
     * @hierarchy = hierarchy in the document
     */
    void addTitle(QString title, int hierarchy);

    /* Function printTest
     * ----------------------------------------
     * print the output in the console
     * ----------------------------------------
     */
    void printTest();
};

#endif	/* TESTOBJECTIFCONSOLE_H */


/* 
 * File:   TestObjectif.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:07
 */

#ifndef TESTOBJECTIF_H
#define	TESTOBJECTIF_H

#include "utils.h"
#include "SingleTest.h"

/* Class TestObjectif
 * ----------------------------------------
 * Create an objectif test
 * ----------------------------------------
 */
class TestObjectif {
/* PROTECTED VARIABLES
 * @testName = the name of the test objectif
 * */
protected:
    QString testName;
public:
    /* CONSTRUCTOR */
    TestObjectif(QString testName);

    /* Function addTitle
     * ----------------------------------------
     * Pure virtual methode, add title to the output
     * ----------------------------------------
     * @title = title to be added
     * @hierarchy = hierarchy in the document
     */
    virtual void addTitle(QString title, int hierarchy) = 0;

    /* Function printTest
     * ----------------------------------------
     * Pure virtual methode, print the output
     * ----------------------------------------
     */
    virtual void printTest() = 0;
};


#endif	/* TESTOBJECTIF_H */


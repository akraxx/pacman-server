/* 
 * File:   TestObjectifHtml.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:08
 */

#ifndef TESTOBJECTIFHTML_H
#define	TESTOBJECTIFHTML_H

#include "TestObjectif.h"

/* Class TestObjectifHtml, inherit from TestObjectif
 * ----------------------------------------
 * Create an objectif test in html format
 * ----------------------------------------
 */
class TestObjectifHtml : public TestObjectif {
/* PROTECTED VARIABLES
 * @out = output is a QDomDocument
 * */
protected:
    QDomDocument out;
public:
    /* CONSTRUCTOR */
    TestObjectifHtml(QString testName);

    /* Function convertToDocument
     * ----------------------------------------
     * Convert a QVariant into QDomDocument
     * ----------------------------------------
     * @var = QVariant to be converted
     * ----------------------------------------
     * @return = the converted QVariant
     */
    QDomDocument convertToDocument(QVariant var);

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
     * print the output in an html file
     * ----------------------------------------
     */
    void printTest();
};

#endif	/* TESTOBJECTIFHTML_H */


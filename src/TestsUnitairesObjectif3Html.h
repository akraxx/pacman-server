/*
 * File:   TestUnitairesObjectif2Html.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:27
 */

#ifndef TESTUNITAIRESOBJECTIF3HTML_H
#define	TESTUNITAIRESOBJECTIF3HTML_H

#include "TestObjectifHtml.h"
#include "TestsUnitairesObjectif3.h"
#include "SingleTestHtml.h"
#include "GraphQt.h"

/* Class TestsUnitairesObjectif3Html, inherit from TestsUnitairesObjectif3
 * ----------------------------------------
 * Test the objectif in an HTML format
 * ----------------------------------------
 */
class TestsUnitairesObjectif3Html : public TestsUnitairesObjectif3, public TestObjectifHtml {
private:
    QDomDocument formattedHtmlDijkstra(QVariantList pathAndCost);
public:
    /* CONSTRUCTOR */
    TestsUnitairesObjectif3Html();

    /* Function executeTestCampaign
     * ----------------------------------------
     * Execute all the campaign (title + test + print)
     * ----------------------------------------
     */
    void executeTestCampaign();
    // NORMAL
    void test3311111(); //cas normal path trouvé
    void test3311112(); //cas normal path non trouvé

    // LIMITE
    void test3311121(); //cas limite path sur un noeud

    // ERREUR
    void test3311131(); //cas d'erreur : noeud start existe pas
    void test3311132(); //cas d'erreur : noeud goal existe pas
};

#endif	/* TESTUNITAIRESOBJECTIF2HTML_H */


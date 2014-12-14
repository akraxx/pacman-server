/*
 * File:   TestObjectif2.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:11
 */

#ifndef TESTOBJECTIF3_H
#define	TESTOBJECTIF3_H

#include "utils.h"

/* Class TestsUnitairesObjectif3
 * ----------------------------------------
 * Define all the test of the objectif
 * ----------------------------------------
 */
class TestsUnitairesObjectif3 {
public:
    /* Function executeTestCampaign
     * ----------------------------------------
     * Pure virtual methode, execute all the campaign (title + test + print)
     * ----------------------------------------
     */

    virtual void executeTestCampaign() = 0;
    // NORMAL
    virtual void test3311111() = 0; //cas normal path trouvé
    virtual void test3311112() = 0; //cas normal path non trouvé

    // LIMITE
    virtual void test3311121() = 0; //cas limite path sur un noeud

    // ERREUR
    virtual void test3311131() = 0; //cas d'erreur : noeud start existe pas
    virtual void test3311132() = 0; //cas d'erreur : noeud goal existe pas
};

#endif	/* TESTOBJECTIF2_H */


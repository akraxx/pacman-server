/* 
 * File:   TestObjectif2.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:11
 */

#ifndef TESTOBJECTIF2_H
#define	TESTOBJECTIF2_H

#include "utils.h"

/* Class TestsUnitairesObjectif2
 * ----------------------------------------
 * Define all the test of the objectif
 * ----------------------------------------
 */
class TestsUnitairesObjectif2 {
public:
    /* Function executeTestCampaign
     * ----------------------------------------
     * Pure virtual methode, execute all the campaign (title + test + print)
     * ----------------------------------------
     */

    virtual void executeTestCampaign() = 0;
    //CONSTRUCTEUR
    virtual void test3241111() = 0; //cas normal oriented & weighted
    virtual void test3241112() = 0; //cas normal !oriented & weighted
    virtual void test3241113() = 0; //cas normal oriented & !weighted
    virtual void test3241114() = 0; //cas normal !oriented & !weighted

    //GETORDER
    virtual void test3241211() = 0; //cas normal

    //NODEEXISTS
    virtual void test3242111() = 0; //cas normal : le noeud existe
    virtual void test3242112() = 0; //cas normal : le noeud n'existe pas

    //ADDNODE
    virtual void test3242211() = 0; //cas normal : ajout d'un noeud du graphe
    virtual void test3242221() = 0; //cas limite : ajout d'un noeud en premiere position du graphe
    virtual void test3242222() = 0; //cas limite : ajout d'un noeud en derniere position du graphe
    virtual void test3242231() = 0; //cas d'erreur : ajout d'un noeud avec un id negatif
    virtual void test3242232() = 0; //cas d'erreur : ajout d'un noeud deja exsitent

    //SETNODEVALUE
    virtual void test3242311() = 0; //cas normal : attribue la valeur d'un noeud du graphe
    virtual void test3242321() = 0; //cas limite : attribue la valeur du premier noeud du graphe
    virtual void test3242322() = 0; //cas limite : attribue la valeur du dernier noeud du graphe
    virtual void test3242331() = 0; //cas d'erreur : attribue la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

    //GETNODEVALUE
    virtual void test3242411() = 0; //cas normal : cherche la valeur d'un noeud du graphe
    virtual void test3242421() = 0; //cas limite : cherche la valeur du premier noeud du graphe
    virtual void test3242422() = 0; //cas limite : cherche la valeur du dernier noeud du graphe
    virtual void test3242431() = 0; //cas d'erreur : cherche la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

    //REMOVENODE
    virtual void test3242511() = 0; //cas normal : supprime un noeud du graphe
    virtual void test3242521() = 0; //cas limite : supprime le premier noeud du graphe
    virtual void test3242522() = 0; //cas limite : supprime le dernier noeud du graphe
    virtual void test3242531() = 0; //cas d'erreur : supprime un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

    //EDGEEXISTS
    virtual void test3243111() = 0; //cas normal : l'arc existe
    virtual void test3243112() = 0; //cas normal : l'arc n'existe pas (comprend plusieurs cas : un des noeuds ou les deux noeuds hors du graphe et l'arc est entre un ou 2 noeuds d'id negatif)
    virtual void test3243121() = 0; //cas limite : l'arc est sur le premier noeud du graphe
    virtual void test3243122() = 0; //cas limite : l'arc est sur le dernier noeud du graphe

    //ADDEDGE
    virtual void test3243211() = 0; //cas normal : ajout d'un arc dans un graphe oriented (comprend aussi le cas du graphe !oriented)
    virtual void test3243221() = 0; //cas limite : ajout d'un arc sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)
    virtual void test3243222() = 0; //cas limite : ajout d'un arc sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)
    virtual void test3243231() = 0; //cas d'erreur : ajout d'un arc entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    virtual void test3243232() = 0; //cas d'erreur : ajout d'un arc deja existent
    virtual void test3243233() = 0; //cas d'erreur : ajout d'un arc dans un graph non pondéré

    //SETEDGEVALUE
    virtual void test3243311() = 0; //cas normal : attribue la valeur d'un arc dans un graphe oriented (comprend aussi le cas du graphe !oriented)
    virtual void test3243321() = 0; //cas limite : attribue la valeur d'un arc sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)
    virtual void test3243322() = 0; //cas limite : attribue la valeur d'un arc sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)
    virtual void test3243331() = 0; //cas d'erreur : attribue la valeur d'un arc entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    virtual void test3243332() = 0; //cas d'erreur : attribue la valeur d'un arc dans un graph non pondéré
    virtual void test3243333() = 0; //cas d'erreur : attribue la valeur d'un arc inexistant

    //GETEDGEVALUE
    virtual void test3243411() = 0; //cas normal : cherche la valeur d'un arc du graphe
    virtual void test3243421() = 0; //cas limite : cherche la valeur de l'arc du premier noeud du graphe
    virtual void test3243422() = 0; //cas limite : cherche la valeur de l'arc du dernier noeud du graphe
    virtual void test3243431() = 0; //cas d'erreur : cherche la valeur de l'arc entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    virtual void test3243432() = 0; //cas d'erreur : cherche la valeur d'un arc dans un graph non pondéré
    virtual void test3243433() = 0; //cas d'erreur : cherche la valeur d'un arc inexistant
    //REMOVEEDGE
    virtual void test3243511() = 0; //cas normal : supprime un arc du graphe
    virtual void test3243521() = 0; //cas limite : supprime l'arc du premier noeud du graphe
    virtual void test3243522() = 0; //cas limite : supprime l'arc du dernier noeud du graphe
    virtual void test3243531() = 0; //cas d'erreur : supprime un arc hors du graphe entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    virtual void test3243532() = 0; //cas d'erreur : supprime un arc dans un graph non pondéré
    virtual void test3243533() = 0; //cas d'erreur : supprime un arc inexistant

    //GETNEIGHBORHOODSIZE
    virtual void test3244111() = 0; //cas normal : nombre de voisins d'un noeud du graphe
    virtual void test3244121() = 0; //cad d'erreur : nombre de voisins d'un noeud hors graphe

    //GETNEIGHBOR
    virtual void test3244211() = 0; //cas normal : retourne le k-ieme voisin d'un noeud du graphe
    virtual void test3244221() = 0; //cas limite : retourne le premier voisin d'un noeud du graphe
    virtual void test3244222() = 0; //cas limite : retourne le dernier voisin d'un noeud du graphe
    virtual void test3244231() = 0; //cas d'erreur : retourne le k-ieme voisin non existent d'un noeud
    virtual void test3244232() = 0; //cas d'erreur : retourne le k-ieme voisin d'un noeud inexistant
};

#endif	/* TESTOBJECTIF2_H */


/* 
 * File:   TestUnitairesObjectif2Html.h
 * Author: isen
 *
 * Created on 20 mars 2011, 15:27
 */

#ifndef TESTUNITAIRESOBJECTIF2HTML_H
#define	TESTUNITAIRESOBJECTIF2HTML_H

#include "TestObjectifHtml.h"
#include "TestsUnitairesObjectif2.h"
#include "SingleTestHtml.h"
#include "GraphQt.h"

/* Class TestsUnitairesObjectif2Html, inherit from TestsUnitairesObjectif2
 * ----------------------------------------
 * Test the objectif in an HTML format
 * ----------------------------------------
 */
class TestsUnitairesObjectif2Html : public TestsUnitairesObjectif2, public TestObjectifHtml {
public:
    /* CONSTRUCTOR */
    TestsUnitairesObjectif2Html();

    /* Function executeTestCampaign
     * ----------------------------------------
     * Execute all the campaign (title + test + print)
     * ----------------------------------------
     */
    void executeTestCampaign();
    //CONSTRUCTEUR
    void test3241111(); //cas normal oriented & weighted
    void test3241112(); //cas normal !oriented & weighted
    void test3241113(); //cas normal oriented & !weighted
    void test3241114(); //cas normal !oriented & !weighted

    //GETORDER
    void test3241211(); //cas normal

    //NODEEXISTS
    void test3242111(); //cas normal : le noeud existe
    void test3242112(); //cas normal : le noeud n'existe pas

    //ADDNODE
    void test3242211(); //cas normal : ajout d'un noeud du graphe
    void test3242221(); //cas limite : ajout d'un noeud en premiere position du graphe
    void test3242222(); //cas limite : ajout d'un noeud en derniere position du graphe
    void test3242231(); //cas d'erreur : ajout d'un noeud avec un id negatif
    void test3242232(); //cas d'erreur : ajout d'un noeud deja exsitent

    //SETNODEVALUE
    void test3242311(); //cas normal : attribue la valeur d'un noeud du graphe
    void test3242321(); //cas limite : attribue la valeur du premier noeud du graphe
    void test3242322(); //cas limite : attribue la valeur du dernier noeud du graphe
    void test3242331(); //cas d'erreur : attribue la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

    //GETNODEVALUE
    void test3242411(); //cas normal : cherche la valeur d'un noeud du graphe
    void test3242421(); //cas limite : cherche la valeur du premier noeud du graphe
    void test3242422(); //cas limite : cherche la valeur du dernier noeud du graphe
    void test3242431(); //cas d'erreur : cherche la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

    //REMOVENODE
    void test3242511(); //cas normal : supprime un noeud du graphe
    void test3242521(); //cas limite : supprime le premier noeud du graphe
    void test3242522(); //cas limite : supprime le dernier noeud du graphe
    void test3242531(); //cas d'erreur : supprime un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

    //EDGEEXISTS
    void test3243111(); //cas normal : l'arc existe
    void test3243112(); //cas normal : l'arc n'existe pas (comprend plusieurs cas : un des noeuds ou les deux noeuds hors du graphe et l'arc est entre un ou 2 noeuds d'id negatif)
    void test3243121(); //cas limite : l'arc est sur le premier noeud du graphe
    void test3243122(); //cas limite : l'arc est sur le dernier noeud du graphe

    //ADDEDGE
    void test3243211(); //cas normal : ajout d'un arc dans un graphe oriented (comprend aussi le cas du graphe !oriented)
    void test3243221(); //cas limite : ajout d'un arc sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)
    void test3243222(); //cas limite : ajout d'un arc sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)
    void test3243231(); //cas d'erreur : ajout d'un arc entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    void test3243232(); //cas d'erreur : ajout d'un arc deja existent
    void test3243233(); //cas d'erreur : ajout d'un arc dans un graph non pondéré

    //SETEDGEVALUE
    void test3243311(); //cas normal : attribue la valeur d'un arc dans un graphe oriented (comprend aussi le cas du graphe !oriented)
    void test3243321(); //cas limite : attribue la valeur d'un arc sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)
    void test3243322(); //cas limite : attribue la valeur d'un arc sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)
    void test3243331(); //cas d'erreur : attribue la valeur d'un arc entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    void test3243332(); //cas d'erreur : attribue la valeur d'un arc dans un graph non pondéré
    void test3243333(); //cas d'erreur : attribue la valeur d'un arc inexistant

    //GETEDGEVALUE
    void test3243411(); //cas normal : cherche la valeur d'un arc du graphe
    void test3243421(); //cas limite : cherche la valeur de l'arc du premier noeud du graphe
    void test3243422(); //cas limite : cherche la valeur de l'arc du dernier noeud du graphe
    void test3243431(); //cas d'erreur : cherche la valeur de l'arc entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    void test3243432(); //cas d'erreur : cherche la valeur d'un arc dans un graph non pondéré
    void test3243433(); //cas d'erreur : cherche la valeur d'un arc inexistant

    //REMOVEEDGE
    void test3243511(); //cas normal : supprime un arc du graphe
    void test3243521(); //cas limite : supprime l'arc du premier noeud du graphe
    void test3243522(); //cas limite : supprime l'arc du dernier noeud du graphe
    void test3243531(); //cas d'erreur : supprime un arc hors du graphe entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
    void test3243532(); //cas d'erreur : supprime un arc dans un graph non pondéré
    void test3243533(); //cas d'erreur : supprime un arc inexistant

    //GETNEIGHBORHOODSIZE
    void test3244111(); //cas normal : nombre de voisins d'un noeud du graphe
    void test3244121(); //cad d'erreur : nombre de voisins d'un noeud hors graphe

    //GETNEIGHBOR
    void test3244211(); //cas normal : retourne le k-ieme voisin d'un noeud du graphe
    void test3244221(); //cas limite : retourne le premier voisin d'un noeud du graphe
    void test3244222(); //cas limite : retourne le dernier voisin d'un noeud du graphe
    void test3244231(); //cas d'erreur : retourne le k-ieme voisin non existent d'un noeud
    void test3244232(); //cas d'erreur : retourne le k-ieme voisin d'un noeud inexistant
};

#endif	/* TESTUNITAIRESOBJECTIF2HTML_H */


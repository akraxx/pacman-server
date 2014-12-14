#include "TestsUnitairesObjectif3Html.h"
#include "TestObjectif.h"
#include "Dijkstra.h"

TestsUnitairesObjectif3Html::TestsUnitairesObjectif3Html() : TestObjectifHtml("TestsUnitairesObjectif3") {

}

QDomDocument TestsUnitairesObjectif3Html::formattedHtmlDijkstra(QVariantList pathAndCost) {
    QDomDocument doc;
    QDomElement elemFieldset = doc.createElement("fieldset");
    QDomElement elemLegend = doc.createElement("legend");

    QDomText textLegend = doc.createTextNode("Dijkstra");
    elemLegend.appendChild(textLegend);
    elemFieldset.appendChild(elemLegend);

    QDomElement elemCost = doc.createElement("div");
    QDomText textCost = doc.createTextNode("total cost : " + pathAndCost.first().toString());
    elemCost.appendChild(textCost);
    elemFieldset.appendChild(elemCost);
    pathAndCost.removeFirst();

    QString nodes;
    for(int i = 0; i < pathAndCost.size(); i++)
        nodes += pathAndCost.at(i).toString() + " ";
    QDomElement elemNode = doc.createElement("div");
    QDomText textNode = doc.createTextNode("path : " + nodes);
    elemNode.appendChild(textNode);
    elemFieldset.appendChild(elemNode);

    doc.appendChild(elemFieldset);

    return doc;
}

void TestsUnitairesObjectif3Html::executeTestCampaign() {
    this->addTitle("3.3.1. Test unitaires", 3);

    this->addTitle("3.3.1.1. Manipulation dijkstra", 4);
    this->addTitle("3.3.1.1.1. Obtenir chemin", 5);
    this->addTitle("3.3.1.1.1.1. Cas normal", 6);
    this->test3311111();
    this->test3311112();
    this->addTitle("3.3.1.1.1.2. Cas limite", 6);
    this->test3311121();
    this->addTitle("3.3.1.1.1.3. Cas d'erreur", 6);
    this->test3311131();
    this->test3311132();

    this->printTest();
}

void TestsUnitairesObjectif3Html::test3311111() {
    SingleTestHtml singleTest("3.3.1.1.1.1.1. Obtention du chemin le plus court dans un graph");

    singleTest.setIntention("Creation d'un graph de 10 noeuds, composes d'arcs. On cherche le chemin le plus court entre le noeud 1 et le noeud 10.");
    singleTest.setExpectedResult("Le reponse doit etre la suivante : 1, 4, 5, 7, 2, 10 avec un cout de 12.");
    try {
        GraphQt<DEFAULT_TYPEVAL>* g = new GraphQt<DEFAULT_TYPEVAL>(false, true, "test");
        for(int i = 1; i <= 10; i++)
            g->addNode(i);

        g->addEdge(1,9);
        g->setEdgeValue(1,9,14);
        g->addEdge(1,2);
        g->setEdgeValue(1,2,12);
        g->addEdge(1,7);
        g->setEdgeValue(1,7,8);
        g->addEdge(1,3);
        g->setEdgeValue(1,3,2);
        g->addEdge(1,4);
        g->setEdgeValue(1,4,2);

        g->addEdge(10,9);
        g->setEdgeValue(10,9,1);
        g->addEdge(10,2);
        g->setEdgeValue(10,2,4);
        g->addEdge(10,7);
        g->setEdgeValue(10,7,6);
        g->addEdge(10,5);
        g->setEdgeValue(10,5,8);
        g->addEdge(10,6);
        g->setEdgeValue(10,6,9);
        g->addEdge(10,8);
        g->setEdgeValue(10,8,4);

        g->addEdge(2,7);
        g->setEdgeValue(2,7,1);
        g->addEdge(3,7);
        g->setEdgeValue(3,7,7);
        g->addEdge(5,7);
        g->setEdgeValue(5,7,1);

        g->addEdge(3,5);
        g->setEdgeValue(3,5,5);
        g->addEdge(3,4);
        g->setEdgeValue(3,4,3);

        g->addEdge(4,5);
        g->setEdgeValue(4,5,4);
        g->addEdge(4,6);
        g->setEdgeValue(4,6,5);

        g->addEdge(5,6);
        g->setEdgeValue(5,6,6);

        g->addEdge(6,8);
        g->setEdgeValue(6,8,3);

        Dijkstra d(g);
        singleTest.setObtainedResult(this->formattedHtmlDijkstra(d.findShortestPath(1,10)));
        delete g;
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Nous avons bien recupere le chemin le plus court.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif3Html::test3311112() {
    SingleTestHtml singleTest("3.3.1.1.1.1.2. Obtention du chemin le plus court dans un graph, mais celui ci n'existe pas");

    singleTest.setIntention("Creation d'un graph de 10 noeuds sans arcs. On cherche le chemin le plus court entre le noeud 1 et le noeud 10.");
    singleTest.setExpectedResult("Le server doit nous indiquer qu'il n'existe pas.");
    try {
        GraphQt<DEFAULT_TYPEVAL>* g = new GraphQt<DEFAULT_TYPEVAL>(false, true, "test");
        for(int i = 1; i <= 10; i++)
            g->addNode(i);

        Dijkstra d(g);
        singleTest.setObtainedResult(this->formattedHtmlDijkstra(d.findShortestPath(1,10)));
        delete g;
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Nous avons bien recupere le message.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif3Html::test3311121() {
    SingleTestHtml singleTest("3.3.1.1.1.2.1. Obtention du chemin le plus court dans un graph");

    singleTest.setIntention("Creation d'un graph de 10 noeuds. On cherche le chemin le plus court entre le noeud 1 et le noeud 1.");
    singleTest.setExpectedResult("Le reponse doit etre la suivante : 1 avec un cout de 0.");
    try {
        GraphQt<DEFAULT_TYPEVAL>* g = new GraphQt<DEFAULT_TYPEVAL>(false, true, "test");
        for(int i = 1; i <= 10; i++)
            g->addNode(i);

        Dijkstra d(g);
        singleTest.setObtainedResult(this->formattedHtmlDijkstra(d.findShortestPath(1,1)));
        delete g;
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Nous avons bien recupere le chemin le plus court.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif3Html::test3311131() {
    SingleTestHtml singleTest("3.3.1.1.1.3.1. Obtention du chemin le plus court dans un graph avec un noeud de depart inexistant");

    singleTest.setIntention("Creation d'un graph de 10 noeuds, composes d'arcs. On cherche le chemin le plus court entre le noeud 11 et le noeud 1.");
    singleTest.setExpectedResult("On doit recuperer une erreur car le noeud d'id 11 n'existe pas.");
    try {
        GraphQt<DEFAULT_TYPEVAL>* g = new GraphQt<DEFAULT_TYPEVAL>(false, true, "test");
        for(int i = 1; i <= 10; i++)
            g->addNode(i);

        g->addEdge(1,9);
        g->setEdgeValue(1,9,14);
        g->addEdge(1,2);
        g->setEdgeValue(1,2,12);
        g->addEdge(1,7);
        g->setEdgeValue(1,7,8);
        g->addEdge(1,3);
        g->setEdgeValue(1,3,2);
        g->addEdge(1,4);
        g->setEdgeValue(1,4,2);

        g->addEdge(10,9);
        g->setEdgeValue(10,9,1);
        g->addEdge(10,2);
        g->setEdgeValue(10,2,4);
        g->addEdge(10,7);
        g->setEdgeValue(10,7,6);
        g->addEdge(10,5);
        g->setEdgeValue(10,5,8);
        g->addEdge(10,6);
        g->setEdgeValue(10,6,9);
        g->addEdge(10,8);
        g->setEdgeValue(10,8,4);

        g->addEdge(2,7);
        g->setEdgeValue(2,7,1);
        g->addEdge(3,7);
        g->setEdgeValue(3,7,7);
        g->addEdge(5,7);
        g->setEdgeValue(5,7,1);

        g->addEdge(3,5);
        g->setEdgeValue(3,5,5);
        g->addEdge(3,4);
        g->setEdgeValue(3,4,3);

        g->addEdge(4,5);
        g->setEdgeValue(4,5,4);
        g->addEdge(4,6);
        g->setEdgeValue(4,6,5);

        g->addEdge(5,6);
        g->setEdgeValue(5,6,6);

        g->addEdge(6,8);
        g->setEdgeValue(6,8,3);

        Dijkstra d(g);
        singleTest.setObtainedResult(this->formattedHtmlDijkstra(d.findShortestPath(11,1)));
        delete g;
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Nous avons bien recupere l'erreur.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif3Html::test3311132() {
    SingleTestHtml singleTest("3.3.1.1.1.3.2. Obtention du chemin le plus court dans un graph avec un noeud de fin inexistant");

    singleTest.setIntention("Creation d'un graph de 10 noeuds, composes d'arcs. On cherche le chemin le plus court entre le noeud 1 et le noeud 11.");
    singleTest.setExpectedResult("On doit recuperer une erreur car le noeud d'id 11 n'existe pas.");
    try {
        GraphQt<DEFAULT_TYPEVAL>* g = new GraphQt<DEFAULT_TYPEVAL>(false, true, "test");
        for(int i = 1; i <= 10; i++)
            g->addNode(i);

        g->addEdge(1,9);
        g->setEdgeValue(1,9,14);
        g->addEdge(1,2);
        g->setEdgeValue(1,2,12);
        g->addEdge(1,7);
        g->setEdgeValue(1,7,8);
        g->addEdge(1,3);
        g->setEdgeValue(1,3,2);
        g->addEdge(1,4);
        g->setEdgeValue(1,4,2);

        g->addEdge(10,9);
        g->setEdgeValue(10,9,1);
        g->addEdge(10,2);
        g->setEdgeValue(10,2,4);
        g->addEdge(10,7);
        g->setEdgeValue(10,7,6);
        g->addEdge(10,5);
        g->setEdgeValue(10,5,8);
        g->addEdge(10,6);
        g->setEdgeValue(10,6,9);
        g->addEdge(10,8);
        g->setEdgeValue(10,8,4);

        g->addEdge(2,7);
        g->setEdgeValue(2,7,1);
        g->addEdge(3,7);
        g->setEdgeValue(3,7,7);
        g->addEdge(5,7);
        g->setEdgeValue(5,7,1);

        g->addEdge(3,5);
        g->setEdgeValue(3,5,5);
        g->addEdge(3,4);
        g->setEdgeValue(3,4,3);

        g->addEdge(4,5);
        g->setEdgeValue(4,5,4);
        g->addEdge(4,6);
        g->setEdgeValue(4,6,5);

        g->addEdge(5,6);
        g->setEdgeValue(5,6,6);

        g->addEdge(6,8);
        g->setEdgeValue(6,8,3);

        Dijkstra d(g);
        singleTest.setObtainedResult(this->formattedHtmlDijkstra(d.findShortestPath(1,11)));
        delete g;
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Nous avons bien recupere le chemin le plus court.");
    singleTest.formatTest(&this->out);
}
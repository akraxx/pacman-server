#include "TestsUnitairesObjectif2Html.h"
#include "TestObjectif.h"

TestsUnitairesObjectif2Html::TestsUnitairesObjectif2Html() : TestObjectifHtml("TestsUnitairesObjectif2") {
    
}

void TestsUnitairesObjectif2Html::executeTestCampaign() {
    this->addTitle("3.2.4. Tests unitaires", 3);
    this->addTitle("3.2.4.1. Manipulation du graph", 4);
    this->addTitle("3.2.4.1.1. Creation d'un graph", 5);
    this->addTitle("3.2.4.1.1.1. Cas normal", 6);
    this->test3241111();
    this->test3241112();
    this->test3241113();
    this->test3241114();
    this->addTitle("3.2.4.1.2. Obtention de l'ordre", 5);
    this->addTitle("3.2.4.1.2.1. Cas normal", 6);
    this->test3241211();
    this->addTitle("3.2.4.2. Manipulation des noeuds", 4);
    this->addTitle("3.2.4.2.1. Est-ce qu'un noeud existe", 5);
    this->addTitle("3.2.4.2.1.1. Cas normal", 6);
    this->test3242111();
    this->addTitle("3.2.4.2.2. Ajout d'un noeud", 5);
    this->addTitle("3.2.4.2.2.1. Cas normal", 6);
    this->test3242211();
    this->addTitle("3.2.4.2.2.2. Cas limite", 6);
    this->test3242221();
    this->test3242222();
    this->addTitle("3.2.4.2.2.3. Cas d'erreur", 6);
    this->test3242231();
    this->test3242232();
    this->addTitle("3.2.4.2.3. Changer la valeur d'un noeud", 5);
    this->addTitle("3.2.4.2.3.1. Cas normal", 6);
    this->test3242311();
    this->addTitle("3.2.4.2.3.2. Cas limite", 6);
    this->test3242321();
    this->test3242322();
    this->addTitle("3.2.4.2.3.3. Cas d'erreur", 6);
    this->test3242331();
    this->addTitle("3.2.4.2.4. Obtenir la valeur d'un noeud", 5);
    this->addTitle("3.2.4.2.4.1. Cas normal", 6);
    this->test3242411();
    this->addTitle("3.2.4.2.4.2. Cas limite", 6);
    this->test3242421();
    this->test3242422();
    this->addTitle("3.2.4.2.4.3. Cas d'erreur", 6);
    this->test3242431();
    this->addTitle("3.2.4.2.5. Suppression d'un noeud", 5);
    this->addTitle("3.2.4.2.5.1. Cas normal", 6);
    this->test3242511();
    this->addTitle("3.2.4.2.5.2. Cas limite", 6);
    this->test3242521();
    this->test3242522();
    this->addTitle("3.2.4.2.5.3. Cas d'erreur", 6);
    this->test3242531();
    this->addTitle("3.2.4.3. Manipulation des arretes", 4);
    this->addTitle("3.2.4.3.1. Est-ce qu'une arrete existe", 5);
    this->addTitle("3.2.4.3.1.1. Cas normal", 6);
    this->test3243111();
    this->test3243112();
    this->addTitle("3.2.4.3.1.2. Cas limite", 6);
    this->test3243121();
    this->test3243122();
    this->addTitle("3.2.4.3.2. Ajout d'arrete", 5);
    this->addTitle("3.2.4.3.2.1. Cas normal", 6);
    this->test3243211();
    this->addTitle("3.2.4.3.2.2. Cas limite", 6);
    this->test3243221();
    this->test3243222();
    this->addTitle("3.2.4.3.2.3. Cas d'erreur", 6);
    this->test3243231();
    this->test3243232();
    this->test3243233();
    this->addTitle("3.2.4.3.3. Changement de la valeur d'une arrete", 5);
    this->addTitle("3.2.4.3.3.1. Cas normal", 6);
    this->test3243311();
    this->addTitle("3.2.4.3.3.2. Cas limite", 6);
    this->test3243321();
    this->test3243322();
    this->addTitle("3.2.4.3.3.3. Cas d'erreur", 6);
    this->test3243331();
    this->test3243332();
    this->test3243333();
    this->addTitle("3.2.4.3.4. Obtention de la valeur d'une arrete", 5);
    this->addTitle("3.2.4.3.4.1. Cas normal", 6);
    this->test3243411();
    this->addTitle("3.2.4.3.4.2. Cas limite", 6);
    this->test3243421();
    this->test3243422();
    this->addTitle("3.2.4.3.4.3. Cas d'erreur", 6);
    this->test3243431();
    this->test3243432();
    this->test3243433();
    this->addTitle("3.2.4.3.5. Suppression d'une arrete", 5);
    this->addTitle("3.2.4.3.5.1. Cas normal", 6);
    this->test3243511();
    this->addTitle("3.2.4.3.5.2. Cas limite", 6);
    this->test3243521();
    this->test3243522();
    this->addTitle("3.2.4.3.5.3. Cas d'erreur", 6);
    this->test3243531();
    this->test3243532();
    this->test3243533();
    this->addTitle("3.2.4.4. Manipulation des voisins", 4);
    this->addTitle("3.2.4.4.1. Obtention du nombre de voisins d'un noeud", 5);
    this->addTitle("3.2.4.4.1.1. Cas normal", 6);
    this->test3244111();
    this->addTitle("3.2.4.4.1.2. Cas d'erreur", 6);
    this->test3244121();
    this->addTitle("3.2.4.4.2. Obtention du nombre de voisins d'un noeud", 5);
    this->addTitle("3.2.4.4.2.1. Cas normal", 6);
    this->test3244211();
    this->addTitle("3.2.4.4.2.2. Cas limite", 6);
    this->test3244221();
    this->test3244222();
    this->addTitle("3.2.4.4.2.3. Cas d'erreur", 6);
    this->test3244231();
    this->test3244232();

    this->printTest();
}

void TestsUnitairesObjectif2Html::test3241111() {
    SingleTestHtml singleTest("3.2.4.1.1.1.1. Creation d'un graph oriented & weighted");

    singleTest.setIntention("Creation d’un graph avec des parametres pour son orientation et son poids. Il devra etre oriente et pondere.");
    singleTest.setExpectedResult("Creation d'un graphe oriente et pondere.");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le graphe a ete cree corectement avec les bon parametres.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3241112() {
    SingleTestHtml singleTest("3.2.4.1.1.1.2. Creation d'un graph non oriented & weighted");

    singleTest.setIntention("Creation d’un graph avec des parametres pour son orientation et son poids. Il devra etre non oriente et pondere.");
    singleTest.setExpectedResult("Creation d'un graphe non oriente et pondere.");
    try {
        Graph<int> g(false, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le graphe a ete cree corectement avec les bon parametres.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3241113() {
    SingleTestHtml singleTest("3.2.4.1.1.1.3. Creation d'un graph oriented & non weighted");

    singleTest.setIntention("Creation d’un graph avec des parametres pour son orientation et son poids. Il devra etre oriente et non pondere.");
    singleTest.setExpectedResult("Creation d'un graphe oriente et non pondere.");
    try {
        Graph<int> g(true, false);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le graphe a ete cree corectement avec les bon parametres.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3241114() {
    SingleTestHtml singleTest("3.2.4.1.1.1.4. Creation d'un graph non oriented & non weighted");

    singleTest.setIntention("Creation d’un graph avec des parametres pour son orientation et son poids. Il devra etre non oriente et non pondere.");
    singleTest.setExpectedResult("Creation d'un graphe non oriente et non pondere.");
    try {
        Graph<int> g(false, false);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le graphe a ete cree corectement avec les bon parametres.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3241211() {
    SingleTestHtml singleTest("3.2.4.1.2.1.1. Obtention de l'ordre");

    singleTest.setIntention("Recuperation de l'ordre du graphe.");
    singleTest.setExpectedResult("On a cree un graphe auquel on a ajoute 3 noeud. L'ordre doit donc etre de 3 apres ces ajouts.");
    try {
        Graph<int> g(false, false);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Graph order : " + QString::number(g.getOrder())));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Nous obtenons l'ordre souhaite.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3242111() {
    SingleTestHtml singleTest("3.2.4.2.1.1.1. Le noeud existe");

    singleTest.setIntention("Verifier qu'un noeud du graphe peut etre trouve.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute un noeud d'id 1. On souhaite donc une repose positive de la fonction.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        if (g.nodeExists(1))
            singleTest.concatObtainedResult(this->convertToDocument("Le noeud existe"));
        else
            singleTest.concatObtainedResult(this->convertToDocument("Le noeud n'existe pas"));


    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La fonction a bien trouve le noeud d'id 1 et nous renvoye une reponse positive.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3242112() {
    SingleTestHtml singleTest("3.2.4.2.1.1.2. Le noeud n'existe pas");

    singleTest.setIntention("Verifier qu'un noeud non present dans le graphe ne peut etre trouve.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute aucun noeud. On souhaite donc une reponse negative de la fonction qu'en a l'existence d'un noeud d'id 1.");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        if (g.nodeExists(1))
            singleTest.concatObtainedResult(this->convertToDocument("Le noeud existe"));
        else
            singleTest.concatObtainedResult(this->convertToDocument("Le noeud n'existe pas"));


    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La fonction n'a pas trouve le noeud d'id 1 et nous renvoye une reponse negative.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3242211() {
    SingleTestHtml singleTest("3.2.4.2.2.1.1. Ajout d'un noeud dans le graph");

    singleTest.setIntention("Verifier l'ajout d'un noeud dans un graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute deux noeud d'id 1 et 3. On y ajoute le noeud d'id 2 qui doit s'inserer dans le graphe entre les noeuds 1 et 3 car notre graphe est trie.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addNode(2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud a ete ajoute au bon endroit.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3242221() {
    SingleTestHtml singleTest("3.2.4.2.2.2.1. AJout d'un noeud en premiere position du graphe");

    singleTest.setIntention("Verifier l'ajout d'un noeud dans un graphe vide.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute un noeud d'id 1. On souhaite que celui-i y soit ajoute.");
    try {
        Graph<int> g(true, true);
        g.addNode(3);
        g.addNode(7);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addNode(1);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud a ete ajoute au bon endroit.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3242222() {
    SingleTestHtml singleTest("3.2.4.2.2.2.2. AJout d'un noeud en derniere position du graphe");

    singleTest.setIntention("Verifier l'ajout d'un noeud en derniere position d'un graphe vide.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute deux noeud d'id 1 et 3. On y ajout un noeud d'id 4. On souhaite que celui-ci soit bien place en derniere position du graphe.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addNode(4);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud a ete ajoute au bon endroit.");
    singleTest.formatTest(&this->out);
}

void TestsUnitairesObjectif2Html::test3242231(){
    SingleTestHtml singleTest("3.2.4.2.2.3.1. Ajout d'un noeud avec un id negatif");

    singleTest.setIntention("Verifier que l'ajout d'un noeud d'id negatif n'est pas possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute un noeud d'id -1. L'ajout de ce noeud, dans le graphe, ne doit pas etre accepte.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(7);

        singleTest.setObtainedResult(g.formattedHtmlGraph());

        g.addNode(-1);

        
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud n'a pas ete ajoute.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : ajout d'un noeud avec un id negatif
void TestsUnitairesObjectif2Html::test3242232(){
    SingleTestHtml singleTest("3.2.4.2.2.3.2. Ajout d'un noeud deja exsitent");

    singleTest.setIntention("Verifier que l'ajout d'un noeud dont l'id existe deja dans le graphe n'est pas possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute un noeud d'id 1. On ajoute un nouveau noeud d'id 1. L'ajout de ce noeud, dans le graphe, ne doit pas etre accepte car il existe deja .");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(7);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addNode(1);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud n'a pas ete ajoute.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : ajout d'un noeud deja exsitent

//SETNODEVALUE
void TestsUnitairesObjectif2Html::test3242311(){
    SingleTestHtml singleTest("3.2.4.2.3.1.1.  Attribue la valeur d'un noeud du graphe");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur a un noeud dans le graphe est possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeuds d'id 1, 2 et 3, on attribue la valeur 2 au noeud 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setNodeValue(2,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur a bien ete attribuee au noeud.");
    singleTest.formatTest(&this->out);
}; //cas normal : attribue la valeur d'un noeud du graphe

void TestsUnitairesObjectif2Html::test3242321(){
    SingleTestHtml singleTest("3.2.4.2.3.2.1. Attribue la valeur du premier noeud du graphe");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur au premier noeud du graphe est possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeud d'id 1, 2 et 3, on attribue la valeur 2 au noeud 1.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setNodeValue(1,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur a bien ete attribuee au noeud.");
    singleTest.formatTest(&this->out);
}; //cas limite : attribue la valeur du premier noeud du graphe

void TestsUnitairesObjectif2Html::test3242322(){
    SingleTestHtml singleTest("3.2.4.2.3.2.2. Attribue la valeur du dernier noeud du graphe");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur au dernier noeud du graphe est possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeud d'id 1, 2 et 3, on attribue la valeur 2 au noeud 3.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setNodeValue(3,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("");
    singleTest.formatTest(&this->out);
}; //cas limite : attribue la valeur du dernier noeud du graphe

void TestsUnitairesObjectif2Html::test3242331(){
    SingleTestHtml singleTest("3.2.4.2.3.3.1. Attribue la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur a un noeud non existant dans le graphe est imppossible.");
    singleTest.setExpectedResult("On a cree un graphe vide et on veut attribuer la valeur 2 a un noeud d'id 2 qui n'existe pas.");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setNodeValue(2,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur n'a pas ete attribuee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : attribue la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

//GETNODEVALUE
void TestsUnitairesObjectif2Html::test3242411(){
    SingleTestHtml singleTest("3.2.4.2.4.1.1. Cherche la valeur d'un noeud du graphe");

    singleTest.setIntention("Recuperation de la valeur d'un noeud du graphe");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On attribue comme valeur de chacun des noeuds, leur id. On veut recuperer la valeur du noeud d'id 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.setNodeValue(1,1);
        g.setNodeValue(2,2);
        g.setNodeValue(3,3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value node 2 : " + QString::number(g.getNodeValue(2))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur du noeud a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas normal : cherche la valeur d'un noeud du graphe

void TestsUnitairesObjectif2Html::test3242421(){
    SingleTestHtml singleTest("3.2.4.2.4.2.1. Cherche la valeur du premier noeud du graphe");

    singleTest.setIntention("Recuperation de la valeur du premier noeud du graphe");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On attribue comme valeur de chacun des noeuds, leur id. On veut recuperer la valeur du noeud d'id 1.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.setNodeValue(1,1);
        g.setNodeValue(2,2);
        g.setNodeValue(3,3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value node 1 : " + QString::number(g.getNodeValue(1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur du noeud a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas limite : cherche la valeur du premier noeud du graphe

void TestsUnitairesObjectif2Html::test3242422(){
    SingleTestHtml singleTest("3.2.4.2.4.2.2. Cherche la valeur du dernier noeud du graphe");

    singleTest.setIntention("Recuperation de la valeur du dernier noeud du graphe");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On attribue comme valeur de chacun des noeuds, leur id. On veut recuperer la valeur du noeud d'id 3.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.setNodeValue(1,1);
        g.setNodeValue(2,2);
        g.setNodeValue(3,3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value node 3 : " + QString::number(g.getNodeValue(3))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur du noeud a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas limite : cherche la valeur du dernier noeud du graphe

void TestsUnitairesObjectif2Html::test3242431(){
    SingleTestHtml singleTest("3.2.4.2.4.3.1. Cherche la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Recuperation de la valeur d'un noeud inexistant. Ce test verifie aussi le cas du noeud d'id negatif.");
    singleTest.setExpectedResult("On a cree un graphe vide. On veut recuperer la valeur du noeud d'id 1.");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value node 1 : " + QString::number(g.getNodeValue(1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur du noeud n'a pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : cherche la valeur d'un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

//REMOVENODE
void TestsUnitairesObjectif2Html::test3242511(){
    SingleTestHtml singleTest("3.2.4.2.5.1.1. Supprime un noeud du graphe");

    singleTest.setIntention("Verifier la suppression d'un noeud dans le graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On supprime le noeud d'id 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);


        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeNode(2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud a bien ete supprime.");
    singleTest.formatTest(&this->out);
}; //cas normal : supprime un noeud du graphe

void TestsUnitairesObjectif2Html::test3242521(){
    SingleTestHtml singleTest("3.2.4.2.5.2.1. Supprime le premier noeud du graphe");

    singleTest.setIntention("Verifier la suppression d'un noeud en premiere position d'un graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On supprime le noeud d'id 1.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeNode(1);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("");
    singleTest.formatTest(&this->out);
}; //cas limite : supprime le premier noeud du graphe

void TestsUnitairesObjectif2Html::test3242522(){
    SingleTestHtml singleTest("3.2.4.2.5.2.2. Supprime le dernier noeud du graphe");

    singleTest.setIntention("Verifier la suppression d'un noeud en derniere position d'un graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On supprime le noeud d'id 3.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeNode(3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud a bien ete supprime.");
    singleTest.formatTest(&this->out);
}; //cas limite : supprime le dernier noeud du graphe

void TestsUnitairesObjectif2Html::test3242531(){
    SingleTestHtml singleTest("3.2.4.2.5.3.1. Supprime un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Verifier que la suppression d'un noeud non existant (comprend aussi le cas du noeud dont l'id est negatif)dans un graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On supprime le noeud d'id 4 (respectivement -1). Cette suppression ne doit pas etre acceptee et une erreur doit nous en informe.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeNode(4);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La suppression n'est pas effectuee et une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : supprime un noeud hors du graphe (comprend aussi le cas du noeud d'id negatif)

//EDGEEXISTS
void TestsUnitairesObjectif2Html::test3243111(){
    SingleTestHtml singleTest("3.2.4.3.1.1.1. L'arrete existe");

    singleTest.setIntention("Verifier qu'un arc du graphe peut etre trouve.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute un noeud d'id 1, 2 et 3 auquel on ajoute un arc. On souhaite donc une repose positive de la fonction.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        if (g.edgeExists(2,2))
            singleTest.concatObtainedResult(this->convertToDocument("Edge (2,2) existe"));
        else
            singleTest.concatObtainedResult(this->convertToDocument("Edge (2,2) n'existe pas"));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La fonction a bien trouve l'arc et nous renvoye une reponse positive.");
    singleTest.formatTest(&this->out);
}; //cas normal : l'arrete existe
void TestsUnitairesObjectif2Html::test3243112(){
    SingleTestHtml singleTest("3.2.4.3.1.1.2. L'arrete n'existe pas");

    singleTest.setIntention("Verifier qu'un arc non present dans le graphe ne peut etre trouve. Ce test verifie plusieurs autres cas : un des noeuds ou les deux noeuds hors du graphe et l'arc est entre un ou 2 noeuds d'id negatif.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute deux noeud d'id 1 et 2, aucun arc. On souhaite donc une reponse negative de la fonction qu'en a l'existence d'un arc entre le noeud d'id 1 et le noeud d'id 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        if (g.edgeExists(1,2))
            singleTest.concatObtainedResult(this->convertToDocument("Edge (1,2) existe"));
        else
            singleTest.concatObtainedResult(this->convertToDocument("Edge (1,2) n'existe pas"));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La fonction n'a pas trouve l'arc et nous renvoye une reponse negative.");
    singleTest.formatTest(&this->out);
}; //cas normal : l'arrete n'existe pas (comprend plusieurs cas : un des noeuds ou les deux noeuds hors du graphe et l'arrete est entre un ou 2 noeuds d'id negatif)

void TestsUnitairesObjectif2Html::test3243121(){
    SingleTestHtml singleTest("3.2.4.3.1.2.1. L'arrete est sur le premier noeud du graphe");

    singleTest.setIntention("Verifier qu'un arc sur le premier noeud du graphe peut etre trouve.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute un noeud d'id 1 auquel on ajoute un arc et un noeud d'id 2. On souhaite donc une repose positive de la fonction.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1,1);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        if (g.edgeExists(1,1))
            singleTest.concatObtainedResult(this->convertToDocument("Edge (1,1) existe"));
        else
            singleTest.concatObtainedResult(this->convertToDocument("Edge (1,1) n'existe pas"));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La fonction a bien trouve l'arc et nous renvoye une reponse positive.");
    singleTest.formatTest(&this->out);
}; //cas limite : l'arrete est sur le premier noeud du graphe

void TestsUnitairesObjectif2Html::test3243122(){
    SingleTestHtml singleTest("3.2.4.3.1.2.2. L'arrete est sur le dernier noeud du graphe");

    singleTest.setIntention("Verifier qu'un arc sur le dernier noeud du graphe peut etre trouve.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute un noeud d'id 1 sans arc et un noeud d'id 2 auquel on ajoute un arc. On souhaite donc une repose positive de la fonction.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(2,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        if (g.edgeExists(2,2))
            singleTest.concatObtainedResult(this->convertToDocument("Edge (2,2) existe"));
        else
            singleTest.concatObtainedResult(this->convertToDocument("Edge (2,2) n'existe pas"));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La fonction a bien trouve l'arc et nous renvoye une reponse positive.");
    singleTest.formatTest(&this->out);
}; //cas limite : l'arrete est sur le dernier noeud du graphe

//ADDEDGE
void TestsUnitairesObjectif2Html::test3243211(){
    SingleTestHtml singleTest("3.2.4.3.2.1.1. Ajout d'une arrete dans un graphe oriented (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Verifier l'ajout d'arc dans un graphe oriented. Ce test verifie aussi le cas du graphe non oriente.");
    singleTest.setExpectedResult("On a cree un graphe oriente dans lequel on a ajoute 4 noeud d'id 1, 2, 3, 4. On ajoute un arc entre les noeuds 2 et 3.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);
        
        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addEdge(2,3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arrete a ete ajoute au bon endroit.");
    singleTest.formatTest(&this->out);

}; //cas normal : ajout d'une arrete dans un graphe oriented (comprend aussi le cas du graphe !oriented)

void TestsUnitairesObjectif2Html::test3243221(){
    SingleTestHtml singleTest("3.2.4.3.2.2.1. Ajout d'une arrete sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Verifier l'ajout d'arc sur le premier noeud d'un graphe oriented. Ce test verifie aussi le cas du graphe non oriente.");
    singleTest.setExpectedResult("On a cree un graphe oriente dans lequel on a ajoute 4 noeud d'id 1, 2, 3, 4. On ajoute un arc sur le noeud d'id 1.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addEdge(1,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arrete a ete ajoute au bon endroit.");
    singleTest.formatTest(&this->out);
}; //cas limite : ajout d'une arrete sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)

void TestsUnitairesObjectif2Html::test3243222(){
    SingleTestHtml singleTest("3.2.4.3.2.2.2. Ajout d'une arrete sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Verifier l'ajout d'arc sur le dernier noeud d'un graphe oriented. Ce test verifie aussi le cas du graphe non oriente.");
    singleTest.setExpectedResult("On a cree un graphe oriente dans lequel on a ajoute 4 noeud d'id 1, 2, 3, 4. On ajoute un arc sur le noeud d'id 1.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addNode(4);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addEdge(4,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arrete a ete ajoute au bon endroit.");
    singleTest.formatTest(&this->out);
}; //cas limite : ajout d'une arrete sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)

void TestsUnitairesObjectif2Html::test3243231(){
    SingleTestHtml singleTest("3.2.4.3.2.3.1. Ajout d'une arrete entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Verifier que l'ajout d'un arc entre deux noeud hors d'un graphe n'est pas autorise. Ce test verifie aussi les cas où l'un des des deux est hors du graphe et celui où l'un des noeuds ou les deux ont un id negatif.");
    singleTest.setExpectedResult("On a cree un graphe oriente sans noeud. On ajoute un arc sur le noeud d'id 1 et d'id 2.");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addEdge(1,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc n'a pas ete ajoutee au graph.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : ajout d'une arrete entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)

void TestsUnitairesObjectif2Html::test3243232(){
    SingleTestHtml singleTest("3.2.4.3.2.3.2. Ajout d'une arrete deja existent");

    singleTest.setIntention("Verifier que l'ajout d'un arc deja existant dans un graphe n'est pas autorise.");
    singleTest.setExpectedResult("On a cree un graphe oriente avec deux noeuds d'id 1 et 2. On ajoute un arc entre les noeuds d'id 1 et 2. Puis on ajoute de nouveau un arc entre les noeuds d'id 1 et 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addEdge(2,3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc n'a pas ete ajoutee au graph.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : ajout d'une arrete deja existent

void TestsUnitairesObjectif2Html::test3243233(){
    SingleTestHtml singleTest("3.2.4.3.2.3.3. Ajout d'une arrete dans un graph non pondere");

    singleTest.setIntention("Verifier que l'ajout d'un arc dans un graphe non pondere n'est pas autorise.");
    singleTest.setExpectedResult("On a cree un graphe oriente mais non pondere avec deux noeuds d'id 1 et 2. On ajoute un arc entre les noeuds d'id 1 et 2. On doit recevoir une erreur.");
    try {
        Graph<int> g(true, false);
        g.addNode(1);
        g.addNode(2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.addEdge(1,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc n'a pas ete ajoutee au graph.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : ajout d'une arrete dans un graph non pondere

//SETEDGEVALUE
void TestsUnitairesObjectif2Html::test3243311(){
    SingleTestHtml singleTest("3.2.4.3.3.1.1. Attribue la valeur d'une arrete dans un graphe oriented (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur a un arc dans le graphe est possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeuds d'id 1, 2 et 3, on ajoute l'arc (2,2) et on lui attribue la valeur 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setEdgeValue(2,2,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur a bien ete attribuee a l'arc.");
    singleTest.formatTest(&this->out);
}; //cas normal : attribue la valeur d'une arrete dans un graphe oriented (comprend aussi le cas du graphe !oriented)

void TestsUnitairesObjectif2Html::test3243321(){
    SingleTestHtml singleTest("3.2.4.3.3.2.1. Attribue la valeur d'une arrete sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur au premier arc dans le graphe est possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeuds d'id 1, 2 et 3, on ajoute l'arc (1,1) et on lui attribue la valeur 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(1,1);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setEdgeValue(1,1,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur a bien ete attribuee au premier arc du graphe.");
    singleTest.formatTest(&this->out);
}; //cas limite : attribue la valeur d'une arrete sur le premier noeud du graphe (comprend aussi le cas du graphe !oriented)

void TestsUnitairesObjectif2Html::test3243322(){
    SingleTestHtml singleTest("3.2.4.3.3.2.2. Attribue la valeur d'une arrete sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur au dernier arc dans le graphe est possible.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeuds d'id 1, 2 et 3, on ajoute l'arc (3,3) et on lui attribue la valeur 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(3,3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setEdgeValue(3,3,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur a bien ete attribuee au dernier arc du graphe.");
    singleTest.formatTest(&this->out);
}; //cas limite : attribue la valeur d'une arrete sur le dernier noeud du graphe (comprend aussi le cas du graphe !oriented)

void TestsUnitairesObjectif2Html::test3243331(){
    SingleTestHtml singleTest("3.2.4.3.3.3.1. Attribue la valeur d'une arrete entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur a un arc inexistant est impossible. Ce test verifie aussi les cas ou l'un des deux ou les deux noeud sont inexistant ou ont un id negatif.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute trois noeuds d'id 1, 2 et 3. On attribue la valeur 2 a l'arc inexistant (2,4).");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setEdgeValue(2,4,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur n'a pas ete attribuee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : attribue la valeur d'une arrete entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)

void TestsUnitairesObjectif2Html::test3243332(){
    SingleTestHtml singleTest("3.2.4.3.3.3.2. Attribue la valeur d'une arrete dans un graph non pondere");

    singleTest.setIntention("Verifier que l'attribuation d'une valeur a un arc inexistant est impossible dans un graph non pondere");
    singleTest.setExpectedResult("On a cree un graphe non pondere dans lequel on a ajoute trois noeuds d'id 1, 2 et 3. On attribue la valeur 2 a l'arc (2,3).");
    try {
        Graph<int> g(true, false);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setEdgeValue(2,3,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur n'a pas ete attribuee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : attribue la valeur d'une arrete dans un graph non pondere

void TestsUnitairesObjectif2Html::test3243333(){
    SingleTestHtml singleTest("3.2.4.3.3.3.3. Attribue la valeur d'une arrete inexistante entre 2 noeuds presents dans le graph");

    singleTest.setIntention("Verifier que l'attribution d'une valeur a un arc inexistant entre 2 noeuds presents dans le graph");
    singleTest.setExpectedResult("On a cree un graphe pondere dans lequel on a ajoute trois noeuds d'id 1, 2 et 3. On attribue la valeur 2 a l'arc inexistant (2,3).");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.setEdgeValue(1,3,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur n'a pas ete attribuee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}

//GETEDGEVALUE
void TestsUnitairesObjectif2Html::test3243411(){
    SingleTestHtml singleTest("3.2.4.3.4.1.1. Cherche la valeur d'une arrete dans un graphe oriented (comprend aussi le cas du graphe !oriented)");

    singleTest.setIntention("Recuperation de la valeur d'un arc du graphe");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3, on ajoute un arc de valeur 2 entre les noeuds d'id 1 et 2. On veut recuperer la valeur de l'arc (2,1).");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,1);
        g.setEdgeValue(2,1,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value Edge (2,1) : " + QString::number(g.getEdgeValue(2,1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur de l'arc a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas normal : cherche la valeur d'une arrete du graphe

void TestsUnitairesObjectif2Html::test3243421(){
    SingleTestHtml singleTest("3.2.4.3.4.2.1. Cherche la valeur de l'arrete du premier noeud du graphe");

    singleTest.setIntention("Recuperation de la valeur du premier arc du graphe");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3, on ajoute un arc de valeur 2 sur le noeud d'id 1. On veut recuperer la valeur de l'arc (1,1).");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(1,1);
        g.setEdgeValue(1,1,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value Edge (1,1) : " + QString::number(g.getEdgeValue(1,1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur du premier arc a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas limite : cherche la valeur de l'arrete du premier noeud du graphe

void TestsUnitairesObjectif2Html::test3243422(){
    SingleTestHtml singleTest("3.2.4.3.4.2.2. Cherche la valeur de l'arrete du dernier noeud du graphe");

    singleTest.setIntention("Recuperation de la valeur du dernier arc du graphe");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3, on ajoute un arc de valeur 2 sur le noeud d'id 3. On veut recuperer la valeur de l'arc (3,3).");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(3,3);
        g.setEdgeValue(3,3,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value Edge (3,3) : " + QString::number(g.getEdgeValue(3,3))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur du dernier arc a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas limite : cherche la valeur de l'arrete du dernier noeud du graphe

void TestsUnitairesObjectif2Html::test3243431(){
    SingleTestHtml singleTest("3.2.4.3.4.3.1. Cherche la valeur de l'arrete entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Recuperation de la valeur d'un arc inexistant");
    singleTest.setExpectedResult("On a cree un graphe vide. On veut recuperer la valeur de l'arc inexistant (1,1).");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value Edge (1,1) : " + QString::number(g.getEdgeValue(1,1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur de l'arc n'a pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : cherche la valeur de l'arrete entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)

void TestsUnitairesObjectif2Html::test3243432(){
    SingleTestHtml singleTest("3.2.4.3.4.3.2. Cherche la valeur d'une arrete dans un graph non pondere");

    singleTest.setIntention("Recuperation de la valeur d'un arc dans un graph non pondere");
    singleTest.setExpectedResult("On a cree un graphe non pondere dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On veut recuperer la valeur de l'arc (3,3).");
    try {
        Graph<int> g(true, false);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value Edge (3,3) : " + QString::number(g.getEdgeValue(3,3))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur de l'arc n'a pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur :  cherche la valeur d'une arrete dans un graph non pondere

void TestsUnitairesObjectif2Html::test3243433(){
    SingleTestHtml singleTest("3.2.4.3.4.3.3. Cherche la valeur d'une arrete inexistante entre 2 noeuds presents dans le graph");

    singleTest.setIntention("Verifier que l'on ne peut recuperer la valeur d'un arc inexistant entre 2 noeuds presents dans le graph");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On veut recuperer la valeur de l'arc (3,3).");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Value Edge (3,3) : " + QString::number(g.getEdgeValue(3,3))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("La valeur de l'arc n'a pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur :  cherche la valeur d'une arrete inexistant

//REMOVEEDGE
void TestsUnitairesObjectif2Html::test3243511(){
    SingleTestHtml singleTest("3.2.4.3.5.1.1. Supprime une arrete du graphe");

    singleTest.setIntention("Verifier la suppression d'un arc dans le graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On ajoute l'arc(2,3). On supprime l'arc(2,3).");
    try {
       Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,3);
        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeEdge(2,3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc a bien ete supprime.");
    singleTest.formatTest(&this->out);
}; //cas normal : supprime une arrete du graphe

void TestsUnitairesObjectif2Html::test3243521(){
    SingleTestHtml singleTest("3.2.4.3.5.2.1. Supprime l'arrete du premier noeud du graphe");

    singleTest.setIntention("Verifier la suppression du premier arc dans le graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On ajoute l'arc(1,1). On supprime l'arc(1,1).");
    try {
       Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(1,1);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeEdge(1,1);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le premier arc a bien ete supprime.");
    singleTest.formatTest(&this->out);
}; //cas limite : supprime l'arrete du premier noeud du graphe

void TestsUnitairesObjectif2Html::test3243522(){
    SingleTestHtml singleTest("3.2.4.3.5.2.2. Supprime l'arrete du dernier noeud du graphe");

    singleTest.setIntention("Verifier la suppression du dernier arc dans le graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On ajoute l'arc(3,3). On supprime l'arc(3,3).");
    try {
       Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(3,3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeEdge(3,3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le dernier arc a bien ete supprime.");
    singleTest.formatTest(&this->out);
}; //cas limite : supprime l'arrete du dernier noeud du graphe
void TestsUnitairesObjectif2Html::test3243531(){
    SingleTestHtml singleTest("3.2.4.3.5.3.1. Supprime une arrete hors du graphe entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)");

    singleTest.setIntention("Verifier que la suppression d'un arc inexistant est impossible.");
    singleTest.setExpectedResult("On a cree un graphe vide. On supprime l'arc inexistant (3,3).");
    try {
       Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeEdge(3,3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc n'a pas ete supprime, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : supprime une arrete hors du graphe entre deux noeuds (ou l'un des deux noeuds) hors du graphe (comprend aussi le cas du noeud d'id negatif)
void TestsUnitairesObjectif2Html::test3243532(){
    SingleTestHtml singleTest("3.2.4.3.5.3.2. Supprime une arrete dans un graph non pondere");

    singleTest.setIntention("Verifier que l'on ne peut supprimer un arc dans un graph non pondere");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On supprime l'arc(3,3).");
    try {
       Graph<int> g(true, false);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeEdge(1,2);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc n'a pas ete supprime, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : supprime une arrete dans un graph non pondere
void TestsUnitairesObjectif2Html::test3243533(){
    SingleTestHtml singleTest("3.2.4.3.5.3.3. Supprime une arrete inexistante entre 2 noeuds presents dans le graph");

    singleTest.setIntention("Verifier que l'on ne peut supprimer un arc inexistant entre 2 noeuds presents dans le graph");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on a ajoute 3 noeuds d'id 1, 2 et 3. On supprime l'arc(3,3).");
    try {
       Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        g.removeEdge(3,3);
        singleTest.concatObtainedResult(this->convertToDocument("#### MODIFIED GRAPH ####"));
        singleTest.concatObtainedResult(g.formattedHtmlGraph());
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("L'arc n'a pas ete supprime, une erreur est affichee.");
    singleTest.formatTest(&this->out);

}; //cas d'erreur : supprime une arrete inexistant

//GETNEIGHBORHOODSIZE
void TestsUnitairesObjectif2Html::test3244111(){
    SingleTestHtml singleTest("3.2.4.4.1.1.1. Nombre de voisins d'un noeud du graphe");

    singleTest.setIntention("Recuperer le nombre de voisins d'un noeud du graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On ajoute les arc (2,1) , (2,3) . On recupere le nombre de voisins du noeud 2.");
    try {
       Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,1);
        g.addEdge(2,3);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighborhoodsize node 2 : " + QString::number(g.getNeighborhoodsize(2))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le nombre de voisins du noeud a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas normal : nombre de voisins d'un noeud du graphe

void TestsUnitairesObjectif2Html::test3244121(){
    SingleTestHtml singleTest("3.2.4.4.1.2.1. Nombre de voisins d'un noeud hors graphe");

    singleTest.setIntention("Recuperer le nombre de voisins d'un noeud inexistant. Ce test concerne aussi le node a un id negatif.");
    singleTest.setExpectedResult("On a cree un graphe vide. On cherche le nombre de voisins du noeud inexistant 1.");
    try {
       Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighborhoodsize node 1 : " + QString::number(g.getNeighborhoodsize(1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le nombre de voisins du noeud n'a pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cad d'erreur : nombre de voisins d'un noeud hors graphe

//GETNEIGHBOR
void TestsUnitairesObjectif2Html::test3244211(){
    SingleTestHtml singleTest("3.2.4.4.2.1.1. Retourne le k-ieme voisin d'un noeud du graphe");

    singleTest.setIntention("Recuperer le k-ieme voisin d'un noeud du graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On ajoute les arc (2,1), (2,2), (2,3) . On recupere le deuxieme voisin du noeud 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,1);
        g.addEdge(2,3);
        g.addEdge(2,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighbor 2 of node 2 : " + QString::number(g.getNeighbor(2,2))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le 2eme voisin du noeud 2 a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas normal : retourne le k-ieme voisin d'un noeud du graphe

void TestsUnitairesObjectif2Html::test3244221(){
    SingleTestHtml singleTest("3.2.4.4.2.2.1. Retourne le premier voisin d'un noeud du graphe");

    singleTest.setIntention("Recuperer le premier voisin d'un noeud du graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On ajoute les arc (2,1), (2,2), (2,3) . On recupere le premier voisin du noeud 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,1);
        g.addEdge(2,3);
        g.addEdge(2,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighbor 1 of node 2 : " + QString::number(g.getNeighbor(2,1))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le premier voisin du noeud 2 a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas limite : retourne le premier voisin d'un noeud du graphe

void TestsUnitairesObjectif2Html::test3244222(){
    SingleTestHtml singleTest("3.2.4.4.2.2.2. Retourne le dernier voisin d'un noeud du graphe");

    singleTest.setIntention("Recuperer le dernier voisin d'un noeud du graphe.");
    singleTest.setExpectedResult("On a cree un graphe dans lequel on ajoute 3 noeuds d'id 1, 2 et 3. On ajoute les arc (2,1), (2,2), (2,3) . On recupere le dernier voisin du noeud 2.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addNode(3);
        g.addEdge(2,1);
        g.addEdge(2,3);
        g.addEdge(2,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighbor 3 of node 2 : " + QString::number(g.getNeighbor(2,3))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le dernier voisin du noeud 2 a bien ete recuperee.");
    singleTest.formatTest(&this->out);
}; //cas limite : retourne le dernier voisin d'un noeud du graphe

void TestsUnitairesObjectif2Html::test3244231(){
    SingleTestHtml singleTest("3.2.4.4.2.3.1. Retourne le k-ieme voisin non existent d'un noeud");

    singleTest.setIntention("Recuperer un voisin inexistant d'un noeud du graphe.");
    singleTest.setExpectedResult("On a cree un graphe avec deux noeuds d'id 1 et 2. On ajoute un arc (1,2). On recupere le deuxieme voisin du noeud 1.");
    try {
        Graph<int> g(true, true);
        g.addNode(1);
        g.addNode(2);
        g.addEdge(1,2);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighbor 2 of node 1 : " + QString::number(g.getNeighbor(1,2))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le voisin numero 2 du noeud 1 n'existe pas, il n'a donc pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : retourne le k-ieme voisin non existent d'un noeud

void TestsUnitairesObjectif2Html::test3244232(){
    SingleTestHtml singleTest("3.2.4.4.2.3.2. Retourne le k-ieme voisin d'un noeud inexistant");

    singleTest.setIntention("Recuperer le deuxieme voisin d'un noeud inexistant.");
    singleTest.setExpectedResult("On a cree un graphe vide. On recupere le deuxieme voisin du noeud 1.");
    try {
        Graph<int> g(true, true);

        singleTest.setObtainedResult(g.formattedHtmlGraph());
        singleTest.concatObtainedResult(this->convertToDocument("Neighbor 2 of node 1 : " + QString::number(g.getNeighbor(1,2))));
    }
    catch(MyException& e) {
        singleTest.setObtainedResult(singleTest.exceptionToDom(e.what()));
    }

    singleTest.setConclusion("Le noeud 1 n'existe pas, son deuxieme voisin n'a donc pas ete recuperee, une erreur est affichee.");
    singleTest.formatTest(&this->out);
}; //cas d'erreur : retourne le k-ieme voisin d'un noeud inexistant
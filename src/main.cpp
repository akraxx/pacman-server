/*
 * File:   main.cpp
 * Author: isen
 *
 * Created on 11 mars 2011, 09:37
 */

#include "utils.h"
#include "GraphResponder.h"
#include "DijkstraResponder.h"
#include "MyException.h"
#include "TestObjectifHtml.h"
#include "GraphQt.h"

#include "TestsUnitairesObjectif2Html.h"
#include "TestsUnitairesObjectif3Html.h"

#include "FibonacciHeapNode.h"
#include "FibonacciHeap.h"
#include "Dijkstra.h"
void testsUnitairesObjectif2Html() {
    TestsUnitairesObjectif2Html tests;
    tests.executeTestCampaign();
}

void testsUnitairesObjectif3Html() {
    TestsUnitairesObjectif3Html tests;
    tests.executeTestCampaign();
}

int pacmanApplication(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    Manager manager;
    PrefixMapper mapper;

    GraphList graphs;

    GraphResponder responderGraphs(&graphs);
    DijkstraResponder responderDijkstra(&graphs);

    mapper.connect(&manager, SIGNAL(newRequest(FastCgiQt::Request*)), SLOT(respond(FastCgiQt::Request*)));

    mapper.addMapping("graphes", &responderGraphs, SLOT(respond(FastCgiQt::Request*)));
    mapper.addMapping("graphes.js", &responderGraphs, SLOT(respond(FastCgiQt::Request*)));
    mapper.addMapping("graphes.xml", &responderGraphs, SLOT(respond(FastCgiQt::Request*)));

    mapper.addMapping("dijkstra", &responderDijkstra, SLOT(respond(FastCgiQt::Request*)));

    return app.exec();
}

int main(int argc, char *argv[]) {
    /* UNCOMMENT THE FOLLOWING LINE TO GENERATE TEST */
    //testsUnitairesObjectif2Html();
    //testsUnitairesObjectif3Html();

    pacmanApplication(argc, argv);
    return 0;
}

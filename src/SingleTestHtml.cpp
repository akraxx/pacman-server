#include "SingleTestHtml.h"

SingleTestHtml::SingleTestHtml(QString title) : SingleTest(title) {

}

QDomDocument SingleTestHtml::exceptionToDom(QString exception) {
    QStringList lines = exception.split("\n");
    QDomDocument doc;
    for(int i = 0; i < lines.size(); i++) {
        doc.appendChild(doc.createTextNode(lines[i]));
        doc.appendChild(doc.createElement("br"));
    }

    return doc;
}

void SingleTestHtml::formatTest(QDomDocument* doc) {
    QDomElement elemTitle = doc->createElement("h"+QString::number(DEFAULT_SINGLETEST_HIERARCHY));
    QDomText textTitle = doc->createTextNode(this->title);
    elemTitle.appendChild(textTitle);

    doc->appendChild(elemTitle);
    
    QDomElement elemTable = doc->createElement("table");
    elemTable.setAttribute("cellspacing", "0");
    elemTable.setAttribute("class", "testArea");

    QDomElement elemTrIntention = doc->createElement("tr");
    QDomElement elemTdIntention = doc->createElement("td");
    elemTdIntention.setAttribute("colspan", "2");
    elemTdIntention.setAttribute("class", "intention");

    QDomText textIntention = doc->createTextNode("But du test : " + this->intention);

    elemTdIntention.appendChild(textIntention);
    elemTrIntention.appendChild(elemTdIntention);
    elemTable.appendChild(elemTrIntention);
    
    QDomElement elemTrResultsText = doc->createElement("tr");
    QDomElement elemTdResultsExpText = doc->createElement("td");
    elemTdResultsExpText.setAttribute("class", "expResults");
    
    QDomText titleResultsExp = doc->createTextNode("Resultat attendu :");

    elemTdResultsExpText.appendChild(titleResultsExp);
    elemTrResultsText.appendChild(elemTdResultsExpText);

    QDomElement elemTdResultsText = doc->createElement("td");

    QDomText titleResults = doc->createTextNode("Resultat obtenu :");

    elemTdResultsText.appendChild(titleResults);

    elemTdResultsText.appendChild(titleResults);
    elemTrResultsText.appendChild(elemTdResultsText);

    elemTable.appendChild(elemTrResultsText);

    QDomElement elemTrResults = doc->createElement("tr");
    QDomElement elemTdExpResult = doc->createElement("td");

    QDomText textExpectedResult = doc->createTextNode(this->expectedResult);

    elemTdExpResult.appendChild(textExpectedResult);
    elemTrResults.appendChild(elemTdExpResult);

    QDomElement elemTdObtResult = doc->createElement("td");
    elemTdIntention.setAttribute("class", "obtainedResult");

    elemTdObtResult.appendChild(this->obtainedResult);
    elemTrResults.appendChild(elemTdObtResult);

    elemTable.appendChild(elemTrResults);

    QDomElement elemTrConclusion = doc->createElement("tr");
    QDomElement elemTdConclusion = doc->createElement("td");
    elemTdConclusion.setAttribute("colspan", "2");
    elemTdIntention.setAttribute("class", "conslusion");

    QDomText textConclusion = doc->createTextNode("Conclusion : " + this->conclusion);

    elemTdConclusion.appendChild(textConclusion);
    elemTrConclusion.appendChild(elemTdConclusion);
    elemTable.appendChild(elemTrConclusion);

    doc->appendChild(elemTable);
}

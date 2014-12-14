#include "TestObjectifHtml.h"

TestObjectifHtml::TestObjectifHtml(QString testName) : TestObjectif(testName) {

}

QDomDocument TestObjectifHtml::convertToDocument(QVariant var) {
    QDomDocument doc;
    QDomElement span = doc.createElement("span");
    span.appendChild(doc.createTextNode(var.toString()));
    doc.appendChild(span);

    return doc;
}

void TestObjectifHtml::addTitle(QString title, int hierarchy) {
    QDomElement elemTitle = this->out.createElement("h"+QString::number(hierarchy));

    QDomText textTitle = this->out.createTextNode(title);
    elemTitle.appendChild(textTitle);
    this->out.appendChild(elemTitle);
}

void TestObjectifHtml::printTest() {
    ofstream file;
    string filename = "tests_output/" + this->testName.append(".html").toStdString();
    file.open(filename.c_str());

    if(file.is_open()) {
        QDomDocument doc;
        QDomElement elemHtml = doc.createElement("html");
        QDomElement elemHead = doc.createElement("head");

        QDomElement elemTitle = doc.createElement("title");
        QDomText title = doc.createTextNode(this->testName);
        elemTitle.appendChild(title);

        elemHead.appendChild(elemTitle);
        QDomElement elemLink = doc.createElement("link");
        elemLink.setAttribute("rel", "stylesheet");
        elemLink.setAttribute("media", "screen");
        elemLink.setAttribute("type", "text/css");
        elemLink.setAttribute("href", "style/test.css");

        elemHead.appendChild(elemLink);
        elemHtml.appendChild(elemHead);

        QDomElement elemBody = doc.createElement("body");
        elemBody.appendChild(this->out);

        elemHtml.appendChild(elemBody);
        doc.appendChild(elemHtml);
        file << doc.toString().toStdString() << endl;
        cout << "The file " << this->testName.toStdString() << " has been created in folder tests_output/." << endl;
    }
    else {
        cout << "Server was unable to create the file " << this->testName.toStdString() << " in folder tests_output/" << endl;
        cout << "Print test in the standard output" << endl;
        cout << this->out.toString().toStdString() << endl;
    }

    file.close();
}

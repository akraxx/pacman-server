#include "TestObjectifConsole.h"

TestObjectifConsole::TestObjectifConsole(QString testName) : TestObjectif(testName) {

}

void TestObjectifConsole::addTitle(QString title, int hierarchy) {
    for(int i = 0; i < hierarchy; i++)
        this->out += " ";

    this->out += title.toUpper() + "\n";
}

void TestObjectifConsole::printTest() {
     cout << this->out.toStdString() << endl;
}

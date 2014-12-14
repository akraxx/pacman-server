#include "SingleTestConsole.h"

SingleTestConsole::SingleTestConsole(QString title) : SingleTest(title) {

}

QString SingleTestConsole::formatTest() {
    QString out;
    out += "**********************************\n";
    out += "---- " + this->title + " ----" "\n";
    out += "## But du test ##\n";
    out += "\t" + this->intention + "\n";
    out += "## Resultat attendu ##\n";
    out += "\t" + this->expectedResult + "\n";
    out += "## Resultat obtenu ##\n";
    out += "\t" + this->obtainedResult + "\n";
    out += "## Conclusion ##\n";
    out += "\t" + this->conclusion + "\n";
    out += "**********************************\n";
    return out;
}

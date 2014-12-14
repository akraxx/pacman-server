#include "MyException.h"

MyException::MyException(QString description, MyException* parentExc) {
    this->description = description;
    this->parentExc = parentExc;
}

MyException::~MyException() {
    delete this->parentExc;
}

QString MyException::what() {
    QString r;
    if(this->parentExc) {
        r += this->parentExc->what();
        r += "##############################################\n";
        r += "### THIS EXCEPTION ENGENDERED AN OTHER ONE ###\n";
        r += "######## ENGENDERED EXCEPTION BELOW ##########\n";
        r += "##############################################\n";
    }
    r += "--------------------------------\n";
    r += "## Error : " + this->description + " ##\n";
    r += "--------------------------------\n";
    r += "\t-> TRACEBACK\n";

    return r;
}



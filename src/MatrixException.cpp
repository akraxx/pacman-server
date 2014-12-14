#include "MatrixException.h"

MatrixException::MatrixException() {

}

QString MatrixException::what() {
    return MyException::what() + "### Matrix Exception ###" + "\n";
}

OutOfRange::OutOfRange(int entry, int rangeMax) {
    this->entry = entry;
    this->rangeMax = rangeMax;
}

QString OutOfRange::what() {
    return MatrixException::what() +
         "Out of range exception :" + "\n"
         "\tYour entry : " + QString::number(this->entry) + "\n"
         "\tAvailable interval : [ 1, " + QString::number(this->rangeMax) + " ]" + "\n";
}

RowOutOfRange::RowOutOfRange(QString description, int entry, int rangeMax) : MyException(description), OutOfRange(entry, rangeMax) {

}

QString RowOutOfRange::what() {
    return OutOfRange::what() + "This row does not exist" + "\n";
}

MyException* RowOutOfRange::cloneExc() const {
    return new RowOutOfRange(*this);
}

ColOutOfRange::ColOutOfRange(QString description, int entry, int rangeMax) : MyException(description), OutOfRange(entry, rangeMax) {

}

QString ColOutOfRange::what() {
    return OutOfRange::what() + "This column does not exist" + "\n";
}

MyException* ColOutOfRange::cloneExc() const {
    return new ColOutOfRange(*this);
}

QString NegativeSize::what() {
    return MatrixException::what() + "Server was unable to instanciate a Matrix with negative size for : ";
}

NegativeRow::NegativeRow(QString description) : MyException(description) {

}

QString NegativeRow::what() {
    return NegativeSize::what() + "rows" + "\n";
}

MyException* NegativeRow::cloneExc() const {
    return new NegativeRow(*this);
}

NegativeCol::NegativeCol(QString description) : MyException(description) {

}

QString NegativeCol::what() {
    return NegativeSize::what() + "columns" + "\n";
}

MyException* NegativeCol::cloneExc() const {
    return new NegativeCol(*this);
}



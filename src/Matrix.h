/* 
 * File:   Matrix.h
 * Author: isen
 *
 * Created on 20 janvier 2011, 10:46
 */

#ifndef MATRIX_H
#define	MATRIX_H

#include "utils.h"
#include "MatrixException.h"

template<typename T> class Matrix {
private:
    int rows;
    int cols;
    T defVal;
    vector<vector<T>* > values;
    void initRow(int cols);
public:
    Matrix(int rows, int cols, T defVal);
    ~Matrix();

    T GetDefVal() const { return defVal; };

    void SetDefVal(T defVal);
    void SetCols(int cols);
    void SetRows(int rows);

    int getRows();
    int getColumns();
    /* inserts a row at index i in the matrix */
    void addRow(int i);
    void removeRow(int i);
    void addColumn(int i);
    void removeColumn(int i);

    T getValue(int i, int j);
    void setValue(int i, int j, T value);

    T& operator() (int rows, int cols);

    void printMatrix();
};

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  CONSTRUCTOR
//
// PROTOTYPE
//  Matrix(int rows, int cols, T defVal)
//
// ARGUMENTS
//  int rows : NUMBER OF MATRIX ROWS
//  int cols : NUMBER OF MATRIX COLUMNS
//  T defVal : DEFAULT VALUE OF THE CASES (CAN BE ANYTHING : INT, FLOAT)
//
// DESCRIPTION OF THE TREATMENT
//  ASSIGN VALUES OF PRIVATE ATTRIBUTES AND INITIALIZE THE MATRIX WITH DEFAULT VALUE
//
// DESCRIPTION OF THE RETURN
//  IF PROBLEM:
//      ASSIGNMENT PROBLEM (NEGATIVE SIZE OR BAD ALLOCATION), DESTRUCTOR IS CALLED AND EXCEPTION IS THROWN AGAIN
//  ELSE
//      RETURN NOTHING
//--------------------------------------//
template<typename T> Matrix<T>::Matrix(int rows, int cols, T defVal) {
    try {
        this->SetCols(cols);
        this->SetRows(rows);
        this->SetDefVal(defVal);

        for(int i = 0; i < rows; i++) {
            this->values.push_back(new vector<T>);
            this->values.at(values.size()-1)->resize(cols, defVal);
        }
    }
    catch(MyException& e) {
        this->~Matrix();
        throw;
    }
    catch(exception& e) {
        this->~Matrix();
        throw;
    }
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  DESTRUCTOR
//
// PROTOTYPE
//  ~Matrix()
//
// ARGUMENTS
//
// DESCRIPTION OF THE TREATMENT
//  DELETE ALL THE INITIALIZED ROWS OF THE MATRIX AND ERASE ALL ROWS (INITIALIZED OR NOT)
//
// DESCRIPTION OF THE RETURN
//  RETURN NOTHING
//--------------------------------------//
template<typename T> Matrix<T>::~Matrix() {
    while(!this->values.empty()) {
        if(this->values[0])
            delete this->values[0];

        this->values.erase(this->values.begin());
    }
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  SETTER
//
// PROTOTYPE
//  void SetDefVal(T defVal)
//
// ARGUMENTS
//  T defVal : DEFAULT VALUE OF THE CASES (CAN BE ANYTHING : INT, FLOAT)
//
// DESCRIPTION OF THE TREATMENT
//  ASSIGN VALUE OF PRIVATE ATTRIBUTE "defVal"
//
// DESCRIPTION OF THE RETURN
//  RETURN NOTHING
//--------------------------------------//
template<typename T> void Matrix<T>::SetDefVal(T defVal) {
    this->defVal = defVal;
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  SETTER
//
// PROTOTYPE
//  void SetCols(int cols)
//
// ARGUMENTS
//  int cols : NUMBER OF MATRIX COLUMNS
//
// DESCRIPTION OF THE TREATMENT
//  ASSIGN VALUE OF PRIVATE ATTRIBUTE "cols"
//
// DESCRIPTION OF THE RETURN
//  IF PROBLEM:
//      COLUMN AS A NEGATIVE ID -> EXCEPTION IS THROWN
//  ELSE
//      RETURN NOTHING
//--------------------------------------//
template<typename T> void Matrix<T>::SetCols(int cols) {
    if(cols >= 0)
        this->cols = cols;
    else
        throw NegativeCol("Can't set a negative column");
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  SETTER
//
// PROTOTYPE
//  void SetRows(int rows)
//
// ARGUMENTS
//  int rows : NUMBER OF MATRIX COLUMNS
//
// DESCRIPTION OF THE TREATMENT
//  ASSIGN VALUE OF PRIVATE ATTRIBUTE "rows"
//
// DESCRIPTION OF THE RETURN
//  IF PROBLEM:
//      ROW AS A NEGATIVE ID -> EXCEPTION IS THROWN
//  ELSE
//      RETURN NOTHING
//--------------------------------------//
template<typename T> void Matrix<T>::SetRows(int rows) {
    if(rows >= 0)
        this->rows = rows;
    else
        throw NegativeRow("Can't set a negative row");
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  GETTER
//
// PROTOTYPE
//  int getRows()
//
// ARGUMENTS
//
// DESCRIPTION OF THE TREATMENT
//  RETURN THE NUMBER OF MATRIX ROWS
//
// DESCRIPTION OF THE RETURN
//  RETURN THE NUMBER OF MATRIX ROWS
//--------------------------------------//
template<typename T> int Matrix<T>::getRows() {
    return this->rows;
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  FUNCTION
//
// PROTOTYPE
//  void addRow(int id_row)
//
// ARGUMENTS
//  int id_row : PLACE OF THE NEW ROW
//
// DESCRIPTION OF THE TREATMENT
//  ATTRIBUTE THE PLACE TO SET A NEW ROW IN A MATRIX
//  IF INDEX PROBLEM :
//      RESIZE THE INDEX, IF GREATER THAN THE LAST ROW, THEN RESIZE TO THE NUMBERS OF COLS. IF NEGATIVE OR NULL SIZE, THEN RESIZE TO 0
//
// DESCRIPTION OF THE RETURN
//  NO RETURN
//--------------------------------------//
template<typename T> void Matrix<T>::addRow(int id_row) {
    if(this->getRows() == 0)
        id_row = 1;
    else if(id_row > (this->getRows()+1) || id_row <= 0)
        throw RowOutOfRange("Can't add a row", id_row, this->getRows());

    this->values.insert(this->values.begin() + (id_row - 1), new vector<T>);
    this->values.at(id_row - 1)->resize(this->getColumns(), this->GetDefVal());
    this->SetRows(this->getRows()+1);
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  FUNCTION
//
// PROTOTYPE
//  void removeRow(int id_row)
//
// ARGUMENTS
//  int id_row : ID OF THE ROW TO BE DELETED
//
// DESCRIPTION OF THE TREATMENT
//  DELETE A ROW OF A MATRIX
//
// DESCRIPTION OF THE RETURN
//  IF PROBLEM:
//      RETURN THE RowOutOfRange EXCEPTION
//  ELSE
//      RETURN NOTHING
//--------------------------------------//
template<typename T> void Matrix<T>::removeRow(int id_row){
    if (id_row > 0 && id_row <= this->getRows()) {
        delete this->values[id_row - 1];
        this->values.erase(this->values.begin()+(id_row - 1));
        this->SetRows(this->getRows() - 1);
    }
    else
        throw RowOutOfRange("Can't remove this row", id_row, this->getRows());
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  FUNCTION
//
// PROTOTYPE
//  void removeColumn(int id_col)
//
// ARGUMENTS
//  int id_col : ID OF THE COLUMN TO BE DELETED
//
// DESCRIPTION OF THE TREATMENT
//  DELETE A COLUMN OF A MATRIX
//
// DESCRIPTION OF THE RETURN
//  IF PROBLEM:
//      RETURN THE ColOutOfRange EXCEPTION
//  ELSE
//      RETURN NOTHING
//--------------------------------------//
template<typename T> void Matrix<T>::removeColumn(int id_col) {
    if(id_col > 0 && id_col <= this->getColumns()) {
        int nbRows = this->getRows();
        for(int i = 0; i < nbRows; i++) {
            this->values.at(i)->erase(this->values.at(i)->begin() + (id_col - 1));
        }
        this->SetCols(this->getColumns() - 1);
    }
    else
        throw ColOutOfRange("Can't remove this column", id_col, this->getColumns());
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  GETTER
//
// PROTOTYPE
//  int getColumns()
//
// ARGUMENTS
//
// DESCRIPTION OF THE TREATMENT
//  RETURN THE NUMBER OF MATRIX COLUMNS
//
// DESCRIPTION OF THE RETURN
//  RETURN THE NUMBER OF MATRIX COLUMNS
//--------------------------------------//
template<typename T> int Matrix<T>::getColumns() {
    return this->cols;
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  FUNCTION
//
// PROTOTYPE
//  void removeColumn(int id_col)
//
// ARGUMENTS
//  int id_col : ID OF THE COL TO BE DELETED
//
// DESCRIPTION OF THE TREATMENT
//  ATTRIBUTE THE PLACE TO SET A NEW COLUMN IN A MATRIX
//  IF INDEX PROBLEM :
//      RESIZE THE INDEX, IF GREATER THAN THE LAST ROW, THEN RESIZE TO THE NUMBERS OF COLS. IF NEGATIVE OR NULL SIZE, THEN RESIZE TO 0
//
// DESCRIPTION OF THE RETURN
//  NO RETURN
//--------------------------------------//
template<typename T> void Matrix<T>::addColumn(int id_col) {
    int nbCols = this->getColumns();
    int nbRows = this->getRows();
    if(this->getColumns() == 0)
        id_col = 1;
    else if(id_col > (nbCols+1) || id_col <= 0)
        throw RowOutOfRange("Can't add a column", id_col, nbCols);

    for(int i = 0; i < nbRows; i++) {
        vector<T>* v = this->values.at(i);
        v->insert(v->begin() + (id_col - 1), this->GetDefVal());
    }

    this->SetCols(this->getColumns()+1);
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  GETTER
//
// PROTOTYPE
//  void getValue(int i, int j)
//
// ARGUMENTS
//  int i : ID ROW OF THE VALUE
//  int j : ID COL OF THE VALUE
//
// DESCRIPTION OF THE TREATMENT
//  RETURN THE VALUE OF THE PLACE LISTED WITH THE CORDINATE ROW i AND COL j
//
// DESCRIPTION OF THE RETURN
//  RETURN THE VALUE OF THE PLACE LISTED WITH THE CORDINATE ROW i AND COL j
//--------------------------------------//
template<typename T> T Matrix<T>::getValue(int i, int j) {
    return this->operator ()(i-1,j-1);
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  SETTER
//
// PROTOTYPE
//  void setValue(int i, int j, T value)
//
// ARGUMENTS
//  int i : ID ROW OF THE VALUE
//  int j : ID COL OF THE VALUE
//  T value : VALUE TO BE ATTRIBUTED
//
// DESCRIPTION OF THE TREATMENT
//  SET THE VALUE AT THE PLACE LISTED WITH THE CORDINATE ROW i AND COL j IN THE MATRIX
//
// DESCRIPTION OF THE RETURN
//  SET THE VALUE AT THE PLACE LISTED WITH THE CORDINATE ROW i AND COL j IN THE MATRIX
//--------------------------------------//
template<typename T> void Matrix<T>::setValue(int i, int j, T value) {
    this->operator ()(i-1,j-1) = value;
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  OVERLOAD OF OPERATOR
//
// PROTOTYPE
//  T& operator ()(int row, int col)
//
// ARGUMENTS
//  int row : ID ROW OF THE VALUE
//  int col : ID COL OF THE VALUE
//  T value : VALUE TO BE ATTRIBUTED
//
// DESCRIPTION OF THE TREATMENT
//  OPERATOR () IS OVERLOAD TO BE USE FOR A CLEARLY NAVIGATION
//
// DESCRIPTION OF THE RETURN
//  RETURN THE VALUE AT THE PLACE LISTED WITH THE ROW row AND COL col OF THE MATRIX
//--------------------------------------//
template<typename T> T& Matrix<T>::operator ()(int row, int col) {
    
    if(row < 0 || row >= this->getRows())
        throw RowOutOfRange("Can't find this row", row+1, this->getRows());
    else if(col < 0 || col >= this->getColumns())
        throw ColOutOfRange("Can't find this column", col+1, this->getColumns());
    
    return this->values.at(row)->at(col);
}

//--------------------------------------//
//              FUNCTION                //
//--------------------------------------//
// TYPE
//  FUNCTION
//
// PROTOTYPE
//  void printMatrix()
//
// ARGUMENTS
//
//
// DESCRIPTION OF THE TREATMENT
//  PRINT ONE BY ONE EVERY LINE OF THE MATRIX
//
// DESCRIPTION OF THE RETURN
//  PRINT ONE BY ONE EVERY LINE OF THE MATRIX
//--------------------------------------//
template<typename T> void Matrix<T>::printMatrix() {
    int nbRows = this->getRows();
    int nbCols = this->getColumns();
    cout << "\t######## MATRIX ########" << endl;
    for(int i = 0; i < nbRows; i++) {
        for(int j = 0; j < nbCols; j++) {
            cout << "\t" << this->values.at(i)->at(j);
        }
        cout << endl;
    }

    cout << "> Number of rows : " << nbRows << endl;
    cout << "> Number of columns : " << nbCols << endl;
}
#endif	/* Graph_H */


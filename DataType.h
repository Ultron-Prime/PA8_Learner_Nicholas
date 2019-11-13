/* -------------------------------------------------
FILE:           DataType.h
DESCRIPTION:    DataType header file for Project 8 for Fall 2019 CS 202-1001 at UNR
COMPILER:       g++ compiler
NOTES:          Provided in the project files

MODIFICATION HISTORY:
Author              Date        Version
----------------    --------    -------
Version 1           YYYY-MM-DD  x.x Description
Nick Learner        2019-11-10  1.0 Created this file, added class DataType declaration
*/

#ifndef DATATYPE_H_
#define DATATYPE_H_

#include <iostream>

class DataType{

friend std::ostream & operator<<(std::ostream & os, const DataType & dataType);
friend std::istream & operator>>(std::istream & is, DataType & dataType);

  public:
    DataType();
    DataType(int intVal, double doubleVal);
	DataType(const DataType & other);
	
    bool operator==(const DataType & rhs) const;
    DataType & operator= (const DataType & rhs);
    
    int getIntVal() const;
    void setIntVal(int i);  
    double getDoubleVal() const;
    void setDoubleVal(double d);

  private:
    int m_intVal;
    double m_doubleVal;
};

#endif //DATATYPE_H_

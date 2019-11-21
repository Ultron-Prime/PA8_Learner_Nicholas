/* -------------------------------------------------
FILE:           ArrayList.h
DESCRIPTION:    ArrayList header file for Project 8 for Fall 2019 CS 202-1001 at UNR
COMPILER:       g++ compiler
NOTES:          Provided in the project files

MODIFICATION HISTORY:
Author              Date        Version
----------------    --------    -------
Version 1           YYYY-MM-DD  x.x Description
Nick Learner        2019-11-10  1.0 Created this file, added class ArrayList declaration
*/

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#include "DataType.h"

class ArrayList{
	
  friend std::ostream & operator<<(std::ostream & os,		//(i)
					       const ArrayList & arrayList);
						   
  public:
    ArrayList();								    		//(1)
    ArrayList(size_t count, const DataType & value);		//(2)
    ArrayList(const ArrayList & other);				    	//(3)
    ~ArrayList();							    			//(4)

    ArrayList & operator= (const ArrayList & rhs);			//(5)


    DataType * front();							     		//(6)
    DataType * back();						                //(7)
	
    DataType * find(const DataType & target,				//(8)
                    DataType * & previous,
                    const DataType * start = NULL);	
	
    DataType * insertAfter(const DataType & target,     	//(9)
                           const DataType & value);	 
    DataType * insertBefore(const DataType & target,  		//(10)
                            const DataType & value);
    DataType * erase(const DataType & target);		 		//(11)

	
    DataType & operator[] (size_t position);				//(12a)
    const DataType & operator[] (size_t position) const;		//(12b)
    
    size_t size() const;									//(13)
    bool empty() const;										//(14)
    void clear();											//(15)	

  private:
  
    void resize(size_t count);		               			//(16)					    
    DataType * m_array;
    size_t m_size;
    size_t m_maxsize;

};

#endif

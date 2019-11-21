/* -------------------------------------------------
FILE:           ArrayList.cpp
DESCRIPTION:    ArrayList C++ file for Project 8 for Fall 2019 CS 202-1001 at UNR
COMPILER:       g++ compiler
NOTES:

MODIFICATION HISTORY:
Author              Date        Version
----------------    --------    -------
Version 1           YYYY-MM-DD  x.x Description
Nick Learner        2019-11-10  1.0 Created this file, started on class ArrayList implementation
Nick Learner        2019-11-11  1.1 Continued implementing ArrayList
Nick Learner        2019-11-13  1.3 Finished implementing ArrayList
*/

#include "ArrayList.h"

//(1)
ArrayList::ArrayList(): m_array(NULL), m_size(0), m_maxsize(0) { }

//(2)
ArrayList::ArrayList(size_t count, const DataType & value): m_size(count), m_maxsize(count)
{
	m_array = new DataType[m_maxsize];
	
	for (size_t i = 0; i < m_size; ++i)
	{
		m_array[i] = value;
	}
}

//(3)
ArrayList::ArrayList(const ArrayList & other): m_size(other.m_size), m_maxsize(other.m_maxsize)
{
	m_array = new DataType[m_maxsize];
	
	for (size_t i = 0; i < m_size; ++i)
	{
		m_array[i] = other.m_array[i];
	}
}

//(4)
ArrayList::~ArrayList()
{
	delete m_array;
}

//(5)
ArrayList & ArrayList::operator= (const ArrayList & rhs)
{
	resize(rhs.m_maxsize);
	
	m_maxsize = rhs.m_maxsize;
	m_size = rhs.m_size;
	
	for (size_t i = 0; i < m_size; ++i)
	{
		m_array[i] = rhs.m_array[i];
	}
	
	return *this;
}

//(6)
DataType * ArrayList::front()
{
	if (m_size == 0)
	{
		return NULL;
	}else
	{
		return m_array;
	}
}

//(7)
DataType * ArrayList::back()
{
	if (m_size == 0)
	{
		return NULL;
	}else
	{
		return &m_array[m_size-1];
	}
}

//(8)
DataType * ArrayList::find(const DataType & target, DataType * & previous, const DataType * start)
{
	if (m_array[0] == target)
	{
		previous = NULL;
		return m_array;
	}
	for (DataType * curr = (m_array + 1); curr != &m_array[m_size]; ++curr)
	{
		if (*curr == target)
		{
			previous = curr - 1;
			return curr;
		}else;
	}
	
	previous = NULL;
	return NULL;
}

//(9)
DataType * ArrayList::insertAfter(const DataType & target, const DataType & value)
{
	DataType * previous;
	DataType * tempdata = find(target, previous);
	
	if (tempdata != NULL)
	{
		if (m_size == m_maxsize)
		{
			resize(m_size + 1);
			tempdata = find(target, previous);
			for (size_t i = 0; i < (m_size - 1); ++i)
			{
				if (m_array[i] == *tempdata)
				{
					for (size_t j = m_size; j > (i + 1); --j)
					{
						m_array[j] = m_array[j - 1];
					}
					
					m_array[i + 1] = value;
					return (m_array + i + 1);
				}
			}
			return NULL;
		}else
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_array[i] == *tempdata)
				{
					for (size_t j = m_size; j > (i + 1); --j)
					{
						m_array[j] = m_array[j - 1];
					}
					
					m_array[i + 1] = value;
					++m_size;
					return (m_array + i + 1);
				}
			}
			return NULL;
		}
	}else
	{
		std::cerr << "Error in insertAfter(); could not find target DataType\n";
		return NULL;
	}
	return NULL;
}

//(10)
DataType * ArrayList::insertBefore(const DataType & target, const DataType & value)
{
	DataType * previous;
	DataType * tempdata = find(target, previous);
	
	if (tempdata != NULL)
	{
		if (m_size == m_maxsize)
		{
			resize(m_size + 1);
			tempdata = find(target, previous);
			for (size_t i = 0; i < (m_size - 1); ++i)
			{
				if (m_array[i] == *tempdata)
				{
					for (size_t j = m_size; j > i; --j)
					{
						m_array[j] = m_array[j - 1];
					}
					
					m_array[i] = value;
					return (m_array + i);
				}
			}
			return NULL;
		}else
		{
			for (size_t i = 0; i < m_size; ++i)
			{
				if (m_array[i] == *tempdata)
				{
					for (size_t j = m_size; j > i; --j)
					{
						m_array[j] = m_array[j - 1];
					}
					
					m_array[i] = value;
					++m_size;
					return (m_array + i);
				}
			}
			return NULL;
		}
	}else
	{
		std::cerr << "Error in insertBefore(); could not find target DataType\n";
		return NULL;
	}
	return NULL;
}

//(11)
DataType * ArrayList::erase(const DataType & target)
{
	DataType * previous;
	DataType * tempdata = find(target, previous);
	
	if (tempdata != NULL)
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			if (m_array[i] == *tempdata)
			{
				for (size_t j = i; j < m_size; ++j)
				{
					m_array[j] = m_array[j + 1];
				}
				
				--m_size;
				return (m_array + i);
			}
		}
		return NULL;
	}else
	{
		std::cerr << "Error in erase(); could not find target DataType\n";
		return NULL;
	}
	return NULL;
}

//(12a)
DataType & ArrayList::operator[] (size_t position)
{
	return m_array[position];
}

//(12b)
const DataType & ArrayList::operator[] (size_t position) const
{
	return m_array[position];
}

//(13)
size_t ArrayList::size() const
{
	return m_size;
}

//(14)
bool ArrayList::empty() const
{
	if (m_size == 0)
	{
		return true;
	}else
	{
		return false;
	}
}

//(15)
void ArrayList::clear()
{
	DataType stddata;
	for (size_t i = 0; i < m_size; ++i)
	{
		m_array[i] = stddata;
	}
	
	m_size = 0;
}

//(16)
void ArrayList::resize(size_t count)
{
	DataType * newarray = new DataType[count];
	if (count <= m_maxsize)
	{
		for (size_t i = 0; i < count; ++i)
		{
			newarray[i] = m_array[i];
		}
	}else if (count > m_maxsize)
	{
		for (size_t i = 0; i < m_maxsize; ++i)
		{
			newarray[i] = m_array[i];
		}
	}else
	{
		std::cerr << "Error in reassignment in resize()\n";
	}
	
	m_maxsize = m_size = count;
	
	delete[] m_array;
	m_array = newarray;
}

//(i)
std::ostream & operator<<(std::ostream & os, const ArrayList & arrayList)
{
	for (size_t i = 0; i < arrayList.m_size; ++i)
	{
		os << arrayList.m_array[i] << "\n";
	}
	
	std::cout << "\n";
	
	return os;
}

/* -------------------------------------------------
FILE:           NodeList.cpp
DESCRIPTION:    NodeList C++ file for Project 8 for Fall 2019 CS 202-1001 at UNR
COMPILER:       g++ compiler
NOTES:

MODIFICATION HISTORY:
Author              Date        Version
----------------    --------    -------
Version 1           YYYY-MM-DD  x.x Description
Nick Learner        2019-11-10  1.0 Created this file, started on class NodeList implementation
Nick Learner        2019-11-13  1.1 Finished implementation
*/

#include "NodeList.h"

//(1)
NodeList::NodeList(): m_head(NULL) { }

//(2)
NodeList::NodeList(size_t count, const DataType & value)
{
	Node * newnode = NULL;
	size_t tempsize = 0;
	
	if (count > 0)
	{
		newnode = new Node(value);
		m_head = new Node(value, newnode);
		
		for (Node * curr = newnode; curr != NULL; curr = curr->m_next)
		{
			++tempsize;
			if (tempsize < count)
			{
				newnode = new Node(value);
				curr->m_next = newnode;
			}else
			{
				break;
			}
		}
	}else
	{
		m_head = NULL;
	}
}

//(3)
NodeList::NodeList(const NodeList & other)
{
	if (other.m_head != NULL && other.m_head->m_next != NULL)
	{
		Node * newnode = new Node(other.m_head->m_next->m_data);
		m_head = new Node(other.m_head->m_data, newnode);
		for (Node * curr = other.m_head->m_next->m_next; curr->m_next != NULL; curr = curr->m_next)
		{
			newnode->m_next = new Node(curr->m_next->m_data);
			newnode = newnode->m_next;
		}
	}else if (other.m_head != NULL && other.m_head->m_next == NULL)
	{
		m_head = new Node(other.m_head->m_data);
	}else
	{
		m_head = NULL;
	}
}

//(4)
NodeList::~NodeList()
{
	clear();
}

//(5)
NodeList & NodeList::operator= (const NodeList & rhs)
{
	clear();
	
	if (rhs.m_head != NULL && rhs.m_head->m_next != NULL)
	{
		Node * newnode = new Node(rhs.m_head->m_next->m_data);
		m_head = new Node(rhs.m_head->m_data, newnode);
		for (Node * curr = rhs.m_head; curr != NULL; curr = curr->m_next)
		{
			newnode->m_next = new Node(curr->m_next->m_data);
			newnode = newnode->m_next;
		}
	}else if (rhs.m_head != NULL && rhs.m_head->m_next == NULL)
	{
		m_head = new Node(rhs.m_head->m_data);
	}else
	{
		m_head = NULL;
	}
	
	return *this;
}

//(6)
Node * NodeList::front()
{
	return m_head;
}

//(7)
Node * NodeList::back()
{
	Node * curr;
	for (curr = m_head; curr != NULL; curr = curr->m_next) { }
	
	return curr;
}

//(8)
Node * NodeList::find(const DataType & target, Node * & previous, const Node * start)
{
	if (m_head->m_data == target)
	{
		previous = NULL;
		return m_head;
	}
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		if (curr->m_next->m_data == target)
		{
			previous = curr;
			return curr->m_next;
		}
	}
	
	previous = NULL;
	return NULL;
}

//(9)
Node * NodeList::insertAfter(const DataType & target, const DataType & value)
{
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		if (curr->m_data == target)
		{
			Node * newnode = new Node(value);
			newnode->m_next = curr->m_next;
			curr->m_next = newnode;
			return newnode;
		}
	}
	
	return NULL;
}

//(10)
Node * NodeList::insertBefore(const DataType & target, const DataType & value)
{
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		if (curr->m_next->m_data == target)
		{
			Node * newnode = new Node(value, curr->m_next);
			curr->m_next = newnode;
			return newnode;
		}
	}
	
	return NULL;
}

//(11)
Node * NodeList::erase(const DataType & target)
{
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		if (curr->m_next->m_data == target)
		{
			Node * delnode = curr->m_next;
			curr->m_next = delnode->m_next;
			delete delnode;
			return curr->m_next;
		}
	}
	
	return NULL;
}

//(12a)
DataType & NodeList::operator[] (size_t position)
{
	size_t tempsize = 0;
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		++tempsize;
		if (tempsize == position)
		{
			return curr->m_data;
		}
	}
	
	return m_head->m_data;
}

//(12b)
const DataType & NodeList::operator[] (size_t position) const
{
	size_t tempsize = 0;
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		++tempsize;
		if (tempsize == position)
		{
			return curr->m_data;
		}
	}
	
	return m_head->m_data;
}

//(13)
size_t NodeList::size() const
{
	size_t tempsize = 0;
	for (Node * curr = m_head; curr != NULL; curr = curr->m_next)
	{
		++tempsize;
	}
	
	return tempsize;
}

//(14)
bool NodeList::empty() const
{
	if (m_head == NULL)
	{
		return true;
	}else
	{
		return false;
	}
}

//(15)
void NodeList::clear()
{
	while (m_head != NULL)
	{
		Node * delnode = m_head;
		m_head = m_head->m_next;
		delete delnode;
	}
}

//(i)
std::ostream & operator<<(std::ostream & os, const NodeList & nodeList)
{
	for (Node * curr = nodeList.m_head; curr != NULL; curr = curr->next())
	{
		os << curr->data() << "\n";
	}
	
	std::cout << "\n";
	
	return os;
}

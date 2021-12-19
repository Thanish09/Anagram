#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
#include "linkList.h"

using namespace std;

template <class T>
class DynStack {
	private:
		struct stackNode {
			T value;
			stackNode* next;
		};
		stackNode* top;
	public:
		DynStack();
		~DynStack();
		void push(T);		//store the swapped letters
		void pop(T&);		//pop out the swapped letter
		bool isEmpty();
};

template <class T>
DynStack<T>::DynStack()
{
	top = nullptr;
}

template <class T>
DynStack<T>::~DynStack()
{
	stackNode* nodeptr;
	stackNode* nextNode;

	nodeptr = top;

	while (nodeptr)
	{
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
}

template <class T>
void DynStack<T>::push(T item)
{

	stackNode* newNode;
	newNode = new stackNode;
	newNode->value = 10;

	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}

}

template <class T>
void DynStack<T>::pop(T& item)
{
	stackNode* temp = nullptr;

	if (isEmpty())
	{
		cout << "The stack is Empty" << endl;
	}
	else
	{
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

template <class T>
bool DynStack<T>::isEmpty()
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;

	return status;
}
#endif


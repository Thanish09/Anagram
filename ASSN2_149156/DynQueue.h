#ifndef DYNQUEUE_H
#define DYNQUEUE_H
#include <iostream>
#include "linkList.h"

using namespace std;

template <class T>
class DynQueue {
	private:
		struct queueNode {
			T value;
			queueNode* next;
		};
		queueNode* front;
		queueNode* rear;
		int quantity;
	public:
		DynQueue();
		~DynQueue();
		bool isEmpty();
		void enqueue(T);		//store the swapped letters
		void dequeue(T&);		//let out the swapped letters
};

template <class T>
DynQueue<T>::DynQueue()
{
	front = nullptr;
	rear = nullptr;
	quantity = 0;
}

template <class T>
DynQueue<T>::~DynQueue()
{
	queueNode* nodeptr;

	while (!isEmpty())
	{
		nodeptr = front;
		front = front->next;
		delete nodeptr;

	}
}

template <class T>
bool DynQueue<T>::isEmpty()
{
	bool status;

	if (quantity)
		status = false;
	else
		status = true;

	return status;
}

template <class T>
void DynQueue<T>::enqueue(T name)
{
	queueNode* newnode;
	newnode = new queueNode;
	newnode->value = name;

	if (isEmpty())
	{
		front = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
	quantity++;
}

template <class T>
void DynQueue<T>::dequeue(T& name)
{
	queueNode* nodeptr;

	if (isEmpty())
	{
		cout << "The queue is empty." << endl;
	}
	else
	{
		name = front->value;
		nodeptr = front;
		front = front->next;
		delete nodeptr;
	}
	quantity--;
}
#endif


#pragma once
#include"Node.h"
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	void insertStart(int value);
	void display();
	void insertEnd(int value);
	void insertPosition(int pos, int value);
	void deleteStart();
	void deleteEnd();
	void deletePosition(int pos);
	int search();
	LinkedList add(LinkedList num2);
private:
	Node * Head, *Tail;
};


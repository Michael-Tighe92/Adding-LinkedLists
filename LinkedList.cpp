#include "LinkedList.h"
#include<iostream>
using namespace std;



LinkedList::LinkedList()
{
	Head = NULL;
	Tail = NULL;
}


LinkedList::~LinkedList()
{
}

void LinkedList::insertStart(int value)
{
	Node * Temp = new Node;
	Temp->data = value;
	Temp->next = NULL;
	if (Head == NULL)
	{
		Head = Temp;
		Tail = Temp;
	}
	else
	{
		Temp->next = Head;
		Head = Temp;
	}
}	

void LinkedList::display()
{
	Node * Temp = new Node;
	Temp = Head;
	while (Temp != NULL)
	{
		cout << Temp->data << " ";
		Temp = Temp->next;
	}
}

void LinkedList::insertEnd(int value)
{
	Node *Temp = new Node;
	Temp->data = value;
	Temp->next = NULL;
	if (Head == NULL)
	{
		Head = Temp;
		Tail = Temp;
		Temp = NULL;
	}
	else 
	{
		Tail->next = Temp;
		Tail = Temp;
	}
	
}

void LinkedList::deleteStart()
{
	Node *Temp = new Node;
	Temp = Head;
	Head = Head->next;
	delete Temp;
}

void LinkedList::deleteEnd()
{
	Node * Current = new Node;
	Node * Previous = new Node;
	Current = Head;
	while (Current->next != NULL)
	{
		Previous = Current;
		Current = Current->next;
	}
	Tail = Previous;
	Tail->next = NULL;
	delete Current;
}

void LinkedList::insertPosition(int pos, int value)
{
	Node *Previous = new Node;
	Node *Current = new Node;
	Node *Temp = new Node;
	Current = Head;
	if (Head != NULL && search() >= pos)
	{
		for (int i = 1;i < pos;i++)
		{
			Previous = Current;
			Current = Current->next;
		}
		Temp->data = value;
		Previous->next = Temp;
		Temp->next = Current;
	}
	else
	{
		cout << "Error! Either Head is Null or Position: " << pos<<" does not exist!" <<endl;
	}
}

void LinkedList::deletePosition(int pos)
{
	Node *Current = new Node;
	Node *Previous = new Node;
	Current = Head;
	if (Head != NULL && search() >= pos)
	{
		for (int i = 1;i < pos;i++)
		{
			Previous = Current;
			Current = Current->next;
		}
		Previous->next = Current->next;
	}
	else
	{
		cout << "Error! Either Head is Null or Position: " << pos << " does not exist!" << endl;
	}
}

int LinkedList::search()
{
	Node * Temp = new Node;
	Temp = Head;
	int counter = 0;
	while (Temp != NULL)
	{
		counter++;
		Temp = Temp->next;
	}
	return counter;
}

LinkedList LinkedList::add(LinkedList num2)
{
	LinkedList Result;
	Node * Temp = new Node;
	Temp = Head;
	int total = 0, carry = 0;
	while (Temp != NULL && num2.Head != NULL)
	{
		total = carry + Temp->data + num2.Head->data;
		if (total >= 10)
		{
			carry = 1;
		}
		else
			carry = 0;
		total = total % 10;
		Result.insertEnd(total);
		Temp = Temp->next;
		num2.Head = num2.Head->next;

	}
	return Result;
}
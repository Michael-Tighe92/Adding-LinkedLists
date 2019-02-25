#include<iostream>
#include"LinkedList.h"
using namespace std;
int main()
{
	LinkedList num1, num2, result;
	Node test;
	int num1_size, num2_size;
	cout << "How many digits will num1 have?" << endl;
	cin >> num1_size;
	int * arr = new int[num1_size];
	cout << "How many digits will num2 have?" << endl;
	cin >> num2_size;
	int * arr2 = new int[num2_size];
	for (int i = 0;i < num1_size;i++)
	{
		cout << "Enter the number!" << endl;
		cin >> arr[i];
		num1.insertEnd(arr[i]);
	}
	cout << endl;
	for (int i = 0;i < num2_size;i++)
	{
		cout << "Enter the number!" << endl;
		cin >> arr[i];
		num2.insertEnd(arr[i]);
	}
	//num1.deletePosition(5);
	cout << "Num1: ";
	num1.display();
	cout << endl;
	cout << "Num2: ";
	num2.display();
	result = num1.add(num2);
	cout << endl;
	cout << "Result: ";
	result.display();
	system("pause");
}

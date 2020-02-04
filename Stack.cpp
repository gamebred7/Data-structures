#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class Stack
{
	int data;                                              
	Stack *Next,*Head;   
public:
	Stack()
	{
		Head = NULL; 
	}

	~Stack()
	{ 
		delete Head;
	}

	void Add(int data, Stack *&MyStack)                          
	{
		Stack *temp = new Stack;                              
		temp->data = data;                                        
		temp->Next = MyStack->Head;                          
		MyStack->Head = temp;                                
	}


	void Show(Stack *MyStack)                                 
	{
		Stack *temp = MyStack->Head;                          
		while (temp != NULL)                                
		{
			cout << temp->data << " ";                         
			temp = temp->Next;                            
		}
	}


	void ClearList(Stack *MyStack)
	{
		while (MyStack->Head != NULL)                        
		{
			Stack *temp = MyStack->Head->Next;                   
			delete MyStack->Head;                                
			MyStack->Head = temp;                                
		}
	}
};





int main()
{
	Stack *MyStack = new Stack; 

	for (int i=0; i<10; i++)
	{
		MyStack->Add(i,MyStack);
	}
	MyStack->Show(MyStack);

	system("pause");
	return 0;
}


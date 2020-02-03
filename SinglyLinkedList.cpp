#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;

template <typename T>
class List
{
public:
	List()
	{
		Size=0;
		head=nullptr;
	}
	~List()
	{
		clear();
	}

	void push_back(T data)             // добавить в конец
	{
		if(head==nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current =this->head;

			while(current->pNext!=nullptr)
			{
				current=current->pNext;
			}
			current->pNext = new Node<T>(data); 
		}
		Size++;
	}

	void push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insert(T value, int index)
	{
		if(index==0)
		{
			push_front(value);
		}
		else
		{
			Node<T>* previous=this->head;

			for(int i=0; i<index-1; i++)
			{
				previous=previous->pNext;
			}


			previous->pNext= new Node<T>(value, previous->pNext);
			Size++;
		}
	}

	void removeAt(int index)
	{
		if(index==0)
		{
			pop_front();
		}
		else
		{
			Node<T>* previous = this->head;

			for(int i=0; i<index-1; i++
			{
				previous = previous->pNext;
			}

			Node<T>* toDelete = previous->pNext;
			previous->toNext=toDelete->pNext;

			delete toDelete;
			Size--;
		}
	}

	void pop_back()
	{
		removeAt(Size-1);
	}

	void clear()
	{
		while(Size)
		{
			pop_front();
		}
	}

	void pop_front()
	{
		Node<T> *temp = head;
		head = head->pNext;
		delete temp;
		Size--;
	}

	int GetSize()
	{
		return Size;
	}

	T& operator[](const int index)
	{
		int counter = 0;
		Node<T> *current = this->head;

		while(current!=nullptr)
		{
			if(counter==index)
			{
				return current->data;
			}
			current=current->pNext;
			counter++;
		}
	}

private:
	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data=data;
			this->pNext=pNext;
		}
	};

	int Size;
	Node<T> *head;
};

int main()
{
	List<int> lst;

	int numbersCount;
	cin>>numbersCount;

	for(int i=0; i<numbersCount; i++)
	{
		lst.push_back(rand()%10);
	}





	lst.GetSize();

	for(int i=0; i<lst.GetSize(); i++)
	{
		cout<<lst[i]<<endl<<endl;
	}

	system("pause");
	return 0;
}


//============================================================================
// Name        : Queue job application.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class node
{
	int no;
	node* nptr;

public:
	node()
{
		no=0;
		nptr=NULL;
}


	friend class queue;

};


class queue
{
	node* front;
	node* rear;
	//static int size;
	//int n;

public:
	node* create(int);
	void add(int);
	int pop();
	void del(int);
	/*int isempty();
	int isfull();*/
	void display();

	queue(/*int a*/)
	{
		front=NULL;
		rear=NULL;
		//n=a;
	}


};

//int queue::size=0;

node* queue::create(int a)
{
	node* temp;
	temp=new node;
	temp->no=a;
	//size++;
	return temp;

}

void queue::add(int a)
{

	if(front==NULL)
	{
		front=create(a);
		rear=front;
	}
/*	else if(size>n)
	{
		cout<<"Queue full";
		return;
	}*/
	else{
		node* temp;
		temp=front;
		while(temp->nptr!=NULL)
		{
			temp=temp->nptr;
		}
		temp->nptr=create(a);
		rear=temp->nptr;
	}
}

/*int queue::isempty()
{
	if(front==NULL)
	{
		return 1;

	}
	else{
		return 0;
	}
}*/

int queue::pop()
{
	if(rear==NULL)
	{
		return -1;
	}
	else if(front==rear)
	{
		int a=front->no;
		front=NULL;
		rear=NULL;
		return a;


	}
	else{
		node *temp,*tmp;
		temp=front;
		tmp=new node;

		while(temp->nptr!=rear)
		{
			temp=temp->nptr;
		}
		tmp=rear;
		rear=temp;
		temp->nptr=NULL;
		int a=tmp->no;
		delete tmp;
		//size--;
		return a;

	}
}

void queue::del(int a)
{
	if(front==NULL)
	{
		return;
	}
	else{
		node *temp,*tmp;
		temp=front;
		tmp=new node;

		while(temp->nptr->no!=a)
		{
			temp=temp->nptr;
		}
		rear=temp;
		tmp=temp->nptr;
		temp->nptr=tmp->nptr;
		delete tmp;
		cout<<"Job deleted.\n";
		//size--;

	}
}

void queue::display()
{
	if(front==NULL)
	{
		return;
	}
	else{
		node* temp;
		temp=front;

		while(temp!=NULL)
		{
			cout<<"  "<<temp->no<<"   ";
			temp=temp->nptr;
		}
	}
}


/*int queue::isfull()
{
	if(size>n)
	{
		return 1;

	}
	else{
		return 0;
	}
}*/


int main() {
	int n;
	char c;
	/*cout << "Enter the size of queue" << endl; // prints
	cin>>n;*/
	queue q1;

	do{

		cout<<"Enter the choice"<<endl;
		cout<<"1.Add job\n"<<"2.Del job\n"<<"3.Display\n"<<"4.Pop\n";
		cin>>n;
		int a;
		switch(n)
		{
		case 1:
			cout<<"Enter the job no.\n";
			cin>>a;
			q1.add(a);

			break;

		case 2:
			cout<<"Enter the job no to be deleted\n";
			cin>>a;
			q1.del(a);
			break;

		/*case 3:
			a=q1.isempty();
			if(a==1)
			{
				cout<<"Queue is empty !";
			}
			else{
				cout<<"Queue is not empty !";
			}

			break;

		case 4:
			a=q1.isfull();
			if(a==1)
			{
				cout<<"Queue is full !";
			}
			else{
				cout<<"Queue is not full !";
			}
			break;*/


		case 3:
			cout<<"\nThe jobs in the queue are:\n";
			q1.display();
			break;

		case 4:
			a=q1.pop();
			if(a!=-1)
			cout<<"Job no. "<<a<<" completed.\n";
			break;

		default:
			cout<<"Wrong choice!!\n";

		}
		cout<<"Do you want to continue ?  (y/n)";
		cin>>c;
	}

	while(c=='y');

	return 0;
}

//============================================================================
// Name        : Pinnacle club linked list.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<cstring>
using namespace std;



class node
{

	string name;
	int prn;
	node *nptr;

public:

	node(){
		name="";
		prn=0;
		nptr=NULL;
	}

	friend class linked_list;




};



class linked_list
{

public:
	node *start,*end;
	void add();
	void insert_begin();
	void insert_last();
	void del(int);
	void compute();
	void display();
	void rev(node*);
	void sort();
	node* create();
	void concan(linked_list,linked_list);

	linked_list()
	{
		start=NULL;
		end=NULL;

	}



};


void linked_list::concan(linked_list l1,linked_list l2)
{





	node *tmp1;
	tmp1=l1.start;
	node *tmp2;
	tmp2=l2.start;

	while(tmp1!=NULL)
	{
		node *tmp,*val;
		tmp=start;
		val=new node;
		val->prn=tmp1->prn;

		if(start==NULL)
		{
			start=val;
			val=val->nptr;

		}
		else
		{
			while(tmp->nptr!=NULL)
			{
				tmp=tmp->nptr;
			}
			tmp->nptr=val;
			val->nptr=NULL;

		}
		tmp1=tmp1->nptr;
	}

	while(tmp2!=NULL)
	{
		node *val,*tmp;
		val=new node;
		val->prn=tmp2->prn;
		tmp=start;
		while(tmp->nptr!=NULL)
		{
			tmp=tmp->nptr;
		}
		tmp->nptr=val;
		val->nptr=NULL;
		tmp2=tmp2->nptr;
	}



}


int main() {

	int c;
	char c1;
	linked_list l1,l2,*l3;
	l3=new linked_list;

	do{
		cout<<"Select an option:"<<endl;
		cout<<"1. Add member\n";
		cout<<"2. Del member\n";
		cout<<"3. Compute total no of members\n";
		cout<<"4. Display the members\n";
		cout<<"5. Display members in reverse order\n";
		cout<<"6. Create and operate second linked list\n";
		cout<<"7. link other link list\n";
		cout<<"8. Sort the resultant link list\n";

		cin>>c;

		switch(c)
		{
		case 1:
			l1.add();

			break;

		case 2:
			int a;
			cout<<"Enter the pnr no.";
			cin>>a;
			l1.del(a);

			break;

		case 3:
			l1.compute();

			break;

		case 4:
			l1.display();

			break;

		case 5:
			l1.rev(l1.start);

			break;

		case 6:

			int co;

			do{
				cout<<"Select an option:"<<endl;
				cout<<"1. Add member\n";
				cout<<"2. Del member\n";
				cout<<"3. Compute total no of members\n";
				cout<<"4. Display the members\n";
				cout<<"5. Display members in reverse order\n";

				cin>>co;

				switch(co)
				{
				case 1:
					l2.add();

					break;

				case 2:
					int a;
					cout<<"Enter the pnr no.";
					cin>>a;
					l2.del(a);

					break;

				case 3:
					l2.compute();

					break;

				case 4:
					l2.display();

					break;

				case 5:
					l2.rev(l2.start);

					break;


					break;


				default:
					cout<<"Wrong choice!!";

				}

				cout<<"Do you wish to continue operations on second list(y/n)";

				cin>>c1;
			}
			while(c1=='y');

			break;



		case 7:
			l3->concan(l1,l2);
			l3->display();
			break;

		case 8:
			l3->sort();
			l3->display();
			break;


		default:
			cout<<"Wrong choice!!";

		}

		cout<<"Do you wish to continue (y/n)";

		cin>>c1;
	}
	while(c1=='y');

	return 0;
}




node* linked_list::create()
{
	node *temp;
	temp=new node;
	//cout<<"Enter the name :\n";
	//cin>>temp->name;
	cout<<"Enter the PRN:\n";
	cin>>temp->prn;
	return temp;


}

void linked_list::add()
{

	node *front=NULL, *New=NULL;
	front=start;


	if(start==NULL)
	{
		start=create();
	}

	else{
		New=create();

		while(front->nptr!=NULL)
		{
			front=front->nptr;
		}


		front->nptr=New;
		end=front->nptr;

	}

}

void linked_list::display()
{
	node *front=NULL;

	front=start;

	while(front->nptr!=NULL)
	{
		cout<<front->prn<<endl;
		front=front->nptr;
	}

	cout<<front->prn<<endl;


}

void linked_list::rev(node* temp)
{
	while(temp->nptr !=NULL)
	{
		rev(temp->nptr);
		break;
	}
	cout<<temp->prn<<endl;
}


void linked_list::compute()
{
	node *front=NULL;
	int count=0;
	front=start;

	while(front->nptr!=NULL)
	{
		count++;
		front=front->nptr;
	}

	cout<<count+1<<endl;


}


void linked_list::del(int a)
{
	node *front=NULL;
	node *temp=NULL;

	if(start->prn==a)
	{
		temp=start;
		start=start->nptr;
		delete temp;
	}

	else{
		front=start;
		node *temp1;
		temp1=NULL;

		while(front->nptr->prn!=a)
		{
			front=front->nptr;

		}

		temp1=front->nptr;
		front->nptr=temp1->nptr;
		delete temp1;
	}
	display();


}

void linked_list::sort()
{
	node* temp;
	temp=start;
	node* tp;

	while(temp!=NULL)
	{
		tp=start;
		for(int i=0;tp!=NULL;i++)
		{

			if(temp->prn<tp->prn)
			{
				int t;
				t=temp->prn;
				temp->prn=tp->prn;
				tp
				->prn=t;
			}
			else{
				tp=tp->nptr;
			}
		}

		temp=temp->nptr;
	}
}


























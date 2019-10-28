//============================================================================
// Name        : Butterscotch vanilla linked list.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class node
{public:
	int prn;
	node* nptr;


	node()
{
		prn=0;
		nptr=NULL;
}

	friend class linked_list;
};

class linked_list
{
public:
	node* head;
	node* create(int);
	void add(int);
	void display();
	void compute();
	int check(int);
	void count();



	linked_list()
	{
		head=NULL;
	}

};

node* linked_list::create(int p)
{
	node *temp;
	temp=new node;
	temp->prn=p;

	return temp;
}

void linked_list::add(int p)
{
  node* start;
  start=head;

  if(head==NULL)
  {
	  head=create(p);
  }
  else{
	  while(start->nptr!=NULL)
	  {
		  start=start->nptr;
	  }

	  start->nptr=create(p);

  }

  cout<<"Element added."<<endl;

}

void linked_list::display()
{
	node* start;
	start=head;
	while(start!=NULL)
	{
		cout<<start->prn<<endl;
		start=start->nptr;
	}

}

int linked_list::check(int a)
{
	node* start;
	start=head;
	while(start!=NULL)
	{
		if(a==start->prn)
		{
			return 1;
		}

		start=start->nptr;
	}

	return 0;
}

void linked_list::count()
{
	node* temp;
	temp=head;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->nptr;
	}
	cout<<"Total students:  "<<count<<endl;
}


int main() {
	int n,prn;
	linked_list U,B,V,OB,OV,BV,N,A;
	cout<<"Enter the the no. of students u want to add.";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the prn-  ";
		cin>>prn;
		U.add(prn);
	}

	cout<<"Enter the no. of students who like butterscotch.";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the prn no.";
		int prn;
		cin>>prn;
		B.add(prn);
	}


	cout<<"Enter the no. of students who like vanilla.";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cout<<"Enter the prn no.";
		int prn;
		cin>>prn;
		V.add(prn);
	}

	char c;
	int d;
do{
	cout<<"Enter:\n"<<"Students who like -\n"<<"1.Only butterscotch\n";
	cout<<"2.Only Vanilla\n"<<"3.Both\n"<<"4.Neither\n"<<"5.Either vanilla or butterscotch or both";

	cin>>d;

	switch(d)
	{
	case 1:
        node* start1;
        start1=B.head;
        while(start1!=NULL)
        {
        	int x=start1->prn;
        	int y=V.check(x);
        	if(y==0)
        	{
        		OB.add(x);
        	}
        	start1=start1->nptr;
        }
        OB.count();
        cout<<"Students are:\n";
        OB.display();



		break;

	case 2:
		node* start2;
		        start2=V.head;
		        while(start2!=NULL)
		        {
		        	int x=start2->prn;
		        	int y=B.check(x);
		        	if(y==0)
		        	{
		        		OV.add(x);
		        	}
		        	start2=start2->nptr;
		        }
		        OV.count();
		        cout<<"Students are:\n";
		                OV.display();

		break;

	case 3:
		node* start3;
		        start3=U.head;
		        while(start3!=NULL)
		        {
		        	int x=start3->prn;
		        	int y=V.check(x);
		        	int z=B.check(x);
		        	if(y==1 && z==1)
		        	{
		        		BV.add(x);
		        	}
		        	start3=start3->nptr;
		        }
		        BV.count();
		        cout<<"Students are:\n";
		        BV.display();

		break;

	case 4:
		node* start4;
				        start4=U.head;
				        while(start4!=NULL)
				        {
				        	int x=start4->prn;
				        	int y=V.check(x);
				        	int z=B.check(x);
				        	if(y==0 && z==0)
				        	{
				        		N.add(x);
				        	}
				        	start4=start4->nptr;
				        }
				        N.count();
				        cout<<"Students are:\n";
				        N.display();

		break;

	case 5:
		node* tp1;
		tp1=OB.head;
		node* tp2;
		tp2=OV.head;
		node* tp3;
		tp3=BV.head;


		while(tp1!=NULL)
		{
			int x=tp1->prn;
			A.add(x);
			tp1=tp1->nptr;
		}
		while(tp2!=NULL)
				{
					int x=tp2->prn;
					A.add(x);
					tp2=tp2->nptr;
				}
		while(tp3!=NULL)
				{
					int x=tp3->prn;
					A.add(x);
					tp3=tp3->nptr;
				}
		A.count();
		cout<<"Students are: \n";
		A.display();

		break;

default:

		cout<<"Wrong choice!!!";
	}

	cout<<"Do you want to continue?";
	cin>>c;
}
while(c=='y');



	return 0;
}

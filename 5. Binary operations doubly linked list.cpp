//============================================================================
// Name        : Doubly linked list.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
using namespace std;

int count=0;
int count1,count2;

class node
{

	string name;
	int dat;
    node *nptr;
    node *pptr;

public:

    node(){
    	name="";
    	dat=0;
    	nptr=NULL;
    	pptr=NULL;
    }

    friend class linked_list;




};



class linked_list
{

public:
	node *start,*end;
	void add(int);
	void display();
	void bcreate(int);
	void complement1(linked_list*);
	void addition(linked_list,linked_list,int,int);
	void complement2(linked_list*);
	node* create(int );


	linked_list()
	{
		start=NULL;
		end=NULL;

	}



};





int main() {

	int c,n1,n2;
	char c1;

	linked_list l1,*l2,l3,*l4,*l5;

	l2=new linked_list;
	l4=new linked_list;
	l5=new linked_list;

	cout<<"Enter the first no.";
	cin>>n1;

	l1.bcreate(n1);
	count1=count;





	//do{
	cout<<"Select an option:"<<endl;
	cout<<"1. Addition \n";
	cout<<"2. 1's complement\n";
	cout<<"3. 2's complement \n";
	cin>>c;

	switch(c)
	{
	case 1:
        cout<<"Enter the second no. " ;
        cin>>n2;

        l3.bcreate(n2);
        count2=count;


      l4->addition(l1,l3,count1,count2);

        l4->display();
		break;

	case 2:
        l1.complement1(l2);
        l2->display();

		break;

	case 3:
		 l1.complement1(l2);
		l5->complement2(l2);
		l5->display();

			break;


	default:
		cout<<"Wrong choice!!";

	}

	/*cout<<"Do you wish to continue (y/n)";

	cin>>c1;
	}
	while(c1=='y');*/

	return 0;
}




node* linked_list::create(int n)
{
	node *temp;
	temp=new node;

	temp->dat=n;

    return temp;


}

void linked_list::add(int n)
{

	node *front=NULL, *New=NULL;
	front=end;


	if(end==NULL)
	{
	end=create(n);
	start=end;

	}

	else{
		New=create(n);

		while(front->pptr!=NULL)
		{
			front=front->pptr;
		}


		front->pptr=New;
		start=front->pptr;
		start->nptr=front;

	}

}

void linked_list::bcreate(int n)
{
	count=0;
    while(n!=0)
    {
    	add(n%2);
    	n=n/2;
    	count++;
    }

}


void linked_list::display()
{
	node *front=NULL;

	front=start;

	while(front->nptr!=NULL)
	{
		cout<<front->dat;
		front=front->nptr;
	}

	cout<<front->dat<<endl;




}

void linked_list::complement1(linked_list *l2)
{
	node* temp;
	temp=end;

	while(temp!=NULL)
	{
		if(temp->dat==0)
		{
			l2->add(1);
		}
		else if(temp->dat==1)
		{
			l2->add(0);
		}



		temp=temp->pptr;
	}

}


void linked_list::addition(linked_list l1,linked_list l3,int n1,int n2)
{


	int carry=0;
	node* temp1=l1.end;
	node* temp2=l3.end;






	while(temp1!=NULL && temp2!=NULL)
	{


		if(carry+temp1->dat +temp2->dat ==0)
		{
			carry=0;
			add(0);

			temp1=temp1->pptr;
			temp2=temp2->pptr;
		}
		else if(carry+temp1->dat +temp2->dat ==1)
		{
			carry=0;
		    add(1);

			temp1=temp1->pptr;
			temp2=temp2->pptr;
		}

		else if(carry+temp1->dat +temp2->dat ==2)
		{
					carry=1;
					add(0);

					temp1=temp1->pptr;
					temp2=temp2->pptr;
		}
		else if(carry+temp1->dat +temp2->dat >2)
		{
							carry=1;
							add(1);


							temp1=temp1->pptr;
							temp2=temp2->pptr;
		}
	}

	while(temp1!=NULL)
	{


		if(carry==0)
		{
			carry=0;
			int i=temp1->dat;
			add(i);


			temp1=temp1->pptr;

		}
		else{

			if(carry+temp1->dat==1)
			{
				carry=0;
				add(1);

				temp1=temp1->pptr;
			}
			else{
				carry=1;
				add(0);


				temp1=temp1->pptr;
			}

		}



	}

	while(temp2!=NULL)
	{

				if(carry==0)
				{
					carry=0;
					int i=temp2->dat;
					add(i);

					temp2=temp2->pptr;

				}
				else{

					if(carry+temp2->dat==1)
					{
						carry=0;
						add(1);

						temp2=temp2->pptr;
					}
					else{
						carry=1;
						add(0);

						temp2=temp2->pptr;
					}

				}

	}

	if(carry==1)
	{
		add(1);
	}



}

void linked_list::complement2(linked_list* l2)
{
	node* temp=new node;
	temp=l2->end;
	int carry=1;




	while(temp!=NULL)
	{


        if(carry+temp->dat==1)
        {
        	add(1);
        	carry=0;
        	temp=temp->pptr;
        }
        else if(carry+temp->dat==2)
        {
        	add(0);
        	carry=1;
        	temp=temp->pptr;
        }



	}
		if(carry==1)
		{
			add(1);
		}



}







//============================================================================
// Name        : Paranthesis check using stack.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class node
{
	char para;
	node* nptr;

public:
	node()
{
		para=NULL;
		nptr=NULL;

}

	friend class stack;
};

class stack
{
	node* top;

public:
	stack()
{

		top=NULL;
}
	static int pk;
	void push(char);
	char pop();
	int check(char );
	node* create(char);
	void result();
	void display();

};

int stack::pk=0;

void stack::display()
{
	node *front;

	front=top;

	while(front!=NULL)
	{
		cout<<front->para<<endl;

		front=front->nptr;
	}




}

node* stack::create(char a)
{
	node* temp;
	temp=new node;
	temp->para=a;
	return temp;
}

void stack::push(char a)
{
	node* temp;
	temp=new node;

	if(top==NULL)
	{
		top=create(a);
	}
	else
	{
		temp=create(a);
		temp->nptr=top;
		top=temp;
	}

}

char stack::pop()
{
	char a=top->para;
	node* tmp;
	tmp=top;
	top=top->nptr;
	delete tmp;
	return a;
}

int stack::check(char a)
{
	char x;
	int z;

	switch(a)
	{

	case '}':
		x=pop();
      if(x!='{')
      {
    	cout<<"Error !!";
    	  return 0;
      }
		break;

	case ']':
		x=pop();
		if(x!='[')
		{
			cout<<"Error !!";
			    	  return 0;

		}
		break;

	case ')':
		x=pop();
		if(x!='(')
		{
			cout<<"Error !!";
			    	  return 0;

		}
		break;

	case '{':
			push(a);
			break;

		case '[':
			push(a);
			break;

		case '(':
			push(a);
			break;


	default:

		break;
	}
	return 1;

}

void stack::result( )
{

 if(top==NULL)
 {
	 cout<<"Everything fine !!";
 }

 else
  {
 	 cout<<"Error!!";
  }



}

int main() {
	char a[100];
	stack s1;
	cout<<"Enter the expression:\n";
		cin>>a;
	int i=0;

	while(a[i]!='\0')
	{
		if(s1.check(a[i])==0)
		{
			return 0;
		}
		else{
		i++;
		}
	}
	s1.result();
	return 0;
}




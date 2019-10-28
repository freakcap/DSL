//============================================================================
// Name        : Infix to postfix .cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

char arr[100];
int a1,b1,c1,d1;

class node
{
	char op;
	int op1;
	node* nptr;

public:
	node()
{
		op='.';
		op1=0;
		nptr=NULL;

}

	friend class stack;
};

class stack
{
	node* top;
	static int count;


public:
	stack()
{

		top=NULL;
}

	void push(char);
	void push(int);
	char pop();
	int popi();
	void convert(char);
	node* create(char);
	node* create(int);
	void empty();
	void eval(char);
	void display();


};

int stack::count=0;

node* stack::create(char a)
{
	node* temp;
	temp=new node;
	temp->op=a;
	return temp;
}
node* stack::create(int a)
{
	node* temp;
	temp=new node;
	temp->op1=a;
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

void stack::push(int a)
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
	char a=top->op;
	node* tmp;
	tmp=top;
	top=top->nptr;
	delete tmp;
	return a;
}


int stack::popi()
{
	int a=top->op1;
	node* tmp;
	tmp=top;
	top=top->nptr;
	delete tmp;
	return a;
}

void stack::display()
{
	cout<<top->op1;


}




void stack::convert(char a)
{


	switch(a)
	{

	case '+':

		if(top==NULL)
		{
			push(a);
		}
		else if(top->op=='*' || top->op=='/' || top->op=='-' || top->op=='+')
		{
			while(top->op=='*'|| top->op=='/' || top->op=='-'|| top->op=='+')
			{
				char x=pop();
				cout<<x;
				arr[count]=x;
				count++;
				if(top==NULL)
				{
					break;
				}
			}
			push(a);
		}

		else{
			push(a);
		}
		break;

	case '-':
		if(top==NULL)
		{
			push(a);
		}

		else if(top->op=='*' || top->op=='/' || top->op=='+' || top->op=='-')
		{
			while(top->op=='*'|| top->op=='/' || top->op=='+' || top->op=='-' )
			{
				char x=pop();
				cout<<x;
				arr[count]=x;
				count++;
				if(top==NULL)
				{
					break;
				}
			}
			push(a);
		}

		else{
			push(a);
		}
		break;

	case '*':
		if(top==NULL)
		{
			push(a);
		}
		else if(top->op=='/' || top->op=='*')
		{

			char x=pop();
			cout<<x;
			arr[count]=x;
			count++;
			push(a);
		}
		else{
			push(a);
		}
		break;

	case '/':
		if(top==NULL)
		{
			push(a);
		}
		else if(top->op=='/' || top->op=='*')
		{

			char x=pop();
			cout<<x;
			arr[count]=x;
			count++;
			push(a);
		}
		else{
			push(a);
		}
		break;

	default:
		cout<<a;
		arr[count]=a;
		count++;
		break;
	}

}

void stack::empty()
{
	node* start;
	start=top;

	while(start!=NULL)
	{
		cout<<start->op;
		arr[count]=start->op;
		count++;
		start=start->nptr;
	}
}


void stack::eval(char a)
{
	int x,y,z;
	switch(a)
	{
	case '+':
		x=popi();
		y=popi();
		z=x+y;
		push(z);

		break;

	case '-':
		x=popi();
		y=popi();
		z=y-x;
		push(z);
		break;

	case '*':
		x=popi();
		y=popi();
		z=x*y;
		push(z);
		break;

	case '/':
		x=popi();
		y=popi();
		z=y/x;
		push(z);
		break;

	case 'a':
		push(a1);
		break;

	case 'b':
		push(b1);
		break;

	case 'c':
		push(c1);
		break;

	case 'd':
		push(d1);
		break;
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
		s1.convert(a[i]);
		i++;
	}
	s1.empty();
	cout<<endl;
	cout<<"Enter value of a\n";
	cin>>a1;
	cout<<"Enter value of b\n";
	cin>>b1;
	cout<<"Enter value of c\n";
	cin>>c1;
	cout<<"Enter value of d\n";
	cin>>d1;

	i=0;
	while(arr[i]!='\0')
	{
		s1.eval(arr[i]);
		i++;
	}
	s1.display();

	return 0;
}





//============================================================================
// Name        : miniproject.cpp
// Author      :21425,21423,21427,21438
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;
void intro();

class queue
{
	int acno[10],loan_amt[10];
	int front,rear;


public:

	queue()
	{

		front=rear=-1;

	}


	void push(int a,int b)
	{
		if(front==-1)
		{
			front++;
			rear++;
			loan_amt[front]=b;
			acno[front]=a;
		}
		else{
			rear++;
			loan_amt[rear]=b;
			acno[rear]=a;
		}
	}

	void display()
	{
		int temp;
		temp=front;
		while(temp!=rear+1)
		{
			cout<<acno<<"\n";
			temp++;
		}
	}

	void count(int a)
	{
		int temp=front;
		int flag=0;
		while(temp!=rear+1)
		{
			if(acno[temp]==a)
			{
				cout<<"\nYou are "<<temp+1<<"th in the queue.\n";
				flag=1;
			}
			temp++;
		}
		if(flag==0)
		{
			cout<<"\n account not found.\n";
		}
	}

};





class account
{
	int acno;
	string name;
	int deposit;
	string type;
	account *next;
	account *pre;
public:
	account():acno(0),name("NONE"),deposit(0),type("NONE"),next(NULL),pre(NULL){}
	void create_account();			//function to get data from user
	void show_account();			//function to show data on screen
	void modify();					//function to add new data
	void dep(int);				    //function to accept amount and add to balance amount
	void withdraw(int);		 		//function to accept amount and subtract from balance amount
	void report();					//function to show data in tabular format
	int retacno() ;					//function to return account number
	int retdeposit();				//function to return balance amount
	string rettype();					//function to return type of account
	void setnext(account *a){next=a;}
	void setpre(account *a){pre=a;}
	account* retnext(){return next;}
	account* retpre(){return pre;}

};

void account::create_account()
{
	cout<<"\nEnter The account No. :";
	cin>>acno;
	cout<<"\nEnter The Name of The account Holder : ";cin.ignore();
	getline(cin,name);
	cout<<"\nEnter Type of The account (Current/Savings) : ";
	cin>>type;
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\nCongratulations!!! Your Account is Created...";
}

void account::show_account()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : ";
	cout<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";cin.ignore();
	getline(cin,name);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}


void account::dep(int x)
{
	deposit+=x;
}

void account::withdraw(int x)
{
	deposit-=x;
}

void account::report()
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}


int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

string account::rettype()
{
	return type;
}
class bank

{
	string manager;
	account *head;
public:
	void create_Acc()
	{
		account *a;
		a=new account;
		a->create_account();
		if(head==NULL)
		{
			head=a;
			a->setnext(NULL);
			a->setpre(NULL);
		}
		else
		{
			account *temp=head;
			while(temp->retnext()!=NULL)
			{
				temp=temp->retnext();
			}
			temp->setnext(a);
			a->setpre(temp);
			a->setnext(NULL);
		}
		ofstream outFile;
		outFile.open("account.dat",ios::binary|ios::app);
		outFile.write(reinterpret_cast<char *>(&a), sizeof(account));
		outFile.close();
	}
	void delete_account(int n)
	{
		account *temp=head;
		while(temp!=NULL){
			if(temp->retacno()==n)
			{
				if(temp==head)							//Deleting head node
				{
					cout<<"\n Deleting head node";
					head=temp->retnext();cout<<"\nupdating head pointer";
					temp->retnext()->setpre(NULL);
					cout<<"\nupdating next node";
					delete(temp);
					cout<<"\n Head node deleted";
				}
				else if(temp->retnext()==NULL)			//deleting last node
				{
					temp->retpre()->setnext(NULL);
					delete(temp);
				}
				else									//deleting node inbetween
				{
					temp->retpre()->setnext(temp->retnext());
					temp->retnext()->setpre(temp->retpre());
					delete(temp);
				}
				cout<<"\n\tRecord Deleted ..";
				break;
			}
			else
				temp=temp->retnext();
		}
		if(temp==NULL){cout<<"\n Account does not exist";
		}

	}
	void display_all()
	{
		account *temp=head;
		cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
		cout<<"====================================================\n";
		cout<<"A/c no.      NAME           Type  Balance\n";
		cout<<"====================================================\n";
		while(temp!=NULL)
		{
			temp->report();
			temp=temp->retnext();
		}
	}
	void deposit_withdraw(int n, int option)
	{
		int amt;
		account *temp;
		while(temp!=NULL){
			if(temp->retacno()==n)
			{
				temp->show_account();
				if(option==1)
				{
					cout<<"\n\tTO DEPOSITE AMOUNT ";
					cout<<"\n\nEnter The amount to be deposited";
					cin>>amt;
					temp->dep(amt);
				}
				if(option==2)
				{
					cout<<"\n\tTO WITHDRAW AMOUNT ";
					cout<<"\n\nEnter The amount to be withdraw";
					cin>>amt;
					int bal=temp->retdeposit()-amt;
					if((bal<500 && temp->rettype()=="saving") || (bal<1000 && temp->rettype()=="Current"))
						cout<<"Insufficience balance";
					else
						temp->withdraw(amt);
				}

				cout<<"\n\t Record Updated";
				break;
			}
			else
				temp=temp->retnext();
		}

	}
	void display_sp(int n)
	{
		account *temp=head;
		while(temp!=NULL)
		{
			if(temp->retacno()==n)
			{
				cout<<"\nBALANCE DETAILS\n";
				temp->show_account();
				break;
			}
			else
				temp=temp->retnext();
		}
		if(temp==NULL){cout<<"\n Account does not exist";}
	}

	void modify_account(int n)
	{
		account *temp=head;
		while(temp!=NULL)
		{
			if(temp->retacno()==n)
			{
				temp->show_account();
				cout<<"\n\nEnter The New Details of account"<<endl;
				temp->modify();
				cout<<"\n\t Record Updated";
				break;
			}
			else
				temp=temp->retnext();}
		if(temp==NULL){cout<<"\n Account does not exist";
		}
	}

};
int main() {
	bank *b=new bank();
	char ch;
	int num;
	intro();
	queue q1;
	do
	{
		cout<<"\n\n\tMAIN MENU";
		cout<<"\n\t01. NEW ACCOUNT";
		cout<<"\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\t04. BALANCE ENQUIRY";
		cout<<"\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\t08. LOAN MANAGEMENT";
		cout<<"\n\t09. EXIT";
		cout<<"\n\tSelect Your Option (1-8)\n ";
		cin>>ch;
		switch(ch)
		{
		case '1':
			b->create_Acc();
			break;
		case '2':
			cout<<"\n\tEnter The account No. : "; cin>>num;
			b->deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\tEnter The account No. : "; cin>>num;
			b->deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\tEnter The account No. : "; cin>>num;
			b->display_sp(num);
			break;
		case '5':
			b->display_all();
			break;
		case '6':
			cout<<"\tEnter The account No. : "; cin>>num;
			b->delete_account(num);
			break;
		case '7':
			cout<<"\tEnter The account No. : "; cin>>num;
			b->modify_account(num);
			break;

		case '8':
			int x;
			cout<<"\n-------------------------------------------------------------\n";
			cout<<"\tLOAN MANAGEMENT";
			cout<<"\n-------------------------------------------------------------\n";
			cout<<"\n\t01. Register for loan.";
			cout<<"\n\t02. Status of loan.\n";
			cin>>x;
			{
				switch(x){

				case 1:
					int a,b;
					cout<<"ENTER ACCOUNT NO.\n";
					cin>>a;
					cout<<"ENTER LOAN AMOUNT\n";
					cin>>b;
					q1.push(a,b);
					cout<<"\nSuccessfully registered.\n";

					break;

				case 2:
					int z;
					cout<<"\nENTER ACC NO.\n";
					cin>>z;
					q1.count(z);

					break;


				}
			}

			break;

		case '9':
			cout<<"\n\tThanks for using bank management system";
			break;
		default :cout<<"\a";
		}
		cout<<"\nDo you want to continue?(y/n)\n";
		cin>>ch;
	}while(ch!='n');
	return 0;
}
void intro()
{
	cout<<"====================================================\n";
	cout<<"\tBANK";
	cout<<"\tMANAGEMENT";
	cout<<"\tSYSTEM\n";
	cout<<"====================================================\n";
	cout<<"\n\nMADE BY :Maitreya, Rishi, Nachiket and Pranav";
	cout<<"\nCollege : PICT, PUNE";
	cin.get();
}

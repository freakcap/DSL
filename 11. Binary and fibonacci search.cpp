//============================================================================
// Name        : binary and fibonacci search.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;


class array
{
	int n;
	int arr[100];

public:
	void input();
	void sort();
	void bin(); //binary search
	void binary(int);
	int  fib(int x,int n) ;    //fibonacci search


	array(int a)
	{
		n=a;
	}
};


void array::input()
{
	cout<<"Enter the roll no of students :-"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}

void array::sort()
{
	int temp=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}

		}
	}

}



void array::binary(int s)
{
	int first=0;
	int last=n-1;
	int mid=(first+last)/2;

	while(first<=last)
	{
		if(arr[mid]<s)
		{
			first=mid+1;
		}
		else if(arr[mid]==s)
		{
			cout<<mid+1<<"  position";
			break;
		}
		else if(arr[mid]>s)
		{
			last=mid-1;
		}
		mid=(first+last)/2;
	}
	if(last<first)
	{
		cout<<"Not found";

	}
}

void array::bin()
{
	int s;
	cout<<"Enter the roll no to search (binary)";
	cin>>s;
    binary(s);

}

int array:: fib(int x,int n)
 {
 	sort();
 	int fib2=0;
 	int fib1=1;
 	int fibm=fib2+fib1;
 	while(fibm<n)
 	{
 		fib2=fib1;
 		fib1=fibm;
 		fibm=fib2+fib1;
	 }
	 int offset=-1;
	 while(fibm>1)
	 {
	 	int i=min(offset+fib2,n-1);
	 	if(arr[i]<x)
	 	{
	 		fibm=fib1;
	 		fib1=fib2;
	 		fib2=fibm-fib1;
	 		offset=i;
		 }
		 else if(arr[i]>x)
		 {
		 	fibm=fib2;
		 	fib1=fib1-fib2;
		 	fib2=fibm-fib1;
		 }
		 else return i;
	 }
	 if(fib1 && arr[offset+1]==x)
	 return offset+1;
	 return -1;
 }

int main() {
	int s,c;
	int k;
	cout << "Enter the total no of students" << endl;
	cin>>s;

	array a1(s);

	a1.input();
	a1.sort();

	cout<<"Enter\n"<<"1.Binary search\n"<<"2.Fibonacci search";
		cin>>c;

		switch(c)
		{
		case 1:
			a1.bin();
			break;

		case 2:
			int key;
			cout<<"\n Enter element to be searched :";
			cin>>key;
	k=a1.fib(key,s);
	if(k==-1)
		cout<<"\n Element not present";
	else
	cout<<"\n Element present at :"<<k;
	break;			

		default:
			cout<<"Wrong choice!!";
		}


	
	return 0;
}


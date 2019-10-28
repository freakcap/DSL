//============================================================================
// Name        : linear and sentinel search.cpp
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
	void lin();      //linear search
	void sen();      //sentinel search


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

void array::lin()
{
	int j;
	cout<<"Enter the roll no to search"<<endl;
	cin>>j;

	for(int i=0;i<n;i++)
	{
		if(arr[i]==j)
		{
			cout<<i+1<<" position"<<endl;
			return;
		}
		else
		{
			continue;
		}
	}
	cout<<"Not found!!"<<endl;
}

void array::sen()
{
	int j;
		cout<<"Enter the roll no to search"<<endl;
		cin>>j;

   arr[n]=j;
   int flag=0;
   for(int i=0;;i++)
   {
	   if(arr[i]==j)
	   {
		   flag=i;
		   break;
	   }
   }



   if(flag !=n)
   {
	   cout<<flag+1<<"  position"<<endl;
   }
   else if(flag==n)
   {
	   cout<<"Not found!!"<<endl;
   }
}



int main() {
	int s,c;

	cout << "Enter the total no of students" << endl;
	cin>>s;

	array a1(s);

	a1.input();

	cout<<"Enter\n"<<"1.Linear search\n"<<"2.Sentinel search";
	cin>>c;

	switch(c)
	{
	case 1:
		a1.lin();
		break;

	case 2:
		a1.sen();
		break;

	default:
		cout<<"Wrong choice!!";
	}




	return 0;
}

//============================================================================
// Name        : selection and bubble sort.cpp
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
	float arr[100];

public:
	void input();
	void sel();      //selection sort
	void bub();      //bubble sort
	void swap(int,int);
	int min(int ,int);


	array(int a)
	{
		n=a;
	}
};


void array::input()
{
	cout<<"Enter the marks of students :-"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
}

/*void array::swap(int i, int j)
{
	int temp=0;
	temp=arr[j];
	arr[j]=arr[i];
	arr[i]=temp;
}*/


int array::min(int first,int last)
{
	int count=first;
	int b=arr[first];
	for(int i=first;i<last+1;i++)
	{

		if(b>arr[i])
		{
			count=i;
			b=arr[i];

		}

	}
	return count;
}






void array::sel()
{

   for(int i=0;i<n;i++)
   {
	   int k;
	   k=min(i,n-1);
	   {
		   int temp=0;

		   	temp=arr[k];
		   	arr[k]=arr[i];
		   	arr[i]=temp;
	   }

   }


   if(n>4)
       {
   		cout<<"Top five scorers are"<<endl;

   		for(int i=n-1;i>n-6;i--)
   		{
   			cout<<arr[i]<<endl;
   		}
   }
   else{
   	cout<<"Top "<<n<<"  scorers are"<<endl;
   	for(int i=n-1;i>=0;i--)
   			{
   				cout<<arr[i]<<endl;
   			}
       }
}

void array::bub()
{

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=n-i;j++)
			{
				if(arr[j]<arr[j+1])
				{
					int temp=0;

					temp=arr[j+1];
					arr[j+1]=arr[j];
					arr[j]=temp;
				}

			}
		}
  if(n>4)
    {
		cout<<"Top five scorers are"<<endl;

		for(int i=0;i<5;i++)
		{
			cout<<arr[i]<<endl;
		}
}
else{
	cout<<"Top "<<n<<"  scorers are"<<endl;
	for(int i=0;i<n;i++)
			{
				cout<<arr[i]<<endl;
			}
    }
}

int main() {
	int s,c;

	cout << "Enter the total no of students" << endl;
	cin>>s;

	array a1(s);

	a1.input();

	cout<<"Enter\n"<<"1.Selection sort\n"<<"2.Bubble sort";
		cin>>c;

		switch(c)
		{
		case 1:
			a1.sel();
			break;

		case 2:
			a1.bub();
			break;

		default:
			cout<<"Wrong choice!!";
		}

	return 0;
}






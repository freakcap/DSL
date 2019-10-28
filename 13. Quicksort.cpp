//============================================================================
// Name        : Quicksort.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define max 10
using namespace std;

class num
{
	int a[max];
	int n;
public:
	num(int n)
{
		this->n=n;
}

	void swap(int&,int&);
	//int partition(int,int);
	void quicksort(int,int);
	void getdata();
	void display();

};
void num::swap(int& a,int& b)
{
	int temp;
	temp=b;
	b=a;
	a=temp;
}

void num::quicksort(int low,int high)
{
	if(low<high)
	{
		int pivot=a[low];
		int i=low+1;
		int j=high;



			do{

				while(a[i]<pivot && i<j)
				{
					i++;
				}
				while(a[j]>pivot && i<j)
				{
					j--;
				}
				if(i<j)
				{
					int temp;
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}while(i<j);

			int temp;
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;

			quicksort(low,j-1);
			quicksort(j+1,high);
		}
	else {
		return;
	}
}
/*void num::quicksort(int low,int high)
{
	if(low+1<high)
	{
		int m=partition(low,high);
		if(low<m+1)
		{
			quicksort(low,m);
		}
		if(m+1<high-1)
		{
			quicksort(m+1,high);
		}
	}

	else{
		return;
	}

}*/

void num::getdata()
{
	cout<<"\nEnter the percentages.\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void num::display()
{
	cout<<"\nSorted list is as follows:\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}


}


int main() {
	cout<<"Enter the no of students :(max 10)";
	int n;
	cin>>n;
	if(n<=10)
	{
		num n1(n);
		n1.getdata();
		n1.quicksort(0,n-1);
		n1.display();
	}
	else{
		cout<<"\nOut of Range!!";
	}

	return 0;
}

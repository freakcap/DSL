//============================================================================
// Name        : student_database.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class student
{
public:
	int marks[100];


void average()
		{
			float sum=0.0;
			for(int i=0;i<10;i++)
			{
				if(marks[i]>=0)
				{
				sum=sum+marks[i];
				}
			}

			cout<<"the average marks are "<<sum/10<<endl;

		}

void min()
		{
			int temp=101;
			for(int i=0;i<10;i++)
			{
				if(marks[i]<temp)

				{
					if(marks[i]>=0)
					{
					temp=marks[i];
					}
				}

			}
			cout<<"The min score is "<<temp<<endl;
		}

void max()
		{
			int temp=-1;
			for(int i=0;i<10;i++)
			{
				if(marks[i]>temp)
				{
					if(marks[i]>=0)
				 {
						temp=marks[i];
				 }
				}

			}
			cout<<"The max score is "<<temp<<endl;
		}

void freq()
		{
			int maxcount=0;
			int val=0;



			for( int i=0;i<10;i++)
			{
                  int count=0;
				for(int j=i;j<10;j++)
				{
					if(marks[i]==marks[j])
					{

						count++;

					}

					if(count>maxcount)
					{
						maxcount=count;
						val=marks[i];

					}
				}
			}
			cout<<"marks repeated the most are "<<val<<endl;
		}

};







int main()
{
	student s;


	for(int i=0;i<10;i++)
	{
		cout<<"Enter the marks of student ( enter -1 for absent students)"<<i+1;
		cin>>s.marks[i];
	}

	cout<<endl;

	s.average();

	s.min();

	s.max();

	s.freq();

	int count=0;

	for(int i=0;i<10;i++)
	{

		if(s.marks[i]<0)
		{
			count++;
		}

	}
    cout<<"no of absent students is  "<<count;
	return 0;
}

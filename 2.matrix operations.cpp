//============================================================================
// Name        : matrix_operations.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
using namespace std;

class matrix
{
public:

	int a[10][10];
	int b[10][10];
    int ans[10][10];
    int sum;

	void upt(int);
	void diag(int);
	void trans(int);
	void add(int);
    void sub(int);
    void mul(int);
    void sadd(int);
};

void matrix::add(int n)
{
	cout<<"addition is"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[i][j]=a[i][j]+b[i][j];
			cout<<ans[i][j]<<"\t";
					if(j==n-1)
					{
						cout<<endl;
					}
		}
	}
}

void matrix::sub(int n)
{
	cout<<"subtraction is"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[i][j]=a[i][j]-b[i][j];
			cout<<ans[i][j]<<"\t";
					if(j==n-1)
					{
						cout<<endl;
					}
		}
	}
}

void matrix::mul(int n)
{
	cout<<"multiplication is"<<endl;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans[i][j]=0;

				for(int k=0;k<n;k++)
				{
					ans[i][j]=ans[i][j]+a[i][k]*b[k][j];

				}
				cout<<ans[i][j]<<"\t";

				if(j==n-1)
				{
					cout<<endl;
				}
			}
		}
}

void matrix::diag(int n)
{
	sum=0;

	for(int i=0;i<n;i++ )
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
			{
				sum=sum+a[i][j];
			}
		}
	}
	cout<<"Summation of the diagonal elements is "<< sum<<endl<<endl;

}

void matrix::upt(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(a[i][j]==0)
			{
				continue;
			}
			else{
				cout<<"The given matrix is not an upper triangular matrix"<<endl<<endl;
				return;
			}
		}

	}
        cout<<"The given matrix is an upper triangular matrix."<<endl<<endl;
}


void matrix::trans(int n)
{
	cout<<"Transpose is"<<endl;
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{

					cout<<a[j][i]<<"\t";

					if(j==n-1)
					{
						cout<<endl;
					}
				}
			}
}

void matrix::sadd(int n)
{
	int min[n-1],max[n-1];

	cout<<"Saddle points  "<<endl;

	for(int i=0;i<n;i++)
	{
		min[i]=10000;
		for(int j=0;j<n;j++)
		{
			if(a[i][j]<min[i])
			{
				min[i]=a[i][j];
			}
		}
	}

	for(int j=0;j<n;j++)
		{
			max[j]=-1000;
			for(int i=0;i<n;i++)
			{
				if(a[i][j]>max[j])
				{
					max[j]=a[i][j];
				}
			}
		}

	 for(int i=0;i<n;i++)
	 {
		 for(int j=0;j<n;j++)
		 {
			 if(min[i]==max[j])
			 {
				 cout<<"Value- "<<min[i]<<"  Position  "<<i<<","<<j<<endl;
			 }

			 else{
				 cout<<"--";
			 }

		 }
	 }

}


int main()
{
	int n;
	int c;
	cout<<"Enter the size of matrix";
	cin>>n;

	matrix m;

	cout<<"Enter the elements of matrix in linear manner"<<endl;

	  for(int i=0;i<n;i++)
	  {
		  for(int j=0;j<n;j++)
		  {
			  cin>>m.a[i][j];
		  }
	  }

	  cout<<"for add sub mul press 1 and for checking properties of matrix and finding transpose press 2";
	  cin>>c;

	  if(c==1)
	  {
		  cout<<"Enter the elements of second matrix in linear manner"<<endl;

		  	  for(int i=0;i<n;i++)
		  	  {
		  		  for(int j=0;j<n;j++)
		  		  {
		  			  cin>>m.b[i][j];
		  		  }
		  	  }
		m.add(n);
		m.sub(n);
		m.mul(n);

	  }
	  else if(c==2)
	  {
		  m.diag(n);
		  m.upt(n);
		  m.trans(n);
		  m.sadd(n);

	  }
	  else
	  {
		  cout<<"error wrong choice!!";

	  }

	return 0;
}

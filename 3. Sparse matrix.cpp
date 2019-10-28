//============================================================================
// Name        : sparse.cpp
// Author      : 21425
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class sparse
{
	private:

	int r,c,a[50][50],Sparse[50][3];
public:
	int returnmatrix()
	{
		return Sparse[50][3];
	}
	void getarr();
	void disp();
	void fastranspose();
	void csparse();
	void displaysparse();
	void addmatrix(matrix m1,matrix m2);
};

void sparse :: addmatrix(matrix m1,matrix m2)
{
	int i=1,j=1,s=1;
	if(m1.r==m2.r && m1.c==m2.c)
	{
Sparse[0][0]=m1.Sparse[0][0];
Sparse[0][1]=m1.Sparse[0][1];
while(i<=m1.Sparse[0][2] && j<=m2.Sparse[0][2])
{
	if(m1.Sparse[i][0]==m2.Sparse[j][0])	//if rows are same
	{
		if(m1.Sparse[i][1]==m2.Sparse[j][1])	//if columns are same
		{
	    Sparse[s][0]=m1.Sparse[i][0];
		Sparse[s][1]=m1.Sparse[i][1];
		Sparse[s][2]=m1.Sparse[i][2]+m2.Sparse[j][2];
		i++;
		j++;
		if(Sparse[0][2]!=0)
		s++;
		}
	else if(m1.Sparse[i][1]<m2.Sparse[j][1])	//if column of m1 < col of m2
	{
		Sparse[s][0]=m1.Sparse[i][0];
		Sparse[s][1]=m1.Sparse[i][1];
		Sparse[s][2]=m1.Sparse[i][2];s++;
		i++;
	}
	else										//if column of m1>col of m2
	{
		Sparse[s][0]=m2.Sparse[j][0];
		Sparse[s][1]=m2.Sparse[j][1];
		Sparse[s][2]=m2.Sparse[j][2];s++;j++;
	}
}

	else										//if rows are not equal
		{
		if(m1.Sparse[i][1]<m2.Sparse[j][1])
				{
					Sparse[s][0]=m1.Sparse[i][0];
					Sparse[s][1]=m1.Sparse[i][1];
					Sparse[s][2]=m1.Sparse[i][2];s++;
					i++;
				}
		else
				{
					Sparse[s][0]=m2.Sparse[j][0];
					Sparse[s][1]=m2.Sparse[j][1];
					Sparse[s][2]=m2.Sparse[j][2];s++;j++;
				}
	}
}

if(i<=m1.Sparse[0][2])				//if elements in m1 are left
{
	int p;
	for(p=i;p<=m1.Sparse[0][2];p++)
	{
		Sparse[s][0]=m1.Sparse[p][0];
		Sparse[s][1]=m1.Sparse[p][1];
		Sparse[s][2]=m1.Sparse[p][2];
		s++;
		
		
	}
}
else if(j<=m2.Sparse[0][2])			//if elements in m2 are left
{
	int p;
	for(p=j;p<=m2.Sparse[0][2];p++)
	{
		Sparse[s][0]=m2.Sparse[p][0];
		Sparse[s][1]=m2.Sparse[p][1];
		Sparse[s][2]=m2.Sparse[p][2];
		s++;
		
	}
}
//end of addition

Sparse[0][2]=s-1;
	cout<<"\n Addition : "<<endl;
	for(i=0;i<=Sparse[0][2];i++)
								{
									for(j=0;j<3;j++)
									{

										cout<<Sparse[i][j];
										cout<<"\t";
									}
									cout<<"\n";
								}
	}
	else
	{
		cout<<"\n Addition is not possible";
	}
}
void sparse::getarr()
{
	cout<<"\n Enter no of rows";
cin>>r;
cout<<"\n Enter no of columns";
cin>>c;
int i,j;
	cout<<"\n enter matrix ";
			for(i=0;i<r;i++)                //get matrix a
				{
					for(j=0;j<c;j++)
					{
						cout<<"\n Enter element at a["<<i<<"]["<<j<<"]";
						cin>>a[i][j];
					}

}
}
void sparse::disp()
{
	int i,j;
	cout<<"\n Matrix  \n";     //display matrix a
				for(i=0;i<r;i++)
						{
							for(j=0;j<c;j++)
							{

								cout<<a[i][j];
								cout<<"\t";
							}
							cout<<"\n";
						}
}
void sparse :: displaysparse()
{
	int i,j,k;
	k=Sparse[0][2];

		cout<<"\n Matrix  \n";     //display matrix a
					for(i=0;i<=k;i++)
							{
								for(j=0;j<3;j++)
								{

									cout<<Sparse[i][j];
									cout<<"\t";
								}
								cout<<"\n";
							}
}
void sparse :: csparse()
{
   int i,j,k=0;
   Sparse[0][0]=r;
   Sparse[0][1]=c;
   for(i=0;i<r;i++)
   {
	   for(j=0;j<c;j++)

	   {
		   if(a[i][j]!=0)
		   {
			   Sparse[k+1][0]=i;
			   Sparse[k+1][1]=j;
			   Sparse[k+1][2]=a[i][j];
			   k++;
		   }
	   }
   }
   Sparse[0][2]=k;
   displaysparse();

}
void sparse::fastranspose()
{
	int Sparse2[50][3];
	int i,j,k,col,loc;
	k=Sparse[0][1];
	int temp[k];
	int index[k];
	for(i=0;i<k;i++)
	{
		temp[i]=0;
		index[i]=0;
	}
	for(i=1;i<=Sparse[0][2];i++)
		{
		int count=Sparse[i][1];
		temp[count]++;
		}
	index[0]=1;
	for(i=1;i<Sparse[0][1];i++)
	{
		index[i]=index[i-1]+temp[i-1];
	}
    Sparse2[0][0]=Sparse[0][1];
    Sparse2[0][1]=Sparse[0][0];
    Sparse2[0][2]=Sparse[0][2];
	for(i=1;i<=Sparse[0][2];i++)
	{
	 col=Sparse[i][1];
	 loc=index[col];
	 index[col]++;
	 Sparse2[loc][0]=Sparse[i][1];
	 Sparse2[loc][1]=Sparse[i][0];
	 Sparse2[loc][2]=Sparse[i][2];
}
	cout<<"\n Traspsoe is :"<<endl;
	for(i=0;i<=Sparse2[0][2];i++)
							{
								for(j=0;j<3;j++)
								{

									cout<<Sparse2[i][j];
									cout<<"\t";
								}
								cout<<"\n";
							}
}

int main()
{

	
	int a;
	class sparse m1,m2,m3;
	do
	{
	int n;
	cout<<"\n Enter 1)Get Matrix 1 \n2)Get Matrix 2 \n3)Display 1st MAtrix \n4)Display second matrix" 
	"\n5)Convert to Sparse \n6)Fast transpose \n7)Additon \n8)Exit";
	switch(n)
	{
	case 1:
	m1.getarr();break;
	case 2:
	m2.getarr();break;
	case 3:
		m1.disp();break;
	case 4:
		m2.disp();break;
	case 5:
		{
			int key;
			cout<<"\n Enter 1)First Matrix 2)Second Matrix";
			cin>>key;
			switch(key)
			{
	case 1:
	m1.csparse();break;
	case 2:
		m2.csparse();break;
	}
}
break;
	case 6:
		{
			int key;
			cout<<"\n Enter 1)First Matrix 2)Second Matrix";
			cin>>key;
			switch(key)
			{
				case 1:
				    m1.fastranspose();break;
				case 2:
					m2.fastranspose();break;
			}
       }
break;
	case 7:
    m3.addmatrix(m1,m2);break;
    }
    cout<<"\n Enter 1)Continue 2)stop";
    cin>>a;
}while(a==1);
    return 0;

}


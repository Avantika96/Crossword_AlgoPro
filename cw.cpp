#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include "tst.cpp"
#define MAX 20

using namespace std;

node *root = NULL;//tst root

char buffer[10];//stack
int top=-1;//stack top

//stack push fn
int push(char ele,int n,int m)
{
	if(top>max(n,m))
	{
		cout<<"overflow"<<"\n";
		return 0;
	}
	else
	{
		top++;
		buffer[top]=ele;
	}
	return 1;
}

//stack pop fn
void pop()
{
	if(top==-1)
	cout<<"Underflow";
	else
	{
		buffer[top]='\0';
		top--;
	}
}

//to .....
int max(int n,int m)
{
	if(n>m)
		return n;
	else
		return m;
}

//in bounds!
int issafe(int n,int m,int i,int j)
{
	if(i>=0 && j>=0 && i<=n && j<=m && top<=max(n,m))
		return 1;
	return 0;
}

//bk word
int find_last(char mat[][MAX],int n,int m,int i, int j,int z)
{
	if(issafe(n,m,i,j))//bounds check
	{
		push(mat[i][j],n,m);
		if(search(root,buffer))//search in tree        	
			return 1;
		if(z!=5)
		{
			if(find_last(mat,n,m,i,j+1,1))
				return 1;
		}
		if(z!=6)
		{
			if(find_last(mat,n,m,i+1,j+1,2))
				return 1;
		}
		if(z!=7)
		{
			if(find_last(mat,n,m,i+1,j,3))
			return 1;
		}
		if(z!=8)
		{
			if(find_last(mat,n,m,i+1,j-1,4))
				return 1;
		}
		if(z!=1)
		{
			if(find_last(mat,n,m,i,j-1,5))
				return 1;
		}
		if(z!=2)
		{
			if(find_last(mat,n,m,i-1,j-1,6))
				return 1;
		}
		if(z!=3)
		{
			if(find_last(mat,n,m,i-1,j,7))
			return 1;
		}
		if(z!=4)
		{
			if(find_last(mat,n,m,i-1,j+1,8))
			return 1;
		}
		pop();
	}
	return 0;

}

//bk each point in array
int find_util(char mat[][MAX],int n,int m)
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(find_last(mat,n,m,i,j,0))
			return 1;
		}
	}
	return 0;
}

//cout...
void find_start(char mat[][MAX],int n,int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}	
		
	if(find_util(mat,n-1,m-1))
	{
		cout<<"\nVoila! It found "<<buffer<<endl<<endl;
	}
	else
		cout<<"\nBetter Luck next time"<<endl<<endl;
	
	memset(buffer,'\0',10);
	top=-1;
}

//to generate random characters
char randomize()
{	
	char p=rand()%25+97;
	return p;
}


int main()
{
//tst
	ifstream fp;
	char readbuffer[10];	
	fp.open("list.txt",ios::in);
	if(!fp.is_open())
	cout<<"error";
	memset(readbuffer,'\0',10);
	while(!fp.eof())
	{	
		fp>>readbuffer;
		insert(&root,readbuffer);
	}
	fp.close();
//tstend

	int choice,r,c,i,j;
	char mat_u[MAX][MAX];
	char mat_r[MAX][MAX];
    
	char mat_4[MAX][MAX]={{'x','q','r','u'},//bent
			      {'b','z','l','a'},
			      {'y','e','w','y'},
			      {'s','m','n','t'}};

	char mat_5[MAX][MAX]={{'q','z','e','s','c'},//no actual word
			      {'m','u','l','f','l'},
			      {'t','m','t','e','r'},
			      {'h','y','k','g','f'},
			      {'a','j','d','p','l'}};
    
	char mat_6[MAX][MAX]={{'p','m','t','l','x','l'},//engage
			      {'e','h','l','i','o','k'},
			      {'o','u','s','i','q','e'},
			      {'z','a','v','g','t','h'},
			      {'w','e','n','g','z','g'},
			      {'m','h','s','a','g','e'}};

	char mat_7[MAX][MAX]={{'i','h','o','a','l','o','w'},//concept
			      {'l','h','c','n','m','x','p'},
			      {'c','y','o','c','y','o','u'},
			      {'o','a','t','n','z','c','o'},
			      {'n','c','t','y','c','q','n'},
			      {'x','e','m','e','r','e','y'},
			      {'s','z','b','s','z','p','t'}};

	char mat_8[MAX][MAX]={{'a','p','p','r','o','a','c','h'},//approach
			      {'i','n','x','s','i','n','l','h'},
			      {'y','l','t','h','r','m','k','k'},
			      {'d','a','w','i','h','g','a','k'},
			      {'s','l','n','i','m','j','t','i'},
			      {'u','i','g','e','h','a','n','t'},
			      {'t','v','t','n','f','g','t','q'},
			      {'m','e','a','a','v','a','p','e'}};

	char mat_9[MAX][MAX]={{'a','l','f','r','u','t','e','g','i'},//foster
			      {'o','o','o','s','c','p','q','h','f'},
			      {'t','e','t','r','i','o','g','h','e'},
			      {'r','t','l','r','y','b','i','j','d'},
			      {'a','y','z','m','i','j','u','t','e'},
			      {'b','a','a','p','d','b','s','r','q'},
			      {'u','o','t','w','p','e','u','p','o'},
			      {'t','l','t','s','t','n','l','t','m'},
			      {'e','m','r','y','q','o','m','n','e'}};

	do
	{
		cout<<"Select an option from the following list\n";
		cout<<"1.Predefined 4X4 matrix\n";
		cout<<"2.Predefined 5X5 matrix\n";
		cout<<"3.Predefined 6X6 matrix\n";
		cout<<"4.Predefined 7X7 matrix\n";
		cout<<"5.Predefined 8X8 matrix\n";
		cout<<"6.Predefined 9X9 matrix\n";
		cout<<"7.A Userdefined matrix\n";
		cout<<"8.A Random Computer Generated matrix\n";    
		cout<<"9.Exit\n";
		
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				find_start(mat_4,4,4);
				break;
			case 2:
				find_start(mat_5,5,5);
				break;
			case 3:
				find_start(mat_6,6,6);
			break;
			case 4:
				find_start(mat_7,7,7);
				break;
			case 5:
			find_start(mat_8,8,8);
				break;
			case 6:
				find_start(mat_9,9,9);
				break;
			case 7:
				cout<<"enter number of rows(less than 20)"<<"\n";
				cin>>r;
				cout<<"enter number of columns(less than 20)"<<"\n";
				cin>>c;
				cout<<"enter the matrix"<<"\n";
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
				{
						cin>>mat_u[i][j];
					}
				}
				find_start(mat_u,r,c);
				break;
			case 8:
				srand(time(NULL));				
				char mat_r[MAX][MAX];
				for(i=0;i<5;i++)
				{
					for(j=0;j<5;j++)
					{
						mat_r[i][j]=randomize();
					}
				}
				find_start(mat_r,5,5);
				break;
			
			case 9:
				cout<<"Do you want to really want to exit?\n";				
				cout<<"Backtracking God will not maaf kariso you...\n";	
				char ch;
				cin>>ch;
				if(ch=='n'||ch=='N')
				{
					choice=10;
				}		
				break;			
			default:
				cout<<"Wrong choice"<<"\n";
				break;
		}
	}
	while(choice!=9);	
	return 0;
}


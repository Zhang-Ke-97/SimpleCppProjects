// Maze 1.8.cpp 
//
#include <stdio.h>
//#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
using namespace std;

struct Cell
{
	int x,y;
	int value;
};

struct Step
{
	 int x,y;
};

struct PPath
{
	Step *Path;
	int top,base;
};




void creatMaze(Cell *&p,int n)
{
	cout<<endl;
	if(n>0)	
	{	
		srand((unsigned)time(NULL));
		int i,j;
		p=new Cell[(n+2)*(n+2)];
		for( i=0;i<(n+2)*(n+2);i++)//+2+2
		{
			p[i].x=i/(n+2);
			p[i].y=i%(n+2);
			p[i].value=0;//p[i].value=rand()%2+1;//

			if(p[i].x==0||p[i].x==n+1||p[i].y==0||p[i].y==n+1)   p[i].value=2;
			
		}

		int t=n*n;
		for(i=0;i<n*n/3;i++)
		{
			j=rand()%t+1;
			p[j].value=2;
		}

		for(i=0;i<(n+2)*(n+2);i++)
		{
			if(p[i].x==1&&p[i].y==1) p[i].value=0;
			if(p[i].x==n&&p[i].y==n) p[i].value=0;
		}
	
		for(i=0;i<(n+2)*(n+2);i++)
		{
		
			if(p[i].value==2)
				cout<<"0";
			else cout<<"1";
			if(p[i].y==n+1)
				cout<<'\n';
		
		}
	}
	else
	{
		cout<<"You Fuck it out !"<<endl;
	}
}

void push(PPath *&P,Cell &m)
{
	
	P->Path[P->top].x=m.x;
	P->Path[P->top].y=m.y;
	m.value=3;
	P->top++;
}

void pop(PPath *&Path)
{
	Path->top--;

}

void exploreMaze(Cell *&p,PPath *&Route,int n)
{
	int k;
	Route=new PPath;
	Route->base=0;Route->top=0;
	Route->Path=new Step[(n+2)*(n+2)];

	int i;


	push(Route,p[n+3]);
	for( i=n+3;Route->top>=0&&!(i==n*(n+3)); )
	{
		
		if(p[i+1].value==0||p[i+1].value==1) 
		{
			i++;
			push(Route,p[i]);
		}
		else if(p[i+n+2].value==0||p[i+n+2].value==1) 
		{
			i=i+n+2;
			push(Route,p[i]);
		}
		else if(p[i-1].value==0||p[i-1].value==1) 
		{
			i--;
			push(Route,p[i]);
		}
	    else if(p[i-n-2].value==0||p[i-n-2].value==1) 
		{
			i=i-n-2;
			push(Route,p[i]);
		}
		else 
		{
			p[i].value=4;
			pop(Route);
			if( (Route->top)>=0)
			i=Route->Path[Route->top].x*(n+2)+Route->Path[Route->top].y;	////////////
		}
	}//for

	if(Route->top<0)
		cout<<"Fail to find Path!"<<endl;
	else 	
	{
		cout<<"Get a Path£∫"<<endl;
		for(k=0;Route->top>=0;Route->top--)
		{
			k++;
		}
		int K=0;
		for(Route->top=0;k>=2;Route->top++,k--,K++)
		{
			
			cout<<"("<<Route->Path[Route->top].x <<","<<Route->Path[Route->top].y<<")"<<"-->";
			if( (K+1)%4==0&&K!=0)
			{
				cout<<endl;
			}
		
		}//for

		cout<<"Yeah!"<<endl;
	}//else
}


void PlayOnce()
{
	int n=0;
	cout<<"°ˆInput Size of your Maze please...";cout<<"  "<<"Size=";
	cin>>n;
	PPath *myPath;
	Cell *Maze;
	
	creatMaze(Maze,n);
	exploreMaze(Maze,myPath,n);
	cout<<endl;cout<<endl;
}
void Game()
{
	cout<<"		 "<<"01"<<endl;
	cout<<"		 "<<"10"<<endl;
	
	char c;
	cout<<"Welcome to the Maze World! Choose A or B"<<endl;
	cout<<endl;
	cout<<"A.Enter				  B.Exit"<<endl;
	cout<<endl;
	cin>>c;
	while(c=='A')
	{
		PlayOnce();
		cout<<"Now,continue or exit?"<<endl;
		cout<<"A.Continue     B.Exit"<<endl;
		cin>>c;
	}

}


int main(int argc, char *argv[])
{
	Game();
	getchar();getchar();
	return 0;
}









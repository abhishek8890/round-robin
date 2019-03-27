#include<iostream>
using namespace std;
int small(int [5][2],int);
int sum(int [5][2],int);
int small2(int [5][2],int,int,int);


int main()
{
	int n;
		int s,m=0,o=0,i,k,f,z,min;

	int st,ct[2],d;
	
	
	cout<<"\nEnter the size:";
	cin>>n;
	int a[n][2],b[n][2];
	for(i=1;i<=n;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";
	cin>>a[i][0];
	
	cout<<"\nEnter Burst timep"<<i<<":";
	cin>>a[i][1];	
		
	}
	
	//find first process to run

    
    o=small(a,n);
    m=sum(a,n);

//process run
int p,count=0;

p=a[o][0];
for(int q=p;q<=m+p;q++)
{

	if(q!=p)
	{
	
		a[o][1]--;
		ct[o]=q;
	}
	
	if(a[o][1]==0)
	{
	ct[o]=q;
		
	d=small2(a,n,o,q);
	
    o=d;
    if(a[o][0]!=q)
    {
    	m=m+(a[o][0]-q);
    	q=a[o][0];
	}
    
		
	}
	


	

z=0;

if(count!=1)
{
	if(q!=p){
		
	

	for(f=1;f<=n;f++)
	{
	
		if(q==a[f][0])
		{
		
			if(a[o][1]>a[f][1])
			{
				
								o=f;
							
								count=count+1;
							
			}
			
			
		}
		
	}
}
}


	
	
	
}

cout<<"\n"<<ct[1];
cout<<"\n"<<ct[2];


return 0;
	
}

int small(int e[][2],int n)
{
	int s=e[1][0],o=1;
	for(int k=1;k<n+1;k++)
	{  
		if(s>e[k][0])
		{
			s=e[k][0];
			o=k;
			cout<<o;

		}
		
		if(k==n)
		{
			return o;
			}	
    }
   
    
}

int sum(int w[][2],int n)
{
	int m=0;
	for(int k=1;k<n+1;k++)
	{  
	m=m+w[k][1];
		
    }
    return m;
}

int small2(int e[][2],int n,int i,int p)
{
	int s=e[1][0]+5,o=0;
	for(int k=1;k<n+1;k++)
	{  
	
	if(k==i)
{

			continue;
	}
	else
	{
		o=k;
			return o;
		
				
		
    }

  
}
}

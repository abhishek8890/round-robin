#include<iostream>
using namespace std;
int small(int [5][2],int);
int sum(int [5][2],int);
int small2(int [5][2],int,int);
int check(int [5][2],int,int,int);

int main()
{

int rn;		
	cout<<"\nEnter the size for Round Robin:";
	cin>>rn;
	
	int r[rn][2],max=0,v=0,k,c[2],nk,ar,cc[2],u,y=0;
	
	
	for(int i=1;i<=rn;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";
	cin>>r[i][0];
	
	cout<<"\nEnter Burst timep"<<i<<":";
	cin>>r[i][1];	
		
	}
	
	//find first process to run

    
    v=small(r,rn);
    max=sum(r,rn);
    nk=r[v][0];
    
    //priority
    
    int n;
		int s,m=0,o=0,t=4;
	
	int a[1][2];
		
	cout<<"\nEnter Arrival time for p"<<3<<":";
	cin>>a[1][0];
	
	cout<<"\nEnter Burst timep"<<3<<":";
	cin>>a[1][1];	
		
		cout<<"\nEnter priority"<<3<<":";
	cin>>a[1][2];
	
	
	//find first process to run
    
    //fcfs
    
    	int fc[1][3],ct[2],p,count=0,d=0;

	cout<<"\nEnter the size of fcfs:";
	
	cout<<"\nEnter Arrival time for p"<<4<<":";
	cin>>fc[1][0];
	
	cout<<"\nEnter Burst timep"<<4<<":";
	cin>>fc[1][1];	
	
	cout<<"\nEnter priority"<<4<<":";
	cin>>fc[1][2];		
	
	
	
	if(v>a[1][0])
	{
		if(a[1][0]>fc[1][0])
		{
			d=fc[1][0];
			p=2;
		}
		else
		{
			d=a[1][0];
			p=1;
		}
		
	}
	else
	{
		d=nk;
	}
	
	//find first process to run
	
	cout<<d;
	for(int j=d;j<=30+30;j++)
	{
		cout<<"f";
		if(p==2 || p==1)
		{
			if(p==2){
			cout<<"\nfcfs"<<j;
			fc[1][1]--;
			ct[1]=j+2;
			if(fc[1][1]==0)
			{
				cout<<"\nrr";
				ct[1]=j;
				p=1;
				if(j<a[1][0])
				{
				j=a[1][0];
			}
			}
		}
		else
		{
			cout<<"\nssda"<<j;
			a[1][1]--;
		//	cc[1]=j+3;
			if(a[1][1]==0)
			{cout<<"\nr"<<fc[1][1];;
				cc[1]=j;
				p=2;
				if(j<fc[1][0])
				{
				j=fc[1][0];
			}
			}
			
		}
		}
		
		if(a[1][1]==0 && fc[1][1]==0)
	{cout<<"\nl";
		break;
	}
		
		if(r[1][0]==j ||r[2][0]==j)
		{
			cout<<"y";
		
			if((fc[1][1]>r[1][1]) || (fc[1][1]>r[2][1]) || (a[1][1]>r[1][1]) || (a[1][1]>r[2][1]))
			{
			
			
			for(int k=j;k<=max+j+10;k=k+t)
			{
				int x=0;
				cout<<"g";
					if(r[v][1]==0)
	{
		cout<<"c";
		u=v;
			cout<<v<<k;
		c[v]=k;
		if(y==0)
		{cout<<"small";
				v=small2(r,rn,u);
				y=1;
				x=1;
				
		}
		
		cout<<v;
		
	}
			
			if(r[v][1]==1)
			{
				u=v;
				r[v][1]=r[v][1]-1;
				cout<<"\n1."<<v<<k;
				c[v]=k+1;
				t=1;
				if(x==0)
				{
				
					v=small2(r,rn,u);
					y=1;
					x=1;
				}
				
			}
			if(r[v][1]==2)
			{
				u=v;
				r[v][1]=r[v][1]-2;
				cout<<"\n2."<<v<<k;
				c[v]=k+2;
			t=2;
					if(x==0)
				{
				
					v=small2(r,rn,u);
					y=1;
					x=1;
				}
				
			}
			if(r[v][1]==3)
			{
				u=v;
				r[v][1]=r[v][1]-3;
				cout<<"\n3."<<v<<k;
				c[v]=k+3;
				t=3;
				if(x==0)
				{
				
					v=small2(r,rn,u);
					y=1;
					x=1;
				}
			}
			if(x==0){
			
			r[v][1]=r[v][1]-4;
			t=4;
			c[v]=k+4;
			
		}
	

cout<<"\n"<<k<<v<<r[v][1];
/*
if(x==0){
c[v]=k;
}*/
	if(r[1][1]==0 && r[2][1]==0)
	{cout<<"\nd";
		if(a[1][0]>fc[1][0])
		{
			p=2;
			j=fc[1][0];
		}
		else{
			p=1;
			j=a[1][0];
		}
		
		break;
	}
if(j==0)
{
		cout<<"j";
	ar=check(r,v,k,rn);	
if(ar!=0)
{
	v=ar;
	j=j+1;
}
}
			}
		
		}
		
		
	}
		
	}
	
cout<<"\n"<<c[1];
cout<<"\n"<<c[2];

cout<<"\n"<<cc[1];
cout<<"\n"<<ct[1];
	
    
}

// Function Defination


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

int small2(int e[][2],int n,int i)
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

int check(int b[][2],int i,int nk,int n)
{
	int c,k;
	for(c=1;c<=n;c++)
	
	{
		if(c==i)
		{
			continue;
		}
		if((0<=b[c][0]) && (b[c][0]<=nk+2))
		{
			k=c;
			return k;
		}
	}
	return 0;	
}


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
	
	int r[rn][2],max=0,v=0,k,c[2],nk,ar,cc[2],u,y=0,b[rn][2];
	
	for(int i=1;i<=rn;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";
	cin>>r[i][0];
	b[i][0]=r[i][0];
	
	cout<<"\nEnter Burst timep"<<i<<":";
	cin>>r[i][1];
	b[i][1]=r[i][1];	
		
	}
	
	//find first process to run

    
    v=small(r,rn);
    max=sum(r,rn);
    nk=r[v][0];
    
    
	
	//priority queue
    
	int s,m=0,o=0,t=4,n,a[1][2],a1[2][2];
		
	cout<<"\nPriority :";
	cout<<"\nEnter Arrival time for p"<<3<<":";
	cin>>a[1][0];
	a1[1][0]=a[1][0];
	
	cout<<"\nEnter Burst timep"<<3<<":";
	cin>>a[1][1];
	a1[1][1]=a[1][1];	
		
	cout<<"\nEnter priority"<<3<<":";
	cin>>a[1][2];
	
	
	
    
    //fcfs
    
    int fc[1][3],ct[2],p,count=0,d=0,fc1[2][3];
	
	cout<<"\nFirst come First serve:";
	cout<<"\nEnter Arrival time for p"<<4<<":";
	cin>>fc[1][0];
	fc1[1][0]=fc[1][0];
	
	
	cout<<"\nEnter Burst timep"<<4<<":";
	cin>>fc[1][1];
	fc1[1][1]=fc[1][1];	
	
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
	
	
	for(int j=d;j<=30+30;j++)
	{
		if(p==2 || p==1)
		{
			if(p==2)
			{
			fc[1][1]--;
			ct[1]=j+2;
			if(fc[1][1]==0)
			    {
	
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
			a[1][1]--;
			if(a[1][1]==0)
			{
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
	{
		break;
	}
		
		if(r[1][0]==j ||r[2][0]==j)
		{
			if((fc[1][1]>r[1][1]) || (fc[1][1]>r[2][1]) || (a[1][1]>r[1][1]) || (a[1][1]>r[2][1]))
			{
			
			
			for(int k=j;k<=max+j+10;k=k+t)
			{
				int x=0;
				if(r[v][1]==0)
	{
		u=v;
		c[v]=k;
		if(y==0)
		{
				v=small2(r,rn,u);
				y=1;
				x=1;
				
		}
		
	}
			
			if(r[v][1]==1)
			{
				u=v;
				r[v][1]=r[v][1]-1;
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
	
	if(r[1][1]==0 && r[2][1]==0)
	{
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
	
cout<<"\n\n Round Robin";
int tat[5];
tat[1]=c[1]-b[1][0];
cout<<"\n Completion time p1:"<<c[1]<<"\t Turn Around Time:"<<tat[1]<<"\t Waiting time:"<<tat[1]-b[1][1];
tat[2]=c[2]-b[2][0];
cout<<"\n Completion time p2:"<<c[2]<<"\t Turn Around Time:"<<tat[2]<<"\t Waiting time:"<<tat[2]-b[2][1];


cout<<"\n\n Priority";
tat[3]=cc[1]-a1[1][0];
cout<<"\n Completion time p3:"<<cc[1]<<"\t Turn Around Time:"<<tat[3]<<"\t Waiting time:"<<tat[3]-a[1][1];

cout<<"\n\nFirst come First serve";
tat[4]=ct[1]-fc1[1][0];
cout<<"\n Completion time p4:"<<ct[1]<<"\t Turn Around Time:"<<tat[4]<<"\t Waiting time:"<<tat[4]-fc1[1][1];
	
    
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


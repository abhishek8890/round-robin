#include<iostream>

using namespace std;
int small(int [5][2],int);
int sum(int [5][2],int);
int small2(int [5][2],int,int);
int check(int [5][2],int,int,int);


int main()
{
	int n;
		int s,m=0,o=0,i,k,f,z,min,ch=-1,w=0,big=0;

	int st,ct[2],d;
	
	
	cout<<"\nEnter the size for SJF:";
	
	cin>>n;
	int a[n][2],b[n][2];
	for(i=1;i<=n;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";
	cin>>a[i][0];
	b[i][0]=a[i][0];
	
	cout<<"\nEnter Burst timep"<<i<<":";
	cin>>a[i][1];
	b[i][1]=a[i][1];	
		
	}
	
    o=small(a,n);
    m=sum(a,n);
    
    //Round Robin
    int rn;
    cout<<"\nEnter the size for Round Robin:";
	cin>>rn;
	
	int r[rn][2],max=0,v=0,t,c[2],nk,ar,r2[rn][2];
	
	
	for(int i=1;i<=n;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";
	cin>>r[i][0];
	r2[i][0]=r[i][0];
	
	cout<<"\nEnter Burst time"<<i<<":";
	cin>>r[i][1];
	r2[i][1]=r[i][1];	
		
	}
	
	 v=small(r,rn);
    max=sum(r,rn);
    
    if(a[o][0]<=r[v][0])
    {
    	
    	   //SJF process

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
		
        w=o;
		ct[o]=q;
		
		

	d=small2(a,n,o);
    o=d;
    
    if(a[o][0]!=q)
    {
    	if(r[v][0]==q)
    	{
    		
    		while(!(a[o][0]<=q))
    		{
    			if(r[v][1]==1)
    			{
    				r[v][1]=r[v][1]-1;
    				ch=check(a,w,q,n);
    				q++;
    				m++;
    				if(r[v][1]==0)
    				{
    				c[v]=q;
    					v=small2(r,rn,v);
					}
    				
				}
				
				else
				
				{
					r[v][1]=r[v][1]-2;
					ch=check(a,w,q,n);
					q=q+2;
					m=m+2;
					if(r[v][1]==0)
    				{
    				c[v]=q;
    					v=small2(r,rn,v);
					}
				}
				
				if(ch==0)
				{
					continue;
				}
    
			}
		}
		else
		{
		
    	m=m+(a[o][0]-q);
    	q=a[o][0];
	
		}
	
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
   	}
	

{
	//Round Robin process
 if(ct[1]>ct[2])
 {
 	big=ct[1];
 	if(big<r[v][0])
   	{
   		big=r[v][0];
	   }
   }
   else
   {
   	big=ct[2];
   	if(big<r[v][0])
   	{
   		big=r[v][0];
	   }
   	
	 }  


if(r[v][1]==0)
{
	t=v;
	v=small2(r,rn,t);
}


for(int p=big;p<max+big;p=p+2)
{
		r[v][1]=r[v][1]-2;
		
	if(r[v][1]==0 || r[v][1]==-1)
	{
		t=v;
		if(r[v][1]==-1)
		{
		c[v]=p+1;
	}
	else
	{
		c[v]=p+2;
	}
		v=small2(r,rn,t);
			max=max+(r[v][0]-p);
    	p=r[v][0];
		
	}
	
	if(r[1][1]==0 && r[2][1]==0)
	{
		break;
	}
	
	ar=check(r,v,p,rn);	
if(ar!=0)
{
	v=ar;
}

}
}

cout<<"\n SJF";
int tat[5];
tat[1]=ct[1]-b[1][0];
cout<<"\n Completion time p1:"<<ct[1]<<"\t Turn Around Time:"<<tat[1]<<"\t Waiting time:"<<tat[1]-b[1][1];
tat[2]=ct[2]-b[2][0];
cout<<"\n Completion time p2:"<<ct[2]<<"\t Turn Around Time:"<<tat[2]<<"\t Waiting time:"<<tat[2]-b[2][1];


cout<<"\n\n Round Robin";
tat[3]=c[1]-r2[1][0];
cout<<"\n Completion time p1:"<<c[1]<<"\t Turn Around Time:"<<tat[3]<<"\t Waiting time:"<<tat[3]-r2[1][1];
tat[4]=c[2]-r2[2][0];
cout<<"\n Completion time p2:"<<c[2]<<"\t Turn Around Time:"<<tat[4]<<"\t Waiting time:"<<tat[4]-r2[2][1];



return 0;
	
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
		if((nk-2<=b[c][0]) && (b[c][0]<=nk+2))
		{
			k=c;
			return k;
		}
	}
	return 0;	
}


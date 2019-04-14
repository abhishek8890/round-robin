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
	
	
	cout<<"\nEnter the size for SJF(Max:2):";
	
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
	if(n==1)
	{
	b[2][0]=a[2][0]=-1;
	b[2][1]=a[2][1]=-1;	
	}
	
    o=small(a,n);
    m=sum(a,n);
    
    //Round Robin
    int rn;
    cout<<"\nEnter the size for Round Robin(Max:2):";
	cin>>rn;
	
	int r[rn][2],max=0,v=0,t,c[2],nk,ar,r2[rn][2];
	
	
	for(int i=1;i<=rn;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";

	cin>>r[i][0];
	r2[i][0]=r[i][0];
	
	cout<<"\nEnter Burst time"<<i<<":";
	
	cin>>r[i][1];
	r2[i][1]=r[i][1];	
		
	}
	if(rn==1)
	{
		r2[2][0]=r[2][0]=-1;
		r2[2][1]=r[2][1]=-1;	
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
	
	if(b[2][0]==-1)
	{
		ct[2]=0;
	}
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
int tat[5],wt[5];

	
cout<<"\n SJF";

tat[1]=ct[1]-b[1][0];
wt[1]=tat[1]-b[1][1];
if(wt[1]<0)
{
	wt[1]=-(wt[1]);
	if(ct[1]<0)
	{
		ct[1]=-(ct[1]);
		ct[1]=ct[1]+wt[1];
	}
	else
	{
		ct[1]=ct[1]+wt[1];
	}
}
cout<<"\n Completion time p1:"<<ct[1]<<"\t Turn Around Time:"<<tat[1]<<"\t Waiting time:"<<wt[1];
tat[2]=ct[2]-b[2][0];
wt[2]=tat[2]-b[2][1];
if(wt[2]<0)
{
	wt[2]=-(wt[2]);
	if(ct[2]<0)
	{
		ct[2]=-(ct[2]);
		ct[2]=ct[2]+wt[2];
	}
	else
	{
		ct[2]=ct[2]+wt[2];
	}
}
cout<<"\n Completion time p2:"<<ct[2]<<"\t Turn Around Time:"<<tat[2]<<"\t Waiting time:"<<wt[2];

if(c[1]>0 && c[2]>0)
{


if(c[1]>c[2] && rn==2)
{
	
	c[1]=c[1]-2;
}
if(c[1]<c[2] && rn==2)
{
	c[2]=c[2]-2;
}
if(rn==1)
{
	c[2]=0;
}

}
cout<<"\n\n Round Robin";
tat[3]=c[1]-r2[1][0];
wt[3]=tat[3]-r2[1][1];
if(wt[3]<0)
{
	wt[3]=-(wt[3]);
	if(c[1]<0)
	{

		c[1]=-(c[1]);
		c[1]=c[1]+wt[3];
	}
	else
	{
		c[1]=c[1]+wt[3];
	}
}
else
{
	c[1]=c[1]-wt[3];
	if(c[1]<0)
	{
		c[1]=-(c[1]);
	}
	wt[3]=r2[1][1]-r2[2][1];
	if(wt[3]<0)
	{
		wt[3]=-(wt[3]);
	}
}
tat[3]=c[1]-r2[1][0];
wt[3]=tat[3]-r2[1][1];
cout<<"\n Completion time p3:"<<c[1]<<"\t Turn Around Time:"<<tat[3]<<"\t Waiting time:"<<wt[3];
tat[4]=c[2]-r2[2][0];
wt[4]=tat[4]-r2[2][1];
if(wt[4]<0)
{

	wt[4]=-(wt[4]);
	if(c[2]<0)
	{
	
		//c[2]=-(c[2]);
		c[2]=c[2]+wt[4];
	}
	else
	{
		
		c[2]=c[2]+wt[4];
	}

}
else
{
	c[2]=c[2]-wt[4];
	if(c[2]<0)
	{
		c[2]=-(c[2]);
	}
	
}
tat[4]=c[2]-r2[1][0];
wt[4]=tat[4]-r2[2][1];
cout<<"\n Completion time p4:"<<c[2]<<"\t Turn Around Time:"<<tat[4]<<"\t Waiting time:"<<wt[4];



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


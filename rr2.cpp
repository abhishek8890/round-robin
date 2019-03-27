#include<iostream>
using namespace std;
int small(int [5][2],int);
int sum(int [5][2],int);
int small2(int [5][2],int,int);
int check(int [5][2],int,int,int);

int main()
{

		
	cout<<"\nEnter the size for Round Robin:";
	cin>>rn;
	
	int r[rn][2],max=0,v=0,k,rn,c[2],nk,ar;
	
	
	for(int i=1;i<=n;i++)
	{
		
	cout<<"\nEnter Arrival time for p"<<i<<":";
	cin>>r[i][0];
	
	cout<<"\nEnter Burst timep"<<i<<":";
	cin>>r[i][1];	
		
	}
	
	//find first process to run

    
    v=small(r,rn);
    max=sum(r,rn);


nk=a[v][0];




for(int p=nk;p<=max+nk;p=p+2)
{
		r[v][1]=r[v][1]-2;
	

	if(r[v][1]==0 || r[v][1]==-1)
	{
	
		k=o;
		if(r[v][1]==-1)
		{
		c[v]=p+1;
	}
	else
	{
		c[v]=p+2;
	}
		v=small2(r,rn,k);
		
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

cout<<"\n"<<c[1];
cout<<"\n"<<c[2];



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
	
	int x=1,c,k;
	for(c=1;c<=n;c++)
	
	{
		if(c==i)
		{
			continue;
		}
		if((nk<=b[c][0]) && (b[c][0]<=nk+2))
		{
			
			k=c;
			return k;
			
	
		}
	}
	return 0;
	
	
	
}

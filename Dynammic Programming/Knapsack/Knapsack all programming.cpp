#include <iostream>
#include <conio.h>
using namespace std;
class Knapsack
{
	private:
		int **dp,n,w;
		
	public:
		Knapsack(int,int);
		
		void display();
		int knapsack_r(int*,int*,int,int);
		void knapsack_i(int*,int*,int,int);
	
	 	
};
Knapsack::Knapsack(int N,int W)
{
	n=N;
	w=W;
	
	dp=new int*[w];
	for(int i=0;i<w;i++)
	{
		dp[i]=new int(n+1);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<w;j++)
		{	
		 	dp[i][j]=0;	
		}
	}
	
	display();
}
int Knapsack::knapsack_r(int wt[],int value[],int w,int n)
{
	
	if(w==0 || n==0)
	{
		return 0;
	}
	
	
	
	if(wt[n-1]>w)
	{
		return dp[n-1][n-1]=knapsack_r(wt,value,w,n-1);
		

    }
	else
	{
 		return dp[n-1][n-1]=max(value[n-1]+knapsack_r(wt,value,w-wt[n-1],n-1),knapsack_r(wt,value,w,n-1));

	}
	
}
void Knapsack::knapsack_i(int wt[],int value[],int w, int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<w;j++)
		{
			if(wt[i-1]<=j)
			{
				dp[i][j]=max(value[i]+dp[i-1][j-wt[i-1]],dp[i][j]);
			}
			else 
			{
				dp[i][j]=dp[i][j];
			}
		}
	}
}
void Knapsack::display()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<w;j++)
		{
			cout<<dp[i][j]<<" , ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}
int main()
{
	/*
	int *wt,*value,n,w;
	cout<<"Enter the number of element : ";
	cin>>n;
	cout<<"Enter the size of Knapsack : ";
	cin>>w;
	
	wt=new int(w);
	value=new int(n);
	for(int i=0;i<n;i++)
	{
		cout<<"Weight item ("<<i+1<<") : ";
		cin>>wt[i];
		cout<<"Value  item ("<<i+1<<") : ";
		cin>>value[i];
	}
	*/
	int value[] = { 60, 100, 120 };
    int wt[] = { 1, 2, 3 };
    int  w= 5;
    int n=3,m=3;
    
    
    int choose;
    
    

	Knapsack obj(n+1,w+1);
	obj.knapsack_i(wt,value,w,n);
    cout<<endl;
    obj.display();
	
	getch();
	return 0;
}

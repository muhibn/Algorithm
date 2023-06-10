#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
class Search{
	private:
	public:
		int BinarySearch(t*,int,int,t);
		int BinaryQuizOne(t*,int,int,t,int,int);
		int binaryQuizTwo(t*,int,int,t);
		int binaryQuizThree(t*,int,int,t);		
};

template <class t>
int  Search<t>::BinaryQuizOne(t arr[],int l,int r,t key,int runTime,int size)
{
	try{
	if(runTime<size){
		runTime++;
	
	if(l<r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==key)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
			return mid;
		  
		}
		if(arr[mid]>key)
		{
			return BinaryQuizOne(arr,l,mid,key,runTime,size);
		}
		else{
			return BinaryQuizOne(arr,mid,r,key,runTime,size);
		}
	}
	}else{
		throw(runTime);
	}
	}
	catch(int rt)
	{
		cout<<"Function is in infinit loop "<<endl;
		cout<<"equal to size of array : "<<rt;
		
		cout<<endl;
	}
	
}
template <class t>
int  Search<t>::BinarySearch(t arr[],int l,int r,t key)
{
	if(l<r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==key)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
			return mid;
		  
		}
		if(arr[mid]>key)
		{
			return BinarySearch(arr,l,mid-1,key);
		}
		else{
			return BinarySearch(arr,mid+1,r,key);
		}
	}
}

template <class t>
int  Search<t>::binaryQuizTwo(t arr[],int l,int r,t key)
{
	int last=r;
	while(l<r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]<arr[mid-1])
		{
			if(arr[0]>key)
			{
				BinarySearch(arr,mid,last,key);
			}
			else
			{
				BinarySearch(arr,0,mid,key);
			}
			return 0;
		}
		else if(arr[mid]<arr[l])
		{
			r=mid+1;
		}
		else{
			l=mid-1;
		}
		
	}
}

template <class t>
int  Search<t>::binaryQuizThree(t arr[],int l,int r,t key)
{
	if(l<=r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==mid)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
		    return mid;
		}
		if(arr[mid]>mid)
		{
			
			return binaryQuizThree(arr,l,mid-1,key);
		}
		else{
			return binaryQuizThree(arr,mid+1,r,key);
		}
	}
}


int main() 
{
	int choose;
	int arr[]={-2,-1,2,3,7,52,62,72,82};
	int x=3;
	Search<int> obj;

	do{
		cout<<"\nEnter the choose \n";
		cout<<"1 for Question one without (mid-1 & mid+1)  \n";
		cout<<"2 for Question two  rotated array \n";
		cout<<"3 for Question three find arr[k]=k \n ";
		cin>>choose;
		switch(choose)
		{
			case 1 :{
					int arr[]={1,2,3,5,7,52,62,72,82};
	                int x=100;
			        int size=(sizeof(arr)/sizeof(arr[0]));
					obj.BinaryQuizOne(arr,0,size,x,0,size);
				break;
			}
			case 2  :{
					int arr[]={232,434,1,2,3,5,7,52,62,72,82};
	                 int x=3;
			         int size=(sizeof(arr)/sizeof(arr[0])); 
					 obj.binaryQuizTwo(arr,0,size,x);
				
				break;
			}
			case 3 :{
					int arr[]={0,1,1,3,5,7,52,62,72,82};
	                int x=3;
			        int size=(sizeof(arr)/sizeof(arr[0])); 
					obj.binaryQuizThree(arr,0,size,arr[0]);
				
				break;
			}
			case 0 :continue;
			 break;
			default:cout<<"wrong choose \n";
			
		}
		
	}while(choose!=0);
	
	getch();
	return 0;
	
}

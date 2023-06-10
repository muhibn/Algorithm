#include <iostream>
#include <conio.h>
using namespace std;
template <class t>
class Search{
	private:
	public:
		int linearSearch(t*,int,t key);
		int binarySearch(t*,int,int,t);
		int   minMaxSearch(t*,int);
		
};
template <class t>
int Search<t>::linearSearch(t arr[],int n,t key)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
		{
			cout<<"this element is exist in this position : "<<i<<endl;
			return i;
		}
	}
}
template <class t>
int  Search<t>::binarySearch(t arr[],int l,int r,t key)
{
	if(l<=r)
	{
		int mid=(r+l)/2;
		
		if(arr[mid]==key)
		{
			cout<<"This element is exist in this position : "<<mid<<endl;
		    return mid;
		}
		if(arr[mid]>key)
		{
			return binarySearch(arr,l,mid-1,key);
		}
		else{
			return binarySearch(arr,mid+1,r,key);
		}
	}
}
int main()
{
	int choose;
	int arr[]={1,2,3,4,5,6,7,8};
	int x=4;
	Search<int> obj;
	int size=(sizeof(arr)/sizeof(arr[0]));
	do{
		cout<<"Enter the choose \n";
		cout<<"1 for linear Search \n";
		cout<<"2 for binary search \n";
		cin>>choose;
		switch(choose)
		{
			case 1 :obj.linearSearch(arr,size,x);
			 break;
			case 2 : obj.binarySearch(arr,0,size,x);
			 break;
			default:cout<<"wrong choose \n";
			
		}
		
	}while(choose!=0);
	
	getch();
	return 0;
	
}

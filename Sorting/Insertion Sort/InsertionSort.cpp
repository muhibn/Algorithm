#include <iostream>
#include <conio.h>
#include <algorithm>

using namespace std;
template <class t>
class InsertionSort
{
	private :
	public :
		int  insertions(t *,t, int );
		void inserSortfun(t*,int);
		void display(t *,int );
		void possible_locat_i(t *,int);
		void number_comperason(t*,int);
		int insertionSortComparisons(t arr[], int size);
		void  computeAveComp();
		
};
template <class t>
void InsertionSort<t>::inserSortfun(t arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		t key=arr[i];
		int j=i-1;
		insertions(arr,key,j);
	}
}
template<class t>
int  InsertionSort<t>::insertions(t *arr,t key,int j)
{
	int comparison;
	while(arr[j]>key && j>=0)
	{
		arr[j+1]=arr[j];
		j--;
		comparison++;
	}
	arr[j+1]=key;
	return comparison;
}
template <class t>
void InsertionSort<t>::display(t arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
template <class t>
void InsertionSort<t>::possible_locat_i(t arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int j=0;
		cout<<"For  {" <<arr[i]<<"} Possible location : ";
		for( j=0;j<i+1;j++)
		{
			cout<<"["<<j<<"] , ";
		}
		cout<<"      total possible location :"<<j++<<endl;
	}
}
template <class t>
void InsertionSort<t>::number_comperason(t arr[],int n)
{
	display(arr,n);
	
	int i;
	cout<<"Enter the \"i\"  value : ";
	cin>>i;
	t key=arr[i];
	int j=i-1;
	while(arr[j]>key && j>=0)
	{
		arr[j+1]=arr[j];
		j--;
	}
	arr[j+1]=key;
	
	cout<<"Number of comperason for i th "<<key<<" is : "<<i-1;
	cout<<endl;
}



template <class t>
void InsertionSort<t>::computeAveComp() {
    int arr[] = {1, 2, 3, 4,5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int totalcomp = 0;
    int numpermut = 0;
    int arr2[4];

    do {
    	for(int i=0;i<size;i++)
    	      arr2[i]=arr[i];
    	      
    	      
    	for(int i=1;i<size;i++)
	    {
			t key=arr[i];
			int j=i-1;
		    totalcomp+=insertions(arr2,key,j);
		}
    	
    	numpermut++;
    } while (next_permutation(arr, arr + size));

    double avegcomp = totalcomp/ numpermut;
    cout<<avegcomp;
}

int main()
{
	InsertionSort<int> obj;
	
	int arr[]={1,5,6,3,4,2};
	
	int size=(sizeof(arr)/sizeof(arr[0]));
	obj.display(arr,size);
	int choose;
	do{
		cout<<endl;
		cout<<"Enter the choose \n";
		cout<<"1 for Insertion sort \n";
		cout<<"2 for possible location of i \n";
		cout<<"3 for number of comperason \n";
		cout<<"4 for averge number of computation \n";
		cout<<"5 for display the array \n";
		cout<<"0 for exit ";
		cin>>choose;
		
		switch(choose)
		{
			case  1:obj.inserSortfun(arr,size);
			  break;
			case  2:obj.possible_locat_i(arr,size);
			  break;
			case  3:obj.number_comperason(arr,size);
			  break;
			case  4: obj.computeAveComp();
			  break;
			case  5:obj.display(arr,size);
			  break;
		
			default:cout<<"Worng choose \n";
		
		}
	}while(choose!=0);
	
	getch();
	return 0;
}

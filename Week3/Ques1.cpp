#include<iostream>
using namespace std;
//Sort an array of 0,1,2's

void printArray(int arr[],int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void logic1(int array[],int n)
{
    cout<<"logic 1"<<endl;              //O(n^2)
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=i; j <n; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printArray(array,n);
}
void logic2(int array[],int n)
{
    cout<<"logic 2"<<endl;
    int max=2;
    int count[3]={0};
    int sorted[100];
    int x=0;
    for(int i=0;i<n;i++)//n                                            //O(n)
    {
        count[array[i]]++;
    }
    for(int i=1;i<=2;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--)//n
    {
        int x=(count[array[i]]=count[array[i]]-1);
        sorted[x]=array[i];
    }
    printArray(sorted,n);
}
void logic3(int arr[],int size)
{
    cout<<"logic 3"<<endl;
	int chain[3][size];
	int i=0,j=0,k=0,l;

	for(l=0;l<size;l++)//n                                                //O(n)
	{
		if(arr[l]==0)
			{
                chain[0][i]=arr[l];
                i++;
            }
		if(arr[l]==1)
			{
                chain[1][j]=arr[l];
                j++;
            }
		if(arr[l]==2)
			{
                chain[2][k]=arr[l];
                k++;
            }
	}

	for(int ct=0;ct<i;ct++)//i               //n
		arr[ct]=chain[0][ct];

	for(int ct=0;ct<j;ct++)//j
		arr[i+ct]=chain[1][ct];

	for(int ct=0;ct<k;ct++)//k
		arr[i+j+ct]=chain[2][ct];

    printArray(arr,size);
}
int main()
{
    int array[100];
    int n;
    cout<<"Enter array size : \n";
    cin>>n;


    cout<<"Enter array elements : \n";


    for(int i=0;i<n;i++)
    {
        cin>>array[i];

    }

    logic1(array,n);
    logic2(array,n);
    logic3(array,n);

    return 0;
}

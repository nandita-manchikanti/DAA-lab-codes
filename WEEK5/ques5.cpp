#include<iostream>
using namespace std;

void printarr(int array[],int n)
{
    cout<<"The merged sorted array is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void insertionsort(int arr[],int n)
{ 
    int i, key, j; 
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}
void merging1(int arr1[],int arr2[],int n1,int n2)
{
    int i=0;
    int j=0;
    int n3=n1+n2;
    int arr3[100];
    int k=0;

    while(i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j])
        {
           arr3[k++]=arr1[i++];
        }
        else
        {
            arr3[k++]=arr2[j++];
        }
    }
    while(i<n1)
    {
        arr3[k++]=arr1[i++];
    }
    while(j<n2)
    {
        arr3[k++]=arr2[j++];
    }
    printarr(arr3,n3);
}

void merging2(int arr1[],int arr2[],int n1,int n2)
{
    int arr[n1+n2];
    int i=0;
    for(i=0;i<n1;i++)
    {
        arr[i]=arr1[i];
    }
    int j=i;
    int k=0;
    for(int j=i;j<n1+n2;j++)
    {
        arr[j]=arr2[k];
        k++;
    }
    insertionsort(arr,n1+n2);
    printarr(arr,n1+n2);
}
void merging3(int arr1[],int arr2[],int m,int n)
{
    for (int i = n - 1; i >= 0; i--) 
    {
        int j, last = arr1[m - 1];
        for (j = m - 2; j >= 0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j + 1] = arr1[j];
        }
        if (j != m - 2 || last > arr2[i]) 
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
        printarr(arr1,m);
        printarr(arr2,n);

    }
    int arr[m+n];
    int i;
    for(i=0;i<m;i++)
    {
        arr[i]=arr1[i];
    }
    int j=i;
    int k=0;
    for(int j=i;j<m+n;j++)
    {
        arr[j]=arr2[k];
        k++;
    }
    printarr(arr,m+n);
}
int main()
{
    int n1;
    int n2;
    cout<<"Enter the size of first array :"<<endl;
    cin>>n1;
    int arr1[n1];
    cout<<"Enter the elements of the first array"<<endl;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of second array :"<<endl;
    cin>>n2;
    int arr2[n2];
    cout<<"Enter the elements of the second array"<<endl;
    for(int j=0;j<n2;j++)
    {
        cin>>arr2[j];
    }
    merging1(arr1,arr2,n1,n2);
    merging2(arr1,arr2,n1,n2);
    merging3(arr1,arr2,n1,n2);
    return 0;
}

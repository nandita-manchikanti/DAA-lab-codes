#include<iostream>
#include<algorithm>
using namespace std;
void heapify(int arr[], int n)
{
    int i=0;
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n);
    }
}
 
int minimumElement(int array[],int n)
{
    int i,first,second;

    first=second=array[n/2-1];
    for(i=n/2;i<n;++i)
    {
        if(array[i]<first)
        {
            second=first;
            first=array[i];
        }
    }
    cout << "The smallest element is " << first << " and second smallest element is " << second << endl;
    return 0;
}
void printarr(int array[],int n)
{
    cout<<"The sorted array is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }
}
int main()
{
    //Number of nodes
    int n;
    cout<<"Enter the size of array :";
    cin>>n;
    int heap[100];
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>heap[i];
    }
    heapify(heap,n);
    printarr(heap,n);
    minimumElement(heap, n);
    return 0;
}

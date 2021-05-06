#include<iostream>
using namespace std;
class sorting
{
    public:
        int binarySearch(int a[], int item, int low, int high);
};
class operations : public sorting{

    public:
        void insertionsort(int arr[],int n);
        void printarray(int array[],int n);
};

void operations::printarray(int array[],int n)
{
    cout<<"The sorted array is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }
}
int sorting::binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
 
    int mid = (low + high) / 2;
 
    if (item == a[mid])
        return mid + 1;
 
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}

void operations::insertionsort(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        int j=i-1;
        int selected=array[i];
        int loc=binarySearch(array,selected,0,j);
        while(j>=loc)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=selected;
    }

}
int main()
{
    operations obj;
    int n;
    cout<<"Enter the size of array :"<<endl;
    cin>>n;
    int array[n];
    cout<<"Enter the elements of array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    obj.insertionsort(array,n);
    obj.printarray(array,n);
    return 0;
}
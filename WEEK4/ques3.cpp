#include<iostream>
using namespace std;

class search
{
    public:

        int binarySearch_rec(int arr[],int,int,int);

        int ternarySearch_rec(int,int,int,int arr[]);

        int binarySearch_iter(int arr[],int,int ,int);

        int ternarySearch_iter(int l, int r, int key, int arr[]);

        int comparison(int num,int x);
};

class operations : public search{

    public:
        int array[100];
        int n;
        int key;
        void input();
        void bubblesort();
};

int search::comparison(int num,int x)
{
    if(num==x)
        return 1;

    if(num>x)
        return 2;

    if(num<x)
        return 3;
}

void operations::input()
{
    cout << "Enter the array size: ";
    cin >> n;
    cout<<"Enter Array Elements \n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the element you want to search"<<endl;
    cin>>key;
}

void operations::bubblesort()
{
  int temp,i,j;

  for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
   }
}

int search::binarySearch_rec(int arr[], int l, int r, int x)
{
    if (r >= l)

    {
        int mid = l + (r - l) / 2;

        if(comparison(arr[mid],x)==1)
            return 1;

        else if(comparison(arr[mid],x)==2)
            return binarySearch_rec(arr, l, mid - 1, x);

        else if(comparison(arr[mid],x)==3)
            return binarySearch_rec(arr, mid + 1, r, x);
    }

    return -1;
}

int search::binarySearch_iter(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if(comparison(arr[mid],x)==1)
            return 1;

        else if(comparison(arr[mid],x)==3)
            l = mid + 1;

        else if(comparison(arr[mid],x)==2)
            r = mid - 1;
    }
    return -1;
}

int search::ternarySearch_rec(int l, int r, int key, int arr[])
{
    if (r >= l)
    {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if(comparison(arr[mid1],key)==1)
            return 1;

        if(comparison(arr[mid2],key)==1)
            return 1;

        if(comparison(arr[mid1],key)==2)
        {
            return ternarySearch_rec(l, mid1 - 1, key, arr);
        }
        else if(comparison(arr[mid2],key)==3)
        {
            return ternarySearch_rec(mid2 + 1, r, key, arr);
        }
        else
        {
            return ternarySearch_rec(mid1 + 1, mid2 - 1, key, arr);
        }
    }

    return -1;
}

int search::ternarySearch_iter(int l, int r, int key, int arr[])
{
    while (r >= l) {

        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        if(comparison(arr[mid1],key)==1)
            return 1;

        if(comparison(arr[mid2],key)==1)
            return 1;

        else if(comparison(arr[mid1],key)==2)
        {
            r = mid1 - 1;
        }
        else if(comparison(arr[mid2],key)==3)
        {
            l = mid2 + 1;
        }
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}
int main()
{
    operations obj;
    obj.input();
    obj.bubblesort();

    if(obj.binarySearch_rec(obj.array,0,obj.n-1,obj.key)==1)
        cout<<"Binary search recursive - Element is present"<<endl;
    else
        cout<<"Binary search recursive - Element is not present"<<endl;

    if(obj.binarySearch_iter(obj.array,0,obj.n-1,obj.key)==1)
        cout<<"Binary search iterative - Element is present"<<endl;
    else
        cout<<"Binary search iterative - Element is not present"<<endl;

    if(obj.ternarySearch_rec(0,obj.n-1,obj.key,obj.array)==1)
        cout<<"Ternary search recursive - Element is present"<<endl;
    else
        cout<<"Ternary search recursive - Element is not present"<<endl;

    if(obj.ternarySearch_iter(0,obj.n-1,obj.key,obj.array)==1)
        cout<<"Ternary search iterative - Element is present"<<endl;
    else
        cout<<"Ternary search iterative - Element is not present"<<endl;
}



#include<iostream>
#include<time.h>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;
int choice;

class sorting
{
    public:
        void insertionsort(int arr[],int l,int r);
        void selectionsort(int arr[],int n);
        void bubblesort(int arr[],int n);
};

class operations : public sorting{

    public:
        void merge(int arr[],int l,int m ,int r);
        void mergesort(int arr[],int l,int r);
        void check(int  arr[]);
};

void sorting::insertionsort(int arr[],int l,int r)
{  
    int   i, key, j;  
    for (i = l+1; i <=r; i++) 
    {  
        key = arr[i];  
        j = i - 1;  

        while (j >= l && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
} 

void sorting::selectionsort(int array[],int n)
{
     int min,i,j,temp;
     for (i=0;i<=n-2;i++)
     {
         min=i;
         for(j=i+1;j<=n-1;j++)
         {
             if(array[j]<array[min])
                min=j;
         }
         temp=array[i];
         array[i]=array[min];
         array[min]=temp;
     }
} 

void sorting::bubblesort(int array[],int n)
{
  int temp,i,j;
  for(i = 0; i < n-1; i++)
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

void operations::merge(int arr[],int l,int m ,int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
 
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
 
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        }
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void operations::mergesort(int arr[],int l,int r)
{
    if(l-r<=20)
    {
        if(choice==1)
            insertionsort(arr,l,r);
        else if(choice==2)
            selectionsort(arr,r-l+1);
        else
            bubblesort(arr,r-l+1);
    }
    else
    {
        int mid1=l+(r-l)/3;
        int mid2=l+2*((r-l)/3);

        mergesort(arr,l,mid1);
        mergesort(arr,mid1+1,mid2);
        mergesort(arr,mid2+1,r);

        merge(arr,l,mid1,mid2); //n1+n2-1
        merge(arr,l,mid2,r); //n1+n2-1+n3-1
    }

}

void operations::check( int  arr[])
{  int   count=0;
    for( int   i=1;i<1000;i++)
        if(arr[i]<arr[i-1])
            count++;
    if(count==0)cout<<"correct"<<endl;
    else cout<<"wrong";       
}

int main()
{
    operations obj;
    int array[1000];
    srand(time(0));
    clock_t a;
    a=clock();
    for(int i=0;i<1000;i++)
    {
        array[i]=rand();
    }
    choice=1;
    obj.mergesort(array,0,1000-1);
    obj.check(array);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for merge+insertion sorting.\n",a,((float)a)/CLOCKS_PER_SEC);

    choice=2;
    obj.mergesort(array,0,1000-1);
    obj.check(array);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for merge+selection sorting.\n",a,((float)a)/CLOCKS_PER_SEC);

    choice=3;
    obj.mergesort(array,0,1000-1);
    obj.check(array);
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for merge+bubble sorting.\n",a,((float)a)/CLOCKS_PER_SEC);
    return 0;
}
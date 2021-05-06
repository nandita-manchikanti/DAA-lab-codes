#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void logic1(int array[],int n)
{
    cout<<"The duplicate elements are :\n";

    int i,j;

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j<n ;j++)
        {
            if(array[j] == array[i])
            {
                cout<<array[j]<<" ";
            }
        }
    }
}

void logic2(int array[],int n)
{
    int i;
    int maxnum=array[0];

    for(i=0;i<n;i++)
    {
       if(maxnum < array[i])
       {
           maxnum=array[i];
       }
    }

    int minnum=array[0];

    for(i=0;i<n;i++)
    {
       if(minnum > array[i])
       {
           minnum=array[i];
       }
    }

    int range = maxnum - minnum + 1;
    int frequency[100]={0};

    for (int i = 0; i < n ; i++)
    {
        frequency[array[i]-minnum]++;
    }

    cout<<"The duplicate elements are";
    for(int i=0;i<range;i++)
    {
        if(frequency[i]>1)
        {
            cout<<i+minnum<<",";
        }
    }
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
    return 0;
}

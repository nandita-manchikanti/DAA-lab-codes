#include <iostream>
#include<bits/stdc++.h>
#include<array>

using namespace std;

class ArrayOperation
{
public:
    int array[100];
    int n;
    int arrayindex=10;
    int maxnum=0;

    void input();
    void findmax1();
    int findmax2(int *,int ,int );
    void findmax3(int *,int);
};

void ArrayOperation::input()
{
    cout << "Enter the array size: ";
    cin >> n;
    cout<<"Enter Array Elements \n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
}

void ArrayOperation::findmax1()//Finding linearly
{
    int i;
    int maxnum1=array[0];
    for(i=0;i<n;i++)
    {
       if(maxnum1 < array[i])
       {
           maxnum1=array[i];
       }
    }
    cout<<"The MAXIMUM element in the array is by method 1:"<<maxnum1<<endl;
}

int ArrayOperation::findmax2(int *array,int l,int r)//Divide and conquer
{
    if(l==r)
    {
        return array[l];
    }
    int m=(l+r)/2;
    int u=findmax2(array,l,m);
    int v=findmax2(array,m+1,r);
    return u>v?u:v;
}

/*void ArrayOperation::findmax3(int array[],int n)
{
    if(n==1)
    {
        return array[0];
    }
    return max(array[n-1],findmax(array,n-1));
}*/

int main()
{
    ArrayOperation maximum;
    maximum.input();
    maximum.findmax1();
    cout<<"The MAXIMUM element in the array is by method 2:"<<maximum.findmax2(maximum.array,0,maximum.n-1)<<endl;
    //maximum.findmax3();
    return 0;
}

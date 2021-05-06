#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//n*2^n

void sumOfSubsets(vector<int> set,int n,int total)
{
    int x[set.size()];
    int j=set.size()-1;

    //Binary number
    while(n>0)
    {
        x[j]=n%2;
        n=n/2;
        j--;
    }

    int sum=0;
    for(int i=0;i<set.size();i++)
    {
        if(x[i]==1)
        {
            sum=sum+set[i];
        }
    }

    if(sum==total)
    {
        for(int i=0;i<set.size();i++)
        {
            if(x[i]==1)
            {
                cout<<set[i]<<",";
            }
        }
        cout<<endl;
    }
}
void findsubsets(vector<int> array,int sum,int n)
{
    int x=pow(2,n);

    for(int i=0;i<x;i++)
    {
        sumOfSubsets(array,i,sum);
    }
}

int main()
{
    vector<int> array;
    int n;
    cout<<"Enter array size : \n";
    cin>>n;
    int input;
    cout<<"Enter array elements : \n";
    for(int i=0;i<n;i++)
    {
        cin>>input;
        array.push_back(input);
    }
    int sum;
    cout<<"Enter the sum:";
    cin>>sum;
    findsubsets(array,sum,n);
}

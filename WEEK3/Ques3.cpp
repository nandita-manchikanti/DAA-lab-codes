#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//Bitmasking method
int sumOfSubsets(vector<int> set,int n,int total)
{
    int x[set.size()];
    int j=set.size()-1;

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
        cout<<"Yes there exists an Subset whose sum is k"<<endl;
        return 0;
    }
    return 1;
}
int findsubsets(vector<int> array,int sum,int n)
{
    int x=pow(2,n);
    for(int i=0;i < x ;i++)
    {
        if(sumOfSubsets(array,i,sum)==0)
        {
            return 0;
        }
    }
    return 1;
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
    if(findsubsets(array,sum,n)==1)
    {
        cout<<"There does not exist a subset with the given sum "<<endl;
    }
}


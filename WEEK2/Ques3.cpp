#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void pattern1(int n)
{
    cout<<"Pattern-1"<<endl;
    int i;
    int j;

    for(i=n;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void pattern2(int n)
{
    cout<<"Pattern-2"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=i)
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void pattern3(int n)
{
    cout<<"Pattern-3"<<endl;
    int i;
    int j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int pattern4(int n)
{
    cout<<"Pattern-4"<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=n+1-i)
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}

void pattern5(int n)
{
    cout<<"Pattern 5"<<endl;
    int i;
    int j;

    int maxrows;
    if(n%2==0 )
        maxrows=n/2;
    else
        maxrows=(n/2)+1;

    for(i=1;i<=maxrows;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j>=i && j<=n-i+1)
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"\n";
    }

    for(i=n/2;i>=1;i--)
    {
        for(j=1;j<=n;j++)
        {
            if(j>=i && j<=n-i+1)
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
}



int main()
{
    int n;
    int p;
    cout<<"Enter a number : ";
    cin>>n;

    pattern1(n);
    pattern2(n);
    pattern3(n);
    pattern4(n);
    pattern5(n);
    return 0;
}

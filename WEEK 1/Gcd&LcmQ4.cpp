#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class numOperation
{

public:
    void input();
    int gcd1(int,int);
    void gcd_lcm(int,int);
    int gcd3(int,int);
    int lcm1(int,int);
    int lcm2(int,int);
};

//Recursive Function to find gcd using euclidian algorithm
int numOperation::gcd1(int a,int b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a==b)
        return a;
    if(a>b)
        return gcd1(a-b,b);
    else
        return gcd1(a,b-a);
}

//Function to find gcd of two numbers using while loop
void numOperation::gcd_lcm(int a,int b)
{
    int arrayA[100]={0};
    int arrayB[100]={0};
    int gcd=1;

    int j=0;
    int k=0;

    int i;
    for(i=2;a>1;i++)
    {
        while(a%i==0)
        {
            arrayA[j]=i;
            j++;
            a=a/i;
        }
    }

    for(i=2;b>1;i++)
    {
        while(b%i==0)
        {
            arrayB[k]=i;
            k++;
            b=b/i;
        }
    }

    int m=0;
    int n=0;

    while(m<j && n<k)
    {
        if(arrayA[m]<arrayB[n])
        {
            m++;
        }
        else if(arrayB[n]<arrayA[m])
        {
            n++;
        }
        else
        {
            gcd=gcd*arrayB[n];
            m++;
            n++;
        }
    }
    cout<<"GCD by method 2 is : "<<gcd<<endl;

    m=0;n=0;
    int lcm=1;
    while(m<j && n<k)
    {
       if(arrayA[m]<arrayB[n])
       {
           lcm=lcm*arrayA[m];
           m++;
       }
       else if(arrayA[m]>arrayB[n])
       {
           lcm=lcm*arrayB[n];
           n++;
       }
       else
       {
           lcm=lcm*arrayA[m];
           m++;
           n++;
       }
    }
    if(m==j)
    {
        while(n<k)
        {
            lcm=lcm*arrayB[n];
            n++;
        }
    }
    else
    {
        while(m<j)
        {
            lcm=lcm*arrayA[m];
            m++;
        }
    }

    cout<<"LCM by method 1 is : "<<lcm<<endl;
}

//Function to find gcd
int numOperation::gcd3(int a,int b)
{
    int gcd=0;
    for(int i=1;i<=a && i<=b;i++)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
        }
    }
    cout<<"GCD by method 3 is : "<<gcd<<endl;
    return gcd;
}

int numOperation::lcm1(int a,int b)
{
    int gcd=0;
    for(int i=1; i<=a && i<=b; ++i)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
        }
    }

    int lcm=(a*b)/gcd;
    cout<<"LCM by method 2 is : "<<lcm<<endl;
    return lcm;
}
int numOperation::lcm2(int a,int b)
{

    int max;
    // maximum number between a and b is stored in min
    max = (a > b) ? a : b;

    while (1) {
        if (max % a == 0 && max % b == 0)
        {
            cout<<"LCM by method 3 is : "<<max<<endl;
            break;
        }
        ++max;
    }
    return 0;
}

int main()
{
    int a;
    int b;

    start:
    cout<<"Enter the first number  : ";
    cin>>a;
    cout<<"Enter the second number : ";
    cin>>b;
    if(a<=0||b<=0)
    {
        cout<<"Enter only positive numbers \n";
        goto start;
    }

    numOperation ans;

    cout<<"GCD by method 1 is : "<<ans.gcd1(a,b)<<endl;
    ans.gcd3(a,b);
    ans.gcd_lcm(a,b);
    ans.lcm1(a,b);
    ans.lcm2(a,b);
    return 0;
}


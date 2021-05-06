#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<chrono>
#define size 10000
using namespace std;
using namespace std::chrono;

int i=0;

int logic1(int array[])
{
    cout<<i;
    int k=1;
    if(i<=1)
    {
        if(array[0]==-1)
            cout<<"Element found at index  0"<<endl;
        else
            return -1;
    }
    else
    {
        while(k<i-1)
        {
            if(array[k] == -1)
            {
                printf("Element found at index %d \n",k);
                break;
            }
            else
                k++;
        }
        return -1;
    }
    return 0;
}

int logic2(int a[])
{
    if(i<=1)
    {
        if(a[0]==-1)
            {
                cout<<"Element found at index  0"<<endl;
                return 0;
            }
        else
            return-1;
    }
    if(a[i-1]!=-1)
    {
        return -1;
    }
    int beg=0;
    int end=i-1;
    while(beg < end)
    {
        int mid =(beg+end)/2;

        if(a[mid]>0 && a[mid+1]<0)
        {
            cout<<"Element found at index "<<mid+1<<endl;
            break;
        }
        else if(a[mid]<0 && a[mid-1]>0)
        {
            cout<<"Element found at index "<<mid<<endl;
            break;
        }
        else if(a[mid]==-1)
        {
            end = mid-1;
        }
        else
            beg = mid+1;
    }
    return 0;
}

int arr3(int array[],int start)
{
    if(i<=1)
    {
        if(array[0]==-1)
            return 0;
        else
            return -1;
    }
    if(array[i-1]!=-1)
    {
        return -1;
    }
    int temp;
    for(int p=0;pow(2,p)<10000;p++)
    {
        temp=(int)pow(2,p)+start;
        if(array[temp] == -1 && array[temp-1] != -1)
        {
            return temp;
        }
        if(array[temp] == -1)
        {
            return(arr3(array,(int)pow(2,p-1)));
        }
    }
}

int main()
{
    ofstream myfile;
    myfile.open("Ques2.csv");

    clock_t a,b,c;
    char temp;
    int array[5000]={-1};

    while(1)
    {
        scanf("%d%c",&array[i++],&temp);
        if(temp=='\n')
            break;
    }

    a=clock();

    int l1=logic1(array);
    if(l1 == -1)
    {
        cout<<"Element not present"<<endl;
    }
    a=clock()-a;
    printf ("It took me %d clicks (%f seconds) for logic 1.\n",a,((float)a)/CLOCKS_PER_SEC);
    myfile<<((float)a)/CLOCKS_PER_SEC<<endl;



    b=clock();
    int l2=logic2(array);
    if(l2==-1)
    {
        cout<<"Element not present"<<endl;
    }
    b=clock()-b;
    printf ("It took me %d clicks (%f seconds) for logic 2.\n",b,((float)b)/CLOCKS_PER_SEC);
    myfile<<((float)b)/CLOCKS_PER_SEC<<endl;



    c=clock();
    int logic3=arr3(array,0);
    if(logic3==-1)
    {
        cout<<"Element not present"<<endl;
    }
    else
    {
        cout<<"Element found at index "<<logic3<<endl;
    }
    c=clock()-c;
    printf ("It took me %d clicks (%f seconds) for logic 3.\n",c,((float)c)/CLOCKS_PER_SEC);
    myfile<<((float)c)/CLOCKS_PER_SEC<<endl;
    return 0;
}


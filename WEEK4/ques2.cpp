#include<iostream>
using namespace std;

class findneg
{
    public:
        int way_2(int array[],int l,int r);
        int way_3(int array[],int l,int r);
};

class operations : public findneg{

    public:
        int array[100];
        int n;
        void input();
};

void operations::input()
{
    cout << "Enter the array size: ";
    cin >> n;

    cout<<"Enter Array Elements \n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
}

int findneg::way_2(int array[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        return (way_2(array,l,m)+ way_2(array,m+1,r));
    }
    else
    {
        if(array[l]<0)
            return 1;
        else
            return 0;
    }
}

int findneg::way_3(int array[],int l,int r)
{
    if(l >= r && array[l]>=0)
    {
        return 0;
    }
    else if(l==r && array[l]<0)
    {
        return 1;
    }

    int mid1 = l +((r-l)/3);
    int mid2 = r -((r-l)/3);

    return way_3(array,l,mid1)+ way_3(array,mid1+1,mid2)+ way_3(array,mid2+1,r);
}

int main()
{
    operations obj;
    obj.input();
    cout<<"ans:"<<obj.way_2(obj.array,0,obj.n)<<endl;
    cout<<"ans:"<<obj.way_3(obj.array,0,obj.n)<<endl;
}



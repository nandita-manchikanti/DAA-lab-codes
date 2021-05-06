#include<iostream>
using namespace std;


class findmax
{
    public:
        int way_1findmax(int array[],int n);
        int way_2findmax(int array[],int l,int r);
        int way_3findmax(int array[],int l,int r);
        void way_kfindmax(int array[],int l,int r,int &max,int k);

};

class operations : public findmax{

    public:
        int array[100];
        int n;
        int k;
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

    again:
    cout<<"Number of parts the array should be divided into(k<n) : ";
    cin >> k;
    if(k>n)
    {
        goto again;
    }
}

int findmax::way_1findmax(int array[],int n)
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
    return maxnum;
}

int findmax::way_2findmax(int array[],int l,int r)
{
    if(l==r)
    {
        return array[l];
    }
    int m=(l+r)/2;
    int u=way_2findmax(array,l,m);
    int v=way_2findmax(array,m+1,r);
    return u>v?u:v;
}

int findmax::way_3findmax(int array[],int l,int r)
{
    if(l==r)//size is 1
    {
        return array[l];
    }
    if(r==l+1)//size is 2
    {
        if(array[l]>array[r])
        {
            return array[l];
        }
        else
        {
            return array[r];
        }
    }
    if(r==l+2)
    {
        return (  array[l] > array[l+1] ? ( array[l] > array[r] ? array[l] : array[r]) : (array[l+1] > array[r] ? array[l+1] : array[r]) );
    }

    int mid1 = l + ((r - l) / 3);
	int mid2 = l + 2 * ((r - l) / 3);

    int max1=way_3findmax(array,l,mid1);
    int max2=way_3findmax(array,mid1+1,mid2);
    int max3=way_3findmax(array,mid2+1,r);

    return (  max1 > max2 ? ( max1 > max3 ? max1 : max3) : (max2 > max3 ? max2 : max3) );

}

void findmax::way_kfindmax(int array[],int l,int r,int &max,int k)
{
    int j;
    if(r-l<=k-1)
    {
        for(j=l;j<=r;j++)
        {
            if(max < array[j])
            {
                max=array[j];
            }
        }
        return;
    }

    int mid[k-1],i;
    mid[0]=l+(r-l)/k;
    for(i = 1;i<k-1;i++)
    {
        mid[i]=mid[i-1]+(r-l)/k;
    }

    way_kfindmax(array,l,mid[0],max,k);
    for(int i=0;i<k-2;i++)
    {
        way_kfindmax(array,mid[i]+1,mid[i+1],max,k);
    }
    way_kfindmax(array,mid[k-2]+1,r,max,k);
}
int main()
{
    operations obj;
    obj.input();
    int max;
    cout<<"Maximum(1way)"<<obj.way_1findmax(obj.array,obj.n)<<endl;
    cout<<"Maximum(2way)"<<obj.way_2findmax(obj.array,0,obj.n-1)<<endl;
    cout<<"Maximum(3way)"<<obj.way_3findmax(obj.array,0,obj.n-1)<<endl;
    obj.way_kfindmax(obj.array,0,obj.n-1,max,obj.k);
    cout<<"Maximum(kway)"<<max<<endl;
}


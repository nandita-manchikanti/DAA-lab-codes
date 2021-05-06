#include <iostream>
#include<math.h>
using namespace std;

class ArrayOperation
{
    int num;
public:
    void input();
    void primeFactors();
};

void ArrayOperation::input()
{
    cout<<"Enter the number : ";
    cin>>num;

}
void ArrayOperation::primeFactors()
{
    if(num<=1)
    {
        cout<<" It  has no prime factors !"<<endl;
    }
    int i;
    for(i=2;num>1;i++)
    {
        while(num%i==0)
        {
            cout<<i<<" ";
            num=num/i;
        }
    }
    cout<<"\n";
}

int main()
{
    ArrayOperation obj;
    obj.input();
    obj.primeFactors();
    return 0;
}


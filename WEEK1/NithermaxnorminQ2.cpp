#include <iostream>
using namespace std;

class ArrayOperation
{
    int array[1000];
    int n;

public:
    void arrayinput();
    void removeDuplicates();
    void notMinMax();
};

void ArrayOperation::arrayinput()
{
    cout<<"Enter the size of array : ";
    cin>>n;
    cout<<"Enter Array Elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
}
void ArrayOperation::removeDuplicates()
{
    int i,j,k;
    int counteri=0;
    int counterj=0;
    for(i = 0; i < n; i++)
    {   counteri++;
        for(j = i+1; j < n; )
        {
            counterj++;
             /* If any duplicate found */
            if(array[j] == array[i])
            {
                /* Delete the current duplicate element */
                for(k = j; k < n; k++)
                {
                    array[k] = array[k+1];
                }
                /* Decrement size after removing duplicate element */
                n--;
            }
            /* If shifting of elements occur then don't increment j */
            else
            {
                j++;
            }
        }
    }
    cout<<"count"<<counteri;
    cout<<"count j"<<counterj;
}
void ArrayOperation::notMinMax()
{
    if(n<=2)
    {
        cout<<"No number other than min or max !"<<endl;
    }
    else
    {
        if((array[0]<array[1] && array[1]<array[2]) || (array[2]<array[1]  && array[1]<array[0]))
        {
            cout<<"The number is : "<<array[1];
        }
        else if((array[1]<array[0] && array[0]<array[2]) || (array[2]<array[0] && array[0]<array[1]))
        {
            cout<<"The number is : "<<array[0];
        }
        else
        {
            cout<<"The number is : "<<array[2];
        }
    }
}
//Choose the first three numbers and pick the middle element of the three elements
//If there are duplicates then we might have to remove the duplicates
int main()
{
    ArrayOperation random;
    random.arrayinput();
    random.removeDuplicates();
    random.notMinMax();
    return 0;
}

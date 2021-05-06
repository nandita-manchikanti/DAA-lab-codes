#define COINS 9
#define MAX 20
#include <bits/stdc++.h>
using namespace std;

int coins[COINS] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };

void findMin(int cost)
{
    int coinList[MAX] = { 0 };
    int i, k = 0;
 
    for (i = COINS - 1; i >= 0; i--) 
    {
        while (cost >= coins[i])
        {
            cost = cost - coins[i];
            coinList[k++] = coins[i];
        }
    }
 
    for (i = 0; i < k; i++)
    {
        cout<<coinList[i]<<" ";
    }
    return;
}

int main()
{
	int n ;
    cout<<"Enter the number you want change for :"<<endl;
    cin>>n;
	cout << "Following is minimal number of change for "<< n << ":" <<endl;
	findMin(n);
	return 0;
}

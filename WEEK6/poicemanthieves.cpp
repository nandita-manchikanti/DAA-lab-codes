#include <iostream>
#include <vector>
#include <cmath>
  
using namespace std;
//O(n)
//We can observe that thinking irrespective of the policeman and focusing on just the allotment works
// Returns maximum number of thieves that can be caught.

int policeThief(char arr[], int n, int k)
{
    int res = 0;
    vector<int> thief;
    vector<int> police;
  
    // store indices in the vector
    for (int i = 0; i < n; i++) 
	{
        if (arr[i] == 'P')
            police.push_back(i);
        else if (arr[i] == 'T')
            thief.push_back(i);
    }   
  
    // track lowest current indices of thief: thief[l], police: police[r]
    int l = 0, r = 0;
    while (l < thief.size() && r < police.size()) {
  
        // can be caught
        if (abs(thief[l] - police[r]) <= k) 
		{
            res++;
            l++;
            r++;
        }
        // increment the minimum index
        else if (thief[l] < police[r])
            l++;
        else
            r++;
    }
  
    return res;
}
  
// Driver program
int main()
{
    int k, n;
    char arr1[100];
	cout<<"Enter the string of P's and T's : ";
	cin>>arr1;
	cout<<"Enter K :";
	cin>>k;
    n = sizeof(arr1) / sizeof(arr1[0])-1;
    cout << "Maximum thieves caught: "<< policeThief(arr1, n, k) << endl;

    return 0;
}
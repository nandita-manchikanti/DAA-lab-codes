//Find maximum height pyramid from the given array of objects
//Greedy is placing lowest box on the top

//Given n objects, with each object has width wi. We need to arrange them in a pyramidal way such that : 
//Total width of ith is less than (i + 1)th.
//Total number of objects in the ith is less than (i + 1)th.
 
#include<bits/stdc++.h>
using namespace std;

int maxLevel(int boxes[], int n)
{
	sort(boxes, boxes + n);

	int ans = 1;

	int prev_width = boxes[0];
	int prev_count = 1;

	int curr_count = 0;
	int curr_width = 0;

	for(int i=1; i<n; i++)
	{
		curr_width += boxes[i];
		curr_count += 1;

		if (curr_width > prev_width && curr_count > prev_count)
		{
			prev_width = curr_width;
			prev_count = curr_count;

			curr_count = 0;
			curr_width = 0;

			ans++;
		}
	}
	return ans;
}

int main()
{
	int boxes[100];
    int n;
    cout<<"Enter the number of boxes ";
    cin>>n;
	cout<<"Enter the box width of values :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>boxes[i];
    }
	cout << maxLevel(boxes, n) << endl;
	return 0;
}

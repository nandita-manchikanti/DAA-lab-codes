#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

class sorts
{
	public:	
	int swapping(int *xp, int *yp)
    {      
        int temp = *xp;  
        *xp = *yp;  
        *yp = temp;  
    }
    
	void bubble_sort(int arr[], int size)  
    {  
        int a, b;  
        for (a = 0; a < size-1; a++)
		{
			for (b = 0; b < size-a-1; b++) 
			{
				if (arr[b] > arr[b+1]) 
				{
					swapping(&arr[b], &arr[b+1]);
				} 
			}   
		}      
    } 
	
	void insertion_sort(int arr[], int size) 
    { 
        int i, key, j; 
        for (i = 1; i < size; i++)
        {    
            key = arr[i]; 
            j = i - 1; 
            
            while (j >= 0 && arr[j] > key)
            { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    }
	
	void selection_sort(int arr[], int size)  
    {  
        int i, j, min_idx;   
        for (i = 0; i < size-1; i++)  
        {    
            min_idx = i;  
            for (j = i+1; j < size; j++)
			{
				if (arr[j] < arr[min_idx])  
                min_idx = j; 
			}   
            swapping(&arr[min_idx], &arr[i]);  
        }   
    }  
		
}s;

class logics : public sorts
{
	public:
	int logic1(int arr1[],int arr2[],int size1,int size2)
    {
	    int arr3[100];
	    int i,j;
	    for(i=0;i<size1;i++)
	    {
		    arr3[i]=arr1[i];
	    }
	
	    for(i=size1,j=0 ; i<size1+size2; i++,j++)
        {
            arr3[i] = arr2[j];
        }
    
	    selection_sort(arr3,size1+size2);
	
        for(int i=0;i<size1+size2;i++)
        {
    	    cout<<arr3[i]<<"\t";
	    }
    }

    int logic2(int arr1[],int arr2[],int size1,int size2)
    {
	    int i = 0, j = 0, k = 0;
	    int arr3[100];
 
        while (i<size1 && j <size2)
        {
           if (arr1[i] < arr2[j])
           {
        	    arr3[k] = arr1[i];
        	    i++;
		   }
           else
           {
        	    arr3[k] = arr2[j];
        	    j++;
		   }
		   k++;
       }
 
        while (i < size1)
        {
    	    arr3[k] = arr1[i];
    	    k++;
    	    i++;
	    }
 
        while (j < size2)
        {
    	    arr3[k] = arr2[j];
    	    k++;
		    j++;
	    }
	
        for(int i=0;i<size1+size2;i++)
        {
    	    cout<<arr3[i]<<"\t";
	    }
    }

    int logic3(int arr1[],int arr2[],int size1,int size2)
    {    
	    int arr3[100];
	    int p,a;
        for (int i = size2 - 1; i >= 0; i--) 
        {
            int j, last = arr1[size1 - 1];
            for (j = size1 - 2; j >= 0 && arr1[j] > arr2[i]; j--)
            {
        	    arr1[j + 1] = arr1[j];
		    }
 
            if (j != size1 - 2 || last > arr2[i]) 
            {
                arr1[j + 1] = arr2[i];
                arr2[i] = last;
            }
        }
    
        for(int k=0;k<size1;k++)
	    {
		    arr3[k]=arr1[k];
	    }
	
	    for(p=size1, a=0 ; p<size1+size2 ; p++,a++)
        {
            arr3[p] = arr2[a];
        }
    
        for(int i=0;i<size1+size2;i++)
        {
    	    cout<<arr3[i]<<"\t";
	    }
   }		
}l;

int main() 
{ 
    int size1,size2;
    int i;
    int arr1[100];
	int arr2[100];
    
    cout<<"Enter the size of the array1: ";
    cin>>size1;
    
    cout<<"Enter the 1st-array elements:"<<endl;
    for(int i=0;i<size1;i++)
    {
    	cin>>arr1[i];
	}
	
	cout<<"Enter the size of the array2: ";
    cin>>size2;
    
    cout<<"Enter the 2nd-array elements:"<<endl;
    for(int i=0;i<size2;i++)
    {
    	cin>>arr2[i];
	}

    s.selection_sort(arr1,size1);
    
    cout<<"\nThe elements of 1st-array after sorting"<<endl;
    for(int i=0;i<size1;i++)
    {
    	cout<<arr1[i]<<"\t";
	}
	
    s.selection_sort(arr2,size2);
    
    cout<<"\nThe elements of 2nd-array after sorting"<<endl;
    for(int i=0;i<size2;i++)
    {
    	cout<<arr2[i]<<"\t";
	}
	
	cout<<"\n";
	cout<<"\nBY LOGIC1:"<<endl;
	l.logic1(arr1,arr2,size1,size2);
	
	cout<<"\n";
	cout<<"\nBY LOGIC2:"<<endl;
	l.logic2(arr1,arr2,size1,size2);
	
	cout<<"\n";
	cout<<"\nBY LOGIC3:"<<endl;
	l.logic3(arr1,arr2,size1,size2);
    return 0;
	
	 
}

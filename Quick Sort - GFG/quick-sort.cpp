// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
        void quickSort(int arr[], int low, int high)
    {
        if(low < high){
            int pIndex = partition(arr,low,high);
            quickSort(arr,low,pIndex-1);
            quickSort(arr,pIndex+1,high);
        }
    }
    
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];
        int pivotIndex = low;
        for(int i = low; i <= high-1; i++){
            if(arr[i] <= pivot){
                
                swap(arr[pivotIndex],arr[i]);
                pivotIndex++;
            }
        }
        swap(arr[pivotIndex],arr[high]);
        return pivotIndex;
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


long long merge(long long A[],long long left,long long mid,long long right){
   long long i = left,j = mid,k = 0;
   long long temp[right-left+1];
   long long count = 0;
   while(i<mid && j<=right){
       if(A[i] <= A[j]){
           temp[k++] = A[i++];
       }else{
           temp[k++] = A[j++];
           count += mid - i;
       }
   }
   while(i<mid){
       temp[k++] = A[i++];
   }
   while(j<=right){
       temp[k++] = A[j++];
   }
   // copy temp array to original array..
   for(int i=left,k=0;i<=right;k++,i++){
       A[i] = temp[k];
   }
   return count;
}
long long merge_sort(long long A[],long long left,long long right){
   long long count=0;
   if(right>left){
       long long mid = (left+right)/2;
       long long countLeft = merge_sort(A,left,mid);
       long long countRight = merge_sort(A,mid+1,right);
       long long myCount = merge(A,left,mid+1,right);
       
       return myCount + countLeft + countRight;
   }
   return count;
}
long long int inversionCount(long long A[],long long n){
   long long ans = merge_sort(A,0,n-1);
   return ans;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends
#include<bits/stdc++.h>
using namespace std;
/*code for counting sort :The counting sort is used to sort the positive integers in O(n+k) time
what we need is the no of distinct elements in an array to be sorted: k=max element +1 (+1 for including element 0)
*/

int main() {
    int arr[10];//sorting for 10 elements
    int output[10];
    int i,j,k;
    int max=-1;
    for(i=0;i<10;i++)
    {
    	cin>>arr[i];
    	if(arr[i]>max)
    		max=arr[i];
    }
    k=max+1;
    int count[k+1];
    memset(count,0,sizeof(count));
    for(i=0;i<10;i++)
    {
    	count[arr[i]]++;//calculating the occurences of an element in array;
    }
    for(i=1;i<=k;i++)
    {
    	count[i]+=count[i-1];//now count[i]represents the maximum position i can take 
    	                      //i.e value at count[i] implies no of elements in array less than or equal to i;
    }
    for(i=9;i>=0;i--)//travel from back for stable sorting;
    {
      output[count[arr[i]]-1]=arr[i];//-1 for 0 based indexing in arrays;
      count[arr[i]]--;
    }
    for(i=0;i<10;i++)
     cout<<output[i]<<" ";
}

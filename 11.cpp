#include <bits/stdc++.h>
using namespace std;
// LEETCODE = #75
// sort array containing 0 1 2's 
// brut force => using sorting merge or quick
// time = o(nlogn),space = o(n) or O(n)

//optimal solu: DNF ALGORITHM
// time = O(n) ,space =O(1)
void optimal_sorting(int arr[],int n){
        int low =0,mid=0,high = n-1;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[mid],arr[low]);
                low++,mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid],arr[high]);
                high--;
        }
    }
}

// better soln:
//time = O(n) + O(n) = O(2n) ,
// space = O(1)
void better_sorting(int arr[],int n){
    int c0 =0,c1=0,c2 =0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0) c0++;
        else if(arr[i] == 1) c1++;
        else c2++;
    }
    //total time  O(n) bcuz loops 0 to n
    for(int i=0;i<c0;i++) arr[i] = 0;
    for(int i=c0;i<c0+c1;i++) arr[i] = 1;
    for(int i=c0+c1;i<n;i++) arr[i] = 2;
}


int main(){
    int n =8;
    int arr[] = {2,1,0,0,2,1,0,1};
    // better_sorting(arr,n);
    optimal_sorting(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
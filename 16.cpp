#include <bits/stdc++.h>
using namespace std;
//next permutation: leetcode = #31

//brute: by using reccrusion
// time : O(!n * n) extremly more

//better : stl => next_permutation
// next_permutation(arr,arr+n);

//optimal:longer prefix match
// time = O(3n) => two loops and one reverse
// space = o(n)
void optimal_nextpermutation(int arr[],int n){
    //to find break find:
    int idx = -1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }
    //so no dip thats means it the biggest so revers
    //eg => 5 4 3 2 1 the next pemutauion is 1 2 3 4 5
    if(idx == -1) {
        reverse(arr,arr+n);
        return;
    }

        for(int i = n-1;i>idx;i--){
            if(arr[i] > arr[idx]) {
                swap(arr[i],arr[idx]);
                break;
            }
        }
        //left should be small as possible 
        reverse(arr+idx+1,arr+n);
    }


int main(){
    int arr[] = {2,1,5,4,3,0,0};
    int n = 7;
    optimal_nextpermutation(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
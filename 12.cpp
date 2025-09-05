#include <bits/stdc++.h>
using namespace std;

//majority element,leetcode = #169
//optimal : "MOORE'S VOTING ALGORITHM"
// time = O(n) + O(N) => second o(n) only for verify not algorithm2
// space = o(1)
int optimal_majority(int arr[],int n){
        int count =0,el;
        for(int i=0;i<n;i++){
            if(count == 0){
                el = arr[i];
                count = 1;
            }
            else if(arr[i] == el){
                count++;
            }
            else count--;
        }
        // return el;
        //only to verify el is majority
        int c1=0;
        for(int i=0;i<n;i++){
            if(arr[i] == el){
                c1++;
            }
        }
        if(c1 > n/2) return el;
}



//better : HASHING
//time = O(n*logn), best = O(n) or worst = O(n*n) for unordered_map
// space = O(n)
int better_majority(int arr[],int n){
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] > n/2) return arr[i];
    }
    return -1;
}

//brute force:two loops
//time = O(n*n),space = O(1)
int brute_majority(int arr[],int n){
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]) count++;
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}


int main(){
    int n=7;
    int arr[] ={2,2,3,3,1,2,2};
    // int ans = brute_majority(arr,n);
    // int ans = better_majority(arr,n);
    int ans = optimal_majority(arr,n);


    cout<<"majority element is: "<<ans;
    return 0;
}
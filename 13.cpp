#include <bits/stdc++.h>
using namespace std;
//LEETCODE = #53
// MAXIMUM SUBARRAY SUM
//optimal : KADANE'S ALGORITHM
//time = O(n),space = O(1)
int optimal_max_subarraysum(int arr[],int n){
    int sum = 0,maxi = INT_MIN;
    for(int i=0;i<n;i++){
        sum +=arr[i];
        // if(sum > maxi) maxi = sum;
        maxi = max(maxi,sum);
        if(sum<0) sum = 0;
    }
    return maxi;
}


// brute force : 3 inner loops
// time = O(n^3),space = O(1)
int brute_max_subarraysum(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            //generate all subarray
            for(int k=i;k<j;k++){
                sum += arr[k];
                maxi = max(maxi,sum);
            }
        }
    }
    return maxi;
}

//better : same as bruteforce but use only two loops
// time = O(n*n),space = O(1)
int better_max_subarraysum(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        //no need of another loop
        for(int j=i;j<n;j++){
            sum +=arr[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}


//for printing max subarray sum using kadane's algo
//time = O(n),space = O(1)
int printing_optimal_max_subarray(int arr[],int n){
    int ans_start =-1,ans_end =-1,start = 0;
    int sum = 0,maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(sum == 0)  start = i;
        sum +=arr[i];
        // maxi = max(maxi,sum);
        if(sum > maxi){
            maxi = sum;
            ans_start = start,ans_end = i;
        }
        if(sum<0) sum = 0;
    }
    
    for(int i=ans_start;i<=ans_end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maxi;
}


int main(){
    int n = 8;
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    // int ans = brute_max_subarraysum(arr,n);
    // int ans = better_max_subarraysum(arr,n);
    // int ans = optimal_max_subarraysum(arr,n);
    int ans = printing_optimal_max_subarray(arr,n);
    cout<<"sum is  "<<ans;
    return 0;
}
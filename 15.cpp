#include <bits/stdc++.h>
using namespace std;
//product of array except itself: leetcode  #238
//time = O(n*n),space = O(n)
void brute_product_array(int arr[],int n){
    int ans[n];
    for(int i=0;i<n;i++){
        int mul = 1;
        for(int j=0;j<n;j++){
            if(j != i){
                mul *= arr[j];
            }
        }
        ans[i] = mul;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}


void optimal_product_array(int arr[],int n){
        
}

int main(){
    int arr[] = {1,2,3,4};
    int n =4;
    // brute_product_array(arr,n);
    optimal_product_array(arr,n);
    
    return 0;
}
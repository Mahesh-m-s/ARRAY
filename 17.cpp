#include <bits/stdc++.h>
using namespace std;
//LEADER OF AN ARRAY : elements to right sides of leader should less
//brute: two lopps
// time = O(n*n),space = O(n) => not to solve 
void brute_leader(int arr[],int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader = true;
        for(int j=i+1;j<n;j++){
            if(arr[i] < arr[j]){
                leader = false;
                break;
            }
            else{ 
                leader = true;
            }
        }
        if(leader == true){
            ans.push_back(arr[i]);
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    
}

//optimal : loops from back side 
// time = O(n) + O(nlogn),space = O(n) => not to solve
//O(nlogn) = if they asked for sorted version
void optimal_leader(int arr[],int n){
    int maxi = INT_MIN;
    vector<int> ans;
    for(int i = n-1;i>=0;i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi,arr[i]);
    }
    //if you want sorted:
    // sort(ans.begin(),ans.end());

    //if you want in order of array
    reverse(ans.begin(),ans.end());
    for(auto it : ans){
        cout<<it<<" ";
    }
}


int main(){
    int n = 6;
    int arr[] = {10,22,12,3,0,6};
    // brute_leader(arr,n);
    optimal_leader(arr,n);
    return 0;
}
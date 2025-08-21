#include <bits/stdc++.h>
using namespace std;
//TWO SUM:
//type 1 => two return elemnts exits or not 
//type 2 => to return elements index

//brute : two loops 
//time = o(n*n),space = o(1)
pair<int,int> brute_twosum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        //no need j=0
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                // cout<<"yes"; => use void
                return {i,j};
            }
        }
    }
    // cout<<"no"; => void
    return {-1,-1};
}

//better for type1: HASHING 
//optimal for returning index(type 2)
//time = o(n * logn),space = o(n)
// for unordered_map o(n)
pair<int,int> better_twosum(int arr[],int n,int target){
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int more = target - a;
        //condition is true if elemnts exist
        if(mpp.find(more) != mpp.end()){
            //if elemt exist in map means a+more = target
            return {mpp[more],i};
        }
        //storing elemts has key, index as value
        mpp[a] = i;
    }
}

//optimal for only type1 : "TWO POINTER"
//time = O(n)+O(nlogn) ,for sorting O(nlogn)
// space = O(n) or if not considering sorting O(1);

void optimal_twosum(int arr[],int n,int target){

        sort(arr,arr+n);
        int left = 0 ,right = n-1;
        for(int i=0;i<n;i++){
            //left is small ,right is big
            //if sum > target move right-- to reduce sum
            //if sum < target move left++ to increase sum
            int sum = arr[left] + arr[right];
            if(sum < target) left++;

            if(sum > target) right--;

            if(sum == target) {
                cout<<"yes";
                return;
            }
        }
        cout<<"no";
}

int main(){

    int n=5,target = 14;
    int arr[] = {3,4,6,2,9};
    // pair<int,int> ans = brute_twosum(arr,n,target);
    // pair<int,int> ans = better_twosum(arr,n,target);
    // cout<<ans.first<<" "<<ans.second;

    optimal_twosum(arr,n,target); //=> only for type 1

    return 0;
}
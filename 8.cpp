#include <bits/stdc++.h>
using namespace std;
//longest subarray with sum k [positive]

//brute forrce :using two pointer
//subarray is from i to j = len is j-i+1
//time = o(n*n),space is o(1)
void longest_sub(int arr[],int n,int k){
    int len = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum == k) {
                len = max(len,j-i+1);
            }
        }
    }
    cout<<"len is "<<len;
}

//better: hashing
// this method is optimal solution for array has +ve & -ve elemnets
//time = O(n * logn),space = O(n)
void better_longest_sub(int arr[],int n,int k){
    map<long,long> premap;
    int sum = 0,maxlen = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
        if(sum == k){
            maxlen = max(maxlen,i+1);
        }
        long long rem = sum - k;
        //checking rem is exit
        //in  find() if element is not found gives end()
        //it becomes end()== end() so condion false
        if(premap.find(rem) != premap.end()){
            int len = i - premap[rem];
            maxlen = max(maxlen,len);
        }
        if(premap.find(rem) == premap.end()){
            premap[sum] = i;
        }

    }
    cout<<"len is "<<maxlen;

}

//optimal soln: "two pointer == "sliding window"
//move right untill sum < k if its sum >k 
// then sum -=arr[left] and left++(move pointer)

//time = o(n+n) not n*n => inner loop happens very less total o(n)
//space = o(1)
void optimal_longest_sub(int arr[],int n,int k){
    int left = 0,right = 0;
    int sum = arr[0],len =0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            len = max(len,right-left+1);
        }
        right++;
        sum  += arr[right];
    }
    cout<<"lenght is "<<len;
}

int main(){
    int n=10;
    int k =3;
    int arr[] = {1,2,3,1,1,1,1,4,2,3};
    // longest_sub(arr,n,k);
    better_longest_sub(arr,n,k);
    // optimal_longest_sub(arr,n,k);
    return 0;
}

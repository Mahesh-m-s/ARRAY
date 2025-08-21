#include<bits/stdc++.h>
using namespace std;
//COUNT OF SUBARRAY SUM IS K(SAME AS LONGEST SUBARRAY)


//"optimal for -ve and +positive array" => HASHING
//better for only +ve array
// time = o(n *logn),o(n)
void countofsubarray(int arr[],int n,int k){
    int sum =0,count = 0;
    map<int,int> presum;
    presum[0] = 1;//sum =0 intially appear once
    //  eg rem = 7-7 = 0 so 0 should have 1
    for(int i=0;i<n;i++){
        sum += arr[i];
        int rem = sum - k;
        if(presum.find(rem)!= presum.end()){
            count += presum[rem];//update all frequency
        }
        presum[sum]++;//store and update frequency of every sum
    }
cout<<"count of subarray :"<<count;
}

//optimal for only +ve array:
// time = o(n) + o(n) not n*n bcuz 2nd loop very small
// space = o(1)
void optimal_countofsubarray(int arr[],int n,int k){
int left = 0,right =0;
int sum = arr[0],count = 0;
while(right < n){
    while(left <=right && sum > k){
        sum -=arr[left];
        left++;
    }
    if(sum == k){
        count++;
    }
    right++;
    sum +=arr[right];
    }
    cout<<"count of subarray sum k is :"<<count;
}

int main(){
    int n=9;
    int arr[] = {-3,4,-2,1,1,1,3,4,2};
    int k=3;
    countofsubarray(arr,n,k);
    // optimal_countofsubarray(arr,n,k);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
//MAX CONSECUTIVE ONES
// time = o(n),space = o(1)
int max_consecutive(int arr[],int n){
    int count = 0, max1 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            count++;
            max1 = max(count,max1);
            // if(count>max){
            //     max = count;
            // }

        }//if breaks the consecutive
        else{
            count = 0;
        }
    }
    return max1;
}


//FIND NUMBER THAT APPERS ONES WHILE OTHER APPEAR TWICE:

//brutforce:using 1 to n ,nested loops:
// time = o(n*n),space = o(1)
int appear_ones(int arr[],int n){
    for(int i=0;i<n;i++){
        int count =0;
        // int num = arr[i];
        for(int j=0;j<n;j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count ==1) return arr[i];
    }
}

//better solution : can use hash but map is more efficit in map
//bcuz we no need to find max element to give size of hash
// time => o(nlogm) + o(n/2 +1)
// space => o(n/2 +1)
int better_appear_ones(int arr[],int n){
    map<int,int> mpp;
    for(int i = 0;i<n;i++){
        mpp[arr[i]]++;   //time = nlogm
        // n is length of array is size of map
    }
    // for(auto it : mpp){
    //     if(it.second == 1){
    //         return it.first; // time = o(n/2 + 1) => every num appear twice
    //     // key is the element so it.first
    //     }
    // }
    for(int i=0;i<n;i++){
        if(mpp[arr[i]] == 1){
        return arr[i];
        }
    }
    return -1;
}


//optimal solution : USING "XOR"
//time = o(n),space = o(1)
int optimal_appear_ones(int arr[],int n){
    int xor1 =0;
    for(int i=0;i<n;i++){
        xor1 ^= arr[i];
    }
    return xor1;
}


int main(){
    // int n=9;
    // int arr[] = {1,1,0,1,1,1,0,1,1};
    // int num = max_consecutive(arr,n);
    // cout<<"max consecutive = "<<num;
    int n =7;
    int arr[] ={1,1,2,3,3,4,4};
    // int number = appear_ones(arr,n);
    int number = better_appear_ones(arr,n);
    // int number = optimal_appear_ones(arr,n);
    cout<<"number appear ones is = "<<number;
    return 0;
}
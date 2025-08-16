#include <bits/stdc++.h>
using namespace std;
//MISSING ELEMENT IN ARRAY 
//brutforce : 1 to N  loops
//time = o(n*n),space = o(1)
int missing(int arr[],int n){
    for(int i=1;i<n;i++){
        int flag = 0;
        for(int j=0;j<n-1;j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
}

//better solutn : using hash
// time = o(n) + o(n) =>o(2n)
//space = o(n) => hash
int better_missing(int arr[],int n){
    //n+1 bcuz we want 0 to n
    int hash[n+1] ={0};

    for(int i=0;i<n-1;i++){
        hash[arr[i]] = 1;
    }
    // 1 to N 
    for(int i=1;i<n;i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1;


}

//optimal soln: s1= n*(n+1)/2 ,s2 = sum of arr 
//missing num = s1 - s2;
// time = o(n),space = o(1)
int optimal_missing(int arr[],int n){
    int s1 = (n*(n+1))/2;
    int s2 = 0;
    //n-1 bcuz it has one less element 
    for(int i=0;i<n-1;i++){
        s2 += arr[i];
    }
    return s1-s2;
}

//xor of all numbers is not tha big compare to sum of all numbers
//even more optimal : USING XOR => 0^n = n ,n^n = 0
//time = o(n),space = o(1) 
int xor_optimal_missing(int arr[],int n){
    int xor1 = 0;
    //1 to n all numbers
    // for(int i=1;i<=n;i++){
    //     xor1 = xor1 ^ i;
    // }
    int xor2 = 0;
    //i<n-1  : 1 to n elements
    //i<n    : 0 to n elements
    for(int i=0;i<n-1;i++){
        xor1 = xor1 ^ (i+1); //bcuz array from 1 to n
        xor2 = xor2 ^ arr[i];
    }
    //in upper loop 1 to n-1 cover not n
    xor1 = xor1 ^  n;
    return xor1^xor2;
}


int main(){
    int n = 5;
    int arr[] = {1,2,3,5};
    // int num = missing(arr,n);
    // int num = better_missing(arr,n);
    // int num = optimal_missing(arr,n);
    int num = xor_optimal_missing(arr,n);

    cout<<"missing num is = "<<num;
}
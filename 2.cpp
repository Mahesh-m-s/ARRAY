#include <bits/stdc++.h>
using namespace std;
//"check array is sorted and rotated"
bool ifsorted(int arr[],int n){
    int count = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            count ++;
        }
    }
    return count<=1;
}

//"remove duplicate frome sorted array:""
//brute force => using a set
//time = o(nlogn + n) space = o(n)
int duplicate(int arr[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int idx = 0;
    for(auto it : s){
        arr[idx] = it;
        idx++;
    }
    return idx;
}

//optimal soln =>time o(n) space o(1)
//using "two pointer concept"  i and j
//find unique element at j and putting to next of i or (i+1)
int optimal_duplicate(int arr[],int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

//REVERSE AN ARRAY:
// time = o(n/2) == o(n)
// space = o(1)
void reverse(int arr[],int n){
    int j = n-1;
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[j]);
        j--;
    }
}

int main(){
int n = 4;
int arr[] = {1,2,4,4};
// bool res = ifsorted(arr,n);
// if(res ==true ){
//     cout<<"sorted & rotated";
// }
// else{
//     cout<<"not";
// }

// int ind = duplicate(arr,n);
// for(int i = 0;i<ind;i++){
//     cout<<arr[i]<<" ";
// }
// cout<<endl<<ind;

// int index = optimal_duplicate(arr,n);
// for(int i=0;i<index;i++){
//     cout<<arr[i]<<" ";
// }
// cout<<endl<<index;

reverse(arr,n);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}
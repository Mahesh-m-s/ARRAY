#include <bits/stdc++.h>
using namespace std;
// LONGEST CONSECUTIVE SEQUENCE = #128

//optimal : using set and
//logic:first elment previous should not present
//time = O(n) + O(n+2n)
//space = O(n)
void optimal_longest(int arr[],int n){
    unordered_set <int> st;
    int longest =1;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    //for first elements there should not be previous elemnt
    //if previous elemt is exit then its not first
    for(auto it : st){
        //previous is not there
        if(st.find(it-1) == st.end()){
            int count = 1;
            int x = it;
            //x+1 is exits
            while(st.find(x+1) != st.end()){
                count++;
                x = x+1;
            }
            longest = max(longest,count);
        }
    }
    cout<<longest;
}

//better : first sort and find 
//time = O(nlogn) + O(N)
//space = O(1)
void better_longest(int arr[],int n){
    sort(arr,arr+n);
    int longest = 1,count = 1,lastsmall = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == lastsmall){
            count++;
            lastsmall = arr[i];
        }
        // else if(arr[i] == lastsmall) means reapeted elemts so skip it
        else if(arr[i] != lastsmall){
            count = 1;
            lastsmall = arr[i];
        }
        longest = max(longest,count);
    }
    cout<<longest;
}

//brut = two loops
//time = O(n*n),space = O(1)
void brute_longest(int arr[],int n){
    int longest = 1;
    for(int i=0;i<n;i++){
        int count = 1;//each time set to 1
        int x = arr[i];
        for(int j=0;j<n;j++){
            if(arr[j] == x+1){
                count++;
                x++;
                j =-1; //to search from start
            }
        }
        longest = max(longest,count);
    }
    cout<<longest;
}

int main(){
    int arr[] = {102,4,100,1,101,3,2,1,1};
    int n =9;
    // brute_longest(arr,n);
    // better_longest(arr,n);
    optimal_longest(arr,n);
    return 0;
}
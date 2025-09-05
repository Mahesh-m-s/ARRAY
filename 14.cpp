#include <bits/stdc++.h>
using namespace std;
//best time to buy and sell stock 
//leetcode : #121
int buy_sell_stock(int arr[],int n){
    int mini = arr[0],profit = 0;
    for(int i=1;i<n;i++){
        int cost = arr[i] - mini;
        profit = max(profit,cost);
        mini = min(mini,arr[i]);
    }
    return profit;
}

//rearrange array elements by signs: 
//LEETCODE = #2149
// -VE AND +VE ARE EQUAL (N/2)
//brute force : create two array for -ve and +ve elements
// time = O(n)+O(n/2),space = O(n)
void brute_rearrange_array(int arr[],int n){
    vector<int> positive;
    vector<int> negative;
    
    for(int i=0;i<n;i++){
        if(arr[i] < 0) negative.push_back(arr[i]);
        else positive.push_back(arr[i]);
    }
    //inserting +ve and -ve 
    //+ve at even index and -ve at odd index
    for(int i=0;i<n/2;i++){
        arr[2*i] = positive[i];
        arr[2*i+1] = negative[i];
    }
    //just to print
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

//optimal: create ans array add -ve & +ve respect to its index
//time = O(n),space = O(n)
void optimal_rearrange_array(int arr[],int n){
    vector<int> ans(n);
    int pos =0,neg = 1;
    for(int i=0;i<n;i++){
        if(arr[i] < 0){
            ans[neg] = arr[i];
            neg +=2;
        }
        else {
            ans[pos] = arr[i];
            pos += 2;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}

//TYPE 2:
// -VE AND +VE ARE  NOT EQUAL (N/2)
//so for this we want to use brute force method
// time = O(2n) ,space = O(n)
// time O(n) + O(min(pos,neg)) + O(leftovers)
// so time = O(n) + O(n)
void type2_optimal_rearrange(int arr[],int n){
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(arr[i]<0) neg.push_back(arr[i]);
        else pos.push_back(arr[i]);
    }
    if(pos.size() > neg.size()){
        for(int i=0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        //extra positive is added to array
        //until neg index alternative element appear after that
        //remaing positive elements appear
        int index = neg.size() * 2;
        //no -ve elemnts + alternative +ve so *2 done
        for(int i=neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }

    else{
        // else condition : pos == neg
        for(int i=0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        //else for pos < neg
        int index = pos.size() *2;
        for(int i=pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
}


int main(){
    int n = 6;
    int arr[] = {-1,2,3,4,-3,1};
    // int ans = buy_sell_stock(arr,n);
    // cout<<ans;

    //elemets should have equal -ve & +ve elements
    // brute_rearrange_array(arr,n);
    // optimal_rearrange_array(arr,n);
    
    //element are unequal elements
    type2_optimal_rearrange(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
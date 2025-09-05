#include <bits/stdc++.h>
using namespace std;

//spiral matrix #54
//time = O(n*m),space = O(n*m)
void optimal_spiral(int arr[][6],int n,int m) {
    //n -> row ,m -> col
    int top =0,left = 0;
    int right = m-1,bottom = n-1;
    vector<int> ans;
    while(left <= right && top <= bottom){
        //right
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;
        //bottom
        for(int i=top;i<=bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;
        //left
        //check top and bottom (bcus top change in above)
        if(top <= bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(arr[bottom][i]);
        }
    }
        bottom--;
        //top
        //checks left and right(bcus right change in above) 
        if(left <= right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(arr[i][left]);
        }
    }
    left++;
}
    //referece
    for(auto it : ans){
        cout<<it<<" ";
    }
}
int main(){
    int arr[6][6]{
        {1,2,3,4,5,6},
        {20,21,22,23,24,7},
        {19,32,33,34,25,8},
        {18,31,36,35,26,9},
        {17,30,29,28,27,10},
        {16,15,14,13,12,11}
    };
    optimal_spiral(arr,6,6);
    return 0;
}
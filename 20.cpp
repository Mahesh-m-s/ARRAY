#include <bits/stdc++.h>
using namespace std;
//rotate matrix : by 90 clock wise,matirx is square n*n

//optimal:transpose & reverse every row
// time = O(n/2 * n/2) + O(n * n/2) => O(n*n)
// space = O(1)
void optimal_rotate(int arr[][4],int n){
    //for transpose
    //O(n/2*n/2) =>time
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    //for revering a row
    for(int i=0;i<n;i++){
        //row => arr[i]
        reverse(arr[i],arr[i]+n);
    }
    //refence
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//brute : by mapping the index
//time = O(n*n),space(n*n)
void brute_rotate(int arr[][4],int n){
    int ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[j][n-1-i] = arr[i][j];
        }
    }
    //for reference 
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[4][4] ={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int n = 4;
    // brute_rotate(arr,n);
    optimal_rotate(arr,n);


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//set matrix zero #73

//time = O(n*m)+O(n*m)+O(n+m) => O(n*m)
// space = O(1)
void optimal_matrix(int arr[][4],int n,int m){
    //col = arr[0][..] ->first col marking
    //row = arr[..][0] ->first row marking 
    int col0 = 1;//-> first col0 is separate due to collision with row
    //FOR MARKING THE INDEX
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                //row marking -> ith row
                arr[i][0] = 0;
                if(j !=0){
                    //col marking -> jth col
                    arr[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    //FOR REPLACING 1 WITH 0 FOR ROW AND COL
    //START WITHOUT ZEROth COL&ROW -> BCUZ ITSS USE FOR MARKING
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            //check for col and row
            if(arr[i][j] !=0){
                if(arr[0][j] ==0|| arr[i][0] == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }
//for first col its depends on first element
if(arr[0][0]==0){
    for(int j=0;j<m;j++){
        arr[0][j] = 0;
    }
}
//for first row its depends on col0 
if(col0 == 0){
    for(int i=0;i<n;i++){
        arr[i][0] = 0;
    }
}
}

//better: hashing for marking index
//time = O(n*m) + O(n*m),space = O(n)+O(m)
void better_matrix(int arr[][4],int n,int m){
    int row[n] = {0},col[m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]||col[j]){
                arr[i][j] = 0;
            }
        }
    }
}

//brute :for every rows and col of 0 marks as -1
//time = O(n*m)*(n+m) + O(n*m) == O(n^3)
void markrow(int arr[][4],int n,int m,int i){
    for(int j =0;j<m;j++){
        if(arr[i][j] !=0){
        arr[i][j] =-1;
        }
    }
}
void markcol(int arr[][4],int n,int m,int j){
    for(int i=0;i<n;i++){
        if(arr[i][j] !=0){
        arr[i][j] =-1;
        }
    }
}
void brute_matrix(int arr[][4],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] ==0){
                markrow(arr,n,m,i);
                markcol(arr,n,m,j);
            }
        }
    }
    //for repalcing -1 to 0
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
        }
    }
}

int main(){
    // int m=4,n=4;
    int arr[4][4] = {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,1}
    };
    // brute_matrix(arr,4,4);
    // better_matrix(arr,4,4);
    optimal_matrix(arr,4,4);

for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
#include<iostream>
#include <vector>
using namespace std;
//MOVING ALL ZEROES TO END
//Brut force :  time is o(n) + o(x) +o(n-x) = o(2n) or ||o(n) =>chatgpt
//space = o(x) but for worst case =>o(n) extra for temp

void movingtoend(int arr[],int n){
    vector <int> temp;
    //if array is instead of vector create count = 0;
    //and count++ int first loop we get no of element in temp


    for(int i = 0;i<n;i++){
        if(arr[i] != 0){    //step 1 moving non zero to temp
            // temp[i] = arr[i];
            temp.push_back(arr[i]);
        }
    }
    int nz = temp.size();
    for(int i = 0;i<nz;i++){    //step 2 moving non zero to arr first
        arr[i] = temp[i];
    }
    for(int i=nz;i<n;i++){
        arr[i] = 0;       //step 3 pushing zero at end 
    }
}

//optimal soln : using two pointer:
//time = step 1 => o(x) + step 2 o(n-x) == "o(n)"
//space = o(1)
void better_movingtoend(int arr[],int n){
    //i = itertor j = at zero
    int j = -1;
    //step 1 :finding first zero and put to j
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i;  //first zero at j [pointer]
            break;
        }
    }
    //step 2 : if i is !=0 swap with j
    for(int i = j+1;i<n;i++){
        if(arr[i] !=0){
        swap(arr[j],arr[i]);
        j++;
        }
    }
}


int main(){
    int n =7;
    int arr[] = {0,3,0,0,5,0,2};
    // movingtoend(arr,n);
    better_movingtoend(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
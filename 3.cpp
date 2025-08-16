#include<bits/stdc++.h>
using namespace std;
//LEFT ROTATE BY ONE PLACE
//optimal soln => time = o(n) space = o(1)
void leftrotate(int arr[],int n){
    int temp = arr[0];//step1

    for(int i=1;i<n;i++){//step 2
        arr[i-1] = arr[i];
    }

    arr[n-1] = temp;//step 3
}

//left ROTATE BY D PLACE:
//brute force : same logic as rotate by one
//time = o(d) + (n-d) + (d) = "o(n+d)"
//space = o(d) bcuz extra temp
void rotateby_d(int arr[],int n,int d){
    d = d % n; //bcuz multiple of d gives same array
    int temp[d];
    for(int i=0;i<d;i++){   //step 1
        temp[i] = arr[i];
    }
    for(int i=d;i<n;i++){   //step 2
        arr[i-d] = arr[i];
    }
    for(int i=n-d;i<n;i++){     //step 3
        arr[i] = temp[i-(n-d)]; //can use another var j for temp but this better
    }
}

//optimal => time = o(d) + o(n-d)+ o(n) = o(2n) 
//time is not efficient but space is o(1) so this method
//space = o(1)
void better_rotateby_d_left(int arr[],int n,int d){
    d = d % n; //must => multipe gives same array
    reverse(arr,arr+d); //rev 0 to d
    reverse(arr+d,arr+n);// d to n
    reverse(arr,arr+n); // 0 to n (entire array)
}

//rotate to right by d
void better_rotateby_d_right(int arr[],int n,int d){
    d = d%n;
    reverse(arr,arr+(n-d));
    reverse(arr+(n-d),arr+n);
    reverse(arr,arr+n);
}

int main(){

    int n= 5;
    int arr[] = {1,2,3,4,5};
    int d = 7;
    // leftrotate(arr,n);
    // rotateby_d(arr,n,d);
    // better_rotateby_d_left(arr,n,d);
    better_rotateby_d_right(arr,n,d);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


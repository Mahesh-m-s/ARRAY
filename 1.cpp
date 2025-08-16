#include <bits/stdc++.h>
using namespace std;
//FIND LARGEST AND SMALLEST ELEMENT IN AN ARRAY:


//brutforece => first sort and (n-1)th element is largest
//time = o(nlogn) merge or quick sort

//optimal :time => o(n)
void largest_element(int arr[],int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }   
    cout<<"max is "<<max;
}

// FOR SECOND LARGEST ELEMENT :

//brute =>second largest in sort array is (n-2)th elemnt
//time = o(nlogn + n) merge or quick sort
//if n-2 is equal to n-1 so we have to check all element 
// for(i=n-2;i>=0;i--){
//     if(arr[i] != arr[n-1]){
//         int second = arr[i];
//         break;
//     }
// }

//better soln = time o(2n)
void second_largest(int arr[],int n){
    int largest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    int slargest = -1;//if -ve elemets there theN INT_MIN
    for(int i=0;i<n;i++){
        if(arr[i]>slargest && arr[i]<largest){
            slargest = arr[i];
        }
    }
    cout<<"second largest element is = "<<slargest;

}

//optimal soln = o(n)
void better_second_largest(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;//or INT_MIN
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    cout<<"second largest is = "<<slargest;
}

//smallest element:
void smallest_element(int arr[],int n){
    int smallest = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<smallest){
            smallest = arr[i];
        }
    }
    cout<<"smallest is :"<<smallest;
}
// SECOND SMALLEST
void better_second_smallest(int arr[],int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    cout<<"second smallest is = "<<ssmallest;
}


int main(){
    int n = 6;
    int arr[] = {4,6,3,1,6,5};
    // largest_element(arr,n);
    // second_largest(arr,n); => better solution 
    // better_second_largest(arr,n); => optimal solution

    smallest_element(arr,n);
    // better_second_smallest(arr,n);

    return 0;
}
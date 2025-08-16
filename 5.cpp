#include <bits/stdc++.h>
using namespace std;
//FIND UNION & INTERSECTION OF TWO SORTED ARRAY:

//Brut force => USING SET
// time = o(n1*logn) + o(n2*logn) + o(n1+n2)
//o(n1 + n2) = if two array has unique elemnrt then set have to store all element
//space =  o(n1+n2) + o(n1+n2)
// o(n1+n2)  => to solve extra set:
// o(n1+n2) => to return not to solve prlm(not in algo)
void unionoftwo(vector<int> a,vector<int> b){
    set<int> s;
    int n1 = a.size();
    int n2 = b.size();
    for(int i=0;i<n1;i++){
        s.insert(a[i]);
    }
    for(int i=0;i<n2;i++){
        s.insert(b[i]);
    }
    vector<int> temp;
    for(auto it : s){
        temp.push_back(it);
    }
    //printing  not for time complexity just for reference:
    for(auto it : temp){
        cout<<it<<" ";
    }
}

//optimal soln: TWO POINTER:
//time = o(n1+n2)
//space = o(n1+n2) => only for returnig not in algo
void optimal_union(vector<int> a,vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0,j=0;
    vector<int> unionarr;
    while(i<n1 && j <n2){
        if(a[i] <= b[j]){ //bcuz array should sorted
            //unionarr.empty() insted of .size() ==0;
            //checks if previous is same or not 
            //if not same then add to unionarr  
            if(unionarr.size() == 0  || unionarr.back() != a[i]){
                unionarr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionarr.size() == 0  || unionarr.back() != b[j]){
                unionarr.push_back(b[j]);
            }
            j++;
        }
    }
    //if either of two array is over
    while(i<n1){
            if(unionarr.size() == 0  || unionarr.back() != a[i]){
                unionarr.push_back(a[i]);
            }
            i++;
        }
    
    while(j<n2){
        if(unionarr.size() == 0  || unionarr.back() != b[j]){
                unionarr.push_back(b[j]);
            }
            j++;
    }

    //reference not for time complexity
    for(auto it :unionarr){
        cout<<it<<" ";
    }

}

//brut force:  two iteration
//time => o(n1*n2)
//space => o(n2)
void inter(vector<int> a,vector<int> b){
    int n1 = a.size(),n2 = b.size();
    vector<int> ans;
    int vis[n2] = {0};
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    //just to see output
    for(auto it : ans){
        cout<<it<<" ";
    }
}

// optimal soln : TWO POINTER
//time = o(n1 + n2)
// space = o(1)
void optimal_inter(vector<int> a,vector<int> b){
    int n1 = a.size(),n2 = b.size();
    int i=0,j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            i++;
        }
        else if (b[j] < a[i]){
            j++;
        }
        else{ 
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    
}

void myinter(vector<int> a,vector<int> b){
    int n1 = a.size(),n2 = b.size();
    int i=0,j=0;
    vector<int> ans;
    while(i<n1 && j <n2){
        if(a[i] == b[j]){
            ans.push_back(a[i]);
            j++;
            i++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else {
            j++;
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
}


int main(){
    vector<int> a = {1,2,2,3,3,4,5,6};
    vector<int> b = {2,3,3,5,6,6,7};
    // unionoftwo(a,b);
    // optimal_union(a,b);

    // inter(a,b);
    // optimal_inter(a,b);

    myinter(a,b);

}
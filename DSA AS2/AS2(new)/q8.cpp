#include <bits/stdc++.h>
using namespace std;

int count_distinct(vector<int> arr){
    set<int> s(arr.begin(),arr.end());
    return s.size();
}

int main(){
    vector<int> arr={1,2,2,3,4,4,4,5};
    cout<<"Number of distinct elements: "<<count_distinct(arr)<<endl;
    return 0;
}

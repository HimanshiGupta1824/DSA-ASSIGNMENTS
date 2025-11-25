
#include <bits/stdc++.h>
using namespace std;

int merge_count(vector<int> &arr,int l,int r){
    if(l>=r) return 0;
    int m=(l+r)/2,c=merge_count(arr,l,m)+merge_count(arr,m+1,r);
    vector<int> tmp; int i=l,j=m+1;
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]) tmp.push_back(arr[i++]);
        else { tmp.push_back(arr[j++]); c+=m-i+1; }
    }
    while(i<=m) tmp.push_back(arr[i++]);
    while(j<=r) tmp.push_back(arr[j++]);
    for(int k=0;k<tmp.size();k++) arr[l+k]=tmp[k];
    return c;
}

int count_inversions(vector<int> arr){
    return merge_count(arr,0,arr.size()-1);
}

int main(){
    vector<int> arr={2,4,1,3,5};
    cout<<"Number of inversions: "<<count_inversions(arr)<<endl;
    return 0;
}

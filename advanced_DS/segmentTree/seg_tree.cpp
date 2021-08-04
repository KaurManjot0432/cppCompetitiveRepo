#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &arr, vector<int> &segTree, int left, int right, int idx){
    if(left==right){
         segTree[idx] = arr[left];
         return;
    }
    int mid = left + (right-left) /2;
    build(arr,segTree,left,mid,2*idx);
    build(arr,segTree,mid+1,right,2*idx+1);
    segTree[idx] = segTree[2*idx] + segTree[2*idx+1];
}
/*
s is start index of array, e is end index of array, Query[1] : update arr[x] = y;
*/
void update(vector<int> &arr, vector<int> &segTree, int s, int e, int x, int y, int idx){
    if(s==e and s==x){
        arr[x] = y;
        segTree[idx] = y;
        return;
    }
    if(s==e ) return;
    if(s<=x and e>=x) {
        int mid = s + (e-s) /2;
        update(arr,segTree, s,mid,x,y,2*idx);
        update(arr,segTree,mid+1,e,x,y,2*idx+1);
        segTree[idx] = segTree[2*idx]+segTree[2*idx+1];
    }
}

int sum(vector<int> &segTree, int s,int e, int left, int right, int idx){
    //if complete outside
    if(left>e or right < s) return 0;

    //complete overlap
    if(s>=left and e<=right){
        return segTree[idx];
    }
    //otherwise call to left and right 
    int mid = s + (e-s) /2;
    int a1 = sum(segTree, s, mid, left,right, 2*idx );
    int a2 = sum(segTree, mid+1, e, left, right, 2*idx+1);
    return a1+a2;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> segTree(4*n);
    build(arr, segTree, 0, n-1, 1);
    int t;
    cin>>t;
    while(t--){
        int q,l,r;
        cin>>q>>l>>r;
        if(q==1){
            //update
            update(arr,segTree, 0,n-1, l, r, 1);
        } else {
            //sum
            cout<<sum(segTree, 0, n-1, l , r, 1)<<endl;
        }
    }

    return 0;
}
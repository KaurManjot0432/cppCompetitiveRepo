#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll      long long int

void build(vector<ll> &arr, vector<ll> &segTree, int s, int e, int tidx ){
    if(s==e){
        segTree[tidx] = arr[s];
        return;
    }

    int mid = s + (e-s)/2;
    build(arr,segTree,s,mid,2*tidx);
    build(arr,segTree, mid+1, e, 2*tidx+1);
    segTree[tidx] = min(segTree[2*tidx], segTree[2*tidx+1]);
}

void update(vector<ll> &arr ,vector<ll> &segTree, int s, int e, int tidx, int i, ll val){
    if(s==e) {
        arr[i] = val;
        segTree[tidx] = val;
        return;
    }
    if(i>e or i<s) return;
    int mid = s + (e-s)/2;
    update(arr,segTree, s,mid,2*tidx,i,val);
    update(arr,segTree, mid+1, e,2*tidx+1,i,val);
    segTree[tidx] = min(segTree[2*tidx],segTree[2*tidx+1]);
}

int query(vector<ll> &segTree, int s, int e, int tidx, ll l, ll r){
    if(s>=l and e<=r) return segTree[tidx];
    if(l>e or r<s) return INT_MAX;
    
    int mid = s + (e-s)/2;
    ll a1 = query(segTree, s, mid, 2*tidx, l, r);
    ll a2 = query(segTree, mid+1, e, 2*tidx+1, l, r);
    return min(a1,a2);

}

int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<ll> segTree(4*n,0);
    build(arr, segTree, 0, n-1, 1);
    // for(int i=0; i<segTree.size(); i++) cout<<segTree[i]<<"   " ;
   
    while(q--){
        ll t,l,r;
        cin>>t>>l>>r;

        if(t==1){
            //update
            l--;
            update(arr,segTree, 0,n-1,1, l, r);
        } else {
            //sum
            l--,r--;
            cout<<query(segTree, 0, n-1,1, l , r)<<endl;
        }
    }

    return 0;
}

/*
https://www.spoj.com/problems/KGSS/#:~:text=KGSS%20%2D%20Maximum%20Sum&text=You%20are%20given%20a%20sequence,two%20integers%20i%20and%20x.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void build(vector<long long int> &arr, vector<pair<long long int,long long  int>> &segTree, int s, int e, int tidx){
    //base case
    if(s==e){
        segTree[tidx].first = arr[s];
        segTree[tidx].second = INT_MIN;
        return;
    }
    //recursion
    int mid = s + (e-s) /2;
    build(arr, segTree, s, mid, 2*tidx);
    build(arr, segTree, mid+1, e, 2*tidx+1);
    //self work
    segTree[tidx].first = max(segTree[2*tidx].first,segTree[2*tidx+1].first);
    segTree[tidx].second = min(max(segTree[2*tidx].first,segTree[2*tidx+1].second),max(segTree[2*tidx].second,segTree[2*tidx+1].first));
}

void update(vector<long long int> &arr, vector<pair<long long int,long long  int>> &segTree, int s, int e, int tidx, int i, int val){
     if(s==e) {
        arr[i] = val;
        segTree[tidx].first = val;
        segTree[tidx].second = INT_MIN;
        return;
    }

    int mid = s + (e-s)/2;

    if(i>mid)
    update(arr,segTree, mid+1, e,2*tidx+1,i,val);
    else 
     update(arr,segTree, s,mid,2*tidx,i,val);
    
    segTree[tidx].first = max(segTree[2*tidx].first,segTree[2*tidx+1].first);
    segTree[tidx].second = min(max(segTree[2*tidx].first,segTree[2*tidx+1].second),max(segTree[2*tidx].second,segTree[2*tidx+1].first));

}

pair<long long int, long long int> query( vector<pair<long long int,long long int>> &segTree, int s, int e, int tidx, int l, int r){
    if(s>=l and e<=r) {
        return make_pair(segTree[tidx].first, segTree[tidx].second);
    }
    if(l>e or r<s){
        return make_pair(INT_MIN, INT_MIN);
    }
    
    int mid = s + (e-s)/2;
    pair<long long int,long long  int> p1 = query(segTree, s, mid, 2*tidx, l, r);
    pair<long long int,long long  int> p2 = query(segTree, mid+1, e, 2*tidx+1, l, r);
    return make_pair(max(p1.first,p2.first), min(max(p1.first,p2.second),max(p1.second, p2.first)));
}

int main(){
    	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    int n;
    cin>>n;
    vector<long long int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   vector<pair<long long int,long long int>> segTree(4*n);
   build(arr, segTree, 0, n-1, 1);
    int q;
    cin>>q;
    int x,y;
    char c;
    while(q--){
        cin>>c>>x>>y;
        x--;
        if(c=='U'){
            update(arr, segTree, 0, n-1, 1, x, y);
        } else {
            y--;
            pair<long long int,long long  int> p = query(segTree, 0, n-1, 1, x, y);
            cout<<p.first+p.second<<endl;
        }
    }
    return 0;
}
// Problem Link - https://cses.fi/problemset/task/1648
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll         long long int 
const ll N = 2e5+5;
const ll B = 500;
vector<ll> sum(B,0);

ll getBlock(ll id){
    return id/B;
}


void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
}

int main(){
    //input
    ll n,q;
    cin>>n>>q;
    ll x[n];
    for(int i=0; i<n; i++) cin>>x[i];

    //pre-computation
    for(int i=0; i<n; i++){
        sum[getBlock(i)] += x[i];
    }
    //queries
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            ll k,u;
            cin>>k>>u;
            k--;
            sum[getBlock(k)] -= x[k];
            x[k] = u;
            sum[getBlock(k)] += x[k];

        } else {
            ll a,b;
            cin>>a>>b;
            a--,b--;
            ll blocka = getBlock(a);
            ll blockb = getBlock(b);

            ll i=a, ans = 0;
            while(getBlock(i)==blocka and i<=b){
                ans += x[i];
                i++;       
            }

            for(int j = blocka+1; j<blockb; j++){
                ans+=sum[j];
            }

            if(blocka!=blockb){
                i=b;
                while(getBlock(i)==blockb){
                    ans += x[i];
                    i--;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int

ll gcd_(ll a, ll b){
    if(b==0) return a;
    return gcd_(b,a%b);
}


int main(int argc, char const *argv[]) {
    int t;
    cin>>t;
    while(t--){
    int b;
    cin>>b;
    string a;
    cin>>a;
    int n = a.size();

    if(b==0) cout<<a<<endl;
    else if(a=="0") cout<<b<<endl;
    else {
        //calculate a%b;
        int mod = 0;
       for(int i=0; i<n; i++){
           mod = (mod*10+a[i]-'0')%b;
       }
        cout<<gcd_(b,mod)<<endl;
    }
    }
	return 0;
}

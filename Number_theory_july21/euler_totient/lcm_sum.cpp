#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int

#define N 1000005
int phi[N];
ll lcmsum[N];
void gen_lcmsum(){
    memset(lcmsum,0,sizeof(lcmsum));
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i){
            lcmsum[j]+=(phi[i]*i);
        }
    }
}


void gen_phi(){
    for(int i=1; i<N; i++) phi[i] = i;
    for(int i=2; i<N; i++){
        if(phi[i]==i){
            //i is a prime
            phi[i] = i-1;
            for(int j=2*i; j<N; j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    gen_lcmsum();
}

int main() {
    int t;
    cin>>t;
     gen_phi();
    while(t--){
        int n;
        cin>>n;
        ll sum = lcmsum[n]+1;
        sum*=n;
        sum/=2;
        cout<<sum<<endl;
    }
	return 0;
}

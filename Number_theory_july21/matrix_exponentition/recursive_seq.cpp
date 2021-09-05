// Problem Link -https://www.spoj.com/problems/SEQ/
/*By Manjot Kaur*/
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000000
#define inf             1e18
#define endl			"\n"
#define pb 				push_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define all(n) 			n.begin(),n.end()
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n) 		__builtin_popcount(n)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

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

int k;
ll f1[11],arr[11];
vector<vector<ll>> T(11,vector<ll>(11,0));


vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b){
    vector<vector<ll>> c(k+1,vector<ll>(k+1,0));
    for(int i=1; i<=k; i++){
        for(int j=1; j<=k; j++){
            for(int x=1; x<=k; x++){
                c[i][j] = (c[i][j]+(a[i][x]*b[x][j])%mod)%mod;
            }
        }
    }
    return c;
}
//calculates a^(n-1)
void power(vector<vector<ll>> &a,ll n){
    if(n==1) return;
    power(a,n/2);
    a = multiply(a,a);
    if(n&1){
        a = multiply(a,T);
    }
}

ll fib(ll n){
    if(n<=k){
        return f1[n];
    }
    auto a(T);
    power(a,n-k);
    ll ans=0;

    for(int i=1; i<=k; i++){
        ans = (ans+(a[k][i]*f1[i])%mod)%mod;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	
    int t;
    cin>>t;
    while(t--){
        cin>>k;
        loop(i,1,k) {
            cin>>f1[i];
            f1[i] %= mod;
        }
        loop(i,1,k) cin>>arr[i];

        //find Transformation matrix
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++) T[i][j] = 0;
        }
        for(int i=1; i<k; i++){
            T[i][i+1] = 1;
        }
        for(int i=1; i<=k; i++){
            // log(arr[k-i-1]);
            T[k][i] = arr[k-i+1];
        }
     
        // for(int i=1; i<=k; i++){
        //     for(int j=1; j<=k; j++){
        //         cout<<y[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        ll n;
        cin>>n;
        cout<<(fib(n))<<endl;
    }


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

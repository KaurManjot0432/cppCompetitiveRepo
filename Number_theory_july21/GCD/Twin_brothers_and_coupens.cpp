// Problem Link -
/*By Manjot Kaur*/
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
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

ll fact[1000005];

// class tuple_{
// public:
//     ll x,y,gcd;
// };

// tuple_ extended_euclid_algo(ll a,ll b){
//     if(b==0){
//         tuple_ base;
//         base.gcd = a;
//         base.x = 1;
//         base.y = 0;
//         return base;
//     }
//     tuple_ temp = extended_euclid_algo(b,a%b);
//     tuple_ ans;
//     ans.gcd = temp.gcd;
//     ans.x = temp.y;
//     ans.y = (temp.x-(a/b)*temp.y);
//     return ans;
// }

ll power(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)
            ans = (ans*a)%mod;
        a = ((a%mod)*(a%mod)%mod);
        b>>=1;
    }
    return ans%mod;
}

ll mod_inverse(ll a){
    return power(a,mod-2);
}

ll ncr(ll n, ll r){
    ll ans = fact[n];
    ans = (ans*mod_inverse(fact[n-r]))%mod;
    ans = (ans*mod_inverse(fact[r]))%mod;
    return ans;
}



int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    fact[0] = 1;
    loop(i,1,1000004) fact[i] = (fact[i-1]*i)%mod;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<13){
            cout<<0<<endl;
        } else if(n==13){
            cout<<1<<endl;
        } else {
            n-=13;
            ll ans = 0;
            while(n>=0){
                ans = ((ans%mod)+ncr((n/2)+5,5)%mod)%mod;
                n-=2;
            }
            cout<<ans<<endl;
        }
    }


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

// Problem Link - 
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

const ll N = 3e4+4;
const ll B = 200;
vi l(N/B,0);
vi r(N/B,-1);

ll getBlock(ll id){
    return id/B;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    ll n;
    cin>>n;
    vi a(n), b(n);
    loop(i,0,n-1) cin>>a[i];
    ump<ll,ll> m;
    for(int i=n-1; i>=0; i--){
        if(m.count(a[i])){
            b[i] = m[a[i]];
            m[a[i]] = i;
        } else {
            m[a[i]] = i;
            b[i] = n+1;
        }
    }
    // loop(i,0,n-1) cout<<b[i]<<" ";
    // cout<<endl;
    vi sorted(b);

    //precomputation
    ll lo = 0,hi=-1;
    loop(i,1,n){
        if(getBlock(i)!=getBlock(lo)){
            hi = i;
            l[getBlock(i)] = i;
            r[getBlock(i-1)] = i-1;
            sort(sorted.begin()+lo,sorted.begin()+hi);
            lo=i;
        }
    }

    //queries
    ll q;
    cin>>q;
    while(q--){
        ll aa,bb;
        cin>>aa>>bb;
        aa--,bb--;

        ll blocka = getBlock(aa);
        ll blockb = getBlock(bb);
        ll cc = bb;

        ll i=aa,ans=0;
       
        while(getBlock(i)==blocka and i<=bb){
            if(b[i]>cc) ans++;
            i++;
        }

        for(int i = blocka+1; i<blockb; i++){
            ll s = l[i], e = r[i];
            ll x = upper_bound(sorted.begin()+s,sorted.begin()+e+1,cc) - sorted.begin();
            ans+=(e-x+1);
        }

        if(blocka!=blockb){
            ll i=bb;
            while(getBlock(i)==blockb){
                if(b[i]>cc) ans++;
                i--;
            }
        }
        cout<<ans<<endl;
    }
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

// Problem Link - 
/* By Sanket Singh */
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

void build(vi &arr, vector<vector<ll>> &tree, ll s, ll e, ll ti){
    if(s==e){
        tree[ti].pb(arr[s]);
        return;
    }
    ll m = mid(s,e);
    build(arr, tree, s, m, 2*ti);
    build(arr, tree, m+1, e, 2*ti+1);
    ll i=0,j=0;
    while(i<tree[2*ti].size() and j<tree[2*ti+1].size()){
        if(tree[2*ti][i]<tree[2*ti+1][j]){
            tree[ti].pb(tree[2*ti][i]);
            i++;
        } else {
            tree[ti].pb(tree[2*ti+1][j]);
            j++;
        }
    }
    while(i<tree[2*ti].size()){
        tree[ti].pb(tree[2*ti][i]);
        i++;
    }
    while(j<tree[2*ti+1].size()){
        tree[ti].pb(tree[2*ti+1][j]);
        j++;
    }

}

ll query(vector<vector<ll>> tree, ll s, ll e, ll ti, ll l, ll r, ll k){
    if(l>e or r<s) return 0;
    if(s>=l and e<=r) {
        // loop(i,0,tree[ti].size()-1) cout<<tree[ti][i]<<" ";
        // cout<<endl;
        ll lo = upper_bound(tree[ti].begin(), tree[ti].end(), k) -tree[ti].begin();
        // log(lo);
        ll hi = tree[ti].size();
//        cout<<hi-lo<<endl;
        return hi-lo;
    }
    ll m = mid(s,e);
    ll a = query(tree, s, m, 2*ti, l, r, k);
    ll b = query(tree, m+1, e, 2*ti+1, l, r, k);
    return a+b;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    ll n,q;
    cin>>n;
    vi arr(n);
    loop(i,0,n-1) cin>>arr[i];
    vector<vector<ll>> segTree(4*n);
    build(arr, segTree, 0, n-1, 1);
    // loop(i,1,segTree.size()-1) {
    //     for(ll j=0; j<segTree[i].size(); j++){
    //         cout<<segTree[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cin>>q;
    ll i,j,k,last_ans=0;
    while(q--){
        cin>>i>>j>>k;
        i^=last_ans;
        j^=last_ans;
        k^=last_ans;
        last_ans = query(segTree, 0, n-1, 1, i, j,k);
        cout<<last_ans<<endl;
    }
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

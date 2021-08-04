// Problem Link - https://www.codechef.com/problems/WINLS1
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

void build(vi &arr, vi &tree, ll s, ll e, ll ti){
    if(s==e){
        tree[ti] = arr[s];
        return;
    }
    ll m = mid(s,e);
    build(arr, tree, s, m, 2*ti);
    build(arr, tree, m+1, e, 2*ti+1);
    tree[ti] = tree[2*ti]+tree[2*ti+1];
}

ll query(vi &tree, ll s, ll e, ll ti, ll l, ll r){
    if(l>e or r<s) return 0;
    if(s>=l and e<=r) return tree[ti];
    ll m = mid(s,e);
    ll a = query(tree, s, m, 2*ti, l, r);
    ll b = query(tree, m+1, e, 2*ti+1, l, r);
    return a+b;
}

void update(vi &tree, ll s, ll e, ll ti, ll i, ll val){
    if(s==e){
        tree[ti] = val;
        return;
    }
    ll m = mid(s,e);
    if(i>m){
        //go to right
        update(tree, m+1, e, 2*ti+1, i, val);
    } else {
        //go to left
        update(tree, s, m, 2*ti, i, val);
    }
    tree[ti] = tree[2*ti]+tree[2*ti+1];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    ll n,q,x;
    cin>>n>>q;
    vi arr(n+q);
    vi segTree(4*(n+q));
    ump<ll,ll> map;
    loop(i,0,n-1){
        arr[i]=1;
    }
    ll top = n;
    for(int i=n; i>0; i--){
        map[i] = n-i;
    }
    build(arr, segTree, 0, n+q-1, 1);
    loop(k,0,q-1){
        cin>>x;
        ll id_x = map[x];
        // log(id_x);
        cout<<query(segTree, 0, n+q-1, 1, id_x+1, n+q-1)<<" ";
        arr[id_x]=0;
        arr[top]=1;
        // loop(i,0,n+q-1) cout<<arr[i]<<" ";
        map.find(x)->second = top;
        update(segTree,0,n+q-1, 1,top,1);
        update(segTree,0,n+q-1, 1,id_x,0);
        top++;
    }

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

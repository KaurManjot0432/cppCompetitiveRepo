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
#define vi              vector<int>
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

void build(vi &tree, int s, int e, int ti){
    if(s==e) {
        tree[ti] = 1;
        return;
    }
    int m = mid(s,e);
    build(tree, s, m, 2*ti);
    build(tree, m+1, e, 2*ti+1);
    tree[ti] = tree[2*ti]+tree[2*ti+1];
}

int query(vi &tree, int s, int e, int ti, int k){
    if(s==e) return s+1;
    int m = mid(s,e);
    if(tree[2*ti]<k){
        return query(tree, m+1, e, 2*ti+1, k-tree[2*ti]);
    } else {
        return query(tree, s, m, 2*ti, k);
    }
}

void update(vi &tree, int s, int e, int ti, int i){
    if(s==e){
        tree[ti] = 0;
        return;
    }
    int m = mid(s,e);
    if(i>m){
        update(tree, m+1, e, 2*ti+1, i);
    } else {
        update(tree, s, m, 2*ti, i);
    }
    tree[ti] = tree[2*ti] + tree[2*ti+1];
}


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int n;
    cin>>n;
    vi arr(n);
    loop(i,0,n-1) cin>>arr[i];
    vi res(n), tree(4*n);
    build(tree, 0, n-1, 1);
    int ones = n;
    for(int i=n-1; i>=0; i--){
        int r = arr[i]+1;        //find rth one from right
        int l = ones-r+1;     //find lth one from left->similar to kth one from left
        log(l);
        int ans = query(tree, 0, n-1, 1, l);
        log(ans);
        res[i] = ans;
        update(tree, 0, n-1, 1, ans-1);
        ones--;
    }
    logarr(res, 0, n-1);

	#ifndef ONLINE_JUDGE 

	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

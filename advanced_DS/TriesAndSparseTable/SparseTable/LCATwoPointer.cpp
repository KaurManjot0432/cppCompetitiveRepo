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

const int N = 1005;
vector<int>adj[N];
int parent[N];
int depth[N];
void dfs(int curr, int p){
    parent[curr] = p;
    for(auto child : adj[curr]){
        if(child!=parent[curr]){
            depth[child] = 1+depth[curr];
            dfs(child,curr);
        }
    }
}

int findLCA(int x, int y){
    if(x==y) return x;
    if(depth[x]>depth[y]) swap(x,y);
    int d = depth[y] - depth[x];
    while(d--){
        y = parent[y];
    }
    //Now Both Nodes are at same level
    while(x!=y){
        x = parent[x];
        y = parent[y];
    }
    return x;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    int t;
    cin>>t;
    loop(i,1,t){
        int n;
        cin>>n;
        loop(u,1,n) {
            int m;
            cin>>m;
            while(m--){
                int v;
                cin>>v;
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
        memset(depth,0,sizeof(depth));
        dfs(1,0);
        // loop(i,1,n){
        //     log(i,parent[i],depth[i]);
        // }
        // loop(i,1,n){
        //     cout<<i<<"->";
        //     for(int i : adj[i]) cout<<i<<"->";
        //     cout<<endl;
        // }
        int q;
        cin>>q;
        cout<<"Case "<<t<<":"<<endl;
        while(q--){
            int x,y;
            cin>>x>>y;
           cout<<findLCA(x,y)<<endl;
        }
    }
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

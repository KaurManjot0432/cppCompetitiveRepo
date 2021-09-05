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

const int MAX = 505;
ll dp[MAX][MAX];

ll get_ways(int n,int m,set<pair<int,int>>& blocked){
    if(blocked.find(mp(n-1,m-1))!=blocked.end()) return 0;
    dp[n-1][m-1] = 1;
    for(int i=m-2; i>=0; i--) {
        pair<int,int> p = mp(n-1,i);
        if(blocked.find(p)==blocked.end())
        dp[n-1][i] = dp[n-1][i+1];
        else dp[n-1][i] = 0;
    }
    for(int i=n-2; i>=0; i--){
        pair<int,int> p = mp(i,m-1);
        if(blocked.find(p)==blocked.end())
        dp[i][m-1] = dp[i+1][m-1];
        else dp[i][m-1] = 0;
    }
    for(int i=n-2; i>=0; i--){
        for(int j=m-2; j>=0; j--){
            pair<int,int> p = mp(i,j);
            if(blocked.find(p)==blocked.end()){
                dp[i][j] = ((dp[i+1][j]%mod)+ (dp[i][j+1]%mod))%mod;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[0][0];
}

ll get_ways_optimezed(int n,int m,set<pair<int,int>>& blocked){
    vector<vector<ll>> dp(2,vector<ll>(m));
    if(blocked.find(mp(n-1,m-1))!=blocked.end()) return 0;

    dp[1][m-1] = 1;

    for(int i=m-2; i>=0; i--){
        pair<int,int> p = mp(n-1,i);
        if(blocked.find(p)==blocked.end()){
            dp[1][i] = dp[1][i+1];
        } else {
            dp[1][i] = 0;
        }
    }
    // loop(i,0,m-1) cout<<dp[1][i]<<" ";
    // cout<<endl;
    int flag = 0;
    for(int i=n-2; i>=0; i--){
        pair<int,int> p = mp(i,m-1);
        if(blocked.find(p)==blocked.end()){
            dp[flag][m-1] = dp[1-flag][m-1];
        } else {
            dp[flag][m-1] = 0;
        } 
        for(int j=m-2; j>=0; j--){
            pair<int,int> p = mp(i,j);
            if(blocked.find(p)==blocked.end()){
                dp[flag][j] = ((dp[1-flag][j]%mod) + (dp[flag][j+1]%mod) %mod);
            } else {
                // log(p.ff,p.ss);
                dp[flag][j] = 0;
            }
        }
    //         loop(i,0,m-1) cout<<dp[flag][i]<<" ";
    // cout<<endl;
        flag = 1-flag;
    }
    return dp[1-flag][0];

}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        set<pair<int,int>> blocked;
        loop(i,0,k-1){
            int x,y;
            cin>>x>>y;
            x--,y--;
            blocked.emplace(mp(x,y));
        }
        // cout<<get_ways(n,m,blocked)<<endl;
        cout<<get_ways_optimezed(n,m,blocked)<<endl;
        // loop(i,0,n-1){
        //     loop(j,0,m-1){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(auto p : blocked) cout<<p.ff<<" "<<p.ss<<endl;
    }
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

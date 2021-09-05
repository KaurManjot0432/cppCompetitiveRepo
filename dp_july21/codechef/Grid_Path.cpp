// Problem Link -https://www.codechef.com/START10B/problems/GRIDPA
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

#define N 155
#define K 305
ll dp[N][N][K];
char grid[N][N];
int a[N][N];

void max_coin(int n, int k){
    loop(i,0,n-1){
        loop(j,0,n-1){
            loop(l,0,k){
                dp[i][j][l] = -inf;
            }
        }
    }
    dp[0][0][0] = a[0][0];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if(i>0 and grid[i][j]=='.') dp[i][j][0] =  max(dp[i][j][0],dp[i-1][j][0] + a[i][j]);
            if(j>0 and grid[i][j]=='.') dp[i][j][0] =  max(dp[i][j][0],dp[i][j-1][0] + a[i][j]);

            for(int l = 1; l<=k; l++){
                if(i>0)
                dp[i][j][l] =  max(dp[i][j][l], dp[i-1][j][l-1] + a[i][j]);
                if(j>0)
                dp[i][j][l] =  max(dp[i][j][l], dp[i][j-1][l-1] + a[i][j]);
            }

            if(i>0 and grid[i][j]=='.') dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k] + a[i][j]);
            if(j>0 and grid[i][j]=='.') dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k] + a[i][j]);

        }
    }
    
    cout<<max(dp[n-1][n-1][k],(ll)-1)<<endl;

}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        loop(i,0,n-1){
            loop(j,0,n-1){
                cin>>grid[i][j];
            }
        }
        loop(i,0,n-1){
            loop(j,0,n-1){
                cin>>a[i][j];
            }
        }
        max_coin(n,k);
    }

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

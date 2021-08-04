// Problem Link - 
/* By Manjot Kaur */
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

#define N 1005
vector<int> price(N), pages(N);
int dp[2][100005];


//top-down solution will give us TLE
// int maximize_pages(int n,int m){
//     if(n==0) return dp[n][m] = (m>=price[n])?pages[n] : 0;
//     if(dp[n][m]!=-1) return dp[n][m];

//     if(m>=price[n]) {
//         dp[n][m] = max(maximize_pages(n-1,m) , maximize_pages(n-1,m-price[n])+pages[n]);
//     } else {
//         dp[n][m] = maximize_pages(n-1,m);
//     }
//     return dp[n][m];
// }


int maximize_pages(int n, int m){
    loop(i,0,m){
        if(i>=price[0]) dp[0][i] = pages[0];
        else dp[0][i] = 0;
    }
    int flag = 1;
    loop(i,1,n){
        loop(j,0,m){
            if(j>=price[i]){
                dp[flag][j] = max(dp[1-flag][j], pages[i]+dp[1-flag][j-price[i]]);
            } else {
                dp[flag][j] = dp[1-flag][j];
            }
        }
        flag = 1-flag;
    }
    return dp[1-flag][m];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int n,m;
    cin>>n>>m;
    
    loop(i,0,n-1) cin>>price[i];
    loop(i,0,n-1) cin>>pages[i];

    // memset(dp,-1,sizeof(dp));
    cout<<maximize_pages(n-1,m)<<endl;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

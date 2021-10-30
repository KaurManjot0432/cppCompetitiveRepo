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
//this ques is variation of TSP

string dfs(int mask, int curr, vector<string> &A,vector<vector<string>> &dp,vector<vector<int>> &overlap){
    if(!dp[mask][curr].empty()){
        return dp[mask][curr];
    }
    int pre=mask^(1<<curr);
    if(pre==0){
        return dp[mask][curr]=A[curr];
    }

    for(int i=0; i<A.size(); i++){
        if(pre & (1<<i)!=0){
            string temp = dfs(pre, i, A, dp, overlap) + A[curr].substr(overlap[i][curr]);
            if(dp[mask][curr].empty() or temp.size()<dp[mask][curr].size()){
                dp[mask][curr] = temp;
            }
        }
    }
    return dp[mask][curr];
}

string shortestSuperstring(vector<string>& A) {
    int n = A.size();
    vector<vector<string>> dp((1<<n), vector<string>(n));
    vector<vector<int>> overlap(n,vector<int>(n,0));

    //find overlap of two strigs i,j
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j){
                string a = A[i];
                string b = A[j];
                for(int k=min(a.size(), b.size()); k>=0; k--){
                    if(a.substr(a.size()-k) == b.substr(0,k)){
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        dfs((1<<n)-1, i, A, dp, overlap);
    }
    int all = (1<<n)-1;
    string ans = dp[all][0];
    for(int i=1; i<n; i++){
        if(dp[all][i].size()<ans.size()){
            ans = dp[all][i];
        }
    }
    return ans;


}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

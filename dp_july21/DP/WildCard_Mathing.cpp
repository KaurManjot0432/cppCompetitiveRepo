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

// bool WildCard_matching(int i, int j, string &text, string &pat){
//     if(j==pat.size()) return dp[i][j] = i==text.size();

//     if(i<text.size() and j<pat.size() and dp[i][j]!=-1) return dp[i][j];

//     if(i<text.size() and pat[j]!='*'){
//         if(text[i]==pat[j] or pat[j]=='?') return dp[i][j] = WildCard_matching(i+1,j+1,text,pat);
//         return dp[i][j] = false;
//     }

//     if(i>=text.size() and pat[j]!='*') return dp[i][j] = false;

//     while(j<pat.size()-1 and pat[j+1]=='*') j++;

//     if(i>=text.size() and j<pat.size()-1) return dp[i][j] = false;

//     return dp[i][j] = (WildCard_matching(i,j+1,text,pat) or WildCard_matching(i+1,j,text,pat));

// }

bool wildCard_bu(string &text, string &pat){
    int m = text.size();
    int n = pat.size();
    bool dp[n+1][m+1];
    dp[0][0] = true;
    for(int i=1; i<=n; i++){
        if(pat[i-1]=='*') dp[i][0] = dp[i-1][0];
        else dp[i][0] = false;
    }

   for(int j=1; j<=m; j++){
        //pat has been exhausted
        dp[0][j] = false;
    }

 for(int i=1; i<=n; i++){
         for(int j=1; j<=m; j++){
            if(pat[i-1]==text[j-1] or pat[i-1]=='?') dp[i][j] = dp[i-1][j-1];
            else if(pat[i-1]=='*') dp[i][j] = (dp[i-1][j] or dp[i][j-1]);
            else dp[i][j] = false;
        }
    }

    return dp[n][m];

}
bool isMatch(string s, string p) {
    return wildCard_bu(s,p);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    string text, pat;
    cin>>text>>pat;
    cout<<isMatch(text,pat)<<endl;
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

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
const int N = 1e6+6;
const int LOG = 20;
int table[N][LOG];
int bin_log[N];
vi pre(N,0);
vi A(N);
 
int query(int l, int r){
    int len = r-l+1;
    int k = bin_log[len];
    return min(table[l][k],table[r-(1<<k)+1][k]);
}
 
void preprocess(int n){
    loop(j,1,LOG-1){
        for(int i=0; i+(1<<j)-1 <= n; i++){
            table[i][j] = min(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
    }
}
 
int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here...
    string s;
    cin>>s;
    int n = s.size();
    for(int i=1; i<=s.size(); i++){
        if(s[i-1]=='(') pre[i] = pre[i-1]+1;
        else pre[i] = pre[i-1] - 1;
    }
   
    bin_log[1] = 0;
    loop(i,2,N-1) bin_log[i] = bin_log[i/2]+1;
 
    //preprocessing
    loop(i,0,n) table[i][0] = pre[i];
    preprocess(n);
    vi B;
    int ind = 0,count=0,maxLen = INT_MIN;;
    for(int i=0; i<s.size(); i++){
        for(int j=i+1; j<=s.size(); j++){
            if(pre[i]==pre[j]) A[ind++]=j;
        }
        // loop(i,0,ind-1) cout<<A[i]<<" ";
        // cout<<endl;
        int lo = 0, hi = ind-1;
        int curr_len =0;
        while(lo<=hi){
            int mid = (lo+(hi-lo)/2);
            // log(mid);
            int min_ = query(i,A[mid]);
            // log(min_);
            if(min_ == pre[i]) {
                lo = mid+1;
                maxLen = max(maxLen,(int)A[mid]-i);
                if(A[mid]-i > curr_len) curr_len = A[mid]-i;
            } else {
                hi = mid-1;
            }
 
        }
        if(curr_len>0) {
            B.pb(curr_len);
            i+=curr_len;
            // count++;
        }
        ind=0;
    }
    if(!B.empty()) loop(i,0,B.size()-1) if(B[i]==maxLen) count++;
    if(count>0) cout<<maxLen<<" "<<count<<endl;
    else cout<<"0 1"<<endl;
	
 
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}
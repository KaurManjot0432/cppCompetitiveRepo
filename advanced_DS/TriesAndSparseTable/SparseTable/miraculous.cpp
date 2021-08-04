// Problem Link - https://www.spoj.com/problems/TNVFC1M/
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

const int N = 1e4+4;
const int LOG = 14;
int table[N][LOG];
int bin_log[N];
int arr[N];
vector<int> res(N,0);

void preprocess(int n){
    loop(j,1,LOG-1){
        for(int i=0; i+(1<<j)-1 < n; i++){
            if(arr[table[i][j-1]] > arr[table[i+(1<<(j-1))][j-1]]){
                table[i][j] = table[i+(1<<(j-1))][j-1];
            } else {
                table[i][j] = table[i][j-1];
            }
        }
    }
}

int query(int l, int r){
    int len = r-l+1;
    int k = bin_log[len];
    if(arr[table[l][k]] > arr[table[r-(1<<k)+1][k]]) {
        return table[r-(1<<k)+1][k];
    }
    return table[l][k];
    
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int n,h,a,b;
    cin>>n>>h>>a>>b;
    loop(i,0,n-1) cin>>arr[i];

    bin_log[1] = 0;
    loop(i,2,N-1) bin_log[i] = bin_log[i/2]+1;

    loop(i,0,n-1) table[i][0] = i;
    preprocess(n);
    for(int i=n-1; i>=0; i--){
        int l = ((i-h+1)>=0) ? i-h+1 : 0;
        int r = i;
        int min_ind = query(l,r);
        // log(l,r,min_ind)
        if(arr[min_ind]==arr[r]) res[r]++;
        else res[min_ind]++;

    }
	loop(i,a-1,b-1){
        cout<<res[i]<<" ";
    }

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

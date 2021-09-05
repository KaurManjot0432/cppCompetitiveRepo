// Problem Link -https://www.codechef.com/problems/NITA11
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



int x[] = {1,0,-1,0,1,-1,1,-1};
int y[] = {0,1,0,-1,1,1,-1,-1};

void dfs(vector<vector<char>> &a, int i, int j,int n){
    if(i>=n || i<0 || j>=n || j<0) return;
    if(a[i][j] == '.') return;
    a[i][j] = '.';
    for(int k=0; k<8; k++){
        dfs(a,i+x[k], j+y[k],n);
    }
}

int main(int argc, char const *argv[]) {
	// Write your code here....
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> a(n,vector<char>(n));
        loop(i,0,n-1){
            loop(j,0,n-1){
                cin>>a[i][j];
            }
        }
        bool got = false;
        int c = 0;
        loop(i,0,n-1){
            loop(j,0,n-1){
                    if(a[i][j]=='S'){
                        dfs(a,i,j,n);
                        c++;
                    }
                
            }
        }
        if(c%2!=0){
            cout<<"Alice\n";
        } else {
            cout<<"Bob\n";
        }
    }
	return 0;
}

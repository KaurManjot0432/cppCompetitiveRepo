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

int ways = 0;

void display(int n, vector<vector<bool>> &board){
    for(vector<bool> row : board){
        for(bool el : row){
            if(el){
                cout<<"K";
            } else {
                cout<<".";
            }
        }
        cout<<"\n";
    }
    cout<<"-----------\n";
}

bool isSafe(int n, int i, int j, vector<vector<bool>> &board){
    if(i-1>=0 and j-2>=0 and board[i-1][j-2]) return false;
    if(i-1>=0 and j+2<n and board[i-1][j+2]) return false;
    if(i-2>=0 and j-1>=0 and board[i-2][j-1]) return false;
    if(i-2>=0 and j+1<n and board[i-2][j+1]) return false;
    return true;
}

void NKnights(int sr,int sc,int placed,int n,vector<vector<bool>> &board){
    if(placed==n){
        ways++;
        display(n,board);
        return;
    }

    for(int row = sr; row<n; row++){
        for(int col = ((row==sr)? sc : 0); col<n; col++){
            if(not board[row][col] and isSafe(n,row,col,board)){
                board[row][col] = true;
                NKnights(row,col+1,placed+1,n,board);
                board[row][col] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
	int n;
    cin>>n;
    vector<vector<bool>> board(n,vector<bool>(n,false));
   NKnights(0,0,0,n,board);
   cout<<ways<<endl;



	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

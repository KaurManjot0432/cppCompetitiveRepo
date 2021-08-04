// Problem Link - https://www.spoj.com/problems/GSS1/
/* By Sanket Singh */
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

class Node{
    public : 
       ll maxSum;
       ll mps;
       ll mss;
       ll sum;
};

void build(vi &arr, vector<Node*> &seg, int l, int r, int tidx){
    if(l==r){
        seg[tidx]->maxSum = arr[l];
        seg[tidx]->mps = arr[l];
        seg[tidx]->mss = arr[l];
        seg[tidx]->sum = arr[l];
        return;
    }
    ll m = mid(l,r);
    build(arr, seg, l, m, 2*tidx);
    build(arr, seg, m+1, r, 2*tidx+1);

    seg[tidx]->maxSum = max({seg[2*tidx]->maxSum ,seg[2*tidx+1]->maxSum , (seg[2*tidx]->mss+seg[2*tidx+1]->mps)});
    seg[tidx]->mps = max(seg[2*tidx]->mps, seg[2*tidx]->sum+seg[2*tidx+1]->mps);
    seg[tidx]->mss = max(seg[2*tidx+1]->mss, seg[2*tidx+1]->sum+seg[2*tidx]->mss);                                                                                                                      
    seg[tidx]->sum = seg[2*tidx]->sum + seg[2*tidx+1]->sum;
}

Node* query(vector<Node*> &seg, int l, int r, int tidx, int x, int y){
    Node *temp = new Node();
    temp->sum = temp->mps = temp->mss = temp->maxSum = INT_MIN;

    if(x>r or y<l){                     //complete outside
        return temp;
    }
    if(l>=x and r<=y){
        //complete inside
        return seg[tidx];
    }
    int m = mid(l,r);
    Node  *a = query(seg, l, m, 2*tidx, x, y);
    Node *b = query(seg, m+1, r, 2*tidx+1, x, y);

    temp->maxSum = max({a->maxSum ,b->maxSum , (a->mss+b->mps)});
    temp->mps = max(a->mps, a->sum+b->mps);
    temp->mss = max(b->mss, b->sum+a->mss);                                                                                                                      
    temp->sum = a->sum + b->sum;

    return temp;

}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    int n,m,x,y;
    cin>>n;
    vi arr(n);
    vector<Node*> seg(4*n);
    loop(i,0,n-1) cin>>arr[i];
    loop(i,1,4*n-1) seg[i] = new Node();
    build(arr, seg, 0, n-1, 1);
    cin>>m;
    while(m--){
        cin>>x>>y;
        Node* res = query(seg, 0, n-1, 1, x, y);
        cout<<res->maxSum<<endl;
    }

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

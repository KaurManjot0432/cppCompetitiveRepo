// Problem Link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
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
#define vs              vector<string>
#define vp				vector<pair<ll,ll>>
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
ll arr[100005];
ll p[100005];
ll tree[400000]; 
void fastPow(){
    p[0]=1;
    loop(i,1,100000){
        p[i] = (2*p[i-1])%3;
    }
}

void build(int s, int e, int ti){
    if(s=e){
        tree[ti] = arr[s];
        return;
    }
    int m = mid(s,e);
    build(s, m, 2*ti);
    build(m+1, e, 2*ti+1);
    tree[ti] = (tree[2*ti]*p[e-m]+tree[2*ti+1])%3;
    return;
}

void update(int s, int e, int ti, int i){
    if(s==e and s==i){
        tree[ti] = 1;
        return;
    }
    if(s==e) return;
    if(i>e or i<s) return;
    int m = mid(s,e);
    update(s, m, 2*ti, i);
    update(m+1, e, 2*ti+1, i);
    tree[ti] = (tree[2*ti]*p[e-m]+tree[2*ti+1])%3;
    return;
}

int query(int s, int e, int ti, int l, int r){
    if(l>e or r<s) return 0;
    if(s>=l and e<=r) return (tree[ti]*p[r-e])%3;
    int m = mid(s,e);
    int a = query(s, m, 2*ti, l, r);
    int b = query(m+1, e, 2*ti+1, l, r);
    return (a+b)%3 ;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int n,q,type,l,r,ind;
    cin>>n;
    string str;
    cin>>str;
    loop(i,0,n-1){
        arr[i] = str[i]-48;
    }
    fastPow();
    build(0, n-1, 1);
    
    cin>>q;
    while(q--){
        cin>>type;
        if(type==0){
            cin>>l>>r;
            int res = query(0, n-1, 1, l, r);
            cout<<res<<endl;
        } else{
            cin>>ind;
            if(str[ind]=='0'){
                    str[ind]='1';
                    arr[ind] = 1;
                    update(0, n-1, 1, ind);
                }
        }
    }
	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

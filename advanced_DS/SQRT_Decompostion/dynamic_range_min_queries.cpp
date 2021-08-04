// Problem Link - https://cses.fi/problemset/task/1649
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

const ll N = 2e5+5;
const ll B = 500;
vi mini(N/B,INT_MAX),l(N/B,0), r(N/B);

ll getBlock(ll id){
	return id/B;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n,q;
	cin>>n>>q;
	ll x[n];
	loop(i,0,n-1) cin>>x[i];
	//precomputation
	loop(i,0,n-1){
		mini[getBlock(i)] = min(mini[getBlock(i)],x[i]);
	}
	loop(i,1,n){
		if(getBlock(i)!=getBlock(i-1)){
			l[getBlock(i)] = i;
			r[getBlock(i-1)] = i-1;
		}
	}
	//handle queries
	while(q--){
		int type;
		cin>>type;
		// loop(i,0,n-1) cout<<x[i]<<" ";
		// cout<<endl;
		if(type==1){
			//point update
			ll k,u;
			cin>>k>>u;
			k--;
			x[k] = u;
			mini[getBlock(k)] = INT_MAX;
			for(int i=l[getBlock(k)]; i<=r[getBlock(k)]; i++){
				mini[getBlock(k)] = min(mini[getBlock(k)],x[i]);
			}
			
		} else {
			//getminimum
			ll a,b;
			cin>>a>>b;
			a--,b--;

			ll blocka = getBlock(a);
			ll blockb = getBlock(b);

			ll i=a, ans = INT_MAX;
			while(getBlock(i)==blocka and i<=b){
				ans = min(ans,x[i]);
				i++;
			}

			for(int j = blocka+1; j<blockb; j++){
				ans = min(ans,mini[j]);
			}

			if(blocka!=blockb){
				i=b;
				while(getBlock(i)==blockb){
					ans = min(ans, x[i]);
					i--;
				}
			}

			cout<<ans<<endl;
		}
	}
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}



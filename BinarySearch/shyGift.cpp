// Problem Link - https://www.codechef.com/problems/ASHIGIFT
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

struct tripl{
public:
    ll x,y,z;

    bool operator < (const struct tripl &c1)const{
        return x < c1.x;
    }
};

bool good(ll mid, vector<pair<ll,ll>>& dishes, vector<tripl> &clans){

    ll i=0, j=0, grp=mid;
    while(i<dishes.size() and j<clans.size()){
        if(dishes[i].ff>=clans[j].x){
            if(clans[j].y<=grp) grp+=clans[j].z;
            j++;
        } else {
            if(dishes[i].ss>grp) return false;
            grp-=dishes[i].ss;
            i++;
        }
    }
    
    while(i<dishes.size()){
        if(dishes[i].ss>grp) return false;
        grp-=dishes[i].ss;
        i++;
    }

    
    return grp>0;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        ll b;
        cin>>b;
        vector<pair<ll,ll>> dishes(b);
        loop(i,0,b-1){
            ll a,b;
            cin>>a>>b;
            dishes[i].ff=a,dishes[i].ss=b;
        }
        sort(dishes.begin(),dishes.end());
        ll c;
        cin>>c;
        vector<tripl> clans(c);
        loop(i,0,c-1){
            ll a,b,c;
            cin>>a>>b>>c;
            clans[i].x=a, clans[i].y=b, clans[i].z=c;
        }
        sort(clans.begin(),clans.end());

        ll lo = 1, hi = 1;
        loop(i,0,b-1){
            hi += dishes[i].ss;
        }
        ll ans=-1;
        while(lo<=hi){
            ll mid = (lo+(hi-lo)/2);
            if(good(mid,dishes,clans)){
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        cout<<ans<<endl;
    }
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

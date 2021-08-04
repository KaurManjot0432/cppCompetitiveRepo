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

const ll N = 1e5+5;
const ll B = 350;
vi mini(N/B,INT_MAX),lazy(N/B,0),l(N/B,0),r(N/B);

ll getBlock(ll id){
    return id/B;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    ll n,q;
    cin>>n>>q;
    vi arr(n);
    loop(i,0,n-1) cin>>arr[i];

    //precomputation
    loop(i,0,n-1){
        mini[getBlock(i)] = min(mini[getBlock(i)],arr[i]);
        if(i>0 and getBlock(i)!=getBlock(i-1)){
            l[getBlock(i)] = i;
            r[getBlock(i-1)] = i-1;
        }
    }
    r[getBlock(n-1)] = n-1;

    //queries
    while(q--){
        char ch;
        cin>>ch;
        if(ch=='q'){
            ll l,r;
            cin>>l>>r;
            l--,r--;

            ll blocka = getBlock(l);
            ll blockb = getBlock(r);

            ll i=l,ans=INT_MAX;
            while(getBlock(i)==blocka and i<=r){
                ans = min(ans,arr[i]+lazy[blocka]);
                i++;
            }

            for(int i=blocka+1; i<blockb; i++){
                ans = min(ans,mini[i]);
            }

            if(blocka!=blockb){
                ll i=r;
                while(getBlock(i)==blockb){
                    ans = min(ans,arr[i]+lazy[blockb]);
                    i--;
                }
            }
            cout<<ans<<endl;

        } else {
            ll x,y,z;
            cin>>x>>y>>z;
            x--,y--;

            ll blocka = getBlock(x);
            ll blockb = getBlock(y);

            ll i=x;
            while(getBlock(i)==blocka and i<=y){
                arr[i]+=z;
                i++;
            }
            //update mini array
            ll s = l[blocka], e = r[blocka];
            mini[blocka] = INT_MAX;
            for(int i=s; i<=e; i++){
                arr[i]+=lazy[blocka];
                mini[blocka] = min(mini[blocka],arr[i]);
            }
            lazy[blocka] = 0;

            for(int i = blocka+1; i<blockb; i++){
                lazy[i]+=z;
                mini[i]+=z;
            }

            if(blocka!=blockb){
                ll i=y;
                while(getBlock(i)==blockb){
                    arr[i]+=z;
                    i--;
                }
                //update mini array
                ll s = l[blockb], e = r[blockb];
                mini[blockb] = INT_MAX;
                for(int i=s; i<=e; i++){
                    arr[i]+=lazy[blockb];
                    mini[blockb] = min(mini[blockb],arr[i]);
                }
                lazy[blockb]=0;
            }


        }
    }
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

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

#define N 100005

int cnt[N];
int chk[N];
int mob[N];
int arr[N];
int freq[N];
ll pow2[N];

void mobius_gen(){
    for(int i=0; i<N; i++) {
        chk[i] = 1;
        cnt[i] = 0;
    }
    for(int i=2; i<N; i++){
        if(cnt[i]) continue;//if num is composite
        for(int j=i; j<N; j+=i){
            chk[j]*=i;
            cnt[j]++;
        }
    }

    for(int i=1; i<N; i++){
        if(chk[i]==i){
            if(cnt[i]&1) mob[i] = -1;
            else mob[i] = 1;
        } else {
            mob[i] =  0;
        }
    }
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    memset(freq,0,sizeof(freq));
    mobius_gen();
    int n;
    cin>>n;
    loop(i,0,n-1){
        cin>>arr[i];
        freq[arr[i]]++;
    }

    pow2[0] = 1;
    for(int i=1; i<N; i++){
        pow2[i] = pow2[i-1]*2;
        pow2[i]%=mod;
    }
    ll ans = 0;
    for(int i=1; i<N; i++){
        int c = 0;
        for(int j=i; j<N; j+=i){
            c+=freq[j];
        }
        ll subseq = pow2[c]-1;
        ans += (mob[i]*subseq);
        ans%=mod;
    }
    ans+=mod;
    cout<<(ans%mod)<<endl;

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

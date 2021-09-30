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
#define N 10000000
bitset<N> sieve;
vi primes;

void gen(){
    sieve.set();
    for(int i=2; i*i<N; i++){
        if(sieve[i]){
            for(int j=i*i; j<N; j+=i){
                sieve[j] = false;
            }
        }
    }
    for(int i=2; i<N; i++) if(sieve[i]) primes.pb(i);
}

void solve(ll n){
    set<ll> used;
    for(int i=2; i*i<=n; i++){
        if(n%i==0 and !used.count(i)){
            used.emplace(i);
            n=n/i;
            break;
        }
    }
    for(int i=2; i*i<=n; i++){
        if(n%i==0 and !used.count(i)){
            used.emplace(i);
            n=n/i;
            break;
        }
    }
    if(used.size()<2 or n==1 or used.count(n)){
        cout<<"NO\n";
    } else {
        cout<<"Yes\n";
        used.emplace(n);
        for(auto it : used){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    gen();
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        solve(n);

        // vi ans(3,-1);
        // ump<ll,ll> m;
        // ll n,num;
        // cin>>n;
        // num=n;
        //     for(int i=0; i<primes.size(); i++){
        //         if(primes[i]<=num){
        //             while(n%primes[i]==0){
        //                 if(m.count(primes[i])) m[primes[i]]++;
        //                 else m[primes[i]] = 1;
        //                 n/=primes[i];
        //             }
        //             if(n==1)break;
        //         } else{
        //           break;
        //         }
        //     }
        //     bool get = false;
        //     // for(auto e : m) cout<<e.ff<<"->"<<e.ss<<endl;

        //     if(m.size()==1){
        //         for(auto e : m){
        //             if(e.ss >=6) {
        //                 get = true;
        //                 ans[0] = e.ff;
        //                 ans[1] = e.ff*e.ff;
        //                 ans[2] = num/(ans[0]*ans[1]);
        //             } else if(e.ss>=3 and n!=1){
        //                 get = true;
        //                 ans[0]  = e.ff;
        //                 ans[1] = e.ff*e.ff;
        //                 ans[2] = num/(ans[0]*ans[1]);
        //             }
        //         }
        //     } else if(m.size()==2){
        //         int p1=-1,p2=-1;
        //         for(auto e : m){
        //             if(p1==-1) p1=e.ff;
        //             else p2=e.ff;
        //         }
        //         int x = num/(p1*p2);
        //         if(x!=1 and x!=p1 and x!=p2){
        //             get = true;
        //             ans[0] = p1;
        //             ans[1] = p2;
        //             ans[2] = x;
        //         }
        //     }
        //     else if(m.size()>=3){
        //         // log(num);
        //         get=true;
        //         int p1=-1,p2=-1;
        //         for(auto e : m){
        //             // log(e.ff);
        //             if(p1==-1) p1=e.ff;
        //             else if(p2==-1) p2=e.ff;
        //             else break;
        //         }
        //         ans[0] = p1;
        //         ans[1] = p2;
        //         ans[2] = num/(p1*p2);
        //     }
        //     if(!get){
        //         cout<<"NO"<<endl;
        //     } else {
        //         cout<<"YES"<<endl;
        //         cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        //     }
        

    }


	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

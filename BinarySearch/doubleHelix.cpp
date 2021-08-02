
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




int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here...
    while(true){
    int n;
    cin>>n;
    if(n==0) break;
    int a[n];
    loop(i,0,n-1) cin>>a[i];
    int m;
    cin>>m;
    int b[m];
    loop(i,0,m-1) cin>>b[i];
    vi a_pre(n),b_pre(m);
    vector<pair<int,int>> meet;
    a_pre[0] = a[0],b_pre[0] = b[0];
    loop(i,1,n-1) a_pre[i] = a[i]+a_pre[i-1];
    loop(i,1,m-1) b_pre[i] = b[i]+b_pre[i-1];
    int i=0,j=0;
    while(i<n and j<m){
        if(a[i]==b[j]){
            meet.push_back(mp(i,j));
            i++,j++;
        } else if(a[i]>b[j]){
            j++;
        } else {
            i++;
        }
    }

//     loop(i,0,meet.size()-1) cout<<meet[i].ff<<" ";
//     cout<<endl;
//  loop(i,0,meet.size()-1) cout<<meet[i].ss<<" ";
//     cout<<endl;

// now i know the intersection points
ll sum =  0;
    loop(k,0,meet.size()-1){
        int a = meet[k].ff, b = meet[k].ss;
        if(k==0){
            if(a_pre[a]  > b_pre[b]){
            sum+=a_pre[a];
            } else {
                sum+=b_pre[b];
            }
        } else {
            if(a_pre[a]-a_pre[meet[k-1].ff]  > b_pre[b]-b_pre[meet[k-1].ss]){
            sum+=(a_pre[a]-a_pre[meet[k-1].ff] );
        } else {
            sum+=(b_pre[b]-b_pre[meet[k-1].ss]);
        }
        }
        
        cout<<sum<<endl;
    }
    ll sum1=0,sum2=0;
    i = meet[meet.size()-1].ff+1;
    j = meet[meet.size()-1].ss+1;
    while(i<n) {
        sum1+=a[i];
        i++;
    }
    while(j<m){
        sum2+=b[j];
        j++;
    }
    sum+=max(sum1,sum2);
    cout<<sum<<endl;
    }

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

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

class query{
    public:
        ll l,r,id;
};

const ll N = 1e5+5, B = 350;
vi tree, start_tm(N), end_tm(N), color(N), freq(N,0), sum(N,0), ans(N);
ump<int,list<int>> m;
ll st=0, mf=INT_MIN;


void dfs(int root){
        st++;
        tree.pb(root);
        start_tm[root] = st;
        for(int child : m[root]){
            dfs(child);
        }
        end_tm[root] = st;
}

bool cmp(query a, query b){
    if(a.l/B==b.l/B) return a.r<b.r;
    return a.l/B < b.l/B;
}

void add(int id){
    int e = color[tree[id]];
    sum[freq[e]] -= e;
    freq[e]++;
    mf = max(mf,freq[e]);
    sum[freq[e]] += e;
}

void remove(int id){
    int e = color[tree[id]];
    sum[freq[e]] -= e;
    if(sum[freq[e]]==0) mf--;
    freq[e]--;
    sum[freq[e]] += e;
    
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    int n;
    cin>>n;
    loop(i,1,n) cin>>color[i];
    int root;
    loop(i,1,n-1){
        int x,y;
        cin>>x>>y;
        if(i==1) root = x;
        m[x].pb(y);
    }

    //tree flattening using dfs
    tree.pb(-1);
    dfs(root);
    // loop(i,1,n) cout<<tree[i]<<" ";
    // cout<<endl;
    // loop(i,1,n) cout<<start_tm[tree[i]]<<" ";
    // cout<<endl;
    // loop(i,1,n) cout<<end_tm[tree[i]]<<" ";
    // cout<<endl;

    vector<query> qu(n+1);
    loop(i,1,n){
        qu[i].l = start_tm[i];
        qu[i].r = end_tm[i];
        qu[i].id = i;
        // cout<<qu[i].l<<" "<<qu[i].r<<" "<<qu[i].id<<endl;
    }


    sort(qu.begin()+1,qu.end(),cmp);
    // loop(i,1,n)  cout<<qu[i].l<<" "<<qu[i].r<<" "<<qu[i].id<<endl;
    int left = 1, right = 0;
    loop(i,1,n){
        if(qu[i].l==qu[i].r){
            ans[qu[i].id] = color[qu[i].id];
        } else {
        int s = qu[i].l, e = qu[i].r;
        while(right<e){
            right++;
            add(right);
        }
        while(left<s){
            remove(left);
            left++;
        }
        while(right>e){
            remove(right);
            right--;
        }
        while(left>s){
            left--;
            add(left);
        }
        log(mf);
        log(sum[mf]);
        ans[qu[i].id] = sum[mf];
        }
    }    
    loop(i,1,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

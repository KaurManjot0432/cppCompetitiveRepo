// Problem Link - https://leetcode.com/problems/maximum-genetic-difference-query/
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
public:
    Node* next[2];
    int freq;
    Node(){
        next[0] = next[1] = NULL;
        this->freq = 0;
    }
    
};

class Trie{
public:
    Node* head;
    Trie(){
        head = new Node;
    }
    void insert(int n){
        Node *curr = head;
        for(int i=18; i>=0; i--){
            int bit = (n>>i)&1;
            if(curr->next[bit]==NULL) curr->next[bit] = new Node;
            curr = curr->next[bit];
            curr->freq++;
        }
    }

    int query(int x){
        Node* curr = head;
        int ans = 0;
        for(int i=18; i>=0; i--){
            int bit = (x>>i)&1;
            if(curr->next[!bit]!=NULL and curr->next[!bit]->freq>0){
                curr = curr->next[!bit];
                ans += (1<<i);
            } else {
                curr = curr->next[bit];
            }
        }
        return ans;
    }

    void remove(int n){
        Node* curr = head;
        for(int i=18; i>=0; i--){
            int bit = (n>>i)&1;
            curr = curr->next[bit];
            curr->freq--;
        }
    }
};

class Solution {
public:
    Trie trie;


    void dfs(int u, vector<vector<int>>& adj,vector<vector<pair<int,int>>>& qsByNode,vector<int>& ans){
        trie.insert(u);

        for(auto& q : qsByNode[u]){
            ans[q.second] = trie.query(q.first);
        }

        for(auto& child : adj[u]){
            dfs(child,adj,qsByNode,ans);
        }
       
        trie.remove(u);
    }

    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        int n = parents.size(), m = queries.size(), root = -1;
        vector<vector<int>> adj(n);
        vector<vector<pair<int,int>>> qsByNode(n);
        vector<int> ans;

        //making graph
        for(int i=0; i<n; i++){
            if(parents[i]==-1) root = i;
            else adj[parents[i]].push_back(i);
        }

       for(int i=0; i<m; i++){
           qsByNode[queries[i][0]].push_back(make_pair(queries[i][1],i));
       }

        dfs(root,adj,qsByNode,ans);
        return ans;
    }

};
 


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....
    int n,m;
    cin>>n>>m;
    vector<int> parents(n);
    vector<vector<int>> queries(m);
    loop(i,0,n-1) cin>>parents[i];
    loop(i,0,m-1){
        int node,val;
        cin>>node>>val;
        queries[i][0] = node;
        queries[i][1] = val;
    }
    Solution s;
    vector<int> ans = s.maxGeneticDifference(parents, queries);
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

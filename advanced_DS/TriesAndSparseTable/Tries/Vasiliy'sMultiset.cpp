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

class Node{
public:
    int freq;
    Node* left;
    Node* right;

    Node(int freq){
        this->freq = freq;
    }
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root = new Node(-1);
    }

    void insert(int n){
        Node* temp = root;
        for(int i=31; i>=0; i--){
            int b = (n>>i)&1;
            if(b==0){
                if(temp->left==NULL) temp->left = new Node(1);
                else temp->left->freq++;
                temp = temp->left;
            } else {
                if(temp->right==NULL) temp->right = new Node(1);
                else temp->right->freq++;
                temp = temp->right;
            }
        }
    }

    void remove(int n){
        Node* temp = root;
        for(int i=31; i>=0; i--){
            int b = (n>>i)&1; 
            if(b==0) {
                temp->left->freq--;
                temp=temp->left;
            }  else {
                temp->right->freq--;
                temp=temp->right;
            }
        }
    }

    ll maxxor(int x){
        Node* temp = root;
        ll ans =  0;
        for(int i=31; i>=0; i--){
            int b = (x>>i)&1;
            if(b==0){
                if(temp->right==NULL || temp->right->freq==0) temp=temp->left;
                else {
                    
                    ans+=(int)pow(2,i);
                    temp=temp->right;
                }
            } else {
                if(temp->left==NULL || temp->left->freq==0) temp = temp->right;
                else {
                    ans+=(int)pow(2,i);
                    temp = temp->left;
                }
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

    int q;
    cin>>q;

    Trie tr;
    tr.insert(0);
    while(q--){
        char type;
        cin>>type;
        if(type=='+'){
            int n;
            cin>>n;
            tr.insert(n);
        } else if(type=='-'){
            int n;
            cin>>n;
            tr.remove(n);
        } else {
            int n;
            cin>>n;
            cout<<tr.maxxor(n)<<endl;
        }
    }
	

	#ifndef ONLINE_JUDGE 
	  clock_t end = clock();
	  cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
	#endif 
	return 0;
}

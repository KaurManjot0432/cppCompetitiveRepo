//link : https://www.codechef.com/JUNE18B/problems/SHKSTR

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>

class Node{
public:
    Node* child[26];
    bool isEnd;
    Node(){
        this->isEnd = false;
        for(int i=0; i<26; i++){
            this->child[i] = 0;
        }
    }
};

Node* head;

void insert(string s){
    Node* curr = head;
    for(char ch : s){
        int c = ch-'a';
        if(!curr->child[c]){
            curr->child[c] = new Node();
        }
        curr = curr->child[c];
    }
    curr->isEnd = true;
}

string query(string s){
    Node* curr = head;
    string res;
    for(char ch : s){
        int c = ch-'a';
        if(!curr->child[c]){
            break;
        }
        curr = curr->child[c];
        res+=ch;
    }
    while(!curr->isEnd){
        for(int i=0; i<26; i++){
            if(curr->child[i]){
                res+=(char)(i+'a');
                curr = curr->child[i];
                break;
            }
        }
    }
    return res;
}


const int N = 1e5+1005;

int main(){

    head = new Node;
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    int q;
    cin>>q;
    vector<string> ans(q);
   vector<pair<string, ll> > v[N];
	for(ll i = 0; i < q; i++) {
		ll r; string p;
		cin >> r >> p;
		v[r - 1].pb(mp(p, i));
	}

    for(int i=0; i<n; i++){
        insert(s[i]);
        for(auto qury : v[i]){
            ans[qury.second] = query(qury.first);
        }
    }

    for(int i=0; i<q; i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

class Trie{
public:
    const static int N = 26;
    const static char basechar = 'a';

    struct TrieNode{
    public:
        int children[N];
        bool isEnd;
        int freq;

        TrieNode(){
            for(int i=0; i<N; i++) children[i] = -1;
            isEnd = false;
            freq=0;
        }
    };

    vector<TrieNode> tree;

    //Base constructor
    Trie(){
        tree.push_back(TrieNode());
    }

    void insert(string str){
        int p = 0;
        tree[p].freq++;
        for(int i=0; i<str.size(); i++){
            if(tree[p].children[str[i]-basechar]==-1){
                tree.push_back(TrieNode());
                tree[p].children[str[i]-basechar] = tree.size()-1;
            }
            p = tree[p].children[str[i]-basechar];
            tree[p].freq++;
        }
        tree[p].isEnd = true;
        cout<<str<<" inserted"<<endl;
    }

    bool search(string str){
        int p = 0;
        for(int i=0; i<str.size(); i++){
            if(tree[p].children[str[i]-basechar]==-1)
                return false;
            p = tree[p].children[str[i]-basechar];
        }
        return tree[p].isEnd;
    }

    void printTrie(int p){
        //simple dfs will print all strings present in the trie
        for(int i=0; i<26; i++){
            if(tree[p].children[i]!=-1){
                char ch = basechar+i;
                cout<<ch;
                if(tree[tree[p].children[i]].isEnd) {
                    cout<<endl;
                    return;
                }
                printTrie(tree[p].children[i]);
            }
        }    

    }

};

int main(){
    file_i_o();

    Trie tr = Trie();
    tr.insert("sam");
    tr.insert("sanket");
    tr.insert("samar");
    tr.insert("samarth");
    tr.insert("samant");
    tr.insert("sagar");
    tr.insert("samual");
    tr.insert("samu");

    // cout<<tr.search("sam")<<endl;
    // cout<<tr.search("sama")<<endl;
    // cout<<tr.search("samar")<<endl;
    // cout<<(tr.search("samar") ? "Yes" : "No")<<endl;
    // cout<<(tr.search("saman") ? "Yes" : "No")<<endl;
    // cout<<(tr.search("samu") ? "Yes" : "No")<<endl;
    // cout<<(tr.search("sama") ? "Yes" : "No")<<endl;

    tr.printTrie(0);

    return 0;
}
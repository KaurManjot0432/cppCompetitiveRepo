#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    bool isTerminal;
    int freq;
    unordered_map<char,Node*> children;

    Node(char ch){
        this->ch = ch;
        freq = 0;
    }
};

class Trie{
    public:
        Node *root;

        Trie(){
            root = new Node('\0');
        }

    void insert(string str){
        Node *temp = this->root;
        for(int i=0; i<str.size(); i++){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            } else {
                Node *n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
            temp->freq++;
        }
        temp->isTerminal = true;
    }

    void convert_into_pre(Node *root, string str,string output){

        char ch = str[output.size()];
        root = root->children[ch];
        if(root->freq>1){
            convert_into_pre(root,str,output+ch);
        }else {
            cout<<(output+ch)<<endl;
            return;
        }
            
    }

    void uniquePrefixArray(string str){
         convert_into_pre(this->root,str,"");
    }

};

int main(){
    int n;
    cin>>n;
    Trie tr;
    vector<string> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        tr.insert(arr[i]);
    }
    for(int i=0; i<n; i++){
         tr.uniquePrefixArray(arr[i]);
    }
   

    return 0;
}
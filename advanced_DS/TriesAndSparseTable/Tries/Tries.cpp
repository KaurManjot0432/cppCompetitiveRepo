#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    char ch;
    bool isTerminal;
    unordered_map<char, Node*> children;

    Node(char ch){
        this->ch = ch;
        this->isTerminal = false;
    }
};

class Trie{
public:
    Node *root;

    Trie(){
        this->root = new Node('\0');
    }

    void insert(string str){
        Node* temp = root;
        for(char ch : str){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            } else {
                Node* n = new Node(ch);
                temp->children[ch]=n;
                temp=n;
            }
        }
        temp->isTerminal = true;
        return;
    }

    bool search(string str){
        Node* temp = root;
        for(char ch : str){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            } else {
               return false;
            }
        }
        return  temp->isTerminal == true;
    }

    void print(){
        dfs("",root);
    }
    void dfs(string sofar,Node* root){
        if(root->isTerminal) {
            cout<<sofar<<endl;
        }
        for(auto child : root->children){
            dfs(sofar+child.first,child.second);
        }
        return;
    }

    void printPrefix(string str){
        Node* temp = root;
        for(char ch : str){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            } else {
               return false;
            }
        }
        dfs(str,temp);
    }
};

int main(){

    Trie tr;
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        tr.insert(str);
    }
    tr.print();
    int s;
    cin>>s;
    while(s--){
        string str;
        cin>>str;
        cout<<((tr.search(str)==1) ? "Yes" : "No");
    }

    return 0;
}
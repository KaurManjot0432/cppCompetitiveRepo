#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    char ch;
    bool isTerminal;
    unordered_map<char,Node*> children;

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
            Node *temp = root;
            for(int i=0; i<str.size(); i++){
                char ch = str[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                } else {
                    Node *n = new Node(ch);
                    temp->children[ch]= n;
                    temp = n;
                }
            }
            temp->isTerminal=true;
            return;
        }

        bool search(string str){
             Node *temp = root;
            for(int i=0; i<str.size(); i++){
                char ch = str[i];
                if(temp->children.count(ch)){
                    temp = temp->children[ch];
                } else {
                   return false;
                }
            }
            return temp->isTerminal;
        
        }

        void print(Node *root,string sofar){
            Node *temp = root;
            if(temp->isTerminal)  {
                cout<<sofar<<endl;
                if(temp->children.size()==0) return;
            }
            for(auto child : temp->children){
               print(child.second,sofar+child.first);
            }

        }
        void print(){
            print(root,"");
        }

        void dfs(Node *root, string pre, string output){
            if(root==NULL) return;
            if(root->isTerminal) cout<<output<<endl;
            for(auto ch : root->children){
                dfs(ch.second,pre,output+ch.first);
            }
        }
    

        void printWithPrefix(string pre){
           Node *temp = this->root;
           for(int i=0; i<pre.size(); i++){
               char ch = pre[i];
               if(temp->children.count(ch)){
                   temp = temp->children[ch];
               } else {
                   return;
               }
           }
        dfs(temp,pre,pre);
        }

};


int main(){
    int n;
    cin>>n;
    Trie tr ;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        tr.insert(s);
    }
    tr.print();
   int t;
   cin>>t;
   while(t--){
       string pre;
       cin>>pre;
       tr.printWithPrefix(pre);
        cout<<"Strings with prefix : "<<pre<<'\n';
   }
    return 0;
}
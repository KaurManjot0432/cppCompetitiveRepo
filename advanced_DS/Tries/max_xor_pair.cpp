#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class TrieNode{
    public:
    TrieNode *left;
    TrieNode *right;
    void insert(int n, TrieNode *root){
        TrieNode *temp = root;
        for(int i=31; i>=0; i--){
            int b = (n>>i)&1;
            if(b==0){
                if(temp->left==NULL){
                    temp->left = new TrieNode();
                }
                temp = temp->left;
            } else {
               if(temp->right==NULL){
                    temp->right = new TrieNode();
                }
                temp = temp->right;
            }

        }
    }
};
 int findMaxXorPair(TrieNode *root, vector<int> &arr){
        int ans = INT_MIN;
        insert(arr[0],root);
        for(int i=1; i<arr.size(); i++){
            int n = arr[i];
            TrieNode *temp = root;
             int curr_xor=0;
            for(int j=31; j>=0; j--){
                int b = (n>>j)&1;
                if(b==0){
                    if(temp->right==NULL){
                        temp = temp->left;
                    }else {
                        curr_xor += (int)pow(2,j);
                        temp = temp->right;
                    }
                }else {
                     if(temp->left==NULL){
                        temp = temp->right;
                    }else {
                        curr_xor += (int)pow(2,j);
                        temp = temp->left;
                    }
                }
            }
            ans = max(ans,curr_xor);
            insert(arr[i],root);
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    TrieNode *tr = new TrieNode();
    cout<<findMaxXorPair(tr,arr);
    return 0;
}
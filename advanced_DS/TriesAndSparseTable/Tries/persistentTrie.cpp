#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 5e6*22;

class Node{
public:
    int left, right, count;
};

Node trie[N];
int root[N];
int new_ptr;

int insert(int prev, int x){
    int temp = new_ptr++;
    int curr = temp;
    trie[curr] = trie[prev];
    for(int i=20; i>=0; i--){
        int bit = (x>>i)&1;
        if(bit){
            trie[curr].right = new_ptr++;   //storing the index no. of right node in curr node
            trie[trie[curr].right] = trie[trie[prev].right]; //copy the node from prev trie..just one node not the whole trie
            trie[trie[curr].right].count++;
            curr = trie[curr].right;
            prev = trie[prev].right;
        } else {
            trie[curr].left = new_ptr++;   //storing the index no. of left node in curr node
            trie[trie[curr].left] = trie[trie[prev].left];
            trie[trie[curr].left].count++;
            curr = trie[curr].left;
            prev = trie[prev].left;
        }
    }
     return temp;
}

int max_xor(int prev, int curr, int x){
    int y=0;
    for(int i=20; i>=0; i--){
        int b = (x>>i)&1;
        if(b){
            if(trie[trie[curr].left].count > trie[trie[prev].left].count ) {
                curr = trie[curr].left;
                prev = trie[prev].left;
            } else {
                curr = trie[curr].right;
                prev = trie[prev].right;
                y+=(1<<i);
            }
        } else {
            if(trie[trie[curr].right].count > trie[trie[prev].right].count){
                curr = trie[curr].right;
                prev = trie[prev].right;
                y+=(1<<i);
            } else {
                curr = trie[curr].left;
                prev = trie[prev].left;
            }
        }
    }
    return y;
}

int less_than_equal_to(int prev, int curr, int x){
    int ans = 0;
    for(int i=20; i>=0; i--){
        int b = (x>>i)&1;
        if(b){
            ans += (trie[trie[curr].left].count - trie[trie[prev].left].count);
            curr = trie[curr].right;
            prev = trie[prev].right;
        } else {
            curr = trie[curr].left;
            prev = trie[prev].left;
        }
    }
    ans+=trie[curr].count-trie[prev].count;
    return ans;
}

int kth_smallest(int prev, int curr, int k){
    int ans=0;
    for(int i=20; i>=0; i--){
        if((trie[trie[curr].left].count - trie[trie[prev].left].count)>=k){
            curr = trie[curr].left;
            prev = trie[prev].left;
        } else {
            k-= (trie[trie[curr].left].count - trie[trie[prev].left].count);
            curr = trie[curr].right;
            prev = trie[prev].right;
            ans+=(1<<i);
        }
    }
    return ans;
}

int main(){

    //initialize all things
    root[0]=0;
    trie[0].left = trie[0].right = trie[0].count = 0;
    new_ptr =  1;

    int n=1;  //n deontes the version of trie
    int m;
    cin>>m;
    while(m--){
        int type;
        cin>>type;
        if(type==0){
            int x;
            cin>>x;
            root[n] = insert(root[n-1],x);
            n+=1;
        } else if(type==1){
            int l,r,x;
            cin>>l>>r>>x;
            cout<<max_xor(root[l-1],root[r],x)<<endl;
        } else if(type==2){
            int k;
            cin>>k;
            n-=k;
        } else if(type==3){
             int l,r,x;
            cin>>l>>r>>x;
            cout<<less_than_equal_to(root[l-1],root[r],x)<<endl;
        } else if(type==4){
             int l,r,k;
            cin>>l>>r>>k;
            cout<<kth_smallest(root[l-1],root[r],k)<<endl;
        }
    }
    return 0;
}

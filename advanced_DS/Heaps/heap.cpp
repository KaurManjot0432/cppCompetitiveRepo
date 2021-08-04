#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void upheapify(vector<int> &heap, int i){
    if(i==0) return;
    int parent = (i-1)/2;
    if(heap[i]>heap[parent]){
        swap(heap[i],heap[parent]);
        upheapify(heap,parent);
    }
}

void downheapify(vector<int> &heap, int i){
    int lc = i*2+1;
    int rc = i*2+2;
    if(lc>=heap.size() and rc>=heap.size()) return;
    int largest = i;
    if(lc<heap.size() and heap[largest]<heap[lc]){
        largest = lc;
    } 
    if(rc<heap.size() and heap[largest]<heap[rc]){
        largest = rc;
    }
    if(largest!=i){
        swap(heap[i],heap[largest]);
        downheapify(heap,largest);
    }
}

void push(vector<int> &heap, int val){
    heap.push_back(val);
    upheapify(heap, heap.size()-1);
}

void pop(vector<int> &heap){
    if(heap.size()==0) {
        cout<<"heap is empty"<<endl;
        return ;
    } 
    if(heap.size()==1){
        heap.pop_back();
        return ;
    }
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downheapify(heap,0);
}

int get(vector<int> &heap){
    if(heap.empty()) {
        cout<<"heap is empty"<<endl;
        return INT_MAX;
    }
    return heap[0];
}

void remove(vector<int> &heap, int i){
    swap(heap[i],heap[heap.size()-1]);
    heap.pop_back();
    downheapify(heap,i);
}

void buildHeapInPlace(vector<int> &arr){
    for(int i=arr.size()-1; i>=0; i--){
        downheapify(arr, i);
    }
}
void downheapifyHeapSort(vector<int> &heap, int i,int size){
    int lc = i*2+1;
    int rc = i*2+2;
    if(lc>=size and rc>=size) return;
    int largest = i;
    if(lc<size and heap[largest]<heap[lc]){
        largest = lc;
    } 
    if(rc<size and heap[largest]<heap[rc]){
        largest = rc;
    }
    if(largest!=i){
        swap(heap[i],heap[largest]);
        downheapifyHeapSort(heap,largest, size);
    }
}

void HeapSortHelper(vector<int>  &heap, int size){
    if(size==1) return;
    swap(heap[0],heap[size-1]);
    size--;
    downheapifyHeapSort(heap, 0, size);
    HeapSortHelper(heap, size);
}

void HeapSort(vector<int> &arr){
    buildHeapInPlace(arr);
    HeapSortHelper(arr, arr.size());
}

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


int main(){
    file_i_o();
    // vector<int> heap;
    // push(heap,25);
    // push(heap,75);
    // push(heap,65);
    // push(heap,285);
    // push(heap,295);
    // push(heap,0);
    // push(heap,50);
    // for(int i=0; i<heap.size(); i++){
    //     cout<<heap[i]<<"  ";
    // }
    // cout<<endl;
    // cout<<get(heap)<<endl;
    // push(heap,1000);
    int n;
    cin>>n;
    vector<int> heap(n);
    for(int i=0; i<n; i++) cin>>heap[i];
    for(int i=0; i<n; i++){
        cout<<heap[i]<<"  ";
    }
    cout<<endl;
    HeapSort(heap);
    for(int i=0; i<n; i++){
        cout<<heap[i]<<"  ";
        // pop(heap);
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* createTree(){
    cout<<"enter a value"<<endl;
    int data;
    cin>> data;

    if(data==-1){
        return NULL;
    }

    // step1:- create node for the new data

    Node* root=new Node(data);

    // step2: make left subtree;
    cout<<"enter the node for the left"<<endl;
    root->left=createTree();
    
    // step3: make right subtree
    cout<<"enter the node for the right"<<endl;
    root->right= createTree();

    return root;

}


int main(){

    Node* root=createTree();
    return 0;
}

// example input
// 10 20 50 65 -1 -1 90 -1 -1 70 -1 -1 30 60 -1 -1 100 -1 -1 30
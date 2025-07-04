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
void leveOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        cout<<front->data<<" ";

        if(front->left !=NULL){
            q.push(front->left);
        }
        if(front->right !=NULL){
            q.push(front->right);

        }
    }
}
void levelOrderPrint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front=q.front();
        q.pop();

        if(front ==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
                cout<<front->data<<" ";

            if(front->left !=NULL){
                q.push(front->left);
            }
            if(front->right !=NULL){
                q.push(front->right);

            }
        }
        
    }
}


int main(){

    Node* root=createTree();

    cout<<"level Order Traversal"<<endl;
    leveOrderTraversal(root);
    cout<<endl;

    cout<<"level Order Printing:"<<endl;
    levelOrderPrint(root);
    return 0;
}
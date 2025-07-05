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
int search(int inOrder[],int size,int ele){
    for(int i=0;i<size;i++){
        if(inOrder[i]==ele){
            return i;
        }
    }
    return -1;
}

void createMapping(int inOrder[],int size,map<int,int> &Value){
 for(int i=0;i<size;i++){
    int ele=inOrder[i];
    Value[ele]=i;
 }
}
Node* constructTreePreIn(int posOrder[],int inOrder[],int size,int &posIndex,int inOrderStart,int inOrderEnd,map<int,int>& value){ //posIndex ko by refence hi pass karna hoga kiyuki backtracing time wapas se 0 se start hoga 
//base condition
    if(posIndex>=size || inOrderStart>inOrderEnd){
        return NULL;
    }
    int ele=posOrder[posIndex];
    posIndex--;

    Node* root=new Node(ele);

    //search this ele from inOrder
    // int position =search(inOrder,size,ele); //t.c=O(n);

    int position=value[ele]; //T.c=o(1) for searching element

    root->right=constructTreePreIn(posOrder,inOrder,size,posIndex,position+1,inOrderEnd,value);
    root->left=constructTreePreIn(posOrder,inOrder,size,posIndex,inOrderStart,position-1,value);

    return root;
}


int main(){

   
    int posOrder[]={8,6,14,4,10,2};//LRN
    int inOrder[]={8,14,6,2,10,4};  //LNR
    int size=6;
    int posOrderIndex=size-1;
    int inOrderStart=0;
    int inOrderEnd=size-1;

    map<int,int> value;
    createMapping(inOrder,size,value);
    Node* root=constructTreePreIn(posOrder,inOrder,size,posOrderIndex,inOrderStart,inOrderEnd,value);

    cout<<"level Order Traversal"<<endl;
    levelOrderPrint(root);
    return 0;
}
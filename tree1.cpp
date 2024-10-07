#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createtree(){
    int val;
    cout<<"enter the value or -1 if dont want the node :";
    cin>>val;
    cout<<endl;

    if(val==-1){
        return NULL;
    }
    // creating the node 
    node* root=new node(val);
    // creteing left tree
    cout<<"what do you want to add in left of "<<root->data<<" : "<<endl;
    root->left=createtree();
    
    // creating right tree
    cout<<"what do you want to add in right of "<<root->data<<" : "<<endl;
    root->right=createtree();

    return root;
    
}
// traversals of the tree
void preordertrav(node* root){
// base case 
    if( root==NULL){
        return ;
    }
    // we need to print node left right 
    // printing the node 
    cout<<root->data<<" " ;
    // printing left child
    preordertrav(root->left);
    // printing right 
    preordertrav(root->right);

}
// inorder
void inordertrav(node* root){
// base case 
    if( root==NULL){
        return ;
    }
    // we need to print  left node right 
    
    // printing left child
    inordertrav(root->left);
    // printing the node 
    cout<<root->data<<" " ;
    // printing right 
    inordertrav(root->right);

}
void postordertrav(node* root){
// base case 
    if( root==NULL){
        return ;
    }
    // we need to print  left node right 
    
    // printing left child
    postordertrav(root->left);
    // printing right 
    postordertrav(root->right);
    // printing the node 
    cout<<root->data<<" " ;

}
// level order traversal
void levelordertrav(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        node* front=q.front();
        q.pop();
        if(front==NULL){
            cout<<endl;
            q.push(NULL);
        }
        else {
            cout<<front->data<<" ";
            if(front->left!=NULL){ 
                q.push(front->left);
            }
            if(front->right!=NULL)
                q.push(front->right);
        }
    }
}

int main(){
    node* root= createtree();
    // cout<<root->data;

    // cout<<"preorder traversal : "<<endl;
    // preordertrav(root);
    // cout<<"inoder traversal : "<<endl;
    // inordertrav(root);
    // cout<<"postoder traversal : "<<endl;
    // postordertrav(root);

    // levelordertrav(root);
    

}
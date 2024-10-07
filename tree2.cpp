#include<iostream>
#include<queue>
#include<map>

using namespace std;

// checking for balanved tree leet 110

// class Solution {
// public:
//     int height(TreeNode* root){
//         if(root==NULL)
//             return NULL;
//         int lh=height(root->left);
//         int rh=height(root->right);

//         return max(lh,rh)+1;
//     }
//     bool isBalanced(TreeNode* root) {
//         // base condition 
//         if(root==NULL)
//             return true;
//         // checking current node
//         int lh=height(root->left);
//         int rh=height(root->right);
//         bool cur=(abs(lh-rh)<=1);

//         bool ltr=isBalanced(root->left);
//         bool rtr=isBalanced(root->right);

//         return (ltr && rtr && cur);
        
//     }
// };

// leet 112 path sum
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     bool solve(TreeNode* root, int targetSum,int sum){
//         if(root==NULL)
//             return false ;
//         sum+=root->val;
//         if(root->left==NULL && root->right ==NULL){
//             if(sum==targetSum)
//                 return true;
//             else{
//                 return false;
//             }
//         }

//         bool ltans=solve(root->left,targetSum,sum);
//         bool rtans=solve(root->right,targetSum,sum);

//         return ltans||rtans;

//     }
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         int sum=0;
//         bool ans=solve(root,targetSum,sum);
//         return ans;
//     }
// };


// leet 113 path sum 2 
// class Solution {
// public:
//     void solve(TreeNode* root, int targetSum,int sum,vector<vector<int>>&ans,vector<int>temp){
//         if(root==NULL)
//             return ;
//         sum+=root->val;
//         temp.push_back(root->val);
//         if(root->left==NULL && root->right ==NULL){
//             if(sum==targetSum)
//                 ans.push_back(temp);
//             else{
//                 return ;
//             }
//         }

//         solve(root->left,targetSum,sum,ans,temp);
//         solve(root->right,targetSum,sum,ans,temp);


//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>>ans;
//         vector<int>temp;
//         int sum=0;
//         solve(root,targetSum,sum,ans,temp);
//         return ans;
//     }
// };


// class Node{
//   public:
// 	int data;
// 	Node* left;
// 	Node* right;

// 	Node(int val) {
// 	  this->data = val;
// 	  this->left = NULL;
// 	  this->right = NULL;
// 	}
// };

// //it returns root node of the created tree
// Node* createTree() {
//   cout << "enter the value for Node: " << endl;
//   int data;
//   cin >> data;

//   if(data == -1) {
// 	return NULL;
//   }
//   //Step1: create Node
//   Node* root = new Node(data);
//   //Step2: Create left subtree
//   //cout << "left of Node: " << root->data << endl;
//   root->left = createTree();
//   //Step3: Craete right subtree
//   //cout << "right of Node: " << root->data << endl;
//   root->right = createTree();
//   return root;

// }

// void preOrderTraversal(Node* root) {
// 	//base case
// 	if(root == NULL) {
// 		return;
// 	}
// 	// N L R
// 	//N 
// 	cout << root->data << " ";
// 	// L
// 	preOrderTraversal(root->left);
// 	// R
// 	preOrderTraversal(root->right);
// }

// void inorderTraversal(Node* root) {
// 	//LNR
// 	//base case
// 	if(root == NULL) {
// 		return;
// 	}
// 	//L
// 	inorderTraversal(root->left);
// 	// N
// 	cout << root->data << " ";
// 	// R
// 	inorderTraversal(root->right);
// }

// void postOrderTraversal(Node* root) {
// 	//LRN
// 	//base case
// 	if(root == NULL) {
// 		return;
// 	}
// 	//L
// 	postOrderTraversal(root->left);
// 	//R
// 	postOrderTraversal(root->right);
// 	//N
// 	cout << root->data << " ";
// }

// void levelOrderTraversal(Node* root) {
// 	queue<Node*> q;
// 	q.push(root);
// 	q.push(NULL);

// 	//asli traversal start krete h 

// 	while(!q.empty()) {
// 		Node* front = q.front();
// 		q.pop();

// 		if(front == NULL) {
// 			cout << endl;
// 			if(!q.empty()) {
// 				q.push(NULL);
// 			}
// 		}
// 		else {
// 			//valid node wala case
// 			cout << front->data << " ";

// 			if(front->left != NULL) {
// 				q.push(front->left);
// 			}
// 			if(front->right != NULL) {
// 				q.push(front->right);
// 			}
// 		}
// 	}
// }

// int searchInorder(int inorder[], int size, int target){
//   for(int i=0; i<size; i++) {
//     if(inorder[i] == target) {
//       return i;
//     }
//   }
//   return -1;
// }

// void createMapping(int inorder[], int size, map<int,int> &valueToIndexMap) {

//     for(int i=0; i<size; i++) {
//       int element = inorder[i];
//       int index = i;
//       valueToIndexMap[element] = index;
//     }

// }

// Node* constructTreeFromPreAndInorderTraversal( map<int,int> &valueToIndexMap, int preOrder[], int inOrder[], int &preIndex, int inOrderStart, int inOrderEnd, int size) {
//   //base case
//   if(preIndex >= size || inOrderStart > inOrderEnd) {
//     return NULL;
//   }

//   //1 case main solve krta hu
//   int element = preOrder[preIndex];
//   preIndex++;
//   Node* root = new Node(element);
//   //element search krna padega  inorder me 
//   //int position = searchInorder(inOrder, size, element);
//   int position = valueToIndexMap[element];
//   //baaaki recursion sambhal lega
//   root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inOrder, preIndex, inOrderStart, position-1, size);

//   root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inOrder, preIndex, position+1, inOrderEnd, size);

//   return root;

// }

// Node* constructTreeFromPostAndInorderTraversal( map<int,int> &valueToIndexMap, int postorder[], int inorder[], int &postIndex, int inorderStart, int inorderEnd, int size) {

//   if(postIndex < 0 || inorderStart > inorderEnd) {
//     return NULL;
//   }

//   //1 case main solve krunga
//   int element = postorder[postIndex];
//   postIndex--;
//   Node* root = new Node(element);
//   //search karo inorder me 
//   int position = valueToIndexMap[element];
//   //baaki recursion sambhal lega
//   //right ki call pehle lagegi
//   root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, position+1, inorderEnd, size);

//   root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postorder, inorder, postIndex, inorderStart, position-1, size);

//   return root;


// }

// int main() {
//   // int inorder[] = {10,8,6,2,4,12};
//   // int preOrder[] = {2,8,10,6,4,12};
//   // int size = 6;
//   // int preOrderIndex = 0;
//   // int inorderStart = 0;
//   // int inorderEnd = 5;
//   // map<int,int> valueToIndexMap;
//   // createMapping(inorder, size, valueToIndexMap);

//   // Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder, inorder, preOrderIndex, inorderStart,inorderEnd, size);

//   int inorder[]= {8,14,6,2,10,4};
//   int postorder[] = {8,6,14,4,10,2};
//   int size = 6;
//   int postIndex = size-1;
//   int inorderStart = 0;
//   int inorderEnd = size-1; 
//   map<int,int> valueToIndexMap;
//   createMapping(inorder, size, valueToIndexMap);
//   Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postorder, inorder, postIndex, inorderStart,inorderEnd, size);
//   cout << "Printing the entire tree: " << endl;
//   levelOrderTraversal(root);
//   return 0;
// }
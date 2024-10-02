#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <assert.h>
using namespace std;

template <typename U> class BinaryTree;

template <typename T>
class Node{
    friend BinaryTree<T>;
    public:
        Node(T val){
            value = val;
            left = nullptr;
            right = nullptr;
        }
        T value;
        Node<T>* left;
        Node<T>* right;
};

template <typename U>
class BinaryTree{
    public:
        Node<U>* head;
        BinaryTree(){
            head = nullptr;
        }
        //expression trees
        void prefix_generator(vector<char> &prefix,Node<U>* node){
            if(node == nullptr)return;
            prefix.push_back(node->value);
            prefix_generator(prefix,node->left);
            prefix_generator(prefix,node->right);
        }
        void postfix_generator(vector<char> &postfix,Node<U>* node){
            if(node == nullptr)return;
            postfix.push_back(node->value);
            postfix_generator(postfix,node->left);
            postfix_generator(postfix,node->right);
        }
        void infix_generator(vector<char> &infix,Node<U>* node){
            if(node == nullptr)return;
            char temp1 = node->value;
            if(temp1 == '+' || temp1 == '-' || temp1 == '*' || temp1 == '/')infix.push_back('(');
            infix_generator(infix,node->left);
            infix.push_back(node->value);
            infix_generator(infix,node->right);
            if(temp1 == '+' || temp1 == '-' || temp1 == '*' || temp1 == '/')infix.push_back(')');
        }

        //dfs traversals
        void preorder_call(vector<U>&preor){
            preorder(head,preor);
        }
        void preorder(Node<U>* node,vector<U>&preor){
            if(node == nullptr)return;
            preor.push_back(node->value);
            preorder(node->left,preor);
            preorder(node->right,preor);
        }
        void preorder_call_refined(){
            preorder_refined(head);
        }
        void preorder_refined(Node<U>* node){
            if(node == nullptr)return;
            cout << "---------------------\n";
            cout << "Node: " << node->value << "\n";
            cout << "Left Child: ";
            if(node->left == nullptr)cout << "nullptr\n";
            else cout << node->left->value <<"\n"; 
            cout << "Right Child: ";
            if(node->right == nullptr)cout << "nullptr\n";
            else cout << node->right->value <<"\n"; 
            preorder_refined(node->left);
            preorder_refined(node->right);
        }
        void inorder_call(vector<U>&inor){
            inorder(head,inor);
        }
        void inorder(Node<U>* node,vector<U>&inor){
            if(node == nullptr)return;
            inorder(node->left,inor);
            inor.push_back(node->value);
            inorder(node->right,inor);
        }
        void postorder_call(vector<U>&postor){
            postorder(head,postor);
        }
        void postorder(Node<U>* node,vector<U>&postor){
            if(node == nullptr)return;
            postorder(node->left,postor);
            postorder(node->right,postor);
            postor.push_back(node->value);
        }
};

//creation of tree from preorder and inorder
Node<int>* tree_from_prein(queue<int> &preorder, vector<int> inorder, int lptr, int rptr){
    if(lptr > rptr)return nullptr;
    if(preorder.empty())return nullptr;
    assert(!preorder.empty());
    int value = preorder.front();
    
    preorder.pop();
    int x;
    for(x = lptr ; x <= rptr ; x++){
        if(inorder[x] == value)break;
    }
    Node<int>* temp = new Node<int>(value);
    temp->left = tree_from_prein(preorder,inorder,lptr,x-1);
    temp->right = tree_from_prein(preorder,inorder,x+1,rptr);
    return temp;
}

//creation of expression tree from postfix expression
Node<char>* expression_tree_from_postfix(stack<char> &s){
    Node<char>* temp = new Node<char>(s.top());
    char temp1 = s.top();
    s.pop();
    if(temp1 == '+' || temp1 == '-' || temp1 == '*' || temp1 == '/'){
        temp->right = expression_tree_from_postfix(s);
        temp->left = expression_tree_from_postfix(s);
    }
    return temp;
}

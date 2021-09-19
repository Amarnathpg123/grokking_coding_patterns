#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};


void right_side_view(Node *root){
    if(not root) return;
    printf("Right side view of the tree: \n");

    queue<Node*> Q;
    Q.push(root);
    while(Q.size()){
        size_t sz = Q.size();
        for(size_t i = sz; i > 0; --i){
            Node *current = Q.front(); Q.pop();
            if(i == 1) printf("%ld\n", current->key);

            if(current->left != nullptr) Q.push(current->left);
            if(current->right != nullptr) Q.push(current->right);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(98);
    root->right->left = new Node(11);
    root->right->right = new Node(5);
    root->left->left->left = new Node(10);
    root->right->right->right = new Node(8);
    
    right_side_view(root);
    return 0;
}
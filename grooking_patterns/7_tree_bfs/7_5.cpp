#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};


unsigned tree_min_height(Node *root){
    if(not root) return 0;

    queue<Node*> Q;
    unsigned min_height = 0;
    Q.push(root);
    while(Q.size()){
        min_height++;
        for(size_t i = Q.size(); i > 0; --i){
            Node *current = Q.front();
            Q.pop();

            if(current->left != nullptr) Q.push(current->left);
            if(current->right != nullptr) Q.push(current->right);

            if(current->left == nullptr and current->right == nullptr) return min_height;
        }
    }
    return min_height;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    // root->left->left = new Node(9);
    root->left->right = new Node(98);
    root->right->left = new Node(11);
    root->right->right = new Node(5);
    // root->left->left->left = new Node(10);
    root->right->right->right = new Node(8);
    
    printf("Minimum height of the tree: %u\n", tree_min_height(root));

    return 0;
}
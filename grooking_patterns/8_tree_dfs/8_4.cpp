#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    unsigned key;
    Node* left;
    Node* right;

    Node(unsigned key_): key(key_), left(nullptr), right(nullptr) {}
};

bool has_path_sequence(Node *root, unsigned const &path_sequence, unsigned path){
    if(not root) return false;

    path = 10*path + root->key;

    if(not root->left and not root->right)
        if(path == path_sequence) return true;

    return has_path_sequence(root->left, path_sequence, path) or \
            has_path_sequence(root->right, path_sequence, path);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(1);
    root->left = new Node(0);
    root->right = new Node(1);
    root->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(5);

    unsigned path_sequence = 116;
    if(has_path_sequence(root, path_sequence, 0)) printf("Yes tree has path sequence %u\n", path_sequence);
    else printf("No tree doesn't have path sequence %u\n", path_sequence);
    return 0;
}
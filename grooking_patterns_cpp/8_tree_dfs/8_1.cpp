#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

bool has_path(Node *root, long sum){
    if(not root) return false;

    if(root->key == sum and not root->left and not root->right)
        return true;

    return has_path(root->left, sum-root->key) or has_path(root->right, sum-root->key);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    long sum = 0;

    sum = 23;
    if(has_path(root, sum)) printf("Yes, path found with sum %ld\n", sum);
    else printf("No path found with sum %ld\n", sum);

    sum = 16;
    if(has_path(root, sum)) printf("Yes, path found with sum %ld\n", sum);
    else printf("No path found with sum %ld\n", sum);
    return 0;
}
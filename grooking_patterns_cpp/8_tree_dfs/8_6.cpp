#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

unsigned find_height(Node *root, unsigned &diameter){
    if(not root) return 0;

    unsigned left_height = find_height(root->left, diameter);
    unsigned right_height = find_height(root->right, diameter);

    unsigned temp = left_height+right_height+1;
    diameter = max(diameter, temp);

    return max(left_height,right_height)+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    unsigned diameter = 0;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    find_height(root, diameter);
    printf("Diameter of the tree is: %u\n", diameter);
    
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->left->right->left = new Node(10);
    root->right->right->left->left = new Node(11);

    find_height(root, diameter);
    printf("Diameter of the tree is: %u\n", diameter);
    return 0;
}
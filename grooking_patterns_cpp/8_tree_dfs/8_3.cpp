#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

unsigned long find_path_sums(Node *root, unsigned long path_sum){
    if(not root) return 0;

    path_sum = 10*path_sum + root->key;

    if(not root->left and not root->right)
        return path_sum;

    return find_path_sums(root->left, path_sum) + find_path_sums(root->right, path_sum);
}

unsigned long find_allpath_sum(Node *root){
    return find_path_sums(root, 0);
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

    printf("All path sum is: %lu \n", find_allpath_sum(root));
    return 0;
}
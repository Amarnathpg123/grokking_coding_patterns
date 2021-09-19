#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

long find_max_sum_n2n(Node *root, long &max_sum){
    if(not root) return 0;

    long left_sum_max = max(find_max_sum_n2n(root->left, max_sum),long(0));
    long right_sum_max = max(find_max_sum_n2n(root->right, max_sum),long(0));

    long local_sum = left_sum_max+right_sum_max+root->key;

    max_sum = max(max_sum, local_sum);

    return max(left_sum_max, right_sum_max)+root->key;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    long max_sum = INT64_MIN;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    find_max_sum_n2n(root, max_sum);
    printf("Max sum between node to node is: %ld\n", max_sum);

    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->left = new Node(9);
    max_sum = INT64_MIN;
    find_max_sum_n2n(root, max_sum);
    printf("Max sum between node to node is: %ld\n", max_sum);

    root = new Node(-1);
    root->left = new Node(-3);
    max_sum = INT64_MIN;
    find_max_sum_n2n(root, max_sum);
    printf("Max sum between node to node is: %ld\n", max_sum);

    return 0;
}
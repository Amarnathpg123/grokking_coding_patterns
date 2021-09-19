#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

void find_all_paths(Node *root, long const &sum, size_t &path_count, vector<long> &current_path){
    if(not root) return;

    if(current_path.size()) 
        transform(current_path.begin(), current_path.end(), current_path.begin(), [&](long x){return x+root->key;});
    current_path.push_back(root->key);

    for(auto &i: current_path)
        if(i == sum) path_count++;

    if(root->left or root->right){
        find_all_paths(root->left, sum, path_count, current_path);
        find_all_paths(root->right, sum, path_count, current_path);
    }
    transform(current_path.begin(), current_path.end(), current_path.begin(), [&](long x){return x-current_path.back();});
    current_path.pop_back();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(4);
    root->right->left = new Node(10);
    root->right->right = new Node(5);

    long sum = 0;
    size_t path_count = 0;
    vector<long> current_path = {};

    sum = 11;
    path_count = 0;
    current_path.clear();
    find_all_paths(root, sum, path_count, current_path);
    printf("Path count with path sum %ld is: %lu\n", sum, path_count);
    return 0;
}
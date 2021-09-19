#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

void find_all_paths(Node *root, long sum, vector<long> &current_path, vector<vector<long>> &allpaths){
    if(not root) return;

    current_path.push_back(root->key);
    if(root->key == sum and not root->left and not root->right)
        allpaths.push_back(current_path);

    else{
        find_all_paths(root->left, sum-root->key, current_path, allpaths);
        find_all_paths(root->right, sum-root->key, current_path, allpaths);
    }
    current_path.pop_back();
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
    vector<vector<long>> allpaths = {};
    vector<long> current_path = {};

    sum = 23;
    allpaths.clear();
    current_path.clear();
    find_all_paths(root, sum, current_path, allpaths);

    printf("All paths for the sum %ld are: \n", sum);
    for(vector<long> &temp: allpaths){
        for(long &i: temp) printf("%ld->", i);
        printf("null\n");
    }

    sum = 16;
    allpaths.clear();
    current_path.clear();
    find_all_paths(root, sum, current_path, allpaths);

    printf("\nAll paths for the sum %ld are: \n", sum);
    for(vector<long> &temp: allpaths){
        for(long &i: temp) printf("%ld->", i);
        printf("null\n");
    }
    return 0;
}
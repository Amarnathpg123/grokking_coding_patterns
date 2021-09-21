#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

void averages_of_levels(Node *root, vector<long> &averages){
    if(not root) return;

    queue<Node*> Q;
    Q.push(root);
    while(Q.size()){
        size_t sz = Q.size();
        long long level_sum = 0;
        for(size_t i = Q.size(); i > 0; --i){
            Node *current = Q.front(); Q.pop();
            level_sum += current->key;

            if(current->left != nullptr) Q.push(current->left);
            if(current->right != nullptr) Q.push(current->right);
        }
        averages.push_back(level_sum/sz);
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
    
    vector<long> averages;
    printf("Averages of levels are: ");
    averages_of_levels(root, averages);
    for(auto &i: averages) printf("%ld ", i);
    cout << endl;

    return 0;
}
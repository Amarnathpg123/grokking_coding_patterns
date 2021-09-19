#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(nullptr), right(nullptr) {}
};

class tree_level_order{
    vector<long> level_order_vector;
    Node *root = nullptr;

    void make_level_order(Node *root){
        if(not root) return;

        queue<Node*> Q;
        Q.push(root);
        while(Q.size()){
            for(size_t i = Q.size(); i > 0; --i){
                Node *current = Q.front(); Q.pop();
                level_order_vector.push_back(current->key);

                if(current->left != nullptr) Q.push(current->left);
                if(current->right != nullptr) Q.push(current->right);
            }
        }
    }
public:
    tree_level_order(Node *root_): root(root_){
        make_level_order(root);
    }

    long find_successor(long const &key) const{
        for(size_t i = 0; i < this->level_order_vector.size(); ++i)
            if(level_order_vector.at(i) == key){
                if(i >= level_order_vector.size()-1) return INT64_MIN;
                return level_order_vector.at(i+1);
            }
        return INT64_MIN;
    }

};

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
    
    tree_level_order *tree = new tree_level_order(root);
    long key;

    key = 12;
    printf("Level Order Successor of node %ld is %ld \n", key, tree->find_successor(key));

    key = 7;
    printf("Level Order Successor of node %ld is %ld \n", key, tree->find_successor(key));

    key = 11;
    printf("Level Order Successor of node %ld is %ld \n", key, tree->find_successor(key));

    return 0;
}
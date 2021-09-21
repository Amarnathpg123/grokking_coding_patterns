#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_): key(key_), left(NULL), right(NULL) {}
};

void rev_level_order_traversal(Node *root=nullptr){
    printf("Reverse Level Order Tree Traversal: \n");
    if(not root) return;

    queue<Node*> Q;
    vector<Node*> vec;
    Q.push(root);
    Q.push(nullptr);

    while(Q.size() > 1){
        Node *current = Q.front();
        vec.push_back(current);
        Q.pop();

        if(not current){
            Q.push(nullptr);
            continue;
        }

        if(current->left) Q.push(current->left);
        if(current->right) Q.push(current->right);
    }

    while(vec.size()){
        Node* current = vec.back();
        vec.pop_back();
        if(not current) printf("\n");
        else printf("%ld ", current->key);
    }
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    Node *root = new Node(12);
    root->left = new Node(7);
    root->right = new Node(1);
    root->left->left = new Node(9);
    root->left->right = new Node(99);
    root->right->left = new Node(10);
    root->right->right = new Node(5);
    
    rev_level_order_traversal(root);
    return 0;
}
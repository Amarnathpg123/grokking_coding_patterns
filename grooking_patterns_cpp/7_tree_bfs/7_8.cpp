#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;
    Node* next;

    Node(long key_): key(key_), left(nullptr), right(nullptr), next(nullptr) {}
};

void point_to_next_level_order(Node *root){
    if(not root) return;

    queue<Node*> Q;
    Q.push(root);
    Node *previous = nullptr;
    while(Q.size()){
        size_t sz = Q.size();
        for(size_t i = sz; i > 0; --i){
            Node *current = Q.front(); Q.pop();
            if(previous) previous->next = current;
            previous = current;

            if(current->left) Q.push(current->left);
            if(current->right) Q.push(current->right);
        }
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
    
    point_to_next_level_order(root);

    printf("Testing level order traversal: \n");
    Node *temp = root;
    while(temp != nullptr){
        printf("%ld ", temp->key);
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long key;
    Node* left;
    Node* right;

    Node(long key_) : key(key_), left(NULL), right(NULL) {}
    Node(long key_, Node* left_, Node* right_) : key(key_), left(left_), right(right_) {}
};

void level_order_traversal(Node *root=nullptr){
    printf("Level Order Tree Traversal: \n");
    if(not root) return;

    queue<Node*> Q;
    Q.push(root);
    Q.push(nullptr);

    while(Q.size() > 1){
        Node *current = Q.front();
        Q.pop();

        if(not current){
            printf("\n");
            Q.push(nullptr);
            continue;
        }
        printf("%ld ", current->key);

        if(current->left) Q.push(current->left);
        if(current->right) Q.push(current->right);
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
    
    level_order_traversal(root);
    return 0;
}
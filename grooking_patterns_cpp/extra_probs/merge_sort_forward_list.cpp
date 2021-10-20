#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

void findSize(int &n, ListNode *A) {
    while(A) n++, A = A->next;
}

ListNode* mergeSort(int n, ListNode *A) {
    if(not A->next) return A;

    ListNode *left = A, *right, *tmp = A, *sorted = NULL;
    int mid = n/2;
    while(mid-- > 1) tmp = tmp->next;
    right = tmp->next; tmp->next = NULL;
    mid = n/2;

    left = mergeSort(mid, left);
    right = mergeSort(mid, right);
    tmp = NULL;

    while(left and right) {
        if(left->val < right->val) {
            if(not tmp) {
                tmp = left;
                left = left->next;
                tmp->next = NULL;
                sorted = tmp;
            }
            else {
                tmp->next = left;
                left = left->next;
                tmp = tmp->next;
                tmp->next = NULL;
            }
        }
        else {
            if(not tmp) {
                tmp = right;
                right = right->next;
                tmp->next = NULL;
                sorted = tmp;
            }
            else {
                tmp->next = right;
                right = right->next;
                tmp = tmp->next;
                tmp->next = NULL;
            }
        }
    }

    if(left) tmp->next = left;
    if(right) tmp->next = right;
    return sorted;
}

ListNode* sortList(ListNode* A) {
    if(not A or not A->next) return A;

    int n = 0;
    findSize(n, A);

    return mergeSort(n, A);
}

void printList(ListNode *A) {
    while(A) cout << A->val << " ", A = A->next;
    cout << endl;
}

ListNode* push(vector<int> &arr) {
    ListNode *t = new ListNode(0), *h = NULL;
    h = t;
    for(int i = 0; i < arr.size(); ++i) {
        if(i == 0) t->val = arr[i];
        else t->next = new ListNode(arr[i]), t = t->next;
    }
    return h;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    vector<int> arr = {5, 66, 68, 42, 73, 25, 84, 63, 72, 20, 77, 38, 8, 99, 92, 49, 74, 45, 30, 51, 50, 95, 56, 19, 31, 26, 98, 67, 100, 2, 24, 6, 37, 69, 11, 16, 61, 23, 78, 27, 64, 87, 3, 85, 55, 22, 33, 62};
    ListNode *A = push(arr);
    printList(sortList(A));
    return 0;
}
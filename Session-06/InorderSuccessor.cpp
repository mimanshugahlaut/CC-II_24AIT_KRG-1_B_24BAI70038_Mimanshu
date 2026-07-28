/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        Node* curr = root;
        Node* successor = nullptr;
        
        while (curr != nullptr && curr->data != k->data) {
            if (k->data < curr->data) {
                successor = curr;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        
        if(curr == nullptr) return -1;
        
        if(curr->right != nullptr) {
            successor = curr->right;
            while (successor->left != nullptr) successor = successor->left;
        }
        
        if (successor != nullptr) return successor->data;
        
        return -1;
    }
};

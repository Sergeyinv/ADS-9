// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

template <typename T>
class BST {
 private:
    struct Node {
        T data;
        int count = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };
    Node* m_root;

    Node* createNode(Node* root, const T& data) {
        if (root == nullptr) {
            root = new Node;
            root->data = data;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->data < data) {
            root->left = createNode(root->left, data);
        } else if (root->data > data) {
            root->right = createNode(root->right, data);
        } else {
            ++(root->count);
        }
        return root;
    }

    int searchNode(Node* root, const T& data) {
        if (root == nullptr) {
            return 0;
        } else if (root->data == data) {
            return root->count;
        } else if (root->data < data) {
            return searchNode(root->left, data);
        } else {
            return searchNode(root->right, data);
        }
    }

    int treeDepth(Node* root) {
        int left = 0, right = 0;
        if (root == nullptr) {
            return 0;
        } else {
            left = treeDepth(root->left);
            right = treeDepth(root->right);
        }
        if (right > left) {
            return ++right;
        } else {
            return ++left;
        }
    }

 public:
    BST() :m_root(nullptr) {}
    void CreateNode(const T& data) { m_root = createNode(m_root, data); }
    int search(const T& data) { return searchNode(m_root, data); }
    int depth() { return treeDepth(m_root) - 1; }
};

#endif  // INCLUDE_BST_H_

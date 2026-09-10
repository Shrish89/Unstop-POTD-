#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Build tree from level order
Node* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) {
        return NULL;
    }

    Node* root = new Node(arr[0]);

    vector<Node*> nodes;
    nodes.push_back(root);

    int index = 1;

    for (int i = 0; i < nodes.size() && index < arr.size(); i++) {

        if (arr[index] != -1) {
            nodes[i]->left = new Node(arr[index]);
            nodes.push_back(nodes[i]->left);
        }
        index++;

        if (index < arr.size() && arr[index] != -1) {
            nodes[i]->right = new Node(arr[index]);
            nodes.push_back(nodes[i]->right);
        }
        index++;
    }

    return root;
}

// Check if two trees are flip equivalent
bool isSame(Node* root1, Node* root2) {

    // Both are NULL
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    // One is NULL and other is not
    if (root1 == NULL || root2 == NULL) {
        return false;
    }

    // Values must be same
    if (root1->data != root2->data) {
        return false;
    }

    // Case 1: No swap
    bool noSwap = isSame(root1->left, root2->left) &&
                  isSame(root1->right, root2->right);

    // Case 2: Swap left and right
    bool swap = isSame(root1->left, root2->right) &&
                isSame(root1->right, root2->left);

    return noSwap || swap;
}

int main() {

    string line1, line2;

    getline(cin, line1);
    getline(cin, line2);

    stringstream ss1(line1);
    stringstream ss2(line2);

    vector<int> arr1;
    vector<int> arr2;

    int x;

    while (ss1 >> x) {
        arr1.push_back(x);
    }

    while (ss2 >> x) {
        arr2.push_back(x);
    }

    Node* root1 = buildTree(arr1);
    Node* root2 = buildTree(arr2);

    if (isSame(root1, root2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
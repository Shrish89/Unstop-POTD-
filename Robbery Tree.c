#include <bits/stdc++.h>

using namespace std;

struct Tree {
    int val;
    Tree* left;
    Tree* right;
};

Tree* newNode(string value) {
    Tree *cur = new Tree;
    int data = stoi(value);
    cur->val = data;
    cur->left = NULL;
    cur->right = NULL;
    return cur;
}

Tree* insert(vector<string> v, int i) {
    int n = v.size();
    if(i >= n) return NULL;
    if(v[i] == "null") return NULL;
    Tree* root = newNode(v[i]);
    root->right = insert(v, 2 * i + 2);
    root->left = insert(v, 2 * i + 1);
    return root;
}

unordered_map<Tree*, int> dp;

int DP(Tree* root) {
    if(root == NULL) return 0;
    if(dp.count(root)) return dp[root];
    int res = DP(root->left) + DP(root->right), cur = root->val;
    if(root->left) cur += DP(root->left->left) + DP(root->left->right);
    if(root->right) cur += DP(root->right->left) + DP(root->right->right);
    return dp[root] = max(cur, res);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    vector<string> v;
    while(cin >> s) {
        v.push_back(s);
    }
    Tree* root = insert(v, 0);
    dp.clear();
    cout << DP(root);
    return 0;
}
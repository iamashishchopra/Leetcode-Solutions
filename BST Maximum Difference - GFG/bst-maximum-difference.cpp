//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    vector<Node*> targetNodes;
    int maxSumFromRootToTarget = INT_MIN, minSumFromTargetToLeaf = 1e5+1;
public:
    void findMax2(Node* root, int target, int& sum) {
        
        if(!root)return;
        
        sum += root->data;
        
        if(!root->left and !root->right) {
            minSumFromTargetToLeaf = min(minSumFromTargetToLeaf, sum);
        }
        
        findMax2(root->left,target,sum);
        findMax2(root->right,target,sum);
        
        sum -= root->data;
    }
    void findMax1(Node* root, int target, int& sum) {
        if(!root)return;
        
        if(root->data == target) {
            targetNodes.push_back(root);
            maxSumFromRootToTarget = max(maxSumFromRootToTarget,sum);
        }
        
        sum += root->data;
        findMax1(root->left,target,sum);
        findMax1(root->right,target,sum);
        sum -= root->data;
    }
    int maxDifferenceBST(Node *root,int target){
        int sum = 0;
        findMax1(root,target,sum);
        
        if(maxSumFromRootToTarget == INT_MIN)return -1;
        
        sum = 0;
        for(auto &node: targetNodes) {
            findMax2(node->left,target,sum);
            sum = 0;
            findMax2(node->right,target,sum);
            sum = 0;
        }
        if(minSumFromTargetToLeaf == 1e5+1)return maxSumFromRootToTarget;
        
        return maxSumFromRootToTarget - minSumFromTargetToLeaf;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
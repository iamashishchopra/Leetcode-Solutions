/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public int rangeSumBST(TreeNode root, int low, int high) {
        int sum[] = new int[1];
        traversal(root, low, high, sum);
        return sum[0];
    }

    private void traversal(TreeNode root, int low, int high, int sum[]) {
        if (root == null) return;
        if (root.val <= high && root.val >= low) sum[0] += root.val;
        traversal(root.left, low, high, sum);
        traversal(root.right, low, high, sum);
    }
}

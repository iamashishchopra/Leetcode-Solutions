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

    public int longestUnivaluePath(TreeNode root) {
        int[] max = new int[1];
        helpUnivalue(root, max);
        return Math.max(max[0]-1,0);
    }

    private int helpUnivalue(TreeNode root, int[] max) {
        if (root == null) return 0;
        int left = helpUnivalue(root.left, max);
        int right = helpUnivalue(root.right, max);
        if (root.left != null && root.left.val == root.val && root.right != null && root.right.val == root.val) {
            max[0] = Math.max(max[0], left + 1 + right);
            return 1 + Math.max(left, right);
        } else if (root.left != null && root.left.val == root.val) {
            max[0] = Math.max(max[0], left + 1);
            return 1 + left;
        } else if (root.right != null && root.right.val == root.val) {
            max[0] = Math.max(max[0], right + 1);
            return 1 + right;
        }
        return 1;
    }
}

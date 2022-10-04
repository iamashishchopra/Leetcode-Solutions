/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {

    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        TreeNode ans[] = new TreeNode[1];
        traversal(original, cloned, target, ans);
        return ans[0];
    }

    private void traversal(TreeNode original, TreeNode cloned, TreeNode target, TreeNode ans[]) {
        if (original == null) return;

        if (original.val == target.val) ans[0] = cloned;

        traversal(original.left, cloned.left, target, ans);
        traversal(original.right, cloned.right, target, ans);
    }
}

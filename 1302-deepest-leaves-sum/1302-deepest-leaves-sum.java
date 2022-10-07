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

    public int deepestLeavesSum(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        int sum = 0;

        q.offer(root);

        while (!q.isEmpty()) {
            int s = q.size();
            sum = 0;
            for (int i = 0; i < s; i++) {
                TreeNode temp = q.poll();
                sum += temp.val;
                if (temp.left != null) q.offer(temp.left);
                if (temp.right != null) q.offer(temp.right);
            }
        }

        return sum;
    }
}

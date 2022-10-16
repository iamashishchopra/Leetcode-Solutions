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

    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if (depth == 1) {
            TreeNode node = new TreeNode(val);
            node.left = root;
            return node;
        }
        if (root == null) return root;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        int counter = 1;
        while (!q.isEmpty()) {
            counter++;
            if (counter == depth) break;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode temp = q.poll();
                if (temp.left != null) q.offer(temp.left);
                if (temp.right != null) q.offer(temp.right);
            }
            
        }
        while (!q.isEmpty()) {
            TreeNode temp = q.poll();
            
                TreeNode l = new TreeNode(val);
                l.left = temp.left;
                temp.left = l;
            
            
                TreeNode r = new TreeNode(val);
                r.right = temp.right;
                temp.right = r;
            
        }
        return root;
    }
}

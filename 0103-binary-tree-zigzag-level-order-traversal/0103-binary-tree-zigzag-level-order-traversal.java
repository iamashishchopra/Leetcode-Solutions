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

    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        boolean flag = false;
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        if (root == null) return ans;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while (!q.isEmpty()) {
            int size = q.size();
            LinkedList<Integer> sublist = new LinkedList<Integer>();
            for (int i = 0; i < size; i++) {
                TreeNode temp = q.poll();
                if (temp.left != null) q.add(temp.left);
                if (temp.right != null) q.add(temp.right);
                if (flag) sublist.addFirst(temp.val); else sublist.addLast(temp.val);
               
            }
            flag=!flag;
            ans.add(sublist);
        }
        return ans;
    }
}

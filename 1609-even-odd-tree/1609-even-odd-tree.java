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

    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        int level = 0;
        int last = 0;
        boolean flag = true;
        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> lis = new LinkedList<Integer>();
            for (int i = 0; i < size; i++) {
                TreeNode temp = queue.poll();
                if (temp.left != null) queue.offer(temp.left);
                if (temp.right != null) queue.offer(temp.right);
                lis.add(temp.val);
                if (level % 2 == 0) {
                    if (temp.val % 2 == 0) flag = false;
                    if (i != 0) {
                        if (temp.val <= last) flag = false;
                    }
                } else {
                    if (temp.val % 2 != 0) flag = false;
                    if (i != 0) {
                        if (temp.val >= last) flag = false;
                    }
                }

                last = temp.val;
            }
            level++;
        }
        return flag;
    }
}

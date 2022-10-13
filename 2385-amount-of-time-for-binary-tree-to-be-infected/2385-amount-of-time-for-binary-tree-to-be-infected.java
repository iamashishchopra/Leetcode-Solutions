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
import java.util.HashMap;

class Solution {

    private TreeNode mapParents(TreeNode root, Map<TreeNode, TreeNode> map, int start) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        TreeNode node=new TreeNode(-1);
        while (!q.isEmpty()) {
            TreeNode temp = q.poll();
            if (temp.val == start) node = temp;
            if (temp.left != null) {
                q.add(temp.left);
                map.put(temp.left, temp);
            }
            if (temp.right != null) {
                q.add(temp.right);
                map.put(temp.right, temp);
            }
        }
        return node;
    }

    public int amountOfTime(TreeNode root, int start) {
        Map<TreeNode, TreeNode> map = new HashMap<>();
        TreeNode s = mapParents(root, map, start);
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        Map<TreeNode, Boolean> vis = new HashMap<>();
        q.offer(s);
        vis.put(s, true);
        int counter = 0;
        while (!q.isEmpty()) {
            int flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode temp = q.poll();
                if (temp.left != null && vis.get(temp.left) == null) {
                    q.offer(temp.left);
                    vis.put(temp.left, true);
                    flag = 1;
                }
                if (temp.right != null && vis.get(temp.right) == null) {
                    q.offer(temp.right);
                    vis.put(temp.right, true);
                    flag = 1;
                }
                if (map.get(temp) != null && vis.get(map.get(temp)) == null) {
                    q.offer(map.get(temp));
                    vis.put(map.get(temp), true);
                    flag = 1;
                }
            }
            if (flag == 1) counter++;
        }
        return counter;
    }
}

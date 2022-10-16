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

    private void mapParents(TreeNode root, Map<TreeNode, TreeNode> map) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while (!q.isEmpty()) {
            TreeNode temp = q.poll();
            if (temp.left != null) {
                map.put(temp.left, temp);
                q.add(temp.left);
            }
            if (temp.right != null) {
                map.put(temp.right, temp);
                q.add(temp.right);
            }
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        int counter = 0;
        Map<TreeNode, TreeNode> map = new HashMap<TreeNode, TreeNode>();
        mapParents(root, map);
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<Integer> lis = new LinkedList<Integer>();
        Map<TreeNode, Boolean> vis = new HashMap<TreeNode, Boolean>();
        q.offer(target);
        vis.put(target, true);
        while (!q.isEmpty()) {
            if (counter == k) break;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode temp = q.poll();
                if (temp.left != null && vis.get(temp.left) == null) {
                    q.add(temp.left);
                    vis.put(temp.left, true);
                }
                if (temp.right != null && vis.get(temp.right) == null) {
                    q.add(temp.right);
                    vis.put(temp.right, true);
                }
                if (map.get(temp) != null && vis.get(map.get(temp)) == null) {
                    q.add(map.get(temp));
                    vis.put(map.get(temp), true);
                }
            }
            counter++;
        }
        while (!q.isEmpty()) lis.add(q.poll().val);
        return lis;
    }
}

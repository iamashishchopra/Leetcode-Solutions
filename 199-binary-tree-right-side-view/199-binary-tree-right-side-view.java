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
class Pair {
    TreeNode node;
    int l;

    public Pair(TreeNode _node, int _l) {
        node = _node;
        l = _l;
    }
}

class Solution {

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        Queue<Pair> q = new LinkedList<Pair>();
        Map<Integer, Integer> map = new TreeMap<>();
        q.offer(new Pair(root, 0));
        while (!q.isEmpty()) {
            Pair it = q.poll();
            TreeNode node = it.node;
            int level = it.l;
            map.put(level, node.val);
            if (node.left != null) q.offer(new Pair(node.left, level + 1));
            if (node.right != null) q.offer(new Pair(node.right, level + 1));
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) ans.add(entry.getValue());

        return ans;
    }
}

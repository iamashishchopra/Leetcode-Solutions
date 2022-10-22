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

    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode cur = dfs(root, x);
        System.out.println(cur.val);
        int left = 0;
        int right = 0;
        if (cur.left != null) left = countNodes(cur.left);
        if (cur.right != null) right = countNodes(cur.right);
        int parent = n - left - right - 1;
        //System.out.println(parent);
        if (left > n / 2 || right > n / 2 || parent > n / 2) return true;
        return false;
    }

    private TreeNode dfs(TreeNode root, int n) {
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        TreeNode z=null;
        q.offer(root);
        while(!q.isEmpty()){
            TreeNode temp=q.poll();
            if(temp.val==n)
                z=temp;
            if(temp.left!=null)
                q.add(temp.left);
            if(temp.right!=null)
                q.add(temp.right);
        }
        return z;
    }

    private int countNodes(TreeNode root) {
        if (root == null) return 0;
        int left = countNodes(root.left);
        int right = countNodes(root.right);
        return 1 + left + right;
    }
}

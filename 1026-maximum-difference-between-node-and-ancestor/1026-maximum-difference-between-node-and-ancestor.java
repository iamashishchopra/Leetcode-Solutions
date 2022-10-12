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

    public int maxAncestorDiff(TreeNode root) {
        int difference[] = new int[1];
        List<Integer> lis = new LinkedList<Integer>();
        helpMaxAncestorDiff(root, difference, lis);
        return difference[0];
    }

    private void helpMaxAncestorDiff(TreeNode root, int[] difference, List<Integer> lis) {
        if (root == null) return;
        
        lis.add(root.val);
        for(int it:lis)
        difference[0]=Math.max(difference[0],Math.abs(root.val-it));
        helpMaxAncestorDiff(root.left,difference,lis);
        helpMaxAncestorDiff(root.right,difference,lis);
        
        lis.remove(lis.size()-1);
    }
}

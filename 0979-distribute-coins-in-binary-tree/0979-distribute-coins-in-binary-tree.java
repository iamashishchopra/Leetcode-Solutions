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
    public int distributeCoins(TreeNode root) {
        int moves[]=new int[1];
        helpDistribute(root,moves);
        return moves[0];
    }
    private int helpDistribute(TreeNode root,int[] moves){
        if(root==null)
            return 0;
        int left=helpDistribute(root.left,moves);
        int right=helpDistribute(root.right,moves);
        moves[0]+=Math.abs(left)+Math.abs(right);
        return left+right+root.val-1;
    }
}
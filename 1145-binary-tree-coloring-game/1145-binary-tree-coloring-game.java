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
        int val[]=new int[2];
        countNodes(root,val,x);
        int left=val[0];
        int right=val[1];
        int parent = n - left - right - 1;
        if (left > n / 2 || right > n / 2 || parent > n / 2) return true;
        return false;
    }
    private int countNodes(TreeNode root,int[] val,int x) {
        if (root == null) return 0;
        
        int left = countNodes(root.left,val,x);
        int right = countNodes(root.right,val,x);
        if(root.val==x){
            val[0]=left;
            val[1]=right;
        }
            
            
        return 1 + left + right;
    }
}

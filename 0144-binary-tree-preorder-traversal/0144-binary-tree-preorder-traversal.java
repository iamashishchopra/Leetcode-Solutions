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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> lis=new LinkedList<Integer>();
        helpPreOrder(root,lis);
        return lis;
            
    }
    private void helpPreOrder(TreeNode root,List<Integer> lis){
        if(root==null)
            return;
        
        lis.add(root.val);
        helpPreOrder(root.left,lis);
        helpPreOrder(root.right,lis);
        
    }
}
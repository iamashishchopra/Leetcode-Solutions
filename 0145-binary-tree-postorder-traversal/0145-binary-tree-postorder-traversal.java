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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> lis=new LinkedList<Integer>();
        helpPostOrder(root,lis);
        return lis;
            
    }
    private void helpPostOrder(TreeNode root,List<Integer> lis){
        if(root==null)
            return;
        helpPostOrder(root.left,lis);
        helpPostOrder(root.right,lis);
        
        lis.add(root.val);
    }
}
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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> lis1=new LinkedList<Integer>();
        List<Integer> lis2=new LinkedList<Integer>();
        GenerateLeaves(root1,lis1);
        GenerateLeaves(root2,lis2);
        
        return lis1.equals(lis2);
    }
    private void GenerateLeaves(TreeNode node,List<Integer> lis){
        if(node==null)
            return;
        
        if(node.left==null&&node.right==null)
            lis.add(node.val);
        
        GenerateLeaves(node.left,lis);
        GenerateLeaves(node.right,lis);
        
    }
}
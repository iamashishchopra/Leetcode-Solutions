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

    public int sumNumbers(TreeNode root) {
        List<Integer> lis = new LinkedList<Integer>();
        int sum[] = new int[1];
        helpSum(root, sum, lis);
        return sum[0];
    }

    private void helpSum(TreeNode root, int[] sum, List<Integer> lis) {
        if (root == null) return;

        lis.add(root.val);
        
        
        if (root.left==null&&root.right==null) {
            for (int i = 0; i < lis.size(); i++) {
                int temp = lis.get(i);
                sum[0] += temp * (int) Math.pow(10, lis.size() - i - 1);
            }
        }

        helpSum(root.left, sum, lis);
        helpSum(root.right, sum, lis);
        
        lis.remove(lis.size() - 1);
    }
}

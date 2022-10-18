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

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> sublist = new LinkedList<Integer>();
        List<List<Integer>> lis = new ArrayList<List<Integer>>();
        int sum[] = new int[1];
        sum[0] = 0;
        helpPath(root, targetSum, sublist, lis, sum);
        return lis;
    }

    private void helpPath(TreeNode root, int targetsum, List<Integer> sublist, List<List<Integer>> lis, int[] sum) {
        if (root == null) return;
        sublist.add(root.val);
        sum[0] += root.val;
        if (sum[0] == targetsum && root.left == null && root.right == null) {
            lis.add(new ArrayList<Integer>(sublist));
        }

        helpPath(root.left, targetsum, sublist, lis, sum);
        helpPath(root.right, targetsum, sublist, lis, sum);
        sublist.remove(sublist.size() - 1);
        sum[0] -= root.val;
    }
}

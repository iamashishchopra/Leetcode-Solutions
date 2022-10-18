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

    public int pathSum(TreeNode root, int targetSum) {
        List<Integer> lis = new LinkedList<Integer>();
        int counter[] = new int[1];
        counter[0] = 0;
        helpPath(root, targetSum, lis, counter);
        return counter[0];
    }

    private void helpPath(TreeNode root, int targetsum, List<Integer> lis, int[] counter) {
        if (root == null) return;
        lis.add(root.val);
        long sum = 0;
        for (int i = lis.size() - 1; i >= 0; i--) {
            sum += lis.get(i);
            if (sum == targetsum) {
                counter[0]++;
            }
        }

        helpPath(root.left, targetsum, lis, counter);
        helpPath(root.right, targetsum, lis, counter);
        lis.remove(lis.size() - 1);
    }
}

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

    public String smallestFromLeaf(TreeNode root) {
        List<Character> lis = new LinkedList<Character>();
        String ans[] = new String[1];
        int[] flag = new int[1];
        ans[0] = "";
        flag[0] = 0;
        helpSmallestString(root, lis, ans, flag);
        return ans[0];
    }

    private void helpSmallestString(TreeNode root, List<Character> lis, String[] ans, int[] flag) {
        if (root == null) return;
        lis.add((char) (root.val + 97));
        if (root.left == null && root.right == null) {
            String temp = "";

            for (int i = lis.size() - 1; i >= 0; i--) {
                temp += lis.get(i);
            }
            if (flag[0] == 0) {
                ans[0] = temp;
                flag[0] = 1;
            }

            if (temp.compareTo(ans[0]) < 0) ans[0] = temp;
        }
        helpSmallestString(root.left, lis, ans, flag);
        helpSmallestString(root.right, lis, ans, flag);
        lis.remove(lis.size() - 1);
    }
}

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
    public int deepestLeavesSum(TreeNode root) {
        Queue<TreeNode> q=new LinkedList<TreeNode>();
        List<Integer> ans=new ArrayList<>();
        int sum=0;
        if(root==null)
            return sum;
        q.offer(root);
        while(!q.isEmpty()){
            int s=q.size();
            ans.clear();
            for(int i=0;i<s;i++){
                TreeNode temp=q.poll();
                ans.add(temp.val);
                if(temp.left!=null)
                    q.offer(temp.left);
                if(temp.right!=null)
                    q.offer(temp.right);
            }
        }
        for(int i=0;i<=ans.size()-1;i++)
            sum+=ans.get(i);
        
        return sum;
    }
}
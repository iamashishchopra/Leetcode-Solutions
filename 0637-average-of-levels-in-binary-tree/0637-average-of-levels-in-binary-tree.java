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
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> queue=new LinkedList<TreeNode>();
        List<Double> lis=new LinkedList<Double>();
        queue.offer(root);
        while(!queue.isEmpty()){
            int size=queue.size();
            double sum=0.0;
            for(int i=0;i<size;i++){
                TreeNode temp=queue.poll();
                sum+=temp.val;
                if(temp.left!=null)
                    queue.offer(temp.left);
                if(temp.right!=null)
                    queue.offer(temp.right);
            }
            lis.add(Math.round((sum/size) * 100000) / 100000.0);
        }
        return lis;
    }
}
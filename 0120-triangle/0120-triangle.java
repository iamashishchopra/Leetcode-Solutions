class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int dp[][]=new int[triangle.size()][triangle.size()];
        for (int[] row: dp)
            Arrays.fill(row, -1);
        return findMin(0,0,triangle,dp);
    }
    private int findMin(int i,int j,List<List<Integer>> triangle,int[][] dp){
        if(i==triangle.size()-1)
            return triangle.get(i).get(j);
        if(j<0||j>=triangle.get(i).size())
            return (int) 1e8;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ld=triangle.get(i).get(j)+findMin(i+1,j,triangle,dp);
        int rd=triangle.get(i).get(j)+findMin(i+1,j+1,triangle,dp);
        return dp[i][j]=Math.min(ld,rd);
    }
}
class Solution 
{
    private int dfs(int index,int[][] stones,int[] vis)
    {
        int count=1;
        vis[index]=1;
        for(int i=0;i<stones.length;i++)
        {
            if(vis[i]==0&&canBeRemoved(stones[index],stones[i]))
                count+=dfs(i,stones,vis);
        }
        return count;
    }
    public int removeStones(int[][] stones) 
    {
        int ans=0;
        int c=0;
        int[] vis=new int[stones.length];
        for(int i=0;i<stones.length;i++)
        {
            c++;
            ans+=dfs(i,stones,vis);
        }
        return ans-c;
    }
    private boolean canBeRemoved(int[] point1,int[] point2)
    {
        if(point1[0]==point2[0]||point1[1]==point2[1])
            return true;
        return false;
    }
}
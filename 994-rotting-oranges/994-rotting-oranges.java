class Solution 
{
    public int orangesRotting(int[][] grid) 
    {
        Queue<int[]> q=new LinkedList<>();
        int total=0;
        int rotten=0;
        int time=0;
        for(int i=0;i<grid.length;i++)
        {
            for(int j=0;j<grid[0].length;j++)
            {
                if(grid[i][j]==1||grid[i][j]==2)
                    total++;
                if(grid[i][j]==2)
                    q.add(new int[]{i,j});
            }
        }
        
        if(total==0)
            return 0;
        while(!q.isEmpty()&&rotten<total)
        {
            int size=q.size();
            rotten+=size;
            
            if(rotten==total)
                return time;
            
            time++;
            for(int i=0;i<size;i++)
            {
                int[] elem=q.poll();
                
                if(elem[0]+1<grid.length&&grid[elem[0]+1][elem[1]]==1)
                {
                    grid[elem[0]+1][elem[1]]=2;
                    q.add(new int[]{elem[0]+1,elem[1]});
                }
                if(elem[0]-1>=0&&grid[elem[0]-1][elem[1]]==1)
                {
                    grid[elem[0]-1][elem[1]]=2;
                    q.add(new int[]{elem[0]-1,elem[1]});
                }
                if(elem[1]+1<grid[0].length&&grid[elem[0]][elem[1]+1]==1)
                {
                    grid[elem[0]][elem[1]+1]=2;
                    q.add(new int[]{elem[0],elem[1]+1});
                }
                if(elem[1]-1>=0&&grid[elem[0]][elem[1]-1]==1)
                {
                    grid[elem[0]][elem[1]-1]=2;
                    q.add(new int[]{elem[0],elem[1]-1});
                }
            }
        }
        return -1;
    }
}
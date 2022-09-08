class Solution {

    private void dfs(int x, int y, boolean[][] map) {
        if (x < 0 || y < 0 || y >= map[0].length || x >= map.length || map[x][y] == false) return;
        map[x][y] = false;
        dfs(x + 1, y, map);
        dfs(x - 1, y, map);
        dfs(x, y + 1, map);
        dfs(x, y - 1, map);
    }

    public int regionsBySlashes(String[] grid) {
        int ans = 0;
        int n = grid.length;
        boolean[][] map = new boolean[3 * n ][3 * n];
        for (int i = 0; i < 3 * n; i++) Arrays.fill(map[i], true);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i].charAt(j) == '/') map[3 * i + 2][3 * j] = map[3 * i + 1][3 * j + 1] = map[3 * i][3 * j + 2] = false;
                if (grid[i].charAt(j) == '\\') map[3 * i][3 * j] = map[3 * i + 1][3 * j + 1] = map[3 * i + 2][3 * j + 2] = false;
            }
        }
        for(int i=0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {
                if(map[i][j]){
                ans++;
                dfs(i,j,map);
                }
            }
        }
        return ans;
    }
}

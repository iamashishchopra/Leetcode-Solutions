/*class Solution {

    public int countServers(int[][] grid) {
        int total = 0;
        int m = grid.length;
        int n = grid[0].length;
        int[] row = new int[m];
        int[] column = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    column[j]++;
                    total++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1&&row[i] == 1 && column[j] == 1) total--;
            }
        }
        return total;
    }
}*/
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        int[] rows = new int[m], cols = new int[n];
        int total = 0;
        
        for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 0) continue;
            rows[r]++;
            cols[c]++;
            total++;
        }

        for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 1 && rows[r] == 1 && cols[c] == 1)
                total--;
        }
        
        return total;
    }
}

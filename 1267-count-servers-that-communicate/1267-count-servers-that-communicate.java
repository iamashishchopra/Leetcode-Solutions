class Solution {

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
}

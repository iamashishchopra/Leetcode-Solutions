//Similar to number of islands
class Solution {

    private void dfs(int x, ArrayList<ArrayList<Integer>> adj, boolean[] vis, int n) {
        vis[x] = true;
        for (Integer i : adj.get(x)) {
            if (!vis[i]) dfs(i, adj, vis, n);
        }
    }

    public int makeConnected(int n, int[][] connections) {
        int c = 0;
        if (n > (connections.length + 1)) return -1;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++) adj.add(new ArrayList<Integer>());

        for (int i = 0; i < connections.length; i++) {
            adj.get(connections[i][0]).add(connections[i][1]);
            adj.get(connections[i][1]).add(connections[i][0]);
        }

        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                c++;
                dfs(i, adj, vis, n);
            }
        }
        return c - 1;
    }
}

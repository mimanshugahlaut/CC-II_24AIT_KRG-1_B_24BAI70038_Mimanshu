class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);

        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(source);
        vis[source] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == destination)
                return true;

            for (int g : graph[node]) {
                if (!vis[g]) {
                    vis[g] = true;
                    q.push(g);
                }
            }
        }
        return false;
    }
};

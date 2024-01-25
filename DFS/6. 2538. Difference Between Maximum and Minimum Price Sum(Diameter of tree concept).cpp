class Solution {
  public:
    long long maxOutput (int n, vector <vector <int>>& edges, vector <int>& price) {
      std::vector <std::vector <int>> graph (n);
      
      for (auto &e: edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
      }
      
      auto dfs = [&] (auto self, int u, std::vector <long long> &depth) -> void {
        for (int v: graph[u]) {
          if (depth[v] == -1) {
            depth[v] = depth[u] + price[v];
            self(self, v, depth);
          }
        }
      };
      
      std::vector <long long> depth_x (n, -1);
      depth_x[0] = price[0];
      dfs(dfs, 0, depth_x);
      
      auto u = std::max_element(depth_x.begin(), depth_x.end()) - depth_x.begin();
      
      std::vector <long long> depth_y (n, -1);
      depth_y[u] = price[u];
      dfs(dfs, u, depth_y);
      
      auto v = std::max_element(depth_y.begin(), depth_y.end()) - depth_y.begin();

      depth_x = std::vector <long long> (n, -1);
      depth_x[v] = price[v];
      dfs(dfs, v, depth_x);
      
      long long ans = 0;
      
      for (int i = 0; i < n; ++i) {
        ans = std::max(ans, depth_x[i] - price[i]);
        ans = std::max(ans, depth_y[i] - price[i]);
      }
      
      return ans;
    }
};

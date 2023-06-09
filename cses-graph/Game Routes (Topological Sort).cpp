#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int maxN = 1e5+1;
const ll MOD = 1e9+7;

int N, M, a, b, cnt, in[maxN];
ll dp[maxN];
vector<int> G[maxN];
queue<int> Q;

int main(){
    // Read input values N and M
    cin >> N >> M;

    // Read the directed edges and construct the adjacency list
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        G[a].push_back(b);
        in[b]++;
    }

    // Find all the vertices with in-degree 0 and enqueue them
    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    // Initialize dp[1] to 1, as there is one way to reach the starting vertex
    dp[1] = 1;

    // Perform topological sorting using BFS
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        
        // Traverse all outgoing edges from the current vertex u
        for(int v : G[u]){
            // Update the number of ways to reach vertex v
            dp[v] = (dp[v] + dp[u]) % MOD;

            // Decrease the in-degree of v since we have visited one of its incoming edges
            in[v]--;

            // If v has no more incoming edges, enqueue it for further processing
            if(in[v] == 0)
                Q.push(v);
        }
    }

    // Print the number of ways to reach vertex N
    cout << dp[N] << endl;
    return 0;
}

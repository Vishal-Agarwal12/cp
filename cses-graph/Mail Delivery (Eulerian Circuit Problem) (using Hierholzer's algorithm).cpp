// The problem you described is known as the Eulerian circuit problem. It involves finding a path in an undirected graph that starts and ends at the same vertex, and traverses every edge exactly once.

// To solve this problem, you can use the Hierholzer's algorithm, which is an efficient algorithm for finding Eulerian circuits in a graph. Here is the step-by-step process:

// Check if the graph is connected: Ensure that every vertex in the graph has an even degree. If any vertex has an odd degree, it is not possible to find an Eulerian circuit.

// Choose a starting vertex: Select vertex 1 as the starting vertex.

// Construct a circuit: Start from the chosen vertex and perform a depth-first search (DFS) traversal. During the traversal, visit each unused edge incident to the current vertex. Remove the visited edge from the graph after traversal. Repeat this process until there are no unused edges remaining.

// Backtrack to complete the circuit: If there are any unused edges left in the graph, choose one of the vertices on the circuit with remaining edges and repeat step 3 from that vertex. Continue this process until all edges have been visited.

// Output the Eulerian circuit: The result will be a circuit that starts and ends at vertex 1 and traverses every edge exactly once.

#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e5+1;
const int maxM = 2e5+1;

int N, M, deg[maxN];
bool tour_exists, used[maxM];
vector<pii> G[maxN];
vector<int> tour;
stack<int> S;

int main(){
    scanf("%d %d", &N, &M);

    // Read the input and construct the adjacency list representation of the graph
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        deg[a]++; deg[b]++;
    }

    tour_exists = true;

    // Check if the graph satisfies the necessary condition for having an Eulerian circuit
    for(int i = 1; i <= N; i++)
        if(deg[i]&1)
            tour_exists = false;

    // If the graph does not satisfy the condition, print "IMPOSSIBLE" and terminate
    if(!tour_exists){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    S.push(1);

    // Start the Hierholzer's algorithm from vertex 1
    while(!S.empty()){
        int u = S.top();

        // If the current vertex has remaining edges
        if(deg[u]){
            while(!G[u].empty()){
                int v = G[u].back().first;
                int id = G[u].back().second;
                G[u].pop_back();

                // If the edge (u, v) is unused, remove it from the graph
                if(!used[id]){
                    deg[u]--; deg[v]--;
                    used[id] = true;

                    // Push the destination vertex onto the stack
                    S.push(v);
                    break;
                }
            }
        } else {
            // If there are no remaining edges, add the current vertex to the Eulerian circuit and pop it from the stack
            tour.push_back(u);
            S.pop();
        }
    }

    // Check if the size of the Eulerian circuit is correct
    if((int) tour.size() != M+1)
        printf("IMPOSSIBLE\n");
    else
        // Print the vertices of the Eulerian circuit in order
        for(int i = 0; i <= M; i++)
            printf("%d%c", tour[i], (" \n")[i==M]);
}

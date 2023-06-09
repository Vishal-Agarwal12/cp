#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> edge;

const int maxN = 1e5+1;
const int maxM = 2e5+1;

int N, M, a, b, c;
long long sum;
edge edges[maxM];
int ds[maxN];

int find(int u) {
    if (ds[u] < 0)
        return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (ds[u] < ds[v])
        swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

int main() {
    scanf("%d %d", &N, &M); // Read the number of vertices and edges
    fill(ds + 1, ds + N + 1, -1); // Initialize the disjoint set array

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c); // Read the vertices and weight of an edge
        edges[i] = {c, {a, b}}; // Store the edge with its weight
    }

    sort(edges, edges + M); // Sort the edges in ascending order of weight

    for (int i = 0; i < M; i++) {
        edge e = edges[i];
        if (merge(e.second.first, e.second.second)) { // Merge the vertices if they do not create a cycle
            sum += e.first; // Add the weight of the merged edge to the total sum
            N--; // Decrement the number of remaining vertices
        }
    }

    if (N == 1)
        printf("%lld\n", sum); // Print the sum of weights of the minimum spanning tree
    else
        printf("IMPOSSIBLE\n"); // If the minimum spanning tree is not possible for the given graph
}

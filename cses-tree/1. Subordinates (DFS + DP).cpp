
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;

vector<int> adj[MAX]; // adjacency list to represent the tree
int subsize[MAX]; // array to store the size of subtree for each node
bool vis[MAX]; // array to keep track of visited nodes

// Depth-first search (DFS) function to calculate the size of the subtree for a given node
int dfs(int src) {
    vis[src] = true; // mark the current node as visited
    int curr = 1; // initialize the current subtree size as 1

    for (auto child : adj[src]) {
        if (!vis[child]) { // if the child node is not visited
            curr += dfs(child); // recursively calculate the size of the subtree rooted at the child node and add it to the current size
        }
    }

    return subsize[src] = curr; // store the calculated subtree size for the current node and return it
}

int main() {
    int n;
    cin >> n; // read the number of crossings (nodes) in the tree

    // read the connections between the crossings
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x; // read the parent node of the current node
        adj[x].push_back(i); // add the current node as a child to its parent in the adjacency list
        adj[i].push_back(x); // add the parent node to the current node's adjacency list
    }

    dfs(1); // start the DFS traversal from the root node (crossing 1)

    // print the size of the subtree for each node, subtracting 1 from each value
    for (int i = 1; i <= n; i++) {
        cout << subsize[i] - 1 << " ";
    }
}

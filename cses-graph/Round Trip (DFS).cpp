#include <bits/stdc++.h>

#define LL long long

using namespace std;

const int mod = 2e9 + 7;
const int N = 100100;

int n, m;
vector<int> v[N], v1;
bool used[N];
int po[N];

void dfs(int x, int p)
{
    // If the current node is already visited, a cycle is found
    if (used[x])
    {
        // Print the length of the cycle and the cycle path
        cout << v1.size() - po[x] + 1 << endl;
        for (int i = po[x]; i < v1.size(); i++)
            cout << v1[i] << " ";
        cout << x;
        exit(0); // Exit the program as the solution is found
    }
    used[x] = true;
    v1.push_back(x);
    po[x] = v1.size() - 1; // Store the position of the current node in the path
    for (int i = 0; i < v[x].size(); i++)
    {
        int y = v[x][i];
        if (y != p)
        {
            dfs(y, x); // Recursively visit the neighboring nodes
        }
    }
    v1.pop_back(); // Remove the current node from the path after visiting all its neighbors
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );

    cin >> n >> m;

    // Read the edges of the graph
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    // Perform DFS on each connected component of the graph
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            dfs(i, 0); // Start DFS from node i with parent 0
        }
    }

    // If no cycle with a path length of 2 or more is found, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
struct DSU
{
    vector<int> father;
    vector<int> size;
    int components;
    int maxComponentSize;
 
    DSU(int N)
    {
        father = vector<int>(N);
        size = vector<int>(N, 1);
        components = N;
        maxComponentSize = 1;
        for (int i = 0; i < N; i++)
        {
            father[i] = i;
        }
    }
 
    int find(int node)
    {
        if (father[node] != node)
        {
            father[node] = find(father[node]);
        }
        return father[node];
    }
 
    void unite(int A, int B)
    {
        int rootA = find(A);
        int rootB = find(B);
        if (rootA != rootB)
        {
            if (size[rootA] < size[rootB])
            {
                swap(rootA, rootB);
            }
            father[rootB] = rootA;
            size[rootA] += size[rootB];
            maxComponentSize = max(maxComponentSize, size[rootA]);
            components--;
        }
    }
 
    int getMaxComponentSize()
    {
        return maxComponentSize;
    }
 
    int countComponents()
    {
        return components;
    }
};
 
int main()
{
    int N, M;
    cin >> N >> M;
 
    DSU dsu(N);
 
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        dsu.unite(A-1, B-1);
        int numComponents = dsu.countComponents();
        int largestComponentSize = dsu.getMaxComponentSize();
        cout << numComponents << " " << largestComponentSize << endl;
    }
 
    return 0;
}

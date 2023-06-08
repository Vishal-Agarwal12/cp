#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<pair<int, int>> monster; // Stores the positions of the monsters
vector<vector<int>> g; // Grid representing the lava flow
map<pair<int, int>, pair<int, int>> par_mp; // Map to store parent-child relationships
pair<int, int> si, se; // Start and end positions
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // Possible movements (up, down, right, left)

bool isValid(int x, int y, int timer)
{
  if (x < 0 or y < 0 or x >= n or y >= m)
  {
    return false; // Out of bounds
  }
  if (g[x][y] <= timer)
  {
    return false; // Already visited by lava flow
  }
  return true;
}
 
bool isEscape(int x, int y, int timer)
{
  if (!isValid(x, y, timer))
    return false;
  if (x == 0 or y == 0 or x == n - 1 or y == m - 1)
    return true; // Reached the boundary
  return false;
}
 
bool bfsEscape()
{
  queue<pair<pair<int, int>, int>> q;
  q.push(make_pair(si, 0));
  par_mp[si] = {-1, -1}; // Start position has no parent
  while (!q.empty())
  {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int timer = q.front().second; 
    timer++; q.pop();
    for (auto mv : moves)
    {
      int tx = cx + mv.first;
      int ty = cy + mv.second;
      if (isEscape(tx, ty, timer))
      {
        par_mp[{tx, ty}] = {cx, cy};
        se = {tx, ty}; // End position is found
        return true;
      }
      if (isValid(tx, ty, timer))
      {
        par_mp[{tx, ty}] = {cx, cy};
        g[tx][ty] = timer; // Mark the position as visited by lava flow
        q.push({{tx, ty}, timer});
      }
    }
  }
  return false;
}

void preprocessLavaFlow()
{
  queue<pair<pair<int, int>, int>> q;
  for (auto m : monster)
  {
    q.push(make_pair(m, 0));
  }
  while (!q.empty())
  {
    int cx = q.front().first.first;
    int cy = q.front().first.second;
    int timer = q.front().second; 
    timer++; q.pop();

    for (auto mv : moves)
    {
      int tx = cx + mv.first;
      int ty = cy + mv.second;
      if (isValid(tx, ty, timer))
      {
        g[tx][ty] = timer; // Mark the position as visited by lava flow
        q.push({{tx, ty}, timer});
      }
    }
  }
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < n; ++i)
  {
    g[i].resize(m);
  }
 
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      g[i][j] = INT_MAX; // Initialize all positions to maximum value
    }
  }  
 
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      char c; cin >> c;
      if (c == '#')
      {
        g[i][j] = 0; // Mark obstacles as visited by lava flow
      }
      else if (c == 'M')
      {
        g[i][j] = 0;
        monster.push_back({i, j}); // Store monster positions
      }
      else if (c == 'A')
      {
        g[i][j] = 0;
        si = {i, j}; // Set the start position
      }
      else
      {
        g[i][j] = INT_MAX; // Unvisited positions
      }
    }
  }
  if (si.first == 0 or si.second == 0 or si.first == n - 1 or si.second == m - 1) 
  {
    cout << "YES" << endl;
    cout << 0;
    return 0;
  }
  preprocessLavaFlow();
  
  if (!bfsEscape())
  {
    cout << "NO"; // Escape is not possible
    return 0;
  }
  cout << "YES" << endl;
  pair<int, int> tmp = se;
  pair<int, int> tmp1 = par_mp[se];
  pair<int, int> ed = {-1, -1}; 
  vector<char> ans;
  while (tmp1 != ed)
  {
    // Determine the movement direction based on the difference in positions
    if ((tmp.second - tmp1.second) == 1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('R');
    }
    if ((tmp.second - tmp1.second) == -1 and (tmp.first - tmp1.first) == 0)
    {
      ans.push_back('L');
    }
    if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == 1)
    {
      ans.push_back('D');
    }
    if ((tmp.second - tmp1.second) == 0 and (tmp.first - tmp1.first) == -1)
    {
      ans.push_back('U');
    }
    tmp = par_mp[tmp];
    tmp1 = par_mp[tmp];
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto c : ans)
  {
    cout << c;
  }
}

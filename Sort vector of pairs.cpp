


bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}


vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {1, 1}, {2, 3}};
sort(vec.begin(), vec.end(), compare);

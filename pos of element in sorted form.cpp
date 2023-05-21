
// here we are finding positions of array a in sorted order 

    std::vector<std::pair<int, int>> elements;
    for (int i = 0; i < n; ++i)
    {
        elements.push_back(std::make_pair(a[i], i));
    }
    std::sort(elements.begin(), elements.end());
 
    std::vector<int> positions(n);
    for (int i = 0; i < n; ++i)
    {
        positions[elements[i].second] = i;
    }

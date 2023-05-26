// return Index of Next Greater Element
ll findIndexGreaterThan(const std::vector<ll> &sortedVector, ll target)
{
    auto it = std::upper_bound(sortedVector.begin(), sortedVector.end(), target);
    if (it != sortedVector.end())
    {
        return std::distance(sortedVector.begin(), it);
    }
    return -1;
}

// return Index of Greater than or equal to element
ll findIndexGreaterThanOrEqual(const std::vector<ll>& sortedVector, ll target) {
    auto it = std::lower_bound(sortedVector.begin(), sortedVector.end(), target);
    if (it != sortedVector.end()) {
        return std::distance(sortedVector.begin(), it);
    }
    return -1;
}

ll findIndexLessThan(const std::vector<ll>& sortedVector, ll target) {
    auto it = std::lower_bound(sortedVector.begin(), sortedVector.end(), target);
    if (it != sortedVector.begin()) {
        return std::distance(sortedVector.begin(), std::prev(it));
    }
    return -1;
}

ll findIndexLessThanOrEqual(const std::vector<ll>& sortedVector, ll target) {
    auto it = std::upper_bound(sortedVector.begin(), sortedVector.end(), target);
    if (it != sortedVector.begin()) {
        return std::distance(sortedVector.begin(), std::prev(it));
    }
    return -1;
}

//Method 1: Basic Iterative Binary Search

template <typename T>
int binarySearchBasic(const T arr[], int size, const T& target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Target element not found
}


//Method 2: Upper Bound Iterative Binary Search

template <typename T>
int binarySearchUpperBound(const T arr[], int size, const T& target) {
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }

    if (left > 0 && arr[left - 1] == target)
        return left - 1;

    return -1; // Target element not found
}


//Method 3: Lower Bound Iterative Binary Search

template <typename T>
int binarySearchLowerBound(const T arr[], int size, const T& target) {
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }

    if (left < size && arr[left] == target)
        return left;

    return -1; // Target element not found
}


Method 1 is a basic implementation that performs a standard binary search, returning the index of the target element if found.

Method 2 is an upper bound implementation that returns the index of the first element greater than the target, or -1 if the target element is not found.

Method 3 is a lower bound implementation that returns the index of the first element greater than or equal to the target, or -1 if the target element is not found.

#include <iostream>
#include <queue>

using namespace std;

// Comparator function to sort the pair in the priority queue
struct myComp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; // sort by second value in ascending order if first values are equal
        }
        return a.first > b.first; // sort by first value in ascending order
    }
};

int main() {
    // declare a priority queue of pairs using the comparator function
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> myPQ;

    // push some values into the priority queue
    myPQ.push({5, 4});
    myPQ.push({3, 8});
    myPQ.push({5, 1});
    myPQ.push({2, 7});

    // print the top element of the priority queue
    cout << "The top element of the priority queue is: {" << myPQ.top().first << ", " << myPQ.top().second << "}" << endl;

    return 0;
}

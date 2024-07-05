#include<iostream>
#include<queue>
using namespace std;

class RecentCounter {
public:
    queue<int> count;
    RecentCounter() {

    }

    int ping(int t) {
        count.push(t);
        while (t - count.front() > 3000) {
            count.pop();
        }
        return count.size();
    }
};
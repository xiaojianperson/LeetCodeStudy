#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hash_table;
        queue<pair<char, int>> q;

        for (int i = 0;i < s.size();i++) {
            ++hash_table[s[i]];
            q.push(pair<char, int>(s[i], i));
        }

        while (!q.empty()) {
            if (hash_table[q.front().first] == 1) {
                return q.front().second;
            }
            q.pop();
        }
        return -1;
    }
};
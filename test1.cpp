#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param k int整型
     * @param target int整型
     * @return bool布尔型
     */
    bool kInArray(int k, int target) {
        // write code here
        vector<int> res;
        int num = k;
        int length = 1;
        int location = 0;
        int check = 1;
        res.push_back(num);

        while (check == 1) {
            check = 0;
            
            for (int i = location;i < length;i++) {
                res.push_back(res[i] * 2 + 1);
                res.push_back(res[i] * 3 + 1);

                if (res[res.size() - 1] == target || res[res.size() - 2] == target) {
                    return true;
                }

                if (res[res.size() - 1] <= target || res[res.size() - 2] <= target) {
                    check = 1;
                }

                location++;
            }
            length += 2 * length;
        }

        return false;
    }
};

int main() {
    Solution s;
    cout<<s.kInArray(1, 100);
    cout<<1111<<endl;
    return 0;
}
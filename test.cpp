// #include<iostream>
// #include<vector>
// using namespace std;

// void func(vector<int>& ans, vector<int> ans1) {
//     cout << &ans << endl;
//     cout << &ans1 << endl;
// }

// int main() {
//     vector<int> ans = { 0,1 };
//     vector<int>* pointer = &ans;
//     return 0;
// }

#include <iostream>
#include <vector>

class MyClass {
private:
    int  value;
};

int main() {
    std::vector<int> vec = std::vector<int>();
    // MyClass newClass = MyClass();

    // 初始容量可能是0
    std::cout << "Initial capacity: " << vec.capacity() << std::endl;

    // 添加元素，直到触发扩容
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i); // 假设每次push_back都会检查容量并扩容

        // 打印当前容量
        std::cout << "After adding " << i << ": capacity " << vec.capacity() << std::endl;
    }

    return 0;
}

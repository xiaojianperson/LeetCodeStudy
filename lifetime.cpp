#include<iostream>

void func(int*& ptr) {
    // int* _ptr = new int(10);
    int value = 9;
    ptr = &value;
}

int main() {
    int* ptr;
    func(ptr);
    std::cout << *ptr << std::endl;
    return 0;
}
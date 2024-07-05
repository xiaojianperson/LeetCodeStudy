#include<vector>
#include<iostream>
#include <string.h>
using namespace std;

void GetMemory(char*& p, int num) {
    p = (char*)malloc(sizeof(char) * num);
}

void Test(void) {
    char* str = NULL;
    GetMemory(str, 100);
    strcpy(str, "hello");
    cout << str;
}

void changeString(string** ptr) {
    cout << &ptr << endl;
    *ptr = new string("hello");
    // *ptr = (string)"hello";
    cout << &ptr << endl;
}


int main() {
    // Test();

    // string* ptr = new string("world");

    // string* ptr = nullptr;
    // cout << &ptr << endl;
    // string** ptrptr = &ptr;
    // changeString(ptrptr);
    // cout << *ptr << endl;


    // char a = 'h';
    // a = 'X';
    // cout << a << endl;
    // char* p = 'w'; // 注意p指向常量字符串
    // p[0] = 'X'; // 编译器不能发现该错误
    // cout << p << endl;

    // string* a = new string("hello");
    char* b = new char('a');
    cout << b << endl;
    cout << *b << endl;

    return 0;
}
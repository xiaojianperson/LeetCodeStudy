#include <iostream>
#include <type_traits>

// 定义一个结构体，使用alignas指定其对齐字节数为16
struct alignas(32) MyStruct {//自然对齐值=8，有效对齐值=32
    double d1;
    double d2;
    double d3;
};

struct alignas(2) MyStruct {//自然对齐值=8，有效对齐值=8
    double d1;
    double d2;
    double d3;
};

// #pragma pack(push, 2)
// struct MyStruct {
//     char a;
//     int b;
//     double c;
// };
// #pragma pack(pop)

int main() {
    // 创建MyStruct类型的变量
    MyStruct ms;

    // 使用alignof查询MyStruct的对齐字节数并输出，这里是16，因为之前定义为16
    //如果定义为alignas(4) ,即4字节对齐，则为4.
    std::cout << "Alignment of MyStruct is: " << alignof(MyStruct) << " bytes" << std::endl;

    // 使用sizeof查询MyStruct的大小并输出，这里是16
    std::cout << "Size of MyStruct is: " << sizeof(MyStruct) << " bytes" << std::endl;

    return 0;
}
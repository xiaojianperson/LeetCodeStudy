#include<iostream>
#include<vector>
using namespace std;

typedef void (*FUNC)();
int DoSomething(int i)
{
    // cout << "DoSomething" << endl;
    cout << i << endl;
    return 0;
}
int main()
{
    // //下面转换函数指针的代码是不可移植的
    // FUNC f = reinterpret_cast<FUNC>(DoSomething);
    // f();//DoSomething
    // return 0;

    volatile const int a = 2;
	int* p = const_cast<int*>(&a);//取消变量a的const属性
	*p = 3;
	cout << a << endl; //2
	cout << *p << endl;//3
	return 0;
}

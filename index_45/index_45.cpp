// index_45.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
template<typename _Ty>
class SmartPtr {
public:
    template<typename _Ty0>
    SmartPtr(const SmartPtr<_Ty0>& other) :
        ptr(other.ptr){ //只有这里隐式转换成功后才行
    };

    SmartPtr(const SmartPtr& other) {

    }

    SmartPtr(const _Ty* realPtr) :
        ptr(realPtr){
    };
private:
    template <class _Ty0>
    friend class SmartPtr;

    const _Ty* ptr{ nullptr };
};

class Top {

};

class Middle : public Top {
public:
    Middle() = default;
};

class Bottom : public Middle {
public:
    Bottom() = default;
};

#include <iostream>
int main()
{
    SmartPtr<Top> pt1 = SmartPtr<Middle>(new Middle);
    SmartPtr<Top> pt2 = SmartPtr<Bottom>(new Bottom);
    std::cout << "Hello World!\n";
}

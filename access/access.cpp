#include <iostream>
class A {
public:
    void a1(){
      std::cout << "a1" << std::endl;
     }
     virtual void vt(){
      std::cout << "a" << std::endl;
     }
private:
     void a2(){
      std::cout << "a2" << std::endl;
     }
protected:
     void a3(){
      std::cout << "a3" << std::endl;
     }
};


class B : public A {
public:
     void b1(){
      std::cout << "b1" << std::endl;
     }
     virtual void vt(){
      std::cout << "b" << std::endl;
     }
private:
     void b2(){
      std::cout << "b2" << std::endl;
     }
protected:
     void b3(){
      std::cout << "a3" << std::endl;
     }
};

int main() {
     B *pb = new B;
     A *pA = pb;
     pA->vt();  // 正确：输出为 b （多态性）
     pA->a1();  // 正确：输出为 a1
    // pA->a2();  // 错误：pA无权访问私有成员函数 a2
    // pA->a3();  // 错误：pA无权访问保护成员函数 a3
    // pA->b1();  // 错误：b1 不是 类A 的成员函数
    // pA->b2();  // 错误：b2 不是 类A 的成员函数
    // pA->b3();  // 错误：b3 不是 类A 的成员函数

     std::cout << std::endl;
     pb->vt();  // 正确：输出为 b （多态性）
     pb->a1();  // 正确：输出为 a1
    // pb->a2();  // 错误：pb无权访问基类的私有成员函数
    // pb->a3();  // 错误：b无权访问基类的保护成员函数
     pb->b1();  // 正确：输出为 b1
    // pb->b2();  // 错误：pb无权访问自身的私有成员函数
    // pb->b3();  // 错误：pb无权访问自身的保护成员函数

     B b;
     A &rb = b;

     std::cout << std::endl;
     rb.vt();  // 正确：输出为 b （多态性）
     rb.a1();  // 正确：输出为 a1
    // rb.a2();  // 错误：rb无权访问私有成员函数
    // rb.a3();  // 错误：pA无权访问保护成员函数 a3
    // rb.b1();  // 错误：b1 不是 类A 的成员函数
    // rb.b2();  // 错误：b2 不是 类A 的成员函数
    // rb.b3();  // 错误：b3 不是 类A 的成员函数
     std::cout << std::endl;
     b.vt();   // 正确：输出为 b （多态性）
     b.a1();   // 正确：输出为 a1
    // b.a2();   // 错误：b无权访问基类的私有成员函数
    // b.a3();   // 错误：b无权访问基类的保护成员函数
     b.b1();   // 正确：输出为 b1
    // b.b2();   // 错误：b无权访问自身的私有成员函数
    // b.b3();   // 错误：b无权访问自身的保护成员函数

     return 0;
}

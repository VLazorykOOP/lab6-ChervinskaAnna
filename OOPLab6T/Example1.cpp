#include "Lab6Example.h"
#include <iostream>
namespace SpaceExample1 {
    ///Задача. Створити дві ієрархії класів без віртуального та з віртуальним спадкуванням, 
    // з елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами. 
    // Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. 
    // Вивести розміри об’єктів даних класів.
    ///
    class Base
    {
    protected:
        int dat;
        double a[5] = { 10,1,7,1,9 };
    public:
        Base() : dat(1) {}
        Base(int d) : dat(d) {}
        Base(int a1, int a2, int a3, double a4, int a5) : dat(1) {
            a[0] = a1;
            a[1] = a2;
            a[2] = a3;
            a[3] = a4;
            a[4] = a5;
        }
    };
  
    class D1 : protected Base
    {
    protected:
        int d1;
    public:
        D1() : d1(1) {}
        D1(int d) : d1(d) {}
        D1(int d, int dt) : Base(dt), d1(d) {}
        D1(int a, int b, int c, double d, int e) : Base(a, b, c, d, e), d1(1) {}

    };

    class D2 : protected Base
    {
    protected:
        double d2;
    public:
        D2() : d2(1) {}
        D2(int d) : d2(d) {}
        D2(int d, double dt) : Base(d), d2(dt) {}
        D2(int a, int b, int c, double d, int e) : Base(a, b, c, d, e), d2(d) {}
    };

    class D3 : protected D1, protected D2
    {
    protected:
        double dt;
    public:
        D3() : dt(1) {}
        D3(int d) : dt(d) {}
        D3(int a, int b, int c, double d, int e) : D1(a, b), D2(c, d), dt(e) {}
    };

    class D4 : protected D1
    {
    protected:
        double dt;
    public:
        D4() : dt(1) {}
        D4(int d) : dt(d) {}
        D4(int a, int b, int c, double d, int e) : D1(a, b, c, d, e), dt(d) {}
        void showDat()
        {
            std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;
            /// << dat << std::endl;
          //  std::cout << "B12VV::D1V::Base::dat =  " << D12::D1::Base::dat << std::endl;
           // std::cout << "B12VV::D1V::Base::dat =  " << Base::dat << std::endl;
      //      std::cout << "B12VV::D1V::Base::dat =  " << D12::D2::Base::dat << std::endl;
        }
    };
    

    class D5 : protected D1, protected D3
    {
    protected:
        int d5;
    public:
        D5() : d5(1) {}
        D5(int d) : d5(d) {}
        D5(int d, int dt) : D1(d), D3(d), d5(d) {}
        D5(int a, int b, int c, double d, int e) : D1(a, b, c, d, e), d5(d) {}
    };

    class D6 : protected D2, protected D4
    {
    protected:
        int d6;
    public:
        D6() : d6(1) {}
        D6(int d) : d6(d) {}
        D6(int d, int dt) : D2(d), D4(d), d6(d) {}
        D6(int a, int b, int c, double d, int e) : D2(a, b, c, d, e), D4(a, b, c, d, e), d6(d) {}
    };
    /*****virtual*****/

    class D1V : virtual protected Base
    {
    protected:
        int d1;
    public:
        D1V() : d1(1) {}
        D1V(int d) : d1(d) {}
        D1V(int d, int dt) : Base(dt), d1(d) {}
        D1V(int a, int b, int c, double d, int e) : Base(a, b, c, d, e), d1(d) {}
    };

    class D2V : virtual protected Base
    {
    protected:
        double d2;
    public:
        D2V() : d2(1) {}
        D2V(int d) : d2(d) {}
        D2V(int d, double dt) : Base(d), d2(dt) {}
        D2V(int a, int b, int c, double d, int e) : Base(a, b, c, d, e), d2(d) {}
    };

    class D3V :virtual protected D1V, virtual protected D2V
    {
    protected:
        double dt;
    public:
        D3V() : dt(1) {}
        D3V(int d) : dt(d) {}
        D3V(int a, int b, int c, double d, int e) : D1V(a, b), D2V(c, d), dt(e) {}
    };

    class D4V :virtual protected D1V
    {
    protected:
        double dt;
    public:
        D4V() : dt(1) {}
        D4V(int d) : dt(d) {}
        D4V(int a, int b, int c, double d, int e) : D1V(a, b, c, d, e) ,dt(d) {}
    };


    class D5V : virtual protected D1V, virtual protected D3V
    {
    protected:
        int d5;
    public:
        D5V() : d5(1) {}
        D5V(int d) : d5(d) {}
        D5V(int d, int dt) : D1V(d), D3V(d), d5(d) {}
        D5V(int a, int b, int c, double d, int e) : D1V(a, b, c, d, e), d5(d) {}
    };

    class D6V : virtual protected D2V, virtual protected D4V
    {
    protected:
        int d6;
    public:
        D6V() : d6(1) {}
        D6V(int d) : d6(d) {}
        D6V(int d, int dt) : D2V(d), D4V(d), d6(d) {}
        D6V(int a, int b, int c, double d, int e) : D2V(a, b, c, d, e), d6(d)   {}
    };

    //class D2V : virtual protected Base
    //{
    //protected:
    //    double d2;
    //public:
    //    D2V() : d2(1) {}
    //    D2V(int d) : d2(d) {}
    //    D2V(int d, double dt) : Base(d), d2(dt) {}
    //};

    //class D12VV : virtual protected D1V, virtual public D2V
    //{
    //protected:
    //    double dt;
    //public:
    //    D12VV() : dt(1) {}
    //    D12VV(int d) : dt(d) {}
    //    D12VV(int a, int b, int c, double d, int e) : D1V(a, b), D2V(c, d), dt(e) {}
    //};

    //class RV3 : virtual protected D12VV, virtual public Base
    //{
    //protected:
    //    double dt;
    //public:
    //    RV3() : dt(1) {}
    //    RV3(int d) : dt(d) {}
    //    RV3(int a, int b, int c, double d, int e) : D12VV(a, b, c, d, e), Base::Base(a + 1),
    //        dt(e + 1.0) {}
    //    void showDat()
    //    {
    //        std::cout << "  dat =  " << dat << std::endl;
    //        std::cout << "B12VV::D1V::Base::dat =  " << D12VV::D1V::Base::dat << std::endl;
    //        std::cout << "B12VV::D1V::Base::dat =  " << Base::dat << std::endl;
    //        std::cout << "B12VV::D1V::Base::dat =  " << D12VV::D2V::Base::dat << std::endl;
    //    }
    //};

    int mainExample1()
    {
        std::cout << " Example1  \n";
        D5 a, b(1, 2, 3, 4.5, 5);
        D6 c, d(1, 2, 3, 4.5, 5);
        D4V av, bv(1, 2, 3, 4.5, 5);

        std::cout << "Test !\n";
        std::cout << "Size for Base " << sizeof(Base) << std::endl;
        std::cout << "Size for D1 " << sizeof(D1) << std::endl;
        std::cout << "Size for D2 " << sizeof(D2) << std::endl;
        std::cout << "Size for D3 " << sizeof(D3) << std::endl;
        std::cout << "Size for D4 " << sizeof(D4) << std::endl;
        std::cout << "Size for D5 " << sizeof(D5) << std::endl;
        std::cout << "Size for D6 " << sizeof(D6) << std::endl;

        std::cout << "Size for Base " << sizeof(Base) << std::endl;
        std::cout << "Size for D1V " << sizeof(D1V) << std::endl;
        std::cout << "Size for D2V " << sizeof(D2V) << std::endl;
        std::cout << "Size for D3V " << sizeof(D3V) << std::endl;
        std::cout << "Size for D4V " << sizeof(D4V) << std::endl;
        std::cout << "Size for D5V " << sizeof(D5V) << std::endl;
        std::cout << "Size for D6V " << sizeof(D6V) << std::endl;

        return 0;
    }

}
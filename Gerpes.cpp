#include <iostream>


//Наследование - инструмент языка для расширения функционала класса 
//через сужение его специализации


//При наследовании мы строим новый класс через повторное использование написанного ранее класса\
При этом происходит изменение типа доступа компонентов родительского класса исходя из зоны вдимости и типа наследования.


//Что наслед: \
 - поля и методы класса\
 - операторы, если они опред как методы класса\
 - стат поля и методы

//Что не наслед: \
 - друж функ\
 - друж классы\
 - опред как внешн фуек операторы


//Налич наслед в коде ед способ налич способ вкл динам полиморфизма в программе

class Makaka
{
public:
    Makaka() = default;
    Makaka(int a, int b)
    {
        a_ = a;
        b_ = b;
    }
    int GetA()const
    {
        return a_;
    }
    int GetB()const
    {
        return b_;
    }
    void SetA(int a)
    {
        a_ = a;
    }
    void SetB(int b)
    {
        b_ = b;
    }
    void Clear()
    {
        ClearA();
        ClearB();
    }
    int Sum()const
    {
        return a_ + b_;
    }

    bool operator==(const Makaka& sigma)const
    {
        return a_ == sigma.a_ && b_ == sigma.b_;
    }

protected:
    void ClearA()
    {
        a_ = 0;
    }
    void ClearB()
    {
        b_ = 0;
    }

    int b_;
private:
    int a_;
};

bool operator!=(const Makaka& a, const Makaka& b)
{
    return !(a == b);
}

class People : public Makaka
{
public:
    People() = default;
    People(int a, int b, int c):Makaka(a, b), c_(c)
    {
        /*SetA(a);
        b_ = b;*/
    }
    int GetC()const
    {
        return c_;
    }
    int SetC(int c)
    {
        c_ = c;
    }
    int FullSum()
    {
        return GetA() + b_ + c_;
    }
    void Clear()
    {
        Makaka::Clear();
        ClearC();
    }

protected:
    void ClearC()
    {
        c_ = 0;
    }


private:
    int c_;
};


int main()
{
    system("color 0F");
    Makaka one(5, 6);
    Makaka two(2, 2);
    std::cout << two.Sum() << "\n";
    two.Clear();
    std::cout << two.Sum() << "\n";
    People three(4, 5, 7);
    std::cout << three.FullSum() << "\n";
    three.Clear();
    std::cout << three.FullSum() << "\n";

}


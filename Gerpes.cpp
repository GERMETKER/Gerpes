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

//static внутри функ меняет место хран переменной\
    перемещает её из стека вызовов в глобал переменные если примерно если к свободным функ или глобал\
    переменным запрещ их вызов из сторонних кодовых файлов\
    Применённное к методам или полям класса позволяет работать с даными полями и классами без создания объектов


//Правила работы стат методов:\
    1 - их можно вызвать в любой момент работы программы\
    даже если объекта класса для вызова нет под рукой\
    2 - доступность для исп завис только от кат доступа (public, protected, private)\
    3 - в теле стат метода можно вызвать тоько другие стат методы класса и обращ только\
    к стат полям своего класса\
    4 - на работу в внеш эл-ми (арг, глобал переменными, внешн классами и функ) ограничений нет

// Типы наследования\
        public, private, protected

//Наследованем, котор исп в проектах по умлчанию явл public. Оно позвол вкл полиморфизм\
и именно по этому чаще исп.\
Если при наслед не укозать тип по умолчнию\
компилятор будет считать что наследование было приватным.\
При приват наслед меняется доступ род компонентов переход в класс наследник\
и теряется возможность примен полиморфизм.\
При защищ наслед те же проблемы но измен доступа к род полям и методам\
происх по другим правилам

//Налич наслед в коде ед способ налич вкл динам полиморфизма в программе

//base_access | public    | protected | private |
//public      | public    | protected | private |
//protected   | protected | protected | private |
//private     | unreach   | unreach   | unreach |
//Было------->| стало---->

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

    static int st;

    static void RebutWorld()
    {
        std::cout << "World OFF\n";
        
        std::cout << "World ON\n";
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
//В этот момент мы опред чем явл переменная опред стат переменных нужно остов ТОЛЬКО в файлах cpp
int Makaka::st = 0;
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
    //стат методы доступны для работы как от имени объектов класса,\
    так и без них при обращ через имя класса
    system("color 0F");
    Makaka::st = 1;
    Makaka one(5, 6);
    Makaka two(2, 2);
    std::cout << two.Sum() << "\n";
    two.Clear();
    std::cout << two.Sum() << "\n";
    People three(4, 5, 7);
    std::cout << three.FullSum() << "\n";
    three.Clear();
    std::cout << three.FullSum() << "\n";
    std::cout << Makaka::st << "\n";
    Makaka::RebutWorld();
    


    
}


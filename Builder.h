#ifndef BUILDER_H
#define BUILDER_H
#include <iostream>

class Product
{
public:
    Product();
    void SetAtribute1(int atribute) {_atribute_1 = atribute;}
    void SetAtribute2(std::string atribute) {_atribute_2 = atribute;}
    void SetAtribute3(bool atribute) {_atribute_3 = atribute;}

    void Show()
    {   std::cout << "Product constructed : " << std::endl;
        std::cout << "Atribute 1 - " << _atribute_1 << std::endl;
        std::cout << "Atribute 2 - " << _atribute_2 << std::endl;
        std::cout << "Atribute 3 - " << _atribute_3 << std::endl;}
private:
    int _atribute_1;
    std::string _atribute_2;
    bool _atribute_3;
};

class IBuilder
{
public:
    virtual void BuildAtribute_1() = 0;
    virtual void BuildAtribute_2() = 0;
    virtual void BuildAtribute_3() = 0;
    virtual Product getProduct() = 0;

};

class ProductBuilder : public IBuilder
{
public:
    void    BuildAtribute_1()  override     {_product->SetAtribute1(10);}
    void    BuildAtribute_2()  override     {_product->SetAtribute2("AAA");}
    void    BuildAtribute_3()  override     {_product->SetAtribute3(true);}
    Product getProduct()       override     {return *_product;}
private:
    Product *_product;
};

class Director
{
public:
    Director(IBuilder* builder) : _builder(builder){}
    void ConstructProduct()
    {
        _builder->BuildAtribute_1();
        _builder->BuildAtribute_2();
        _builder->BuildAtribute_3();
    }
private:
    IBuilder* _builder;
};






#endif // BUILDER_H

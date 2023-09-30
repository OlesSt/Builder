#ifndef FLUENTBUILDER_H
#define FLUENTBUILDER_H
#include <iostream>

namespace FluentBuilderPattern
{
class Product
{
public:
    Product(){}
    //Methods for setting Atributes with return value of class itself to make a chain
    Product& setAtribute_1 (int atribute)            { _atribute_1 = atribute; return *this;}
    Product& setAtribute_2 (std::string atribute)    { _atribute_2 = atribute; return *this;}
    Product& setAtribute_3 (bool atribute)           { _atribute_3 = atribute; return *this;}

    void Show()
    {
        std::cout << "Product Constructed : " << std::endl;
        std::cout << "Atribute 1 - " << _atribute_1 << std::endl;
        std::cout << "Atribute 2 - " << _atribute_2 << std::endl;
        std::cout << "Atribute 3 - " << _atribute_3 << std::endl;
    }
private:
    int _atribute_1{};
    std::string _atribute_2{};
    bool _atribute_3{};
};

class Builder
{
public:
    Builder() {_product = new Product();}

    Builder &Atribute1 (int value)             {_product->setAtribute_1(value); return *this;}
    Builder &Atribute2 (std::string value)      {_product->setAtribute_2(value); return *this;}
    Builder &Atribute3 (bool value)             {_product->setAtribute_3(value); return *this;}

    Product Build() {return *_product;}

private:
    Product *_product;
};

}

#endif // FLUENTBUILDER_H

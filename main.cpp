#include <QCoreApplication>
#include <iostream>
#include "Builder.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IBuilder *builder = new ProductBuilder();
    Director director(builder);

    director.ConstructProduct();

    std::cout << "Build Product" << std::endl;

    Product prod = builder->getProduct();
    prod.Show();




    return a.exec();
}

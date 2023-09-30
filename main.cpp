#include <QCoreApplication>
#include <iostream>

#include "builder.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // CREATE A BUILDER
    IBuilder *builder = new ProductBuilder();

    //CREATE A DIRECTOR WHO MANEGEs BUILDER
    Director director(builder);

    director.ConstructProduct();

    //CONSTRUCT PRODUCT WITH BUILDER
    std::cout << "Build Product" << std::endl;
    Product prod = builder->getProduct();
    prod.Show();

    return a.exec();
}

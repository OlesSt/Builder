#include <QCoreApplication>
#include <iostream>

#include "builder.h"
#include "FluentBuilder.h"




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    std::cout << "---------- BUILDER ----------" << std::endl;
    // CREATE A BUILDER
    BuilderPattern::IBuilder *builder = new BuilderPattern::ProductBuilder();

    //CREATE A DIRECTOR WHO MANEGEs BUILDER
    BuilderPattern::Director director(builder);

    director.ConstructProduct();

    //CONSTRUCT PRODUCT WITH BUILDER
    std::cout << "Build Product" << std::endl;
    BuilderPattern::Product ProdByBuilder = builder->getProduct();
    ProdByBuilder.Show();

    delete builder;
    std::cout << "==========" << std::endl;


    std::cout << "\n---------- FLUENT BUILDER ----------" << std::endl;
    //CREATE A BUILDER
    FluentBuilderPattern::Builder FluentBuilder;

    //PRODUCE PRODUCT BY BUILDER
    FluentBuilderPattern::Product ProdByFluentBuilder = FluentBuilder.
                                                        Atribute1(10).
                                                        Atribute2("10").
                                                        Atribute3(true).
                                                        Build();
    ProdByFluentBuilder.Show();
    std::cout << "==========" << std::endl;


    return a.exec();
}

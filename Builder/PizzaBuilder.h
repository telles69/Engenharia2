#ifndef PIZZABUILDER_H
#define PIZZABUILDER_H

#include <string>
#include <vector>
#include <memory>
#include "Pizza.h"

class PizzaBuilder {
private:
    std::string tamanho;
    std::vector<std::string> sabores;
    bool bordaRecheada = false;

public:
    PizzaBuilder& comTamanho(const std::string& tam);
    PizzaBuilder& comSabor(const std::string& sabor);
    PizzaBuilder& comBordaRecheada(bool recheada);
    std::unique_ptr<Pizza> build();
};

#endif // PIZZABUILDER_H
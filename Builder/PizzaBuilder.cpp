#include "PizzaBuilder.h"

PizzaBuilder& PizzaBuilder::comTamanho(const std::string& tam) {
    this->tamanho = tam;
    return *this;
}

PizzaBuilder& PizzaBuilder::comSabor(const std::string& sabor) {
    this->sabores.push_back(sabor);
    return *this;
}

PizzaBuilder& PizzaBuilder::comBordaRecheada(bool recheada) {
    this->bordaRecheada = recheada;
    return *this;
}

std::unique_ptr<Pizza> PizzaBuilder::build() {
    // Chama o construtor privado da Pizza, o que é permitido por causa da amizade (friend)
    return std::unique_ptr<Pizza>(new Pizza(tamanho, sabores, bordaRecheada));
}
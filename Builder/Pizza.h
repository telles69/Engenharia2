#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>

class Pizza {
private:
    std::string tamanho;
    std::vector<std::string> sabores;
    bool bordaRecheada;
    double preco;
    
    // Construtor privado para forçar o uso do Builder
    Pizza(std::string tam, const std::vector<std::string>& sab, bool borda);

public:
    double getPreco() const;
    void exibir() const;

    // Concede ao PizzaBuilder acesso aos membros privados da Pizza
    friend class PizzaBuilder;
};

#endif // PIZZA_H
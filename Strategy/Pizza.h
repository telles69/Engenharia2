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

public:
    Pizza(std::string tam, const std::vector<std::string>& sab, bool borda);
    double getPreco() const;
    void exibir() const;
};

#endif
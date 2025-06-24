#include "Pizza.h"
#include <iostream>

// Implementação do Construtor
Pizza::Pizza(std::string tam, const std::vector<std::string>& sab, bool borda)
    : tamanho(tam), sabores(sab), bordaRecheada(borda), preco(0.0) {
    
    if (tamanho == "Grande") {
        preco += 50.0;
    } else if (tamanho == "Média") {
        preco += 40.0;
    } else { // Pequena
        preco += 30.0;
    }

    if (sabores.size() > 1) {
        preco += (sabores.size() - 1) * 5.0;
    }

    if (bordaRecheada) {
        preco += 8.0;
    }
}

double Pizza::getPreco() const {
    return preco;
}

void Pizza::exibir() const {
    std::cout << "  - Pizza " << tamanho << " (";
    for (size_t i = 0; i < sabores.size(); ++i) {
        std::cout << sabores[i] << (i == sabores.size() - 1 ? "" : ", ");
    }
    std::cout << ")";
    if (bordaRecheada) {
        std::cout << " com borda recheada";
    }
    std::cout << " - R$ " << getPreco() << std::endl;
}
#include "Pedido.h"
#include "Pizza.h" 
#include <iostream>
#include <utility> 

// Implementação do Construtor
Pedido::Pedido(std::string tipo, std::string endereco)
    : tipoEntrega(tipo), enderecoCliente(endereco), valorTotal(0.0) {}

// Implementação de adicionarPizza
void Pedido::adicionarPizza(std::unique_ptr<Pizza> pizza) {
    pizzas.push_back(std::move(pizza));
}

// Implementação de calcularValorTotal
void Pedido::calcularValorTotal() {
    valorTotal = 0.0;
    for (const auto& pizza : pizzas) {
        valorTotal += pizza->getPreco();
    }

    if (tipoEntrega == "Delivery") {
        valorTotal += 10.0; 
    }
}

void Pedido::imprimirRecibo() const {
    std::cout << "\n======================================\n";
    std::cout << "         RECIBO DO PEDIDO\n";
    std::cout << "======================================\n";
    std::cout << "Modalidade: " << tipoEntrega << std::endl;
    if (tipoEntrega == "Delivery" && !enderecoCliente.empty()) {
        std::cout << "Endereco de Entrega: " << enderecoCliente << std::endl;
    }
    std::cout << "--------------------------------------\n";
    std::cout << "Itens do Pedido:\n";
    for (const auto& pizza : pizzas) {
        pizza->exibir();
    }
    std::cout << "--------------------------------------\n";
    if (tipoEntrega == "Delivery") {
        std::cout << "Taxa de Entrega: R$ 10.00\n";
    }
    std::cout << "VALOR TOTAL: R$ " << valorTotal << std::endl;
    std::cout << "======================================\n";
}
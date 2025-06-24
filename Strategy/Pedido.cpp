
#include "Pedido.h"
#include "Pizza.h"
#include <iostream>
#include <utility>

Pedido::Pedido(std::unique_ptr<ModalidadeEntregaStrategy> modalidade, std::string endereco)
    : modalidadeEntrega(std::move(modalidade)), enderecoCliente(endereco), valorTotal(0.0) {}

void Pedido::adicionarPizza(std::unique_ptr<Pizza> pizza) {
    pizzas.push_back(std::move(pizza));
}

void Pedido::calcularValorTotal() {
    double valorItens = 0.0;
    for (const auto& pizza : pizzas) {
        valorItens += pizza->getPreco();
    }

    
    double taxa = modalidadeEntrega->calcularTaxa(valorItens);
    this->valorTotal = valorItens + taxa;
}

void Pedido::imprimirRecibo() const {
    double taxa = modalidadeEntrega->calcularTaxa(0); 
    
    std::cout << "\n======================================\n";
    std::cout << "         RECIBO DO PEDIDO\n";
    std::cout << "======================================\n";
    std::cout << "Modalidade: " << modalidadeEntrega->obterNome() << std::endl;
    if (modalidadeEntrega->obterNome() == "Delivery" && !enderecoCliente.empty()) {
        std::cout << "Endereco de Entrega: " << enderecoCliente << std::endl;
    }
    std::cout << "--------------------------------------\n";
    std::cout << "Itens do Pedido:\n";
    for (const auto& pizza : pizzas) {
        pizza->exibir();
    }
    std::cout << "--------------------------------------\n";
    if (taxa > 0) {
        std::cout << "Taxa de Entrega: R$ " << taxa << std::endl;
    }
    std::cout << "VALOR TOTAL: R$ " << valorTotal << std::endl;
    std::cout << "======================================\n";
}
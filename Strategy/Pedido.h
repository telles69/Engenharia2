#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <vector>
#include <memory>
#include "ModalidadeEntregaStrategy.h" 

class Pizza; 

class Pedido {
private:
    std::vector<std::unique_ptr<Pizza>> pizzas;
    std::unique_ptr<ModalidadeEntregaStrategy> modalidadeEntrega; 
    std::string enderecoCliente;
    double valorTotal;

public:
    Pedido(std::unique_ptr<ModalidadeEntregaStrategy> modalidade, std::string endereco = "");

    void adicionarPizza(std::unique_ptr<Pizza> pizza);
    void calcularValorTotal();
    void imprimirRecibo() const;
};

#endif // PEDIDO_H
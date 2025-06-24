#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <vector>
#include <memory>

class Pizza; 

class Pedido {
private:
    std::vector<std::unique_ptr<Pizza>> pizzas;
    std::string tipoEntrega;
    std::string enderecoCliente;
    double valorTotal;

public:
    Pedido(std::string tipo, std::string endereco = "");

    void adicionarPizza(std::unique_ptr<Pizza> pizza);
    void calcularValorTotal();
    void imprimirRecibo() const;
};

#endif // PEDIDO_H
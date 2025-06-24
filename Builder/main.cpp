#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "PizzaBuilder.h"
#include "Pedido.h"
#include "EstrategiaDelivery.h"
#include "EstrategiaRetirada.h"

// Função auxiliar que agora usa o PizzaBuilder
std::unique_ptr<Pizza> criarPizza() {
    std::string tamanho;
    std::string sabor;
    char temBorda;
    char adicionarOutroSabor;

    PizzaBuilder builder;

    std::cout << "\n-- Montando uma nova Pizza --\n";
    std::cout << "Qual o tamanho (Pequena, Média, Grande)? ";
    std::cin >> tamanho;
    builder.comTamanho(tamanho);

    std::cout << "Digite um sabor: ";
    std::cin >> sabor;
    builder.comSabor(sabor);

    do {
        std::cout << "Adicionar outro sabor (s/n)? ";
        std::cin >> adicionarOutroSabor;
        if (adicionarOutroSabor == 's' || adicionarOutroSabor == 'S') {
            std::cout << "Digite o outro sabor: ";
            std::cin >> sabor;
            builder.comSabor(sabor);
        }
    } while (adicionarOutroSabor == 's' || adicionarOutroSabor == 'S');

    std::cout << "Borda recheada (s/n)? ";
    std::cin >> temBorda;
    if (temBorda == 's' || temBorda == 'S') {
        builder.comBordaRecheada(true);
    }
    
    std::cout << "Pizza adicionada ao pedido!\n";
    return builder.build();
}

int main() {
    std::cout << "Bem-vindo a Pizzaria do TPE!\n";
    std::string tipoEscolhido;
    std::string endereco;
    std::unique_ptr<ModalidadeEntregaStrategy> estrategia;

    std::cout << "O pedido e para 'Delivery' ou 'Retirada'? ";
    std::cin >> tipoEscolhido;

    if (tipoEscolhido == "Delivery") {
        std::cout << "Por favor, digite o endereco para entrega: ";
        std::cin.ignore(); 
        std::getline(std::cin, endereco);
        estrategia = std::make_unique<EstrategiaDelivery>();
    } else {
        estrategia = std::make_unique<EstrategiaRetirada>();
    }

    Pedido pedido(std::move(estrategia), endereco);

    char adicionarOutraPizza;
    do {
        auto novaPizza = criarPizza();
        pedido.adicionarPizza(std::move(novaPizza));

        std::cout << "\nDeseja adicionar outra pizza ao pedido (s/n)? ";
        std::cin >> adicionarOutraPizza;
    } while (adicionarOutraPizza == 's' || adicionarOutraPizza == 'S');
    
    pedido.calcularValorTotal();
    pedido.imprimirRecibo();

    std::cout << "\nObrigado pela preferencia!\n";

    return 0;
}
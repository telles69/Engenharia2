#ifndef MODALIDADEENTREGASTRATEGY_H
#define MODALIDADEENTREGASTRATEGY_H

#include <string>

class ModalidadeEntregaStrategy {
public:

    virtual ~ModalidadeEntregaStrategy() = default;
    virtual double calcularTaxa(double valorItens) const = 0;
    virtual std::string obterNome() const = 0;
};

#endif 
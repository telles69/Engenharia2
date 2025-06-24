#ifndef ESTRATEGIARETIRADA_H
#define ESTRATEGIARETIRADA_H

#include "ModalidadeEntregaStrategy.h"

class EstrategiaRetirada : public ModalidadeEntregaStrategy {
public:
    double calcularTaxa(double valorItens) const override;
    std::string obterNome() const override;
};

#endif 
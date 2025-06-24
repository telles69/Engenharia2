#ifndef ESTRATEGIADELIVERY_H
#define ESTRATEGIADELIVERY_H

#include "ModalidadeEntregaStrategy.h"

class EstrategiaDelivery : public ModalidadeEntregaStrategy {
public:
    double calcularTaxa(double valorItens) const override;
    std::string obterNome() const override;
};

#endif 
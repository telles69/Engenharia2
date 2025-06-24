#include "EstrategiaDelivery.h"

double EstrategiaDelivery::calcularTaxa(double valorItens) const {
    return 10.0;
}

std::string EstrategiaDelivery::obterNome() const {
    return "Delivery";
}
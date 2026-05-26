#pragma once

#include <Eigen/Dense>
#include <cmath>

Eigen::VectorXd gradiente_coniugato(
    const Eigen::MatrixXd& A,
    const Eigen::VectorXd& b,
    const Eigen::VectorXd& x0,
    double tolleranza,
    unsigned int iterazioni_massime,
    unsigned int& iterazioni_eseguite)
{
    Eigen::VectorXd soluzione = x0;

    
    Eigen::VectorXd residuo = b - A * soluzione;

    
    Eigen::VectorXd direzione = residuo;

    const double norma_iniziale = residuo.norm();

    iterazioni_eseguite = 0;

    
    if (norma_iniziale < 1e-14)
    {
        return soluzione;
    }

    while (iterazioni_eseguite < iterazioni_massime &&
           residuo.norm() > tolleranza * norma_iniziale)
    {
        Eigen::VectorXd A_direzione = A * direzione;

        double denominatore =
            (direzione.transpose() * A_direzione).value();

        
        if (std::abs(denominatore) < 1e-14)
        {
            break;
        }

        
        double passo =
            (direzione.transpose() * residuo).value()
            / denominatore;

        
        soluzione += passo * direzione;

        
        Eigen::VectorXd nuovo_residuo =
            b - A * soluzione;

        
        if (nuovo_residuo.norm() <=
            tolleranza * norma_iniziale)
        {
            residuo = nuovo_residuo;
            iterazioni_eseguite++;
            break;
        }

        
        double coefficiente =
            ((nuovo_residuo.transpose() * A_direzione).value())
            / denominatore;

        
        direzione =
            nuovo_residuo - coefficiente * direzione;

        residuo = nuovo_residuo;

        iterazioni_eseguite++;
    }

    return soluzione;
}
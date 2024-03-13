/**
 * @file secante.h
 * @author Harold Velasquez (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef SECANTE_H
#define SECANTE_H
#include <iostream>
#include <string.h>
#include "expression.h"
#include "raices.h"

using raices::aproximacion;
using raices::solucion;

namespace raices
{
    /**
     * @brief Metodo de la secante
     */
    class secante
    {
    public:
        /**
         * @brief Crea una nueva instancia del metodo de la secante
         * @param str_func Texto de la funciom
         */
        secante(string str_func) : f(str_func) {}
        /**
         * @brief Encuentra una raiz con los parametros dados
         * @param x0 valor del punto
         * @param x1
         * @param tol
         * @param n
         * @return solucion del metodo
         */
        solucion encontrar(double x0, double x1, double tol, int n)
        {
            solucion sol;
            // Verificar los extremos del intervalo
            if (es_raiz(f, x0))
            {
                sol.raiz = x0;
                return sol;
            }
            if (es_raiz(f, x1))
            {
                sol.raiz = x1;
                return sol;
            }

            // Paso 1
            int i = 1;

            // Paso 2
            do
            {
                // Calculamos la primera aproximacion
                double x2 = x1 - ((f(x1) * (x0 - x1)) / (f(x0) - f(x1)));
                aproximacion aprox(x1, x2);
                // Adicionar la aproximacion a la solucion
                sol.agregar(aprox);
                // verificar si encontro la raiz
                if (aprox.erp < tol)
                {
                    sol.raiz = x2;
                    return sol;
                }
                // siguiente iteracion
                i++;
                // actuaizar los valordes de x0 y x1
                x0 = x1;
                x1 = x2;
            } while (i <= n);
            return sol;
        }

    private:
        expression f;
    };
}

#endif
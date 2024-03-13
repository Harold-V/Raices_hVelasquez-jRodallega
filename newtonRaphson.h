/**
 * @file newtonRaphson.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-02-23
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef newtonRaphson_H
#define newtonRaphson_H
#include <cmath>
#include <iostream>
#include <string>
#include "expression.h"
#include "raices.h"

using raices::aproximacion;
using raices::solucion;
using std::cout;
using std::endl;
using std::string;

namespace raices
{
    class newtonRaphson
    {
        /**
         * @brief Crea una instancia de newtonRaphoson
         * @param str_func Texto que representa la funcion
         * @param strdfunc Texto que representa la derivada de la funcion

         */
    public:
        newtonRaphson(string str_func, string strdfunc) : f(str_func), df(strdfunc){};

        solucion encontrar(double p0, double tol, int n)
        {
            solucion sol;
            // Verificar los extremos del intervalo
            if (es_raiz(f, p0))
            {
                sol.raiz = p0;
                return sol;
            }
            // Paso 1
            int i = 1;
            // Paso 2
            while (i <= n)
            {
                double p = p0 - (f(p0) / df(p0));
                aproximacion ap(p0, p);
                sol.agregar(ap);
                if (ap.erp < tol)
                {
                    sol.raiz = p;
                    return sol;
                }
                p0 = p;
                i++;
            }
            return sol;
        }

    private:
        expression f;
        expression df;
    };

}

#endif
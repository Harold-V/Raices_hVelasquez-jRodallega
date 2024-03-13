/**
 * @file newtonRaphsonG.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-03-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef NEWTON_RAPHSON_G
#define NEWTON_RAPHSON_G
#include "string"
#include "expression.h"
#include "raices.h"

using raices ::aproximacion;
using raices ::solucion;
using std::string;

namespace raices
{
    /**
     * @brief Metodo de newton raphson generalizado
     */
    class newtonRaphsonG
    {
    public:
        /**
         * @brief Crea una instancia de newton raphson generalizado
         * @param str_func
         * @param str_dfunc
         * @param str_d2func
         */
        newtonRaphsonG(string str_func, string str_dfunc, string str_d2func) : f(str_func), df(str_dfunc), d2f(str_d2func) {}

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

            while (i <= n)
            {
                // Paso 3
                double p = p0 - ((f(p0) * df(p0)) / (pow(df(p0), 2) - (f(p0) * d2f(p0))));
                // Crear la instancia de aproximacion
                aproximacion ap(p0, p);
                // Adicionar la aproximacion a la solucion
                sol.agregar(ap);
                // Paso 4
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
        expression f;   /*!< Funcion a evaluar*/
        expression df;  /*!< Derivada de la funcion*/
        expression d2f; /*!< Segunda Derivada de la funcion*/
    };

}
#endif
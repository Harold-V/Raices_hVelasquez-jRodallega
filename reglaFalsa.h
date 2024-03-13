/**
 * @file regla_falsa.h
 * @author Harold Velasquez (hvelasquez@unicauca.edu.co)
 * @brief Definiciones del metodo de regla falsa
 * @copyright MIT License
 *
 */

#ifndef reglaFalsa_H
#define reglaFalsa_H
#include <cmath>
#include <iostream>
#include <string.h>
#include "expression.h"
#include "raices.h"

using std::cout;
using std::endl;
using std::string;

using raices::aproximacion;
using raices::es_raiz;
using raices::solucion;

namespace raices
{
    /**
     * @brief Metodo de la regla falsa
     */
    class reglaFalsa
    {

    public:
        /**
         * @brief Crea una nueva isntancia del metodo de biseccio
         * @param str_func Texto que representa la funcion
         */
        reglaFalsa(string str_func) : f(str_func){};

        /**
         * @brief Encuentra una raiz de la funcion
         * @param xi Extremo inferior del intervalo
         * @param xs Extremo superior del intervalo
         * @param tol Tolerancia
         * @param n Numero maximo de iteraciones
         * @return solucion
         */

        solucion encontrar(double xi, double xs, double tol, int n)
        {
            // solucion a retornar
            solucion sol;

            // Verificar los extremos del intervalo
            if (es_raiz(f, xi))
            {
                sol.raiz = xi;
                return sol;
            }
            if (es_raiz(f, xs))
            {
                sol.raiz = xs;
                return sol;
            }

            // Verificar que se cumpla TVI
            if ((f(xi) * f(xs)) > 0)
            {
                return sol;
            }

            // Paso 1
            int i = 1;

            // Paso 2. Calcular el punto medio y evaluar en en cual sub-intervalo
            double xrAnt = xs - ((f(xs) * (xi - xs)) / (f(xi) - f(xs)));
            if ((f(xi)) * f(xrAnt) > 0.0f)
            {
                xi = xrAnt;
            }
            else
            {
                xs = xrAnt;
            }

            // Paso 3
            while (i <= n)
            {
                // Paso 4 Calculo de la nueva raiz y el error relativo porcentual
                double xrNueva = xs - ((f(xs) * (xi - xs)) / (f(xi) - f(xs)));

                // crear una instancia de aproximacion
                aproximacion aprox(xrAnt, xrNueva);

                // Adicionar la nueva aproximacion a la solucion
                sol.agregar(aprox);

                // Paso 5
                if (aprox.erp < tol || fabs(f(xrNueva)) < DBL_EPSILON)
                {
                    // Solucion encontrada, guardar la raiz y retornar
                    sol.raiz = xrNueva;
                    return sol;
                }

                // Paso 6
                i++;

                // Paso 7. Redifinir el intervalo
                if ((f(xi)) * f(xrNueva) > 0.0f)
                {
                    xi = xrNueva;
                }
                else
                {
                    xs = xrNueva;
                }
                xrAnt = xrNueva;
            }

            return sol;
        };

    private:
        expression f;
    };
}
#endif

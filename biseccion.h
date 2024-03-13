/**
 * @file biseccion.h
 * @author Harold Velasquez (hvelasquez@unicauca.edu.co)
 * @brief Definiciones del metodo de biseccion
 * @copyright MIT License
 *
 */

#ifndef BISECCION_H
#define BISECCION_H
#include <cmath>
#include <iostream>
#include <string.h>
#include "expression.h"
#include "raices.h"

using std::cout;
using std::endl;
using std::string;

using raices::aproximacion;
using raices ::es_raiz;
using raices::solucion;

namespace raices
{
    /**
     * @brief Metodo de biseccion
     */
    class biseccion
    {

    public:
        /**
         * @brief Crea una nueva isntancia del metodo de biseccio
         * @param str_func Texto que representa la funcion
         */
        biseccion(string str_func) : f(str_func){};

        /**
         * @brief Encuentra una raiz de la funcion
         * @param xa Extremo izquierdo del intervalo
         * @param xb Extremo derecho del intervalo
         * @param tol Tolerancia
         * @param n Numero maximo de iteraciones
         * @return solucion
         */

        solucion encontrar(double xa, double xb, double tol, int n)
        {
            // solucion a retornar
            solucion sol;
            // Verificar los extremos del intervalo
            if (es_raiz(f, xa))
            {
                sol.raiz = xa;
                return sol;
            }

            if (es_raiz(f, xb))
            {
                sol.raiz = xb;
                return sol;
            }

            // Verificar que se cumpla TVI
            if ((f(xa) * f(xb)) > 0)
            {
                return sol;
            }

            // Paso 1
            int i = 1;
            // Paso 2. Calcular el punto medio y evaluar en en cual sub-intervalo
            double xAnt = (xa + xb) / 2.0f;
            if ((f(xa)) * f(xAnt) > 0.0f)
            {
                xa = xAnt;
            }
            else
            {
                xb = xAnt;
            }
            // Paso 3
            while (i <= n)
            {
                // Paso 4 Calculo de la nueva raiz y el error relativo porcentual
                double xNueva = (xa + xb) / 2.0f;

                // crear una instancia de aproximacion
                aproximacion aprox(xAnt, xNueva);

                // Adicionar la nueva aproximacion a la solucion
                sol.agregar(aprox);

                // Paso 5
                if (aprox.erp < tol || es_raiz(f, xNueva))
                {
                    // Solucion encontrada, guardar la raiz y retornar
                    sol.raiz = xNueva;
                    break;
                }
                // Paso 6
                i++;
                // Paso 7. Redifinir el intervalo
                if ((f(xa)) * f(xNueva) > 0.0f)
                {
                    xa = xNueva;
                }
                else
                {
                    xb = xNueva;
                }
                xAnt = xNueva;
            }

            return sol;
        };

    private:
        expression f;
    };
}
#endif

/**
 * @file raices.h
 * @author Harold Velasquez (hvelasquez@unicauca.edu.co)
 * @brief Definiciones de los metodos para hallar raices
 * @copyright MIT License
 */

#ifndef RAICES_H
#define RAICES_H
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::setprecision;
using std::setw;
using std::vector;

namespace raices
{
    /**
     * @brief Aproximacion de una raiz
     */
    struct aproximacion
    {
        double anterior; /*!< Valor anterior*/
        double nuevo;    /*!< Valor Nuevo*/
        double erp;      /*!< Error relativo porcentual*/

        /**
         * @brief Crear una nueva instancia de aproximacion
         * @param vAnterior valor anterior
         * @param vNuevo valor nuevo
         */
        aproximacion(double vAnterior, double vNuevo) : anterior(vAnterior), nuevo(vNuevo)
        {
            erp = fabs((nuevo - anterior) / nuevo) * 100.0f;
        }
    };

    /**
     * @brief Solucion de un metodo para hallar la raiz
     */
    struct solucion
    {
        double raiz = NAN;                   /*!< Raiz encontrada*/
        vector<aproximacion> aproximaciones; /*!< Aproximaciones*/

        /**
         * @brief Adiciona una nueva aprocimacion
         * @param a nueva aproximacion
         */
        void agregar(aproximacion a)
        {
            aproximaciones.push_back(a);
        }
        /**
         * @brief
         *
         * @param val
         */
        void establecer(double val)
        {
            raiz = val;
        }
    };

    /**
     * @brief Imprime una solucion encontrada
     * @param sol solucion
     */
    void imprimir_solucion(solucion &sol)
    {
        if (std::isnan(sol.raiz))
        {
            cout << "No se pudo encontrar la raiz" << endl;
        }
        else
        {
            cout << "La raiz es: " << sol.raiz << endl;
        }

        size_t cantAproximaciones = sol.aproximaciones.size();
        // Terminar la funcion si no se realizaron aprocimacines
        if (cantAproximaciones == 0)
        {
            return;
        }

        cout << "Aprocimaciones: " << cantAproximaciones << endl;

        cout << setw(15) << "Anterior" << setw(3) << "   " << setw(15) << "Nuevo" << setw(3) << "   " << setw(20) << "Error rel. Porcentual." << endl;

        for (size_t i = 0; i < sol.aproximaciones.size(); i++)
        {
            const aproximacion aprox = sol.aproximaciones[i];
            cout << setw(15) << setprecision(9) << aprox.anterior << setw(3) << "   " << setw(15) << setprecision(9) << aprox.nuevo << setw(3) << "   " << setw(20) << setprecision(3) << aprox.erp << endl;
        }
    }

    /**
     * @brief Determina si el  dado se evalua a cero (es raiz)
     * @param f Referencia al evaluador de la funcion
     * @param x valor a evaluar
     * @return true si f(x)= 0
     * @return false en caso contrario
     */
    bool es_raiz(expression &f, double x)
    {
        return fabs(f(x)) <= DBL_EPSILON;
    }
};

#endif
#ifndef MULLER_H
#define MULLER_H
double tol = 1e-5; // toleracia que se usa en el proyecto

#include "string"
#include "expression.h"
#include "raices.h"

using raices ::aproximacion;
using raices ::solucion;
using std::string;

namespace raices
{

    class muller
    {
    public:
        muller(string str_func) : f(str_func) {}

        solucion encontrar(double x0, double x1, double x2, double tol, int n)
        {
            solucion sol;
            double h1 = x1 - x0;
            double h2 = x2 - x1;
            double d1 = ((f(x1) - f(x0)) / h1);
            double d2 = ((f(x2) - f(x1)) / h2);
            double a = ((d2 - d1) / (h2 + h1));
            int i = 2;

            // Paso 2
            while (i <= n)
            {
                double b = d2 + (h2 * a);
                double c = f(x2);
                double D = sqrt(pow(b, 2) - (4.0f * a * c));

                double E;
                if (fabs(b - D) <= fabs(b + D))
                {
                    E = b + D;
                }
                double h = (-2.0f * c) / E;
                double p = x2 + h;

                aproximacion ap(x2, p);
                sol.agregar(ap);

                if (ap.erp < tol)
                {
                    sol.raiz = p;
                    return sol;
                }

                x0 = x1;
                x1 = x2;
                x2 = p;
                h1 = x1 - x0;
                h2 = x2 - x1;
                d1 = ((f(x1) - f(x0)) / h1);
                d2 = ((f(x2) - f(x1)) / h2);
                a = ((d2 - d1) / (h2 + h1));
                i++;
            }
            return sol;
        }

    private:
        expression f;
    };

}
#endif

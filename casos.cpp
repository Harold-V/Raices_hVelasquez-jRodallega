#include <iostream>
#include "casos.h"

#include "biseccion.h"
#include "expression.h"
#include "muller.h"
#include "raices.h"
#include "reglaFalsa.h"
#include "newtonRaphson.h"
#include "newtonRaphsonG.h"
#include "secante.h"

using raices::aproximacion;
using raices::biseccion;
using raices::imprimir_solucion;
using raices::muller;
using raices::newtonRaphson;
using raices::newtonRaphsonG;
using raices::reglaFalsa;
using raices::secante;
using raices::solucion;

using std::cout;
using std::endl;
using std::string;

#define TOL 1e-5f

void caso_1()
{

    string str_func = " e^(~x) - ln(x)";
    double x0 = 0.25f;
    double x1 = 0.75f;
    double x2 = 3.25f;
    double tol = TOL;
    int n = 100;

    muller mul(str_func);
    solucion solMul = mul.encontrar(x0, x1, x2, tol, n);
    imprimir_solucion(solMul);
}

void caso_2()
{
}

void caso_3()
{
}

void caso_4()
{
}

void caso_5()
{
}

void caso_6()
{
    string str_func = "x^3-(5*(x^2))+(7*x)-3";
    cout << "Solucion por el metodo de Newton Raphson Generalizado" << endl;
    double p0 = 2.33f;
    double tol = 0.01f;
    int n = 100;

    string str_dfunc = "3*x^2-10*x+7";
    string str_d2func = "6*x-10";

    newtonRaphsonG nrg(str_func, str_dfunc, str_d2func);

    solucion solNrg = nrg.encontrar(p0, tol, n);
    imprimir_solucion(solNrg);
}

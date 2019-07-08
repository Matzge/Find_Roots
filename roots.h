
#ifndef _ROOTS_H_
#define _ROOTS_H_

#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** \brief Funfktion p(x)
 * \param const double x   x Wert der Funktuion
 * \return double x  ausgewerteter Funktionswert p(x)
 */

double p(const double x);

/** \brief Funfktion q(x)
 * \param const double x   x Wert der Funktuion
 * \return double x  ausgewerteter Funktionswert q(x)
 */

double q(const double x);

/** \brief Funfktion s(x)
 * \param const double x   x Wert der Funktuion
 * \return double x  ausgewerteter Funktionswert s(x)
 */

double s(const double x, vector <double> &a);

/** \brief Sucht Nullstellen einer Funktion im Intervall [a,b] mittels Bisektion.
 * \param func  Funktion für die Nullstellen gefunden werden sollen
 * \param const double Intervallbeginn
 * \param const double Intervallende
 * \param const double EPS Genauigkit mit der Nullstellen gesucht werden
 * \return v2 Vektor der alle Nullstelen enthält.
 */

vector<double> roots(const function<double(double)>& func, const double a, const double b, const double EPS);



#endif // _ROOTS_

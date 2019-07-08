#include "bisect.h"
#include <cmath>                  // abs()
#include <functional>             // function; C++11

double Bisect(const std::function<double(double)>& func,
              const double a, const double b, const double eps)
{
    double c = (a + b) / 2, fc = func(c), x0;

    if ( std::abs(fc) < eps ) {
        x0 = c;			// end of recursion
    }
    else if (  fc > 0.0 ) {
        x0 = Bisect(func, c, b, eps);	// search in right intervall
    }
    else {		// i.e., fc < 0.0
        x0 = Bisect(func, a, c, eps);	// search in left intervall
    }

    return x0;			// return with solution
}

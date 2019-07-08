#ifndef BISECT_H_INCLUDED
#define BISECT_H_INCLUDED

#include <functional>             // function; C++11
#include <vector>
/** \brief Returns one solution for the equation @f$ func(x) = 0 @f$ with
 *    @f$ x \in [a,b] @f$.
 *
 *   The solution is determined by bisection.
 *
 *   <b> double (*)(double)</b>
 *   is a function pointer that expects functions declared as:
 *   <b>double pp(double x);</b>
 *   i.e., <b>pp</b> could be used as first argument in the parameter list when calling @p Bisect3.
 *
 * \param[in]   func  function with one @p double input parameter that returns a  @p double value
 * \param[in]   a     interval begin
 * \param[in]   b     interval end
 * \param[in]   eps   accuracy @f$ \varepsilon @f$
 * \return solution @f$ x^\ast@f$ such that  @f$ |func(x^\ast)| < \varepsilon @f$
 * \warning  The function values @f$ func(a) @f$ and @f$ func(b) @f$ musst have different signs.
 *
 */
 double Bisect(const std::function<double(double)>& func,
               const double a, const double b, const double eps);




#endif // BISECT_H_INCLUDED

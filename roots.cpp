#include "roots.h"
#include "bisect.h"
#include "file_io.h"
#include <cmath>
#include <vector>

using namespace std;

double p(const double x)
{
    return (pow(x, 4)-(pow(x, 3)/2)+(pow(x, 2)/2)-(x/2)-0.5)*cos(x);
}

double q(const double x)
{
    return sin(1/x);
}

double s(const double x, vector <double> &a)
{
    double result = 0;
    for(unsigned int i = 0; i < a.size(); ++i)
    {
        result += pow(x, i) * a[i];
    }
    return result;
}


vector <double>roots(const function<double(double)>& func, const double a, const double b, const double EPS)
{
    //Vektor befüllen
    vector<double> v1;
    vector<double> v2;
    double n = 4;
    do
    {
        //Vektor übertragen
        v1.clear();
        v1 = v2;
        v2.clear();

        //Bisektionsverfahren
        double xi = a;
        do
        {

            double a1 = xi;
            double b1 = xi+(b-a)/n;
            double fa = func(a1);
            double fb = func(b1);
            double x0 = 0;
            if (fa*fb > 0.0)
            {

            }
            else if (abs(fa) < EPS || abs(fb) < EPS) {
                    if ( abs(fa) < EPS ) {
                        x0 = a1;
                    }
                    if (abs(fb) < EPS ) {
                    }
                    v2.push_back(x0);
            }
            else {
                if ( fa < 0.0 ) {
                        x0 = Bisect(func, b1, a1, EPS);
                }
                else {
                        x0 = Bisect(func, a1, b1, EPS);
                }
                v2.push_back(x0);
            }
            xi += (b-a)/n;
        } while(xi < b);
        n *= 10;
    } while(v2.size() != v1.size());
    cout<<v2.size()<< " Nullstellen gefunden" <<endl;
    return v2;
}

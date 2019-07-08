#include "roots.h"
#include "file_io.h"

int main()
{


    vector <double> v;
    vector <double> a;
    string name = "input_1.txt";

    //FUNCTION px

    double EPS = 1e-6;
    v = roots(p, -2.5, 2.0, EPS);


    cout << "Nullstellen der Funktion p(x): " << endl;
    for(unsigned int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
    write_vector_to_file("Nullstellen_PX.txt", v);

    //FUCTION qx

    cout<<endl;

    vector <double> v1;
    v1 = roots(q, 0.001, 1.0, EPS);

    cout << "Nullstellen der Funktion q(x): " << endl;
    for(unsigned int i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << endl;
    }
    write_vector_to_file("Nullstellen_QX.txt", v1);



    cout<<endl;

    //FUNKTION s(x)

    read_vector_from_file(name,a);
    vector <double> v2;

    v2 = roots([&a] (double x)->double{return s(x,a);}, -6.0 ,15.0, EPS);

    cout << "Nullstellen der Funktion s(x): " << endl;
    for(unsigned int i = 0; i < v2.size(); ++i)
    {
        cout << v2[i] << endl;
    }
    write_vector_to_file("Nullstellen_SX.txt", v2);

    cout<<endl;


    return 0;
}

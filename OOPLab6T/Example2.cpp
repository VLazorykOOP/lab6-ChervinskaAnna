#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
using namespace std; 
namespace SpaceExample2 {
        using namespace std;
    class Equation {
    protected:
     
    public:
        Equation(){
        }

        virtual int getRoots(double *roots) =0 ;
    };

    class Linear : public Equation {
        protected:
            double K; 
            double B;
        public:
            Linear(double k, double b) : K(k), B(b) {}
            int getRoots(double* roots) {
                if (K == 0) return 0;
                roots[0] = -B / K;
                return 1;
            }
    };
    
    class Squere : public Equation {
    protected:
        double A;
        double B;
        double C;
    public:
        Squere(double a, double b, double c) : A(a), B(b), C(c) {}
        int getRoots(double* roots) {
            double D;
            D = B * B - 4 * A * C;
            if (D == 0) {
                roots[0] = -B / (2 * A);
                return 1;

            }
            if(D>0){
                roots[0] = ( - B + sqrt(D)) / (2 * A);
                roots[1] =( - B - sqrt(D)) / (2 * A);
                return 2;
            }
            return 0;
        }
    };

    class BiSquere : public Equation {
    protected:
        double A;
        double B;
        double C;
    public:
        BiSquere(double a, double b, double c) : A(a), B(b), C(c) {}
        int getRoots(double* roots) {
            double D, t;
            double t1, t2;
            int numRoots=0;
            D = B * B - 4 * A * C;
            if (D == 0) {
                t = -B / (2 * A);
                if(t==0){
                    roots[0] = 0;
                    return 1;
                }
                if (t > 0) {
                    roots[0] = sqrt(t);
                    roots[1] = -sqrt(t);
                    return 2;
                }

            }
            if (D > 0) {
                t1 = (-B + sqrt(D)) / (2 * A);
                t2 = (-B - sqrt(D)) / (2 * A);
                if (t1 == 0) {
                    roots[0] = 0;
                    numRoots = 1;
                }
                if (t1 > 0) {
                    roots[0] = sqrt(t1);
                    roots[1] = -sqrt(t1);
                    numRoots = 2;
                }

                if (t2 == 0) {
                    roots[numRoots++] = 0;
         
                }
                if (t2 > 0) {
                    roots[numRoots++] = sqrt(t2);
                    roots[numRoots++] = -sqrt(t2);
                }

                return numRoots;
            }
            return 0;
        }
    };


    int mainExample2()
    {
        double roots[5];
        int numRoots;
        Linear a = Linear(5, 6);
        numRoots = a.getRoots(roots);

        cout << "Linear roots: (" << numRoots << ")\n";
        for (int i = 0; i < numRoots; i++) {
            cout << roots[i] << endl;
        }

        Squere b = Squere(3, -18, 20);
        numRoots = b.getRoots(roots);

        cout << "Squere roots: (" << numRoots << ")\n";
        for (int i = 0; i < numRoots; i++) {
            cout << roots[i] << endl;
        }

        BiSquere c = BiSquere(1, -70, 600);
        numRoots = c.getRoots(roots);

        cout << "BiSquere roots: (" << numRoots << ")\n";
        for (int i = 0; i < numRoots; i++) {
            cout << roots[i] << endl;
        }

       return 0;
    }


}
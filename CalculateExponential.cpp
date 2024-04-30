#include "CalculateExponential.hpp"
#include <cmath>

void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res) {
    int n = nMax; 

    // allocate and init the result matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = ComplexNumber(0, 0);
        }
    }

    // temp matrix - hold powers of A
    ComplexNumber **Apower = new ComplexNumber*[n];
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i == j) {
            Apower[i][j] = ComplexNumber(1, 0);
        } else {
            Apower[i][j] = ComplexNumber(0, 0);
        }
    }
}
    //fact term int to 1
    double fact = 1.0;

    for (int k = 0; k < nMax; k++) {
        // following formula
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = res[i][j] + Apower[i][j] * (1 / fact);
            }
        }

        // A_power to find A^k
        ComplexNumber **new_power = new ComplexNumber*[n];
        for (int i = 0; i < n; i++) {
            new_power[i] = new ComplexNumber[n];
            for (int j = 0; j < n; j++) {
                new_power[i][j] = ComplexNumber(0, 0);
                // matrix multiplication, i.e A_power * A
                for (int m = 0; m < n; m++) {
                    new_power[i][j] = new_power[i][j] + Apower[i][m] * A[m][j];
                }
            }
        }
        // get rid of mem
        for (int i = 0; i < n; i++) {
            delete[] Apower[i];
        }
        delete[] Apower;
        Apower = new_power;

        // update fact for the next term in the series, i.e +1
        fact *= (k + 1);
    }

    // get rid of mem
    for (int i = 0; i < n; i++) {
        delete[] Apower[i];
    }
    delete[] Apower;
}
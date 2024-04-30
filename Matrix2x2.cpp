
#include "Matrix2x2.hpp"

//q1
Matrix2x2::Matrix2x2() : val00(0.0), val01(0.0), val10(0.0), val11(0.0) {
}

//q2
Matrix2x2::Matrix2x2(const Matrix2x2& other) : val00(other.val00), val01(other.val01), val10(other.val10), val11(other.val11) {

}

//q3
Matrix2x2::Matrix2x2(double a, double b, double c, double d) : val00(a), val01(b), val10(c), val11(d) {

}

//q4
double Matrix2x2::CalcDeterminant() const {
    return val00 * val11 - val01 * val10;
}

//q5
Matrix2x2 Matrix2x2::CalcInverse() const {
    double det = CalcDeterminant();
    return Matrix2x2(val11 / det, -val01 / det, -val10 / det, val00 / det);
}

//q6
Matrix2x2& Matrix2x2::operator=(const Matrix2x2& other) {
    if (this != &other) {
        val00 = other.val00;
        val01 = other.val01;
        val10 = other.val10;
        val11 = other.val11;
    }
    return *this;
}

//q7
Matrix2x2 Matrix2x2::operator-() const {
    return Matrix2x2(-val00, -val01, -val10, -val11);
}

//q8
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const {
    return Matrix2x2(val00 + z.val00, val01 + z.val01, val10 + z.val10, val11 + z.val11);
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const {
    return Matrix2x2(val00 - z.val00, val01 - z.val01, val10 - z.val10, val11 - z.val11);
}

//q9
void Matrix2x2::MultScalar(double scalar) {
    val00 *= scalar;
    val01 *= scalar;
    val10 *= scalar;
    val11 *= scalar;
}

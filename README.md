# MPP-Lab-3
#include <iostream>
#include <vector>
#include <cmath>

class Polynomial {
private:
std::vector<int> coefficients;
int degree;

public:
Polynomial(int deg, const std::vector<int>& coeffs) : degree(deg), coefficients(coeffs) {}

Polynomial(const std::vector<int>& coeffs) : degree(coeffs.size() - 1), coefficients(coeffs) {}

int luate(int x) {
int result = 0;
for (int i = 0; i < coefficients.size(); ++i) {
result += coefficients[i] * pow(x, degree - i);
}
return result;
}

Polynomial operator+(const Polynomial& other) {
std::vector<int> resultCoeffs(std::max(degree + 1, other.degree + 1), 0);
for (int i = 0; i <= degree; ++i) resultCoeffs[i] += coefficients[i];
for (int i = 0; i <= other.degree; ++i) resultCoeffs[i] += other.coefficients[i];
return Polynomial(std::max(degree, other.degree), resultCoeffs);
}

Polynomial operator-(const Polynomial& other) {
std::vector<int> resultCoeffs(std::max(degree + 1, other.degree + 1), 0);
for (int i = 0; i <= degree; ++i) resultCoeffs[i] += coefficients[i];
for (int i = 0; i <= other.degree; ++i) resultCoeffs[i] -= other.coefficients[i];
return Polynomial(std::max(degree, other.degree), resultCoeffs);
}

Polynomial operator*(const Polynomial& other) {
std::vector<int> resultCoeffs(degree + other.degree + 1, 0);
for (int i = 0; i <= degree; ++i) {
for (int j = 0; j <= other.degree; ++j) {
resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
}
}
return Polynomial(degree + other.degree, resultCoeffs);
}

void print() {
for (int i = degree; i >= 0; --i) {
if (coefficients[i] != 0) {
std::cout << (coefficients[i] > 0 && i != degree ? " + " : "") << coefficients[i];
if (i > 0) std::cout << (i == 1 ? "x" : "x^" + std::to_string(i));
}
}
std::cout << std::endl;
}
};

int main() {
std::vector<int> coeffs1 = {1, 2, 3};
std::vector<int> coeffs2 = {4, 5, 6};

Polynomial poly1(coeffs1);
Polynomial poly2(coeffs2);

std::cout << "First polynomial: ";
poly1.print();
std::cout << "Second polynomial: ";
poly2.print();

int x = 2;
std::cout << "Value of the first polynomial at x=" << x << ": " << poly1.evaluate(x) << std::endl;
std::cout << "Value of the second polynomial at x=" << x << ": " << poly2.evaluate(x) << std::endl;

std::cout << "Addition result: ";
(poly1 + poly2).print();
std::cout << "Subtraction result: ";
(poly1 - poly2).print();
std::cout << "Multiplication result: ";
(poly1 * poly2).print();

return 0;
}

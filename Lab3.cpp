#include <iostream>
#include <vector>
#include <cmath>

class Polynomial {
private:
    std::vector<int> coefficients;
    int degree;

public:
    // Конструктор, що приймає ступінь многочлена і масив коефіцієнтів
    Polynomial(int deg, const std::vector<int>& coeffs) : degree(deg), coefficients(coeffs) {}

    // Конструктор, що приймає лише масив коефіцієнтів
    Polynomial(const std::vector<int>& coeffs) : degree(coeffs.size() - 1), coefficients(coeffs) {}

    // Метод для обчислення значення многочлена для заданого аргументу
    int evaluate(int x) {
        int result = 0;
        for (int i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, degree - i);
        }
        return result;
    }

    // Операція додавання многочленів
    Polynomial operator+(const Polynomial& other) {
        std::vector<int> resultCoeffs(std::max(degree + 1, other.degree + 1), 0);
        for (int i = 0; i <= degree; ++i) resultCoeffs[i] += coefficients[i];
        for (int i = 0; i <= other.degree; ++i) resultCoeffs[i] += other.coefficients[i];
        return Polynomial(std::max(degree, other.degree), resultCoeffs);
    }

    // Операція віднімання многочленів
    Polynomial operator-(const Polynomial& other) {
        std::vector<int> resultCoeffs(std::max(degree + 1, other.degree + 1), 0);
        for (int i = 0; i <= degree; ++i) resultCoeffs[i] += coefficients[i];
        for (int i = 0; i <= other.degree; ++i) resultCoeffs[i] -= other.coefficients[i];
        return Polynomial(std::max(degree, other.degree), resultCoeffs);
    }

    // Операція множення многочленів
    Polynomial operator*(const Polynomial& other) {
        std::vector<int> resultCoeffs(degree + other.degree + 1, 0);
        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(degree + other.degree, resultCoeffs);
    }

    // Метод для друку (виведення на екран) опису многочлена
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
    // Приклад використання класу Polynomial
    std::vector<int> coeffs1 = {1, 2, 3}; // коефіцієнти для першого многочлена
    std::vector<int> coeffs2 = {4, 5, 6}; // коефіцієнти для другого многочлена

    Polynomial poly1(coeffs1); // створення першого многочлена
    Polynomial poly2(coeffs2); // створення другого многочлена

    // Виведення описів многочленів на екран
    std::cout << "Перший многочлен: ";
    poly1.print();
    std::cout << "Другий многочлен: ";
    poly2.print();

    // Обчислення значень многочленів для заданого аргументу
    int x = 2;
    std::cout << "Значення першого многочлена при x=" << x << ": " << poly1.evaluate(x) << std::endl;
    std::cout << "Значення другого многочлена при x=" << x << ": " << poly2.evaluate(x) << std::endl;

    // Виконання операцій додавання, віднімання і множення многочленів
    std::cout << "Результат додавання: ";
    (poly1 + poly2).print();
    std::cout << "Результат віднімання: ";
    (poly1 - poly2).print();
    std::cout << "Результат множення: ";
    (poly1 * poly2).print();

    return 0;
}


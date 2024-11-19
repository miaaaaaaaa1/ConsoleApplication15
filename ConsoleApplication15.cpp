#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
private:
    int numerator;   
    int denominator; 

    void simplify() {
        int gcd = gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        simplify();
    }

    void setFraction(int num, int denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        numerator = num;
        denominator = denom;
        simplify();
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero");
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }
};

int main() {
    try {
        Fraction a(1, 2); 
        Fraction b(3, 4); 

        Fraction sum = a + b; 
        Fraction diff = a - b;
        Fraction prod = a * b;  
        Fraction quot = a / b;  

        cout << "a = "; a.print();
        cout << "b = "; b.print();
        cout << "a + b = "; sum.print();
        cout << "a - b = "; diff.print();
        cout << "a * b = "; prod.print();
        cout << "a / b = "; quot.print();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

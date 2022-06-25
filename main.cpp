#include <iostream>

using namespace std;

template<class T>
struct polynomial {
    T *coefficients;
    int degree;
};
typedef float coef_type;
typedef struct polynomial<coef_type> poly_type;

poly_type *load_poly() {
    int degree;
    cout << "Podaj stopien wielomianu: ";
    cin >> degree;
    auto *p = new poly_type;
    p->coefficients = new coef_type[degree + 1];
    p->degree = degree;
    for (int i = degree; i >= 0; i--) {
        cout << "Podaj stopień " << i << ": ";
        cin >> p->coefficients[i - 1];
    }
    return p;
}

poly_type *add(poly_type *p1, poly_type *p2) {
    int degree = p1->degree > p2->degree ? p1->degree : p2->degree;
    auto *output = new poly_type;
    output->coefficients = new coef_type[degree + 1];
    output->degree = degree;
    for (int i = degree; i >= 0; i--) {
        if (p1->degree >= i)
            output->coefficients[i - 1] += p1->coefficients[i - 1];
        if (p2->degree >= i)
            output->coefficients[i - 1] += p2->coefficients[i - 1];
    }
    return output;
};

poly_type *sub(poly_type *p1, poly_type *p2) {
    int degree = p1->degree > p2->degree ? p1->degree : p2->degree;
    auto *output = new poly_type;
    output->coefficients = new coef_type[degree + 1];
    output->degree = degree;
    for (int i = degree; i >= 0; i--) {
        if (p1->degree >= i)
            output->coefficients[i - 1] += p1->coefficients[i - 1];
        if (p2->degree >= i)
            output->coefficients[i - 1] -= p2->coefficients[i - 1];
    }
    return output;
};

poly_type *mul(poly_type *p1, poly_type *p2) {
    int degree = p1->degree + p2->degree;
    auto *output = new poly_type;
    output->coefficients = new coef_type[degree + 1];
    output->degree = degree;
    for (int i = p1->degree; i >= 0; i--) {
        for (int j = p2->degree; j >= 0; j--) {
            output->coefficients[i+j-1] += p1->coefficients[i - 1] * p2->coefficients[j - 1];
        }
    }
    return output;
}

poly_type *divide(poly_type p1, poly_type p2) {
    int degree = p1.degree - p2.degree;
    auto *output = new poly_type;
    output->coefficients = new coef_type[degree + 1];
    output->degree = degree;
    return output;
};

void render_poly(const struct polynomial<coef_type> &p) {
    for (int i = p.degree; i >= 0; i--) {
        if (i > 1)
            cout << p.coefficients[i - 1] << "x^" << i << "+";
        else if (i == 1) {
            cout << p.coefficients[i - 1] << "x+";
        } else {
            cout << p.coefficients[i - 1];
        }
    }
    cout << endl;
}

void menu() {
    cout << "1. Dodawanie" << endl;
    cout << "2. Odejmowanie" << endl;
    cout << "3. Mnożenie" << endl;
    cout << "4. Dzielenie" << endl;
    cout << "5. Koniec" << endl;
    cout << "Podaj opcje: " << endl;
}

int main() {

    char option;
    do {
        menu();
        cin >> option;
        poly_type *p1 = load_poly();
        poly_type *p2 = load_poly();
        switch (option) {
            case '1': {
                render_poly(*add(p1, p2));
                break;
            }
            case '2': {
                render_poly(*sub(p1, p2));
                break;
            }
            case '3': {
                render_poly(*mul(p1, p2));
                break;
            }
//            case '4': {
//                render_poly(*divide(p1, p2));
//                break;
//            }
            case '5': {
                exit(0);
            }
            default: {
                cout << "Nieprawidłowe dane wejściowe";
            }
        }
    } while (option != 3);
    return 0;
}

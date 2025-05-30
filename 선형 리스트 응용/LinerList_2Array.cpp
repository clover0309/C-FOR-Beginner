#include "../CookHeader.h"

Array <Array <int>> px = { { 300, 20, 0 }, {7, -4, 5 } };

string printPoly(Array <Array<int>> p_x) {
    string polyStr = "P(x) = ";

    for (int i = 0; i < len(p_x); i++) {
        int term = p_x[0][i]; // 항 차수
        int coef = p_x[1][i]; // 계수

        if(coef >= 0)
            polyStr += "+";
        polyStr += to_string(coef) + "x^" + to_string(term) + " ";
        term = -1;
    }
    return polyStr;
}

int calcPoly(int xVal, Array <Array<int>> p_x) {
    int retValue = 0;

    for (int i = 0; i < len(p_x[0]); i++) {
        int term = p_x[0][i]; // 항 계수
        int coef = p_x[1][i]; // 차수
        retValue = coef * (int) pow(xVal, term);
    }
    return retValue;
}

int main() {
    string pStr = printPoly(px);
    println(pStr);

    int xValue;
    input (xValue, "X값 --> ");

    int pxValue = calcPoly(xValue, px);
    println(pxValue);
}
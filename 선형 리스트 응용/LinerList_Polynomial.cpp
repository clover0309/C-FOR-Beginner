#include "../CookHeader.h"

//다항식을 계산하기 위한 배열 선언 후, 값을 추가해둠.
Array <int> px = { 7, -4, 0, 5 };

//배열의 값을 통해서, 배열안의 값을 +배열값x^3 형태로 표기해주는 사용자 지정 함수.
string printPoly(Array <int> p_x) {
    int term = len(p_x) - 1;
    string polyStr = "P(x) = ";

    for (int i = 0; i < len(p_x); i++) {
        int coef = p_x[i];
        if (coef >= 0)
            polyStr += "+";
        polyStr += to_string(coef) + "x^" + to_string(term) + " ";
        term--;
    }

    return polyStr;
}

// 값을 통해 x값을 통해서 배열의 값을 계산해주는 사용자 정의 함수.
int calcPoly(int xVal, Array <int> p_x) {
    int retValue = 0;
    int term = len(p_x) - 1;

    for (int i = 0; i < len(p_x); i++) {
        int coef = p_x[i];
        retValue += coef * (int) pow(xVal, term);
        term--;
    }

    return retValue;
}

int main() {
    string pStr = printPoly(px);
    println(pStr);

    int xValue;
    input(xValue, "X값 --> ");

    int pxValue = calcPoly(xValue, px);
    println(pxValue);
}

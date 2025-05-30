#include "../CookHeader.h"

Array <int> tx = { 300, 20, 0 };
Array <int> px = { 7, -4, 5 };

string printPoly(Array <int> t_x, Array <int> p_x) {
    string polyStr = "P(x) = ";

    //반복문을 통해서, 위에서 선언된 px의 배열 길이만큼, 반복을 해준다.
    for (int i = 0; i < len(p_x); i++) {
        //term에는 t_x의 i번째, coef에는 p_x의 i번째가 순서대로 들어온다.
        int term = t_x[i];
        int coef = p_x[i];

        //만약에 coef가 0보다 크면은
        if (coef > 0)
        // P(x) = (iq번째 인덱스) + 이런식으로 표기가 됨.
            polyStr += "+";

        // 최종적으로 polyStr에 이미 저장되 있는 값에 coef과 term을 문자열 형식으로 삽입.
        // P(x) = 7x^300 이런식으로 표기가된다.
        polyStr += to_string(coef) + "x^" + to_string(term) + " ";
        //차수를 1씩 줄이기 위한, term을 후연산으로 빼줌.
        term--;
    }
    //polyStr에 값이 저장되어 있는 상태니, polyStr를 반환함.
    return polyStr;
}

int calcPoly(int xVal, Array <int> t_x, Array <int> p_x) {
    //retValue안에 값을 저장하기 위해, 우선 0으로 초기화.
    int retValue = 0;

    //반복문을 통해서, 파라미터 값으로 받은 p_x의 길이만큼 반복.
    for (int i = 0; i < len(p_x); i++) {
        //term에는 t_x의 i번째, coef에는 p_x의 i번째를 추가함.
        int term = t_x[i];
        int coef = p_x[i];

        //pow함수는 기본적으로 사용가능한 제곱 함수이다.
        // 즉 coef * xVal의 제곱값을 의미한다.
        retValue += coef * (int) pow(xVal, term);
    }
    // 연산값이 retValue에 존재함으로, retValue를 반환.
    return retValue;
}

int main() {
    //전역변수로 선언된 tx와 px를 printPoly에게 인자값으로 던짐.
    string pStr = printPoly(tx, px);
    // printPoly 함수로 이동, 연산 후 pStr을 출력해줌.
    println(pStr);

    // input을 통해 xValue를 추가하기 위해 xValue 변수 선언.
    int xValue;
    input(xValue, "X값 --> ");

    //위에서 사용자가 input을 통해 던진 값 xValue와 전역 변수로 선언된 tx,px를 calcPoly에 던짐.
    int pxValue = calcPoly(xValue, tx, px);
    // calcPoly 함수로 이동, 연산 후 pxValue를 출력함.
    println(pxValue);
}
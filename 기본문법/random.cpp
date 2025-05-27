#include <iostream>
#include <random>

using namespace std;

#define print(data) cout << data << " "

/* 매크로를 통해 randomInit을 선언. 파라미터 값을 무조건 2개씩 받아줘야함. */
/* 하드웨어에서 얻은 난수를 생성하는 객체 rd를 선언. */ 
/* 메르센 트위스터(Mersenne Twister)라는 이름의 난수 생성기. */ 
/* 지정한 범위의 정수 난수를 균등분포로 생성하는 객체.*/
// 매크로 안에는 어지간하면 주석을 넣으면 안될듯 하다. 줄바꿈 인식을 제대로 못하는듯 함.
#define randomInit(start, end) \
    random_device rd; \
    mt19937 gen(rd()); \
    uniform_int_distribution<int> cookRandom(start,end)

int main() {
    /* 
    위에서 선언해둔 randomInit 매크로를 통해 0부터 9999 숫자를
    하드웨어와 메르센 트위스터, 지정한 범위의 정수 난수를 균등분포하여 난수를 추출한다.
    */
    randomInit(0, 9999);

    // 반복문을 통해 추출한 난수를 출력해줌.
    for (int i=0; i<5; i++)
        print(cookRandom(gen));
}
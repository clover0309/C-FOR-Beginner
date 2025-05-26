#include <iostream> // iostream 안에 cout와 cin이라는 식별자가 존재함.

using namespace std; // nanespace를 사용하게 되면, std::cout나 std::cin 이런식으로 사용하지 않아도됨.
// 즉 미리 namespace를 통해서 std::를 적어두는 효과가 나옴. (이부분에서는 약간 C랑은 다른 개념인듯함.)

// define은 매크로를 정의 한 부분이다.
// input안에 data와 msg라는 파라미터 값을 받아서
// 메시지를 먼저 출력해주고, 그뒤에 값을 입력받는다.
#define input(data,msg) \
                cout << msg; \
                cin >> data

int main() {
    string strData;
    int intData;
    input (strData, "문자열 입력 -->");
    input (intData, "정수 입력 -->");
}
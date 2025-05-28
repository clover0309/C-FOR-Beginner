#include "../CookHeader.h"
#include <iostream>

using namespace std;

/*

해당코드를 단순히 작성하자면 이렇게 생성되지만, 미리 사용자 함수를 지정하여서 배열에 None값을 미리 넣을 수도 있다.

int Array_length;

int main() {
    Array <string> katok = { "다현", "정연", "쯔위", "사나", "지효" };
    katok.push_back("None");
    printArray(katok);

    Array_length = len(katok);
    katok[Array_length-1] = "다현";
    printArray(katok);

    katok.push_back("None");
    katok[Array_length-1] = "정연";
    printArray(katok);
}
*/

Array <string> katok;

// 사용자 함수인 add_data 생성 후 파라미터를 통해 함수에 전달.
void add_data(string data){
    //빈 배열을 먼저 추가후, 정수형 len을 통해 길이를 계산 후, 배열의 길이의 -1 만큼 계산하여 값을 추가한다.
    katok.push_back("None");
    int len = len(katok);
    katok[len-1] = data;
    cout << len << endl;
}

int main() {
    // add_data를 통해 각각 값을 추가 후, 빈 배열을 생성한 다음에 배열의 전체 크기만큼 -1을 진행하여, 배열에 값을 추가한다.
    // 출력값을 참조해보면, add_data에서 선언해 둔 len 값이 계속 늘어나는 것을 볼 수 있다.
    add_data("다현");
    add_data("정연");
    add_data("쯔위");
    add_data("사나");
    add_data("지효");

    printArray(katok);
}
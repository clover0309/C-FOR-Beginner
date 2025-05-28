#include "../CookHeader.h"

Array <string> katok = { "다현", "정연", "쯔위", "사나", "지효" };

//사용자 함수 delete_data를 선언. 파라미터 값은 정수형을 받아야함.
void delete_data(int position) {
    // 선 범위 검증을 진행 후, 파리미터 값이 0보다 작으면 삭제가 안되게 방지함.
    if ((position < 0) || (position > len(katok))) {
        print("데이터를 삭제할 범위를 벗어났습니다.");
        return;
    }

    // 배열의 길이의 값을 받는 정수형 len 변수 선언.
    int len = len(katok);
    // 배열의 파라미터 자리에 None을 추가.
    katok[position] = "None";

    // 반복문을 통해, len의 길이 만큼 반복 시작.
    printf("내부 함수 delete_data 반복문 시작. \n");
    for (int i = position + 1; i < len; i++) {
        // 배열 i-1번째에 배열의 i번지의 값을 추가.
        katok[i-1] = katok[i];
        // 배열의 i번지는 None이 된다.
        katok[i] = "None";
    }
    // 그리고 CookHeader 헤더파일을 통해, 배열삭제 함수가 구동됨.
    printf("CookHeader 헤더파일을 통해 배열을 삭제합니다. \n");
    del(katok, len-1);
}

int main() {
    delete_data(1);
    printArray(katok);
    delete_data(3);
    printArray(katok);
}
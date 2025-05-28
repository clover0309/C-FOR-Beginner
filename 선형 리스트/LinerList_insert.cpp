#include "../CookHeader.h"

Array <string> katok = { "다현", "정연", "쯔위", "사나", "지효" };

//데이터를 추가하기 위한 사용자 함수, insert_data를 선언.
// 파라미터 값으로, 배열의 위치와 배열의 값들을 받아서 연산과정 수행.
void insert_data(int position, string data) {
    // position 범위를 선 검증, 범위에 벗어나면 오류 출력.
    if ((position < 0) || (position > len(katok))) {
        print("데이터를 삽입할 범위를 벗어났습니다.");
        return;
    }

    // 배열에 None으로 빈 배열 추가.
    katok.push_back("None");

    //배열의 길이를 계산한 값을 받는 변수 len
    int len = len(katok);

    //반복문을 통해, i 값이 position보다 작아지면 반복문 종료.
    printf("사용자함수 insert_data 내부 반복문 시작. \n");
    for (int i = len-1; i > position; i--) {
        //배열의 i값에 배열의 i-1의 값을 추가.
        katok[i] = katok[i-1];
        //배열의 i-1의 위치에 None 추가. 빈배열이 한칸씩 앞으로 땡겨지면서 빈배열이 생성됨.
        katok[i-1] = "None";
        printArray(katok);
    }

    katok[position] = data;
}

int main() {
    printf("현재 배열에 저장된 값들 : ");
    printArray(katok);


    insert_data(2, "솔라");
    printArray(katok);
    insert_data(6, "문별");
    printArray(katok);
}
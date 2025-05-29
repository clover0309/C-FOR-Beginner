#include "../CookHeader.h"

// 전역변수를 미리 선언.
Array <string> katok;
int sel_num = -1;

void add_data(string data) {
    katok.push_back("None");
    int kLen = len(katok);
    katok[kLen - 1] = data;
}

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
    string data;
    int pos;

    //반복문과 조건문을 통해, 기능 작동 로직을 생성.
    while (sel_num != 4) {
        input(sel_num, "1. 데이터 추가\n2. 데이터 삽입\n3. 데이터 삭제\n4. 프로그램 종료\n 선택: ");
    
    switch (sel_num) {
        case 1:
            input(data, "추가할 데이터 --> ");
            add_data(data);
            printArray(katok);
            break;
        case 2:
            input(pos, "삽입할 위치 --> ");
            input(data, "삽입할 데이터 --> ");
            insert_data(pos, data);
            printArray(katok);
            break;
        case 3:
            input(pos, "삭제할 위치 --> ");
            delete_data(pos);
            printArray(katok);
            break;
        case 4:
            printArray(katok);
            return 0;
        default:
            print("1~4 중 하나를 입력하세요.");
            continue;
    }
}
}

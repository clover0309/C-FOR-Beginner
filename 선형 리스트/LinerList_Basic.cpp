// https://www.notion.so/201700824ca080ed8868d1c671ab0609 선형 리스트에 대한 노션 기본정리는 여기에 작성되어 있습니다.

#include "../CookHeader.h"
#include <stdio.h>

int main() {
// 선형리스트를 생성하기.
Array <string> katok = { "다현", "정연", "쯔위", "사나", "지효" };
printArray(katok); //katok에 저장된 배열들이 전부 표기가 됨.

printf("특상 : ");
println(katok[0]);
printf("1등 : ");
println(katok[4]);

printf("---------------------- \n");

// 데이터 삽입전 빈배열 추가.
katok.push_back("None");
printf("데이터 삽입 전, 빈배열 추가. \n");
printArray(katok);

printf("---------------------- \n");

// 빈 배열을 생성한 5번지에 모모를 추가.
katok[5] = "모모";
printf("빈 배열을 생성한 5번지에 모모를 추가. \n");
printArray(katok);

printf("---------------------- \n");

// 중간 데이터를 삽입하기.
katok.push_back("None");
printArray(katok);

printf("---------------------- \n");

// 배열의 6번지에, 5번지의 값을 추가 후, 5번지의 값을 None 삽입.
katok[6] = katok[5];
katok[5] = "None";
printf("배열의 6번지에, 5번지의 값을 추가 후, 5번지의 값을 None 삽입. \n");
printArray(katok);

printf("---------------------- \n");

// 배열 5번지에, 4번지의 값을 추가 후, 4번지의 값을 None 삽입 후, 4번지에 3번지의 값 추가 후, 3번지의 값을 None 삽입.
katok[5] = katok[4];
katok[4] = "None";
katok[4] = katok[3];
katok[3] = "None";
printf("배열 5번지에, 4번지의 값을 추가 후, 4번지의 값을 None 삽입 후, 4번지에 3번지의 값 추가 후, 3번지의 값을 None 삽입. \n");
printArray(katok);

printf("---------------------- \n");

// 배열 3번지에 미나 추가.
katok[3] = "미나";
printf("배열 3번지에 미나 추가. \n");
printArray(katok);

printf("---------------------- \n");

// 데이터 삭제
katok[4] = "None";
printf("데이터 삭제 \n");
printArray(katok);

printf("---------------------- \n");

// 비워진 4번지에, 5번지의 값을 삽입, 5번지를 비운 후, 5번지에 6번지의 값을 추가 후, 6번지를 비워둔다.
katok[4] = katok[5];
katok[5] = "None";
katok[5] = katok[6];
katok[6] = "None";
printf("비워진 4번지에, 5번지의 값을 삽입, 5번지를 비운 후, 5번지에 6번지의 값을 추가 후, 6번지를 비워둔다. \n");
printArray(katok);

printf("---------------------- \n");

//배열의 6번지 값 제거.
del(katok, 6);
printf("배열의 6번지 값 제거. \n");
printArray(katok);

}

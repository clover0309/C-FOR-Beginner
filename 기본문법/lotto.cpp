#include "../CookHeader.h"

int main() {
    //변수 선언. 
    // 각각 총 생성한 번호(2차원 배열), 생성한 번호(1차원 배열), 뽑은 숫자를 하나하나 받음, 총 몇번 생성하는지. 
    Array <Array <int>> totalLotto;
    Array <int> lotto;
    int pickNum;
    int totCount;

    //단순 출력과, totCount에 저장될 횟수.
    println("** 로또 번호 생성을 시작합니다! **");
    input(totCount, "몇 번을 뽑을까요?");

    //1부터 45까지만 뽑게 함.
    randomInit(1, 45);

    //반복문을 통해 totCount만큼 반복함.
    for (int i=0; i<totCount; i++) {
        //1차원 배열을 사용하기위해 빈배열로 초기화
        lotto = {};
        //참이면 반복을 진행한다.
        while (true) {
            //pickNum에 CookHeader.h에 있는 cookRandom 매크로를 통해 번호를 생성함.
            pickNum = cookRandom(gen);
            //중복을 방지하기 위한, isInArray로 중복체크.
            if (!(isInArray(lotto, pickNum)))
                // 중복이 없다면, 1차원 배열 lotto에 pickNum을 통해 생성한 번호를 추가함.
                lotto.push_back(pickNum);
            // 만약 6개 이상이면 과정을 멈춰버림.
            if (len(lotto) >= 6)
                break;
            }
            //그리고 나서 2차원 배열에 lotto값을 추가함.
            totalLotto.push_back(lotto);
        }

        //반복문을 통해, totCount값 만큼 반복함.
        for (int i=0; i<totCount; i++) {
            //1차원 배열에서, 2차원 배열의 i번째 값을 추가함.
            lotto = totalLotto[i];
            //CookHeader.h에 있는 sortArray를 통해 lotto를 정렬함.
            sortArray(lotto);
            print("자동번호 --> ");
            //lotto의 값을 출력해줌.
            printArray(lotto);
        }
    }
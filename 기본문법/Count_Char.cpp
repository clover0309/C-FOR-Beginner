#include "../CookHeader.h"

int main() {
    //문자열을 준비함. poet를 선언을 먼저한 후 값을 지정해놓고, 이후에 합연산을 진행하여 장문을 만들어냄.
    string poet = "One little, Two little, Three little Indians \n";
    poet += "Four little, Five little, Six little Indians \n";
    poet += "Seven little, Eight little, Nine little Indians \n";
    poet += "Ten little Indians boys";

    //char형태의 배열과, int형태의 배열을 준비함.
    // 각각 문자열을 담을 배열과, 글자를 세는 배열을 준비한 것임.
    Array <char> charAry;
    Array <int> countAry;

    //반복문 시작. poet의 길이만큼 i를 반복함. 
    for (int i=0; i<len(poet); i++) {
        // 문자형 ch는 poet[i]번째를 가리킴.
        char ch = poet[i];
        //공백을 제외한 a~Z까지만 솎아냄.
        if (('a' <= ch and ch <= 'z') || ('A' <= ch and ch <= 'Z')) {
            //만약 배열에 ch가 포함이 된다면,
            if (isInArray(charAry, ch)) {
                //정수형 index에서 find 함수를 사용해, 값을 카운트함.
                int index = find(charAry.begin(), charAry.end(), ch) - 
                charAry.begin();
                countAry[index]++;
            }
            //만약 아니면,
            else {
                //charAry 배열에 ch를 넣고.
                charAry.push_back(ch);
                //countAry 배열에 값을 1씩 추가함.
                countAry.push_back(1);
            }
        }
    }
    println("원문");
    println(poet);
    println("----------------");
    println("문자 빈도수 (10회 이상)");
    println("----------------");
    //반복문 시작. charAry길이 만큼 i를 반복함.
    for (int i=0; i<len(charAry); i++) {
        //만약 countAry배열의 i번째가 10보다 같거나 크면.
        if (countAry[i]>=10) {
            //charAry의 i번째 값을 출력함.
            print(charAry[i]);
            println("---->" + to_string(countAry[i]));
        }
    }
}
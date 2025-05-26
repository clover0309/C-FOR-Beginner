#include <iostream>
#include <string>

using namespace std;

#define println(data) cout << data << endl

int main() {
    //str1과 char1을 선언하고 한개씩 값을 줘놓은 상태이다.
    string str1 = "IT CookBook";
    const char* char1 = "자료 구조와 알고리즘";

    //단순 str1 char1에 있는 값들을 출력함.
    println(str1);
    println(char1);

    //str2의 값을 char1의 값 "자료 구조와 알고리즘"으로 선언
    //근데 char1은 char 자료형으로 선언되었지만, str2가 string 자료형으로 되었다.
    string str2 = char1;
    //출력하면 "자료 구조와 알고리즘" 출력
    println(str2);

    //char2의 값을 str1의 값을 그대로 가져옴.
    //str1은 string형태 였지만, 이제 여기서는 char형태로 변경 되어있음.
    const char* char2 = str1.c_str();
    // IT CookBook 출력.
    println(char2);

    //str1의 길이를 나타냄. 11을 출력함.
    // string에서는 size와 length는 같은 출력값을 가지지만,
    // 다른 자료형에서는 사용이 불가능하다. (기본자료형은 sizeof를 사용해야함. length도 마찬가지로 기본자료형에선 사용안됨.)
    println(str1.size());
    println(((string)char1).size());

    //str1에는 100 char1에는 200이라는 값이 들어가서 기존에 들어간 값이 대체됨.
    str1 = "100";
    char1 = "200";
    //자료형이 달라서 서로 더하기가 안되므로, 서로 붙혀서 표기가되므로 100200 이 출력됨.
    println(str1 + char1);

    /*
    stoi는 string to int를 의미함. 즉, string을 int 자료형으로 치환해주는 역할.
    그외에
    stof = string to float
    stol = string to long
    stod = string to double 이 존재함. 단순 자료형 치환.
    자바로 치면 캐스팅 같은 것이라고 생각하면 편할 듯 하다.
    */
    int value = stoi(str1) + stoi(char1);

    //위에서 stoi를 통해서 int자료형으로 변경되었으니, 더한 값이 300이 나오지만,
    // to_string 함수를 통해서 value 값을 가져왔으니, 자료형이 string으로 변경되고, 300은 int형태가 아닌 string형태로 출력된다.
    println("합계는 " + to_string(value));
}
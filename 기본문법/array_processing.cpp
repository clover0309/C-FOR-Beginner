#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Array vector

#define println(data) cout << data << endl

/* 배열을 출력하는 매크로를 선언.
    [ 를 먼저 출력하고, 안에서 반복문을 통해 ary의 사이즈 만큼, ary배열의 칸수인 [i]값 만큼 출력이 된다.
*/
#define printArray(ary) \
                cout << "[ "; \
                for (int i=0; i<(int)ary.size(); i++) \
                cout << ary[i] << " "; \
                cout << "]" << endl

/* 
    각종 배열 관련 매크로들
    sortArray = 배열을 파라미터 값으로 받아, 정렬을 진행해줌
    reverseArray = 배열을 파라미터 값으로 받아, 거꾸로 뒤집어줌.
    copyArray = 파라미터 값을 2개를 받아 배열을 복사해줌.
    insertArray = 파라미터 값을 3개를 받아 배열안에 값을 추가해줌.
    setArray = 배열을 파라미터 값으로 받아, 기존에 배열 칸에 있던 값을 제거후, 배열 값을 추가해줌.
                unique를 통해 중복된 원소값을 하나로 합쳐줌.
    isInArray = 파라미터 값을 2개를 받아서, 배열 안에 값이 존재하는지 찾아줌.
    removeChar = 파라미터 값을 2개를 받아서, strr안에 존재하는 값에서 제거할 값을 찾아 삭제해서 저장해줌.
*/
#define sortArray(ary) sort(ary.begin(), ary.end())
#define reverseArray(ary) reverse(ary.begin(), ary.end())
#define copyArray(source, target) target.assign(source.begin(), source.end())
#define insertArray(ary, position, data) ary.insert(ary.begin() + position, data)
#define setArray(ary) ary.erase(unique(ary.begin(), ary.end()), ary.end())
#define isInArray(ary, data) find(ary.begin(), ary.end(), data) != ary.end()
#define removeChar(strr, chr) strr.erase(remove(strr.begin(), strr.end(), chr), strr.end())

int main() {
    //가변크기의 배열을 ary1, ary2로 선언함.
    Array <int> ary1 = { 8, 4, 3, 1, 3, 7, 7, 4, 6, 3, 1, 1, 9 };
    Array <int> ary2;

    //위에서 선언해둔 sort매크로에게 ary1으로 파라미터 값으로 던짐.
    //여기서 던져진 파라미터 값의 내부값은 위에 선언된 ary1의 배열 값들이다.
    sortArray(ary1);
    printArray(ary1);

    //위에서 선언해둔 reverse 매크로에게 ary1으로 파라미터 값을 던짐.
    reverseArray(ary1);
    // 거꾸로 정렬후 출력해서 보여줌.
    printArray(ary1);

    //위에서 선언해둔 copy 매크로에게 ary1, ary2를 파라미터 값을 던짐.
    copyArray(ary1, ary2);
    //ary2에 ary1의 배열값들이 카피되었으니, ary2를 출력.
    printArray(ary2);

    //위에서 선언해둔 insert 매크로에게 ary1, 2, 8888을 파라미터 값으로 던짐.
    // ary1 배열의 2번지에 8888 값을 던짐.
    insertArray(ary1, 2, 8888);
    printArray(ary1);

    //위에서 선언해둔 set 매크로에게 ary1를 파라미터 값으로 던짐.
    // 여기서는 중복되는 원소값이 7 4 3 1이 중복되는 상황이였는데, 7 4 3 1이 여러 개 있던 것이 1개만 남기고 전부 사라진다.
    setArray(ary1);
    printArray(ary1);

    //위에서 선언해둔 isIn 매크로에게 ary1과 8888을 파라미터 값을 던짐.
    bool yn = isInArray(ary1, 8888);
    //안에 값이 존재함으로 1이 나옴 (자바는 True False로 출력되지만 C는 1 0 으로 나오는듯? =/ 아님. cout을 사용하게되면 1 0으로 출력되고,
    // cout으로 Ture False를 출력하고 싶다면, cout << boolalpha를 사용하면 된다.)
    println(yn);

    //myStr을 string 자료형으로 선언 후 값을 IT CookBook Algorithm으로 지정.
    string myStr = "IT CookBook Algorithm";
    //위에서 선언해둔 removeChar 매크로에게 myStr을 파라미터 값으로 던지고, o만 제거하게 명령한다.
    removeChar (myStr, 'o');
    //출력값은 o가 전부 빠진, IT CkBk Algrithm
    println(myStr);
}
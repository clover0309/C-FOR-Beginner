#include <iostream>
#include <string>
#include <vector>

using namespace std;

//매크로를 통해, println의 data 파라미터에 값이 들어오면
// cout << 들어온 값 << endl로 치환됨.
// cout는 표준 출력 스트림 (printf), << data는 파라미터에 들어온 값 << enld은 개행(\n) 
#define println(data) cout << data << endl

//Array를 vector로 치환을 해줌.
//Array를 사용하면 자동으로 가변 배열인 vector<int>로 치환 해줌.
#define Array vector

//len(ary)를 사용시, (int)ary.size()로 치환시킴.
#define len(ary) (int)ary.size()

//del(ary, position)을 ary.erase(ary.begin() + position)으로 치환시킴.
#define del(ary, position) ary.erase(ary.begin() + position)

// printArray(ary)를 사용시, 밑에 있는 반복문으로 치환시킴.
#define printArray(ary) \
            cout << "[ "; \
            for (int i =0; i < (int)ary.size(); i++) \
                cout << ary[i] << " "; \
            cout << "]" << endl

/* ---------------------------------------------------------------------------
 대충 define의 개념은 이해가 된듯 함. 단순 매크로 개념이라기 보단, 내가 지정해둔 함수를 만드는 그런 느낌인듯?
*/

int main() {
    //vector로 myAry를 생성. 이젠 이녀석은 10,20,30을 가진 가변 배열이 되었음.
    Array <int> myAry = { 10, 20, 30 };
    
    //myAry 제일뒤에 40을 추가해둠. 가변 배열이라서 가능함.
    myAry.push_back(40);
    
    //위에서 printArray를 통해 for문으로 반복 출력하게 지정해놨으니,
    // [ 10 20 30 40 ]이 출력됨.
    printArray(myAry);

    //배열의 크기는 위에서 사용한 매크로 len을 통해 나타낼수 있게됨. to_string을 통해 4가 출력되지만 자료형은 4가됨.
    println("배열 크기 --> " + to_string(len(myAry)));

    //del도 마찬가지로 매크로로 선언되어 있으니, myAry안에 2번째인 30을 지워버림.
    del(myAry,2);
    //출력하면 [ 10 20 40 ]
    printArray(myAry);
}
#include <iostream>
#include <vector>

using namespace std;


#define Array vector

// 매크로를 통해서 printArray2에 파라미터 값을 받게되면,출력과 동시에 반복문을 실행.
#define printArray2(ary2) \
    cout << "[ "; \
    for(int i=0; i<(int)ary2.size(); i++) { \
        cout << "{ "; \
        for(int k=0; k<(int)ary2[i].size(); k++) { \
            cout << "\"" << ary2[i][k] << "\" "; \
        } \
        cout << "} "; \
    } \
    cout << "]" << endl;

// 2차원 배열을 비워버리는 사용자 함수.
Array <Array <int>> emptyArray2(int row, int col) {
    Array <Array <int>> ary2;
    Array <int> tmp;
    // 1차적으로 tmp라는 이름을 가진 배열을 전부 비워버린다.
    for (int i=0; i<row; i++) {
        tmp.clear();
        // 이 과정에서 tmp라는 이름을 가진 2차원 배열에 "0" 이라는 값이 각각 주어진다.
        for (int k=0; k<col; k++)
            tmp.push_back(0);
        //ary2에 tmp 배열의 값들을 전부 추가해준다.
        ary2.push_back(tmp);
    }
    return ary2;
}

int main() {
    Array <Array <string>> grade = { {"수학", "90"}, {"영어","70"}, {"과학","88"} };
    grade.push_back({"역사","75"});
    printArray2(grade);

    // 행이 3, 열이 4인 2차원 함수를 매크로를 통해서 생성한다.
    Array <Array <int>> empArray = emptyArray2(3,4);
    printArray2(empArray);
}
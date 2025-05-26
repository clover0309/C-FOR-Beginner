#include <iostream> // 입출력을 위한 iostream 사용 왜 c언어 자료구조 및 알고리즘인데 c++이 튀어나오는가? ㅋㅋ

using namespace std; // std::cout 형식을 사용하지않고, cout로 간단하게 사용하기 위해서 선언된 using

#define print(data) cout << data << " "
#define println(data) \
                    cout << data << endl

int main() {
    println("안녕하세요?");
    println(100);
    print("또 안녕하세요?");
    print(3.14);
}
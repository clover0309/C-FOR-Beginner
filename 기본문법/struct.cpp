#include <iostream>
#include <vector>

using namespace std;

#define Array vector
#define print(data) cout << data << " ";

// 매크로를 통해 구조체를 먼저 정의해둠.
// string 형태의 data와 구조체 형태의 
typedef struct _Node {
    string data;
    // 자신을 참조하는 자기 참조 포인터.
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;

int main() {
    //자신을 참조하는 Node 포인터 형태의 node1을 초기화
    Node* node1 = new Node;
    //node1 구조체의 data의 값은 "자료구조"
    node1->data = "자료구조";

    //자신을 참조하는 Node 포인터 형태의 node2를 초기화
    Node* node2 = new Node;
    // node2 구조체의 data의 값은 "알고리즘"
    node2->data = "알고리즘";
    // node1의 link는 node2가 된다. (여기서는 포인터의 값을 참조함?)
    node1->link = node2;

    // 자신을 참조하는 Node 포인터 형태의 node3를 초기화
    Node* node3 = new Node;
    // node3 구조체의 data의 값은 "C언어"
    node3->data = "C언어";
    // node2의 link는 node3가 된다. (여기서 포인터의 값을 참조함?)
    node2->link = node3;

    //매크로로 지정한 memory에 node1~node3까지 배열에 집어넣음.
    memory.push_back(node1);
    memory.push_back(node2);
    memory.push_back(node3);

    //반복문을 통해, memory 배열안에 저장된 data값들을 출력해줌.
    for (int i=0; i<3; i++)
        print(memory[i]->data);
    
    // 반복문을 통해, memory 배열안에 저장된 값들을 삭제해줌.
    for (int i=0; i<3; i++)
        delete memory[i];
}
#include "../CookHeader.h"

//typedef는 별칭을 붙히기 위해서 사용하는 문법이다.
// 일반적으로 struct를 통해 바로 생성이 가능함.
// _를 붙히는 이유는 관례적 이유이긴 하나, 강제되지는 않음.
typedef struct _Node {
    string data;
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node * head, * current, * pre;
Array <string> dataArray = { "다현", "정연", "쯔위", "사나", "지효" };

//사용자 함수 선언 부분.
//파라미터 값을 통해 파라미터 값을 검증하여, 배열의 값을 데이터필드 -> 링크필드 순으로 이어준다.
void printNodes(Node* start) {
    if (start == NULL)
        return; 
    Node* current = start;
    print(current->data);
    while (current->link != NULL) {
        current = current->link;
        print(current->data);
    }
    println("");
}

// 메모리를 비우기 위한 사용자 함수 선언.
// 배열의 길이만큼, 배열값을 전부 비워버림. CookHeader.h안에 정의된 함수를 사용함.
void freeMemory() {
    for (int i = 0; i < len(memory); i++)
    delete memory[i];
}

int main() {
    // 구조체 형태의 Node를 선언 후, 초기화 해준다.
    Node* node = new Node;
    //dataArray의 0번지를 node와 data를 이어준다 (head로 만들어주는 과정)
    node->data = dataArray[0];
    //head에 node값을 저장함.
    head = node;
    //배열의 가장 앞에 배치.
    memory.push_back(node);

    //반복문을 통해서, 배열의 길이만큼, 배열의 값을 순차적으로 데이터 필드와 링크 필드 순으로 이어줌.
    for (int i = 0; i < len(dataArray); i++) {
        string data = dataArray[i];
        pre = node;
        node = new Node;
        node->data = data;
        pre->link = node;
        memory.push_back(node);
    }
    //Node를 출력해준다.
    printNodes(head);
    //다 끝났으니 메모리를 비어준다.
    freeMemory();
}



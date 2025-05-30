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
//파라미터 값을 통해 파라미터 값을 검증하여, 데이터를 순차적으로 출력해줌.
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
// 배열의 길이만큼, 배열값을 전부 비워버림.
void freeMemory() {
    for (int i = 0; i < len(memory); i++)
    delete memory[i];
}

void deleteNode(string deleteData) {
    //전달 받은 파라미터값을 통해, 먼저 데이터를 선 검증.
    if (head->data == deleteData) {
        //현재값은 head가 됨.
        current = head;
        //head 데이터 필드가 링크 필드를 가리키게 됨.
        head = head->link;
        return;
    }
    //현재값은 head가 된 후, 반복문 시작.
    current = head;
    // 현재값이 링크 필드를 가리킬때, 데이터가 있는지 먼저 검증.
    while (current->link != NULL) {
        //전 값이 현재값이 되고,
        pre = current;
        //현재 값의 데이터 필드가 링크 필드를 가리킴.
        current = current->link;
        // 현재 값의 데이터 필드가 전달받은 파라미터 값과 동일한지 검증.
        if (current->data == deleteData) {
            //전의 링크 필드는, 현재의 링크필드가 됨.
            pre->link = current->link;
            //현재값의 데이터는 비어짐.
            current->data = "None";
            return;
        }
    }
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

    deleteNode("다현");
    printNodes(head);

    deleteNode("쯔위");
    printNodes(head);

    deleteNode("지효");
    printNodes(head);

    deleteNode("재남");
    printNodes(head);

    //다 끝났으니 메모리를 비어준다.
    freeMemory();
}



#include "../CookHeader.h"

typedef struct _Node {
    string data;
    struct _Node* link = NULL;
} Node;

Array <Node*> memory;
Node* head, *current, *pre;
Array <string> dataArray = { "다현", "정연", "쯔위", "사나", "지효"};

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

// 노드를 검색하는 사용자 함수. 검색할 값을 파라미터 값으로 받는다. 
Node* findNode(string findData) {
    current = head;
    if (head->data == findData)
    return current;
    while (current->link != NULL) {
        current = current->link;
        if(current->data == findData) {
            return current;
        }
    }
    //노드값을 찾지 못하면, NULL을 반환해준다.
    return new Node {"None", NULL};
}

int main() {
    Node* node = new Node;
    node->data = dataArray[0];
    head = node;
    memory.push_back(node);

    for (int i = 1; i < len(dataArray); i++) {
        string data = dataArray[i];
        pre = node;
        node = new Node;
        node->data = data;
        pre->link = node;
        memory.push_back(node);
    }
    printNodes(head);

    Node* fNode;
    fNode = findNode("다현");
    println(fNode->data);

    fNode = findNode("쯔위");
    println(fNode->data);

    fNode = findNode("재남");
    println(fNode->data);

    freeMemory();
}
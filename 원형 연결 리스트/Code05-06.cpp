#include "../CookHeader.h"

typedef struct _Node {
    // 해당 부분은 데이터필드와 링크필드를 의미하는 변수를 선언함.
    string data;
    struct _Node* link = NULL;
} Node;

/* 노드의 포인터형태를 저장하기 위한 배열과 
    헤드, 현재값, 전값
    데이터를 저장해둔 배열을 변수로 선언.
*/ 
Array <Node*> memory;
Node* head, * current, * pre;
Array <string> dataArray = { "다현", "정연", "쯔위", "사나", "지효"};

// 노드를 출력해주는 사용자 지정 함수.
void printNodes(Node* start) {
    if (start == NULL)
        return;
    Node* current = start;
    print(current->data);
    while (current->link != start) {
        current = current->link;
            print(current->data);
    }
    println("");
}

// 메모리를 비워주는 사용자 지정 함수.
void freeMemory() {
    for (int i=0; i < len(memory); i++) {
        delete memory[i];
    }
}

// 노드를 삭제하는 사용자 지정 함수, 파라미터값을 받아 삭제해야 할 데이터를 찾는다.
void deleteNode(string deleteData) {
    // 노드 포인터 형태의 마지막값을 지정.
    Node* last;
    // 조건문을 거치기 전에, 헤드의 데이터 필드의 값과 파라미터값을 검증해, 일치하는 경우 조건문 시작.
    if (head->data == deleteData) {
        //현재 값은 헤드가 되고,
        current = head;
        //헤드는 헤드의 링크필드를 가리킴.
        head = head->link;
        //마지막 값은 헤드가 됨.
        last = head;
        //반복문을 통해, 노드들을 순회, 현재 노드와 겹치지않는 경우에만 반복.
        while (last->link != current) 
            // 마지막 값은, 노드의 링크필드가 됨.
            last = last->link;
        // 마지막 값의 링크필드는 헤드가 됨.
        last->link = head;
        //데이터를 삭제를 의미하는 None이 현재 노드의 데이터 필드에 삽입됨. (실제로는 삭제가 된게 아니라 빈 값으로 처리가됨.)
        current->data = "None";
        //반환.
        return;
    }
    //현재값은 헤드가 되고,
    current = head;
    //반복문을 통해 현재 노드의 데이터필드가 파라미터값과 일치하는지, 검증 후 반복문을 통해서 노드 순회 시작.
    while (current->data == deleteData) {
        //전 노드의 링크필드는 현재 노드의 링크필드가 됨.
        pre->link = current->link;
        //현재 데이터필드는 값이 None이 됨.
        current->data= "None";
        //반환.
        return;
        }
    }

int main() {
    //노드를 저장하기 위한 포인터형 변수 선언.
    Node* node = new Node;
    //node의 데이터 필드에는 미리 지정해둔 dataArray의 0번지 값이 들어감.
    node->data = dataArray[0];
    // 노드를 생성하였으므로, head를 node로 지정.
    head = node;
    // node의 링크필드는 head를 가짐.
    node->link = head;
    //메모리에 그대로 삽입.
    memory.push_back(node);

    // 반복문을 통해, 1번지부터 4번지까지 반복.
    for (int i=1; i<len(dataArray); i++) {
        // data 변수에는 dataArray의 i번지의 값을 가짐.
        string data = dataArray[i];
        // 전값에는 node가 들어감.
        pre = node;

        //노드를 추가 및 사용하기 위해 노드를 초기화
        node = new Node;
        // 노드의 데이터필드는 데이터를 가짐.
        node->data = data;
        //전값의 링크 필드는 노드를 가짐.
        pre->link = node;
        //노드의 링크필드는 헤드가 됨.
        node->link = head;
        // 그대로 삽입. 이과정을 4번 반복하여서 노드를 총 4개 생성 (1번지부터 4번지 까지)
        memory.push_back(node);
    }
    deleteNode("다현");
    printNodes(head);

    deleteNode("다현");
    printNodes(head);

    deleteNode("다현");
    printNodes(head);

    deleteNode("다현");
    printNodes(head);

    freeMemory();
}


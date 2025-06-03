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
// 검색을 위한 사용자 지정 함수 선언. 찾아야 할 데이터값을 파라미터 값으로 받음.
Node* findNode(string findData) {
    //현재 값은 헤드 노드가 됨.
    current = head;
    //헤드의 데이터필드의 값과 파리미터 값과 비교후 조건문 시작.
    if (head->data == findData)
        // 현재 값을 반환.
        return current;

    // 현재의 링크필드가 헤드와 같지 않는지 검증 후, 노드를 순회함.
    while (current->link != head) {
        //현재 값은 현재의 링크필드가 된다.
        current = current->link;
        // 여기서도 현재의 데이터필드의 값이 파라미터 값과 일치하는지 검증 후 조건문 시작.
        if (current->data == findData) {
            //현재값 반환.
            return current;
        }
    }
    //만약에 노드에서 일치하는 값을 찾지 못했으면, 데이터 필드에 None값과 링크 필드는 비워버린다.
    return new Node{ "None", NULL };
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

    Node* fNode;
    fNode = findNode("다현");
    println(fNode->data);

    fNode = findNode("쯔위");
    println(fNode->data);
    
    fNode = findNode("재남");
    println(fNode->data);

    freeMemory();    
}


#include "../CookHeader.h"

// 구조체에 노드에 삽입할 데이터 변수인 data와 Node형태의 변수 link를 초기화 한다.
typedef struct _Node {
    string data;
    struct _Node* link = NULL;
} Node;

int main() {
    //단순 연결 리스트의 시작은 head가 존재한다. 따라서 Node를 참조할 head를 선언후 초기화한다.
    Node* head;

    //head에 node1을 추가하는 과정.
    Node* node1 = new Node;
    node1->data = "다현";
    head = node1;

    //다현 과 정연이 참조될 때, node1의 링크 필드를 통해, node2의 데이터 필드를 가리킨다.
    // node5까지 동일한 과정을 거친다.
    Node* node2 = new Node;
    node2->data = "정연";
    node1->link = node2;

    Node* node3 = new Node;
    node3->data = "쯔위";
    node2->link = node3;
    
    Node* node4 = new Node;
    node4->data = "사나";
    node3->link = node4;
    
    Node* node5 = new Node;
    node5->data = "지효";
    node4->link = node5;

    Node* newNode = new Node;
    newNode->data = "재남";
    newNode->link = node2->link;
    node2->link = newNode;

    //Tail(꼬리)부분은 생략이 가능하니, 없어도 굳이 상관 없다.

    //반복문을 통해 개선된 출력문.
    //current에 head를 저장후, 반복문의 조건을 통해 link가 비어 있지않다면, current와 link를 순차적으로 이어준다.
    //마찬가지로, head의 링크 필드를 통해 link의 데이터 필드와 이어지고, link의 링크 필드를 다음 link의 데이터 필드와 순차적으로 이어준다.
    //node2의 링크필드를 통해 newNode를 이어주었다.
    Node* current = head;
    print(current->data);
    while (current->link != NULL) {
        current = current->link;
        print(current->data);
    }
}
#include "../CookHeader.h"

// 구조체 생성. 
typedef struct _Node {
    //해당 부분은 데이터필드.
    string data;
    //해당 부분은 링크필드.
    struct _Node* link = NULL;
} Node;

int main() {
    //해당 부분은 헤드.
    Node* head;

    //node1 생성. 및 head 지정.
    Node* node1 = new Node;
    node1->data = "다현";
    head = node1;
    node1->link = head;

    //순환형 구조를 가지기 위해, node를 생성후엔 head를 가리키게 한다.
    Node* node2 = new Node;
    node2->data = "정연";
    node1->link = node2;
    node2->link = head;

    Node* node3 = new Node;
    node3->data = "쯔위";
    node2->link = node3;
    node3->link = head;

    Node* node4 = new Node;
    node4->data = "사나";
    node3->link = node4;
    node4->link = head;

    Node* node5 = new Node;
    node5->data = "지효";
    node4->link = node5;
    node5->link = head;

    //node2의 링크 필드를 node3의 링크 필드로 대체 후, node3를 제거하낟.
    node2->link = node3->link;
    delete node3;

    //현재의 값 포인터는 head를 의미하고,
    Node *current = head;
    //여기도 마찬가지로, while문의 조건으로 인해 출력이 되지않음.
    print(current->data);
    while (current->link != head) {
        current = current->link;
        print(current->data);
    }
}

#include "../CookHeader.h"

typedef struct _Node {
    string data[2];
    struct _Node* link = NULL;
} Node2;

Array <Node2*> memory;
Node2* head, *current, *pre;
Array <Array <string>> dataArray = { {"지민", "010-1111-1111"}, 
{"정국", "010-2222-2222"}, {"뷔", "010-3333-3333"}, {"슈가", "010-4444-4444"}, 
{"진", "010-5555-5555"} };

void printNode2(Node2* start) {
    if (start == NULL)
        return;
    Node2* current = start;
    print("[" + current->data[0] + " , " + current->data[1] + "]");
    while (current->link != NULL) {
        current = current->link;
        print("[" + current->data[0] + " , " + current->data[1] + "]");
    }
    println("");
}

void freememory() {
    for (int i = 0; i < len(memory); i++)
    delete memory[i];
}

void makeSimpleLInkedList(Array <string> namePhone) {
    printNode2(head);

    Node2* node;
    node = new Node2;
    node->data[0] = namePhone[0];
    node->data[1] = namePhone[1];
    memory.push_back(node);
    if (head == NULL) {
        head = node;
        return;
    }
    if (head->data[0] > namePhone[0]) {
        node->link = head;
        head = node;
        return;
    }
    // 중간 노드로 삽입하는 경우.
    current = head;
    while (current->link != NULL) {
        pre = current;
        current = current->link;
        if (current->data[0] > namePhone[0]) {
            pre->link = node;
            node->link = current;
            return;
        }
    }
    //삽입하는 노드가 가장 큰 경우
    current->link = node;
}

int main() {
    for (int i = 0; i < len(dataArray); i++) {
        makeSimpleLInkedList(dataArray[i]);
    }
    printNode2(head);

    freememory();
}
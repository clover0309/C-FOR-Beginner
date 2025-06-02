#include "../CookHeader.h"

typedef struct _Node {
    string data[2];
    struct _Node* link = NULL;
} Node2;

Array <Node2*> memory;
Node2* head, * current, * pre;

void printNodes(Node2* start) {
    if (start == NULL)
        return;
    Node2* current = start;
    print("[" + current->data[0] + " , " + current->data[1] + "]");
    while (current->link != NULL) {
        //current는 current의 링크필드를 가리킴.
        current = current->link;
        //current는 데이터 필드의 0번지와 1번지의 값을 출력해줌.
        print("[" + current->data[0] + " , " + current->data[1] + "]");
    }
    println("");
}

void freeMemory() {
    for (int i = 0; i < len(memory); i++)
    delete memory[i];
}

// 단순 연결 리스트를 만드는 함수, main부분에서 dataArray를 파라미터 값으로 전달받음. (배열 전체가 여기에 들어온다.)
void makeSimpleLInkedList(Array <string> nameEmail) {
    //Node2의 포인터 형태를 가진 node 변수 생성 후, 초기화해줌.
    Node2* node;
    node = new Node2;
    
    //node의 데이터필드 0번지, 1번지에 전달받은 파라미터 값을 배열에 삽입.
    node->data[0] = nameEmail[0];
    node->data[1] = nameEmail[1];

    //memory영역에 node값을 추가해줌.
    memory.push_back(node);

    // 만약 head값이 빈다면, head에 node값을 추가해준다. (아마 여기서는 제일 첫번째로 오는 배열의 값들이 head가 되는듯함?)
    if (head == NULL) {
        node->link = head;
        head = node;
        return;
    }

    // 한글로 기입되어 있는경우에, 가나다순으로 정렬이되고, 영어로 되어있는 경우에 abc순으로 정렬이 되는 로직임.
    // 기존에 1번지에 값이 이미 존재하는 경우에, 파라미터값의 1번지 값과 글자 크기를 비교하여서 정렬을 함.
    if (head->data[1] > nameEmail[1]) {
        node->link = head;
        head = node;
        return;
    }
    // 중간 노드로 삽입하는 경우.
    current = head;
    // 만들어진 리스트를 순회하면서, 배열이 들어갈 곳을 찾아감.
    while (current->link != NULL) {
        pre = current;
        current = current->link;
        if (current->data[0] > nameEmail[0]) {
            pre->link = node;
            node->link = current;
            return;
        }
    }
    //삽입하는 노드가 가장 큰 경우
    current->link = node;
}

int main() {
    string name, email;
    while (true) {
        input(name, "이름 --> ");
        if (name == "x" || name == "X")
            break;
        input (email, "이메일 --> ");
        makeSimpleLInkedList({name, email});
        printNodes(head);
    }
    freeMemory();
}
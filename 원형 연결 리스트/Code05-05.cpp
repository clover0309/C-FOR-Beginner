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

/* 노드를 삽입하기 위한 사용자 지정 함수, 노드의 데이터필드값을 
    찾아서 데이터를 삽입해야하기 때문에, 파라미터 값은 2개를 받음.
*/
void insertNode (string findData, string insertData) {
    //노드를 추가하고, 마지막 값(그전에 있던 노드의 필드들)을 저장하기 위해서 변수 2개 선언.
    Node* node;
    Node* last;

    //head의 데이터 필드가 데이터를 찾기위한 파라미터 값과 일치하는지 검증.
    if (head->data == findData) {
        // node 변수를 사용하기 위해 초기화.
        node = new Node;
        //node의 데이터 필드에, 파라미터로 받은 추가할 값으로 지정.
        node->data = insertData;
        //링크 필드는 헤드가 됨.
        node->link = head;
        // 마지막 값은 헤드가 되고
        last = head;
        //반복문을 통해서, 마지막값의 링크필드가 헤드와 일치하는지 검증후에
        while (last->link != head)
            //마지막 값에 링크필드까지 삽입.
            last = last->link;
        // 마지막 값의 링크필드가 노드가 됨.
        last->link = node;
        //헤드값이 노드가 됨.
        head = node;
        //메모리에 삽입.
        memory.push_back(node);
        return;
    }
    //현재 값은 헤드가 됨.
    current = head;
    //반복문을 거치기전에, 현재 링크필드가 헤드와 일치하는지 검증.
    while (current->link != head) {
        //전 값이, 현재 값이 되고.
        pre = current;
        //현재 값이 현재값의 링크필드를 가짐.
        current = current->link;
        //조건문을 거치기전에 현재의 데이터 필드가, 찾는 값(파라미터값)과 일치하는지 검증
        if (current->data == findData) {
            //node를 사용하기위해 초기화.
            node = new Node;
            //노드의 데이터필드는 삽입할 값이 되고,
            node->data = insertData;
            //노드의 링크필드는 현재 값이됨.
            node->link = current;
            //전 값의 링크필드는 노드가 됨.
            pre->link = node;
            //메모리에 삽입.
            memory.push_back(node);
            //반환.
            return;
        }
    }
    // 노드를 사용하기 위해 노드 초기화.
    node = new Node;
    //노드의 데이터필드안에 삽입할 값이 들어감.
    node->data = insertData;
    //현재의 링크필드는 헤드값이 됨.
    current->link = head;
    //메모리에 삽입.
    memory.push_back(node);
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

    insertNode("다현", "화사");
    printNodes(head);

    insertNode("사나", "솔라");
    printNodes(head);

    insertNode("재남", "문별");
    printNodes(head);

    freeMemory();
}
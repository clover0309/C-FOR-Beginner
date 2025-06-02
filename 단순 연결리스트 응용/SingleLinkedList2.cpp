#include "../CookHeader.h"

// 구조체 선언.
typedef struct _Node {
    int data;
    struct _Node* link = NULL;
} Node;

// Node포인터형태의 배열을 할당하기 위한 배열 생성.
Array <Node*> memory;
// 포인터 값을 저장하기위한 변수 3개 선언.
// 헤드를 가리키고, 현재를 가리키고, 전의 것을 가리키는 것으로 칭한다.
Node* head, * current, * pre;

// Node의 값들을 출력해주는 사용자 지정 함수, Node의 포인터형태의 자료형을 가진 파리미터 값을 받는다.
void printNodes(Node* start) {
    //만약에 노드자체가 비어있다면 그냥 종료한다.
    if (start == NULL)
        return;
    
    // Node포인터 형태의 current에 파라미터 값을 삽입.
    Node* current = start;

    //출력 current의 데이터필드 출력.
    print(current->data);

    // 반복문을 통해 current의 링크필드가 비어있지 않은 경우에만
    // current는 current자체가 링크필드를 가리킨다.
    while (current->link != NULL) {
        current = current->link;
        //current의 데이터필드를 출력해준다.
        print(current->data);
    }
    println("");
}

//메모리를 비우는 사용자 지정 함수.
void freeMemory() {
    for (int i = 0; i < len(memory); i++)
    delete memory[i];
}

//로또 리스트를 생성해주는 사용자함수.
void makeLottoList (int num) {

    //Node 포인터 형태의 변수 선언.
    Node* node;
    //사용하기 위해 변수 초기화.
    node = new Node;
    //node의 데이터필드값은 파라미터 값을 삽입.
    node->data = num;
    //배열에 삽입.
    memory.push_back(node);

    //만약 헤드가 비면은, 헤드는 위에서 선언된 node값을 받아옴.
    //여기서 헤드값은 배열 초기값을 받아서 반환함.
    if (head==NULL) {
        head = node;
        return;
    }

    //만약에 헤드의 데이터필드의 값이 num보다 크다면
    if (head->data > num) {

        //node의 링크필드는 헤드값이 된다.
        node->link = head;
        // 헤드는 노드가 된다.
        head = node;
        return;
    }
    //현재 노드가 헤드가 되고.
    current = head;

    //반복문을 통해, 현재 링크값이 비어있지 않다면.
    while (current->link != NULL) {
        //전 값이 현재 노드가 되고.
        pre = current;
        //현재 값은, 현재 노드의 링크를 가리킨다.
        current = current->link;

        //여기서 현재 노드의 데이터필드가 파라미터로 받은 num보다 작으면 정렬을 시도함.
        // 그냥 단순 낮은순서 부터 높은순서대로 숫자의 값을 정렬함.
        if (current->data > num) {
            pre->link = node;
            node->link = current;
            return;
        }
    }
    //현재 노드의 링크필드의 값은 노드의 값이 됨.
    current->link = node;
}

// 참거짓형태로 선언된 사용자 지정 함수는 정수형의 파라미터 값을 받음.
bool findNumber(int num) {
    //만약 헤드값이 비면, 거짓을 반환함.
    if (head == NULL)
    return false;
    
    //현재 노드는 헤드가 된다.
    current = head;

    // 현재 노드의 데이터필드의 값과, 파라미터 값이 일치하면
    if (current->data == num)
        // 참을 반환함.
        return true;

    // 반복문을 통해, 현재 노드의 링크필드가 비어있지 않다면
    while (current->link != NULL) {
        //현재 노드는 현재의 링크필드 값을 삽입함.
        current = current->link;
        // 현재 노드의 데이터필드가 파라미터 값과 일치하면
        if (current->data == num) {
            //참을 반환함.
            return true;
        }
    }
    //작업을 멈추기위한 거짓 반환.
    return false;
}

int main() {
    int lottoCount = 0;
    int lotto;

    //CookHeader.h에 지정된, randomInit을 1부터 45까지의 인자값을 던져서 수행.
    randomInit(1, 45);
    //반복문 시작.
    while (true) {
        //lotto 변수에 저장될 값은 randomInit에서 던진 1부터 45까지를 생성하게됨.
        lotto = cookRandom(gen);

        // 위에서 선언한 사용자 함수를, lotto에 저장된 값을 파라미터 값으로 던짐. 
        if (findNumber(lotto))
            //만약 겹치면, 스킵.
            continue;
                // 겹치지 않으면, 여기를 수행해서 lottoCount를 후연산으로 처리. 해당 if문을 빠져나가면 값이 하나씩 올라감.
                lottoCount++;
                    //위에서 선언한 사용자 함수를 통해, lotto 변수를 파라미터 값으로 던짐.
                    makeLottoList(lotto);
        // 만약, lottoCount가 6보다 크거나 커지면 중단함.
        if (lottoCount >= 6)
                break;
    }
    //여기서 파라미터값을 통해 노드를 전부 출력해줌.
    printNodes(head);
    //메모리에서 볼일을 다봤으니, 메모리를 초기화 해줌.
    freeMemory();
}
#include "../CookHeader.h"

Array <Array <string>> katok = { {"다현", "200"}, {"정연", "150"}, {"쯔위", "90"},
{"사나", "30"}, {"지효", "15"} };

void insert_data(int position, Array <string> pairData) {
    if ( (position < 0) || (position > len(katok)) ) {
        print("데이터를 삽입할 범위를 벗어났습니다.");
        return;
    }

    katok.push_back( {"None", "None"} );
    int kLen = len(katok);

    for (int i = kLen -1; i > position; i--) {
        katok[i] = katok[i-1];
        katok[i-1] = { "None", "None" };
    }

    katok[position] = pairData;
}

void find_and_insert_data(string data, string k_count) {
    int findPos = -1;

    for (int i = 0; i < len(katok); i++) {
        Array <string> pair = katok[i];
        if (stoi(k_count) >= stoi(pair[1])) {
            findPos = i;
            break;
        }
    }
    if (findPos == -1)
        findPos = len(katok);

    Array <string> pairPara = { data, k_count };
    insert_data(findPos, { data, k_count });
}

int main() {
    string data;
    string count;

    while (true) {
        input (data, "추가할 친구 --> ");
        input (count, "카톡 횟수 --> ");
        find_and_insert_data(data, count);
        printArray2(katok);
    }
}
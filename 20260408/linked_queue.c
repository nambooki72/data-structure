#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_queue.h"

// 전역 변수 실제 정의
QueueNode* front = NULL;
QueueNode* rear = NULL;

/*
    함수명: is_queue_empty
    기능  : 큐가 비어 있으면 true, 아니면 false 반환

    연결 큐에서는 front가 NULL이면
    큐에 아무 노드도 없는 상태라고 보면 됩니다.
*/
boolean is_queue_empty() {
    if (front == NULL)
        return true;
    else
        return false;
}

/*
    함수명: addq
    기능  : 큐의 맨 뒤(rear)에 문자 e를 삽입

    연결 큐의 삽입 과정:
    1. 새 노드 동적 할당
    2. item에 데이터 저장
    3. link는 NULL로 설정 (맨 마지막 노드니까)
    4. 큐가 비어 있으면 front와 rear가 모두 새 노드를 가리킴
    5. 비어 있지 않으면 기존 rear의 link를 새 노드로 연결
       그리고 rear를 새 노드로 이동
*/
void addq(Element e) {
    QueueNode* temp;

    // 새 노드 메모리 할당
    temp = (QueueNode*)malloc(sizeof(QueueNode));

    // 메모리 할당 실패 검사
    if (temp == NULL) {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }

    // 새 노드 데이터 저장
    temp->item = e;

    // 새 노드는 맨 뒤에 붙으므로 다음 노드는 없음
    temp->link = NULL;

    // 현재 큐가 비어 있는 경우
    if (front == NULL) {
        front = temp;
        rear = temp;
    }
    // 현재 큐에 노드가 하나 이상 있는 경우
    else {
        rear->link = temp;  // 기존 마지막 노드가 새 노드를 가리키게 함
        rear = temp;        // rear를 새 노드로 갱신
    }
}

/*
    함수명: deleteq
    기능  : 큐의 맨 앞(front) 노드를 삭제하고 그 데이터를 반환

    연결 큐의 삭제 과정:
    1. front 노드를 temp에 잠깐 저장
    2. front의 데이터를 item에 저장
    3. front를 다음 노드로 한 칸 이동
    4. 원래 front였던 노드(temp) 메모리 해제
    5. 삭제 후 front가 NULL이면 큐가 완전히 빈 상태이므로 rear도 NULL로 맞춤

    주의:
    이 함수는 "큐가 비어 있지 않다"는 전제에서 호출하는 것이 PPT 요구사항입니다.
*/
Element deleteq() {
    QueueNode* temp;
    Element item;

    // 삭제할 맨 앞 노드를 temp가 가리키게 함
    temp = front;

    // 반환할 데이터 저장
    item = temp->item;

    // front를 다음 노드로 이동
    front = front->link;

    // 만약 삭제 후 큐가 비게 되면 rear도 NULL로 맞춰야 함
    if (front == NULL) {
        rear = NULL;
    }

    // 원래 front 노드 메모리 해제
    free(temp);

    // 삭제한 데이터 반환
    return item;
}

/*
    함수명: queue_show
    기능  : 현재 큐에 저장된 문자들을 앞에서부터 차례대로 출력

    예:
    a b c 가 들어 있으면
    Queue : a b c

    front부터 시작해서 link를 따라가며 끝(NULL)까지 출력합니다.
*/
void queue_show() {
    QueueNode* p;

    if (is_queue_empty()) {
        printf("\nQueue is empty !!!\n");
        return;
    }

    printf("\nQueue : ");

    p = front;
    while (p != NULL) {
        printf("%c ", p->item);
        p = p->link;
    }
    printf("\n");
}

/*
    main 함수
    PPT의 흐름을 최대한 그대로 따름

    명령어:
    +<c> : 문자 삽입
    -    : 삭제
    S    : 출력
    Q    : 종료
*/
void main() {
    char c, e;

    printf("***************Command***************\n");
    printf("+<c> : AddQ c, - : DeleteQ,\n");
    printf("S : Show, Q : Quit\n");
    printf("*************************************\n");

    // 시작 시 빈 큐
    front = rear = NULL;

    while (1) {
        printf("\nCommand > ");

        c = getchar();
        c = toupper(c);

        switch (c) {
        case '+':
            // 예: +A 입력 시 A를 읽어서 삽입
            e = getchar();
            addq(e);
            break;

        case '-':
            if (is_queue_empty()) {
                printf("\nQueue is empty !!!\n");
            }
            else {
                e = deleteq();
                printf("\n%c\n", e);
            }
            break;

        case 'S':
            queue_show();
            break;

        case 'Q':
            printf("\n");
            exit(1);

        default:
            break;
        }

        // 입력 버퍼에 남아 있는 개행 문자 제거
        while (getchar() != '\n');
    }
}
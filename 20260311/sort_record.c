#include "ex2.h"

void sort_record(void)
{
    int i, j;
    int min_index;
    StudentRecord temp;   // 구조체 전체를 임시 저장할 변수

    /*
        선택 정렬(selection sort)

        i번째 자리에 들어갈 가장 작은 id를 찾아서
        r[i]와 교환한다.
    */
    for (i = 0; i < num_record - 1; i++) {
        min_index = i;

        // i 이후 구간에서 가장 작은 id를 찾음
        for (j = i + 1; j < num_record; j++) {
            if (r[j].id < r[min_index].id) {
                min_index = j;
            }
        }

        // 가장 작은 원소를 현재 위치 i와 교환
        if (min_index != i) {
            temp = r[i];
            r[i] = r[min_index];
            r[min_index] = temp;
        }
    }
}
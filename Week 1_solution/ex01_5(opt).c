// ÀÌÁø Å½»ö
#include <stdio.h>

int bs(int list[], int searchnum, int left, int right) {
    if (left > right)  // Å½»ö ½ÇÆĞ
        return -1;

    int middle = (left + right) / 2;
    printf("Call to binary_search with index [%d, %d]\n", left, right);

    if (list[middle] == searchnum)  // Å½»ö ¼º°ø
        return middle;
    else if (list[middle] > searchnum)  // ¿ŞÂÊ¿¡¼­ Å½»ö
        return bs(list, searchnum, left, middle - 1);
    else  // ¿À¸¥ÂÊ¿¡¼­ Å½»ö
        return bs(list, searchnum, middle + 1, right);
}

int main() {
    int a[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int searchnum, index;

    printf("\n  i:   ");
    for (int i = 0; i < 10; i++) {
        printf("\t%2d", i);
    }
    printf("\n");

    printf("a[i]:  ");
    for (int i = 0; i < 10; i++) {
        printf("\t%2d ", a[i]);
    }
    printf("\n\n");

    printf("Search number: ");
    scanf("%d", &searchnum);

    index = bs(a, searchnum, 0, 9);

    if (index != -1)
        printf("%d is in a[%d]\n", searchnum, index);
    else
        printf("%d is not in the array\n", searchnum);

    return 0;
}

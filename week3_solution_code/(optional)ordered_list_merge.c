#include"ordered_list_merge.h"

int main(void) {
	ArrayList L1 = { {1, 3, 5, 7, 9}, 5 };
	ArrayList L2 = { {2, 4, 6, 8}, 4 };

	printf("리스트 L1 : ");
	for (int i = 0; i < L1.size; i++) {
		printf("%d ", L1.array[i]);
	}
	printf("\n");
	printf("리스트 L2 : ");
	for (int i = 0; i < L2.size; i++) {
		printf("%d ", L2.array[i]);
	}
	printf("\n");

	ArrayList merged_list = ordered_list_merge(&L1, &L2);
	printf("합병된 리스트 : ");
	for (int i = 0; i < merged_list.size; i++) {
		printf("%d ", merged_list.array[i]);
	}
	printf("\n");
	return 0;
}

ArrayList ordered_list_merge(ArrayList* L1, ArrayList* L2) {
    ArrayList merged_list;
    merged_list.size = 0;
    int i = 0, j = 0;

    while (i < L1->size && j < L2->size) {
        if (L1->array[i] < L2->array[j]) {
            insert(&merged_list, L1->array[i]);
            i++;
        }
        else {
            insert(&merged_list, L2->array[j]);
            j++;
        }
    }

    while (i < L1->size) {
        insert(&merged_list, L1->array[i]);
        i++;
    }

    while (j < L2->size) {
        insert(&merged_list, L2->array[j]);
        j++;
    }

    return merged_list;
}

Element get_element(ArrayList* L, int i) {
    if (i >= 0 && i < L->size) {
        return L->array[i];
    }
    printf("Index out of bounds\n");
    exit(1);
}

void insert(ArrayList* L, Element e) {
    if (L->size < MAX) {
        L->array[L->size] = e;
        L->size++;
    }
    else {
        printf("List is full, cannot insert\n");
    }
}
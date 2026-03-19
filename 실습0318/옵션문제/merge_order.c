#include "order_merge.h"

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


ArrayList ordered_list_merge(ArrayList* L1, ArrayList* L2)
{
    ArrayList merged;
    merged.size = 0;

    int i = 0;
    int j = 0;

    while (i < L1->size && j < L2->size)
    {
        if (get_element(L1, i) <= get_element(L2, j))
        {
            insert(&merged, get_element(L1, i));
            i++;
        }
        else
        {
            insert(&merged, get_element(L2, j));
            j++;
        }
    }

    while (i < L1->size)
    {
        insert(&merged, get_element(L1, i));
        i++;
    }

    while (j < L2->size)
    {
        insert(&merged, get_element(L2, j));
        j++;
    }

    return merged;
}

Element get_element(ArrayList* L, int i)
{
	return L->array[i];
}

void insert(ArrayList* L, Element e)
{
	L->array[L->size] = e;
	L->size++;
}
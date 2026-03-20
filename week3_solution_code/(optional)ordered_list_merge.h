#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef int Element;
typedef struct {
	Element array[MAX];
	int size;
}ArrayList;

ArrayList ordered_list_merge(ArrayList* L1, ArrayList* L2);
Element get_element(ArrayList* L, int i);
void insert(ArrayList* L, Element e);

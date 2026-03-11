#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char name[10];
    int id;
    char grade[4];
} StudentRecord;

/* 전역변수 선언만 */
extern StudentRecord r[MAX];
extern int num_record;
extern const char* fname;

/* 함수 원형 */
void read_record(const char* fname);
void print_record(void);
void search_record(void);
void change_record(void);
void write_record(const char* fname);
void sort_record(void);
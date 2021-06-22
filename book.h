#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <malloc.h>
#include <string.h>
#include <locale.h>

#define maxSize 150

void complet(int* num, int lines);
void memStr(FILE* input, int num);
void swap(int* left, int* right);
void bubbleSort(int mass[], int size, int num[]);
void safeOpenFile(FILE** in, char* name, char* mode);
int isEmpty(FILE* in);
int checkLines(FILE* input);
int lineSize(FILE* in, int* mass);
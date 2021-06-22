#include "book.h"

void swap(int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

int checkLines(FILE* in) {
    wchar_t tmp;
    unsigned int line = 1;
    while (!feof(in)) {
        tmp = fgetwc(in);
        if (tmp == L'\n') {
            line++;
        }
    }
    rewind(in);
    return line;
}

int lineSize(FILE* in, int* mass) {
    wchar_t tmp;
    unsigned int line = 0;
    int size = 0, length = 0;
    while (!feof(in)) {
        tmp = fgetwc(in);
        if (tmp == L'\n') {
            mass[line] = size;
            line++;
            size = 0;
            length += size;
        }
        else {
            size++;
        }
    }
    mass[line] = size;
    return length;
}

void complet(int* tmp, int lines) {
    for (short int i = 0; i < lines; ++i) {
        tmp[i] = i + 1;
    }
}

void memStr(FILE* in, int num) {
    char tmp[maxSize] = { 0 };
    for (int i = 0; i < num; i++) {
        fgets(tmp, 150, in);
    }
}

void bubbleSort(int mass[], int size, int num[]) {
    int i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (mass[j] > mass[j + 1]) {
                swap(&mass[j], &mass[j + 1]);
                swap(&num[j], &num[j + 1]);
            }
        }
    }
}

void safeOpenFile(FILE** in, char* name, char* mode) {
    int err = (fopen_s(in, name, mode));
    if (err != 0) {
        printf("Can't open file %s\n", name);
        printf(" Value of errno: %d\n ", errno);
        if (errno == 1) printf("Operation not permitted.\n");
        if (errno == 2) printf("No such file or directory.\n");
        if (errno == 3) printf("Permission denied.\n");
        if (errno == 5) printf("I/O error.");
        exit(-1);
    }
}

int isEmpty(FILE* in) {
    char ch;
    fscanf_s(in, "%c", &ch, 1);
    rewind(in);
    if (ch == EOF) {
        return 1;
    }
    else return 0;
}
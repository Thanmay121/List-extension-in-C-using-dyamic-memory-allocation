#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct{
    int *data; 
    int size;
    int totalcap;
} createlist;

void append(createlist *l1, int value);

createlist *list(int initialcapacity, ...) {
    createlist *ls1 = malloc(sizeof(createlist));
    (*ls1).data = malloc(initialcapacity * sizeof *(*ls1).data);
    (*ls1).size = 0;
    (*ls1).totalcap = initialcapacity;

    if (initialcapacity > 0) {
        va_list args;
        va_start(args, initialcapacity);

        for (int i = 0; i < initialcapacity; i++) {
            int x = va_arg(args, int);
            append(ls1, x);
        }

        va_end(args);
    }

    return ls1;
}

void append(createlist *l1, int value) 
{
    if((*l1).size == (*l1).totalcap)
    {
        int new_capacity = (*l1).totalcap + 1; 
        if (new_capacity == 0) new_capacity = 1;

        int *new_data = realloc((*l1).data,
                                new_capacity * sizeof *(*l1).data);
        (*l1).data = new_data;
        (*l1).totalcap = new_capacity; 
    }

    (*l1).data[(*l1).size] = value;
    (*l1).size++;
}

int get(createlist *l1, int index) {
    return (*l1).data[index];
}

void free_list(createlist *l1) {
    free((*l1).data);
    free(l1);
}
    return (*l1).data[index];
}
void free_list(list *l1) {
    free((*l1).data);
    free(l1);
}


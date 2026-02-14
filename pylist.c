#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int *data; 
    int size;
    int totalcap;
} list;

list *newlist(int initalcapacity) {
    list *ls1= malloc(sizeof(list));
    (*ls1).data = malloc(initalcapacity*sizeof*(*ls1).data);
    (*ls1).size = 0;
    (*ls1).totalcap = initalcapacity;
    return ls1;
}
void append(list *l1, int value) 
{
    if((*l1).size == (*l1).totalcap)
    {
        int new_capacity = (*l1).totalcap+1; 
        if (new_capacity == 0) new_capacity = 1;

        int *new_data = realloc((*l1).data, new_capacity * sizeof *(*l1).data);
        (*l1).data = new_data;
        (*l1).totalcap = new_capacity; 
    }

    (*l1).data[(*l1).size] = value;
    (*l1).size++;
}

int get(list *l1, int index) {
    return (*l1).data[index];
}
void free_list(list *l1) {
    free((*l1).data);
    free(l1);
}

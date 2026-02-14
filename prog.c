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
int main() {
    printf("enter list size");
    int n,choice,temp;
    scanf("%d",&n);
    list *mylist = newlist(n);
    printf("enter list elements");
    for(int k=0;k<n;k++)
    {
        scanf("%d",&(*mylist).data[k]);
    }

    (*mylist).size = n;
    printf("enter 1 to change current list size");
    scanf("%d",&choice);
    if(choice == 1)
    {
    printf("enter number to be appended");
    scanf("%d",&temp);
    append(mylist,temp);
    for(int k=0;k<(*mylist).size;k++)
    {
        printf(" ");
        printf("%d",(*mylist).data[k]);
    }
    }
    free_list(mylist);
    return 0;
}

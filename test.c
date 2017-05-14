#include <stdlib.h>
#include <stdio.h>
//#include <conio.h> only uncomment if needed 

typedef struct node
{
    char c;
    struct node * next;
} node_c;

void create_list_num(node_c ** h,int num_elem);
void print_list(node_c * h);

void main()
{
    node_c * head;
    create_list_num(&head,5);
    print_list(head);
    //getch(); only uncomment if conio is needed
}

void create_list_num(node_c ** h,int num_elem)
 {
     node_c * pt;
     *h = NULL;
     int i;
     for(i = 0;i < num_elem;i++)
     {
         pt = malloc(sizeof(node_c));
         printf("\n enter a character ");
         scanf(" %c",&pt->c);
         pt->next = *h;
         *h = pt;
     }
 }
 
 void print_list(node_c * h)
 {
     node_c * pt = h;
     while(pt != NULL)
     {
         printf(" %c ",pt->c);
         pt = pt->next;
     }
 }
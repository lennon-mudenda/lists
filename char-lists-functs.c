/****************
 * @author:lennon mudenda
 * @description::::
 * a c library to provide helper functions when dealing with linked lists of characters
 * !include stdlib.h always
 * @function list::
 * 1. list creater with known number of elements
 * 2. list creater without known number of elements
 * 3. list elements count
 * 4. add element at positions: start,end,middle:before,middle:after
 * 5. return ith element if exist NULL if not
 * 5. print out list
 * ***************/
 
 typedef struct node
 {
     char c;
     struct node * next;
 } node_c;
 
 /******************
  * @function signatures
 *******************/
 
 void create_list_num(node_c ** h,int num_elem);
 void create_list(node_c ** h);
 int list_num_elem(node_c * h);
 void list_add_start(node_c ** h,node_c ** new_elem);
 void list_add_end(node_c * h,node_c ** new_elem);
 void list_add_mid_before(node_c * h,node_c ** new_elem,node_c ** elem);
 void list_add_mid_after(node_c ** new_elem,node_c ** elem);
 node_c list_ith_elem(node_c * h,int i);
 void print_list(node_c * h);
 
 void create_list_num(node_c ** h,int num_elem)
 {
     node_c * pt;
     h = NULL;
     for(int i = 0;i < num_elem;i++)
     {
         pt = malloc(sizeof(node_c));
         print("enter a character");
         scanf(" %c",&pt->c);
         pt->next = h;
         h = pt;
     }
 }
 void create_list(node_c ** h)
 {  
    char response; 
    node_c * pt;
    h = NULL;
    printf("do you want to enter another element? y/n: ");
    scanf(" %c",&response);
    while(response == 'y')
    {
        pt = malloc(sizeof(node_c));
        print("enter a character");
        scanf(" %c",&pt->c);
        pt->next = h;
        h = pt;
        printf("do you want to enter another element? y/n: ");
        scanf(" %c",&response);
    }
 }
 int list_num_elem(node_c * h)
 {
     node_c * pt;
     int n = 0;
     for(pt = h;pt!=NULL;)
     {
         n += i;
         pt = pt->next;
     }
     return n;
 }
 void list_add_start(node_c ** h,node_c ** new_elem)
 {
     new_elem->next = h->next;
     h = new_elem;
 }
 void list_add_end(node_c * h,node_c ** new_elem)
 {
     node_c * pt;
     pt = h;
     new_elem->next = NULL;
     while(pt->next != NULL)
     {
         pt = pt->next;
     }
     pt->next = new_elem;
 }
 void list_add_mid_before(node_c * h,node_c ** new_elem,node_c ** elem)
 {
    node_c * pt;
    pt = h;
    while(pt->next != elem)
    {
        pt = pt->next;
    }
    new_elem->next = elem;
    pt->next = new_elem;
 }
 void list_add_mid_after(node_c ** new_elem,node_c ** elem)
 {
    new_elem->next = elem->next;
    elem->next = new_elem;
 }
 node_c list_ith_elem(node_c * h,int i)
 {
    node_c * pt;
    int co;
    if(list_num_elem(h)>i)
    {
        return NULL;
    }
    else
    {
        pt = h;
        for(co=1;co<i;co++)
        {
            pt = pt->next;
        }
        return *pt;
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

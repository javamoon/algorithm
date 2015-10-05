#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef Node *LIST; 
typedef Node *Position;

/* node，节点 */
struct node {
    int element;
    Position next;
};

/* 
 * operations (stereotype)
 * 操作
 */
LIST init_list(void);
void delete_list(LIST);
int is_null(LIST);
void insert_node(Position, int);
void delete_node(LIST, Position);
Position find_last(LIST);
Position find_value(LIST, int);
Position find_previous(LIST, Position);
void print_list(LIST);

/* for testing purpose */
int main()
{
    LIST L;
    Position np;
    
    int i;
    /* elements to be put into the list */
    int a[] = {1, 3, 5, 7, 9};

    /* initiate a list */
    L = init_list();
    print_list(L);

    /* insert nodes. Insert just after head node */
    for (i=4; i>=0; i--) {
        insert_node(L, a[i]);
    }
    print_list(L);

    /* delete first node with value 5 */
    np = find_value(L, 1);
    delete_node(L, np);
    print_list(L);

    /* delete list */
    delete_list(L);
	L = NULL;
    print_list(L);

    /* initiate a list */
    L = init_list();
    print_list(L);

    /* insert nodes. Insert just after head node */
    for (i=4; i>=0; i--) {
        insert_node(L, a[i]);
    }
    print_list(L);

    /* delete list */
    delete_list(L);
	return 0;
}

/*
 * Traverse the list and print each element
 * 打印表
 */
void print_list(LIST L)
{
    Position np;
    if(is_null(L)) {
        printf("Empty List\n\n");
        return;
    }

    np = L;
    while(np->next != NULL) { 
        np = np->next;
        printf("%p: %d \n", np, np->element);
    }
    printf("\n");

}

/*
 * Initialize a linked list. This list has a head node
 * head node doesn't store valid element value
 * 创建表
 */
LIST init_list(void) 
{
    LIST L = (LIST) malloc(sizeof(Node));
    //L = (LIST) malloc(sizeof(struct node));
    //L = (Position) malloc(sizeof(struct node));
    L->next = NULL;
    return L;
}

/*
 * Delete all nodes in a list
 * 删除表
 */
void delete_list(LIST L)
{
    Position np, next;

    np   = L;
    do {
        next = np->next;
        free(np);
        np   = next;
    } while(next != NULL);    
}

/*
 * if a list only has head node, then the list is null.
 * 判断表是否为空
 */
int is_null(LIST L) 
{
    return L == NULL || L->next == NULL;
}

/*
 * insert a node after Position np
 * 在np节点之后，插入节点
 */
void insert_node(Position np, int value) 
{
    Position nodeAddr = (Position) malloc(sizeof(Node));
    //nodeAddr = (Position) malloc(sizeof(struct node));
    nodeAddr->element = value;
    nodeAddr->next = np->next;
    np->next = nodeAddr;    
}

/*
 * delete node at Position np
 * 删除np节点
 */
void delete_node(LIST L, Position np)
{
    Position previous, next;
    next     = np->next;
    previous = find_previous(L, np);
    if(previous != NULL) {
        previous->next = next;
        free(np); 
    } else {
        printf("Error: np not in the list");
    }
}

/*
 * find the last node of the list
 * 寻找表的最后一个节点
 */
Position find_last(LIST L)
{
    Position np;
    np = L;
    while(np->next != NULL) {
        np = np->next;
    }
    return np;
}

/*
 * This function serves for 2 purposes:
 * 1. find previous node 
 * 2. return NULL if the Position isn't in the list
 * 寻找npTarget节点前面的节点
 */
Position find_previous(LIST L, Position npTarget)
{
    Position np = L;
    while (np->next != NULL) {
        if (np->next == npTarget) return np; 
        np = np->next;
    } 
    return NULL;
}

/*
 * find the first node with specific value
 * 查询
 */
Position find_value(LIST L, int value) 
{
    Position np = L;
    while (np->next != NULL) {
        np = np->next;
        if (np->element == value) return np;
    }
    return NULL;
}

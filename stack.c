/* use single-linked list to implement stack */
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef Node *Position;
typedef int Element;
// point to the  head node of the list
typedef Node *STACK;
 
struct node {
    Element element;
    Position next;
};

STACK init_stack(void);
void delete_stack(STACK);
Element top(STACK);
void push(STACK, Element);
Element pop(STACK);
int is_null(STACK);

int main(void)
{
    Element a;
    int i;
    STACK sk;
    sk = init_stack();
    push(sk, 1);
    push(sk, 2);
    push(sk, 8);
    printf("Stack is null? %d\n", is_null(sk));
    for (i=0; i<3; i++) {
        a = pop(sk);
        printf("pop: %d\n", a);
    }

    printf("Stack is null? %d\n", is_null(sk));    
    delete_stack(sk);
	return 0;
}

/*
 * initiate the stack
 * malloc the head node.
 * Head node doesn't store valid data
 * head->next is the top node
 */
STACK init_stack(void)
{
    Position np;
    STACK    sk;
    np = (Position) malloc(sizeof(struct node));
    np->next     = NULL;  // sk->next is the top node
    sk = np; 
    return sk;
}

/* pop out all elements 
 * and then delete head node
 */
void delete_stack(STACK sk)
{
    while(!is_null(sk)) {
        pop(sk);
    }
    free(sk);
}
/* 
 * View the top frame
 */
Element top(STACK sk)
{
    return (sk->next->element);
}

/*
 * push a value into the stack
 */
void push(STACK sk, Element value) 
{
    Position np = (Position) malloc(sizeof(Node));
    np->element  = value;
    np->next     = sk->next;
    sk->next     = np; 
}

/* 
 * pop out the top value
 */
Element pop(STACK sk)
{
    Element element;
    Position top;
    if (is_null(sk)) {
        printf("pop() on an empty stack");
        exit(1);
    } else {
        top      = sk->next;
        element  = top->element;     
        sk->next = top->next; 
        free(top);
        return element;
    } 
}

/* check whether a stack is empty*/
int is_null(STACK sk)
{
    return (sk->next == NULL);
}

#ifndef __STACK_H__
#define __STACK_H__

typedef struct {

	void *topOfStack;
	
}Stack;


void Stack_push(Stack *stack , void *element);
void *Stack_pop(Stack *stack);


#endif //  __STACK_H__
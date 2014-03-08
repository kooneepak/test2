#include <stdio.h>
#include "Institution.h"
#include "Linkedlist.h"
#include "Stack.h"


Stack stack;

int Institution_reverse(LinkedList *inputList , LinkedList *outputList){

	void *inst;
	int countElem;
	int i;
	
	inst = List_removeHead(inputList);
	
	for(countElem=0;  inst != NULL ; countElem++){
	Stack_push(&stack,inst);
	inst = List_removeHead(inputList);
	}
	
	
	for(i=0 ; i < countElem ; i++){
	inst = Stack_pop(&stack);
	List_addTail(outputList ,inst);
	}
	

	return countElem;
	
}
	
int isUniversityCollege(void *elem1 , void *type){
	
	if(((Institution *)elem1)->type== (InstitutionType *)type)
		return 1;
	else
	return 0;


}

int Institution_select(LinkedList *inputList , LinkedList *outputList, void *criterion, int(*compare)(void*,void*)){


	



}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	








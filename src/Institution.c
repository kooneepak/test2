#include <stdio.h>
#include "Institution.h"
#include "Linkedlist.h"
#include "Stack.h"
#include "CException.h"


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


	Institution *tempElem = (Institution *) elem1;
	InstitutionType *newType = (InstitutionType *) type;
	if(tempElem->type == *newType)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int Institution_select(LinkedList *inputList , LinkedList *outputList, void *criterion, int(*compare)(void*,void*)){

	void *inst;
	int count = 0; 
	int j;
	void *newType = criterion; 
	
	
	inst = List_removeHead(inputList);
	while(inst != NULL){
		if(compare(inst , newType)){
			Stack_push(&stack,inst);
			count++;
		}
		inst = List_removeHead(inputList);
	}
	
	for(j = 0; j < count; j++) {
	inst = Stack_pop(&stack);
	List_addTail(outputList,inst);
	}
	
}

int wasEstablishedBefore(void *elem1, void *year){

	Institution *tempElem = (Institution *) elem1;
	
	
	if(tempElem->yearEstablished > 2014){
	
		Throw(ERROR_ESTABLISHED);
	
	}
		
	if(tempElem->yearEstablished < *(int *)year)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}


	
	
	
	
	
	
	
	
	








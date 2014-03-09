#ifndef __INSTITUTION_H__
#define __INSTITUTION_H__
#include "Stack.h"
#include "LinkedList.h"


extern Stack stack;

typedef enum {Unknown , University , UniversityCollege , college}InstitutionType;

typedef struct Institution_t{

	char *name;
	char *address;
	unsigned long postcode;
	InstitutionType type;
	int yearEstablished;
	
}Institution;

int Institution_reverse(LinkedList *inputList , LinkedList *outputList);
int Institution_select(LinkedList *inputList , LinkedList *outputList, void *criterion, int(*compare)(void*,void*));
int isUniversityCollege(void *elem1 , void *type);
int wasEstablishedBefore(void *elem1, void *year);

#endif // __INSTITUTION_H__
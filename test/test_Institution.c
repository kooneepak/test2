#include "unity.h"
#include <stdio.h>	
#include "mock_Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"

void setUp(){}
void tearDown(){}

void test_Institution_reverse_element(){

	int numberOfElement;
	LinkedList input = {};
	LinkedList output = {};
	Institution institutionElement1;
	Institution institutionElement2;
	Institution institutionElement3;
	
	input.head = &institutionElement1;
	input.tail = &institutionElement3;
	
	//mocking 
	List_removeHead_ExpectAndReturn(&input,&institutionElement1);
	Stack_push_Expect(&stack,&institutionElement1);
	List_removeHead_ExpectAndReturn(&input,&institutionElement2);
	Stack_push_Expect(&stack,&institutionElement2);
	List_removeHead_ExpectAndReturn(&input,&institutionElement3);
	Stack_push_Expect(&stack,&institutionElement3);
	List_removeHead_ExpectAndReturn(&input,NULL);
	
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement3);
	List_addTail_Expect(&output ,&institutionElement3);
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement2);
	List_addTail_Expect(&output ,&institutionElement2);
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement1);
	List_addTail_Expect(&output ,&institutionElement1);
	
	
	numberOfElement = Institution_reverse(&input, &output);
				  
				  
	TEST_ASSERT_EQUAL(3, numberOfElement);
//test more element 4,5,6			  
}


void test_isUniversitycollege_should_return_one_if_institution_are_the_same_type(){

	Institution institution1 = {.type = UniversityCollege};
	
	
		isUniversityCollege(&institution1, UniversityCollege);
		TEST_ASSERT_EQUAL(1,isUniversityCollege(&institution1, UniversityCollege));




}

void test_isUniversitycollege_should_return_zero_if_institution_are_different_type(){

	Institution institution1 = {.type = UniversityCollege};
	
	
		TEST_ASSERT_EQUAL(0,isUniversityCollege(&institution1, University));


}

void test_institution_select(){


}







	
#include "unity.h"
#include <stdio.h>	
#include "Institution.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"


void setUp(){}
void tearDown(){}

void test_Institution_reverse_three_element(){

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
		  
}

void test_Institution_reverse_four_element(){

	int numberOfElement;
	LinkedList input = {};
	LinkedList output = {};
	Institution institutionElement1;
	Institution institutionElement2;
	Institution institutionElement3;
	Institution institutionElement4;
	
	input.head = &institutionElement1;
	input.tail = &institutionElement4;
	
	//mocking 
	List_removeHead_ExpectAndReturn(&input,&institutionElement1);
	Stack_push_Expect(&stack,&institutionElement1);
	List_removeHead_ExpectAndReturn(&input,&institutionElement2);
	Stack_push_Expect(&stack,&institutionElement2);
	List_removeHead_ExpectAndReturn(&input,&institutionElement3);
	Stack_push_Expect(&stack,&institutionElement3);
	List_removeHead_ExpectAndReturn(&input,&institutionElement4);
	Stack_push_Expect(&stack,&institutionElement4);
	List_removeHead_ExpectAndReturn(&input,NULL);
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement4);
	List_addTail_Expect(&output ,&institutionElement4);
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement3);
	List_addTail_Expect(&output ,&institutionElement3);
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement2);
	List_addTail_Expect(&output ,&institutionElement2);
	
	Stack_pop_ExpectAndReturn(&stack,&institutionElement1);
	List_addTail_Expect(&output ,&institutionElement1);
	
	
	numberOfElement = Institution_reverse(&input, &output);
				  
				  
	TEST_ASSERT_EQUAL(4, numberOfElement);
		  
}


void test_isUniversitycollege_should_return_one_if_institution_are_the_same_type(){

	Institution institution1 = {.type = UniversityCollege};
	InstitutionType newType = UniversityCollege;
	
		isUniversityCollege(&institution1, &newType);
		TEST_ASSERT_EQUAL(1,isUniversityCollege(&institution1, &newType));




}

void test_isUniversitycollege_should_return_zero_if_institution_are_different_type(){

	Institution institution1 = {.type = UniversityCollege};
	InstitutionType newType = University;
	
		TEST_ASSERT_EQUAL(0,isUniversityCollege(&institution1, &newType));
		
	institution1.type = University;
	newType = University;
	
		TEST_ASSERT_EQUAL(1,isUniversityCollege(&institution1, &newType));
		
}

void test_institution_select_will_pass_out_the_institution(){

			LinkedList input = {};
			LinkedList output = {};
			
		Institution institution1 = {.type = University};
		InstitutionType newType = University;
		
		List_removeHead_ExpectAndReturn(&input,&institution1);
		Stack_push_Expect(&stack,&institution1);
		List_removeHead_ExpectAndReturn(&input,NULL);

		Stack_pop_ExpectAndReturn(&stack,&institution1);
		List_addTail_Expect(&output ,&institution1);

		Institution_select(&input,&output,&newType,isUniversityCollege);
	

}

void test_wasEstablishBefore_should_return_one_if_institution_was_established_before_2000(){

		Institution institution1 = {.yearEstablished = 1999};
	
		int year= 2000;
	
		
		TEST_ASSERT_EQUAL(1,wasEstablishedBefore(&institution1, &year));

	
}

void test_wasEstablishBefore_should_return_zero_if_institution_was_established_after_2000(){

		Institution institution1 = {.yearEstablished = 2004};
	
		int year= 2000;
	
		
		TEST_ASSERT_EQUAL(0,wasEstablishedBefore(&institution1, &year));

	
}



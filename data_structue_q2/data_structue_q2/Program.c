#include <stdio.h>
#include <stdlib.h>
#include "Stack_point.h"

void initStack(stack** st);
void main(){
	stack* s1, s2;
	int i, length = 0;
	char temp, symbo;
	
	char* str =(char*) malloc(sizeof(char)*5);
	

	


	s1 = (stack*) malloc(sizeof(stack));
	s2 = (stack*) malloc(sizeof(stack));
	create_stack(s1);
	create_stack(s2);


	gets(str);
	length = strlen(str);

	for(i = 0; i<length; i++){

		
	}

}


void initStack(stack** st){
	(*st) = (stack*) malloc(sizeof(stack));
	create_stack(*st);
}
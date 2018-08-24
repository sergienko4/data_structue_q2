#include <stdio.h>
#include <stdlib.h>
#include "Stack_point.h"
#include "Polynomial.h"

static int ASCIICode = 90;
int isNumOrOperator(char c);
char getChar();
int preoretyId(char c);
int getPreorities(char a, char b);
void calculate(stack* s1, stack* s2, char c);
char todo(stack* s1, stack* s2);

void EX1();
void EX2();
void main() {

	//EX1();
	EX2();




}

void EX2() {
	int x = 0;
	Polynomial* newP = NULL;
	Polynomial* p = create_polynomial();
	Polynomial* p1 = create_polynomial();

	add_polynomial(&p, 5, 2);
	add_polynomial(&p, 8, 6);
	add_polynomial(&p, -8, 6);
	add_polynomial(&p, -1, 2);


	add_polynomial(&p, 5, 42);
	add_polynomial(&p, 1, 100);
	add_polynomial(&p, 3, 1);
	add_polynomial(&p, -4, 3);
	add_polynomial(&p, 1, 5);
	add_polynomial(&p, 7, 8);
	

	print_polynomial(p);


	newP = plus_polynomial(p, p1);
	newP = minus_polynomial(p, p1);
	newP = multyplay_polynomial(p, 0);
	newP = create_polynomial();
	x = get_Power_polynomial(newP);
	reset_power_polynomial(p);
	
}
void EX1() {
	stack* s1;
	stack* s2;
	int i, length = 0, result = -1;
	char temp;

	char* str = (char*)malloc(sizeof(char) * 50);
	s1 = (stack*)malloc(sizeof(stack));
	s2 = (stack*)malloc(sizeof(stack));

	create_stack(s1);
	create_stack(s2);

	gets(str);
	length = strlen(str);

	for (i = 0; i < length; i++) {

		result = isNumOrOperator(str[i]);

		if (str[i] != ' ' &&result == -1) {
			printf("Error, not allowed sybol");
			return;
		}


		// is char
		if (result == 1) {
			push(str[i], s1);
		}
		else {
			// is operator
			if (result == 0) {

				if (stack_is_empty(s2)) {
					push(str[i], s2);
				}
				else {
					stack_top(s2, &temp);
					result = getPreorities(temp, str[i]);
					if (result == 0)
					{
						push(str[i], s2);
					}
					else
					{
						push(todo(s1, s2), s1);
						// check if can calculate in stack
						calculate(s1, s2, str[i]);
						push(str[i], s2);
					}
				}
			}
		}
	}

	// check if can calculate in stack last options
	if (stack_is_empty(s1) == 0) {

		calculate(s1, s2, str[i]);
		pop(s1, &temp);
		free(s1);
		free(s2);
	}

}
// print operetion order
void calculate(stack* s1, stack* s2, char c) {
	int result;
	char temp;
	while (stack_is_empty(s2) == 0) {
		stack_top(s2, &temp);
		result = getPreorities(temp, c);
		if (result) {
			push(todo(s1, s2), s1);
		}
		else {
			break;
		}
	}
}
// print the output
char todo(stack* s1, stack* s2) {
	char temp, temp1, temp2, temp3;

	pop(s2, &temp2);

	pop(s1, &temp);
	pop(s1, &temp1);

	temp3 = getChar();
	printf("%C%C%C=%C\n", temp1, temp2, temp, temp3);
	return temp3;
}
// check who is bigger
int getPreorities(char a, char b) {

	if (preoretyId(a) >= preoretyId(b))
		return 1;
	else
		return 0;
}
// set preority
int preoretyId(char c) {

	switch (c)
	{
	case '-':
		return 0;

	case '+':
		return 1;
	case '/':
		return 2;

	case '*':
		return 3;
	case '^':
		return 4;
	default: return -1;
	}
}
// get the nex ver  calculation
char getChar() {
	char c;
	c = ASCIICode;
	ASCIICode--;
	return (char)c;
}
// 1 char  , 0 operator , -1 not a char
int isNumOrOperator(char c) {

	if ((c >= 'A'&& c <= 'Z') || (c >= '0' && c <= '9')) {
		return 1;
	}
	else {
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			return 0;
		}
		else
		{
			return -1;
		}
	}


}

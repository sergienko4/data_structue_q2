#include <stdlib.h>

#include "Polynomial.h"

Polynomial* create_polynomial() {
	Polynomial* p = malloc(sizeof(Polynomial));
	p->next = NULL;
	p->base = 0;
	p->pow = 0;
	p->prev = NULL;

	return p;
}
void add_polynomial(Polynomial** head, double base, unsigned int pow) {

	
	Polynomial* temp = *head;

	if (temp ->base == 0 && temp->pow==0) {
		temp->base = base;
		temp->pow= pow;
	}
	else
	{
		if (temp->pow > pow) {
			linkChain(temp, base, pow);
		}
		else
		{
			while (temp->next != NULL) {
				if (temp->next->pow == pow) {
					temp->next->base+= base;
					break;
				}
				else {
					temp = temp->next;
				}
			}
			if (temp->pow < pow && temp->next == NULL) {
				linkChain(temp, base, pow);
			}
		}
	}
}

linkChain(Polynomial* temp, double base, unsigned int pow) {
	Polynomial* newCain = NULL;

	newCain = create_polynomial();
	newCain->base = base;
	newCain->pow = pow;
	newCain->prev = temp;
	temp->next = newCain;
}
Polynomial* Plus_polynomial(Polynomial* P1, Polynomial* P2) {
	return NULL;
}
Polynomial* minus_polyknomial(Polynomial* P1, Polynomial* P2) { return NULL; }
Polynomial* multyplay_polynomial(Polynomial* P1, Polynomial* P2) { return 0; }
int get_Power_polynomial(Polynomial* head) { return  0; }
void remove_power_polynomial(Polynomial** head) {}
void Print_polynomial(Polynomial* head) {}
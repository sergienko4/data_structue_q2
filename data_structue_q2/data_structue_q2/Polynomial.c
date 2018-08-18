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

	if (base != 0) {

		if (temp->base == 0 && temp->pow == 0) {
			temp->base = base;
			temp->pow = pow;
		}
		else
		{
			if (temp->pow > pow) {
				linkChainNext(temp, base, pow);
			}
			else
			{
				while (temp->next != NULL) {
					if (temp->next->pow == pow && (temp->base + base != 0)) {
						temp->next->base += base;
						break;
					}
					else {
						if (temp->next->pow > pow && temp->pow < pow) {
							linkChainNext(temp, base, pow);
						}
						temp = temp->next;
					}
				}
				if (temp->pow < pow && temp->next == NULL) {
					linkChainNext(temp, base, pow);
				}
			}
		}
	}
}
void linkChainNext(Polynomial* temp, double base, unsigned int pow) {
	Polynomial* newCain = NULL;
	Polynomial* helper = NULL;
	// set new chain
	newCain = create_polynomial();
	newCain->base = base;
	newCain->pow = pow;


	newCain->prev = temp;
	helper = temp->next;
	if (helper != NULL) {
		helper->prev = newCain;
		newCain->next = helper;
	}
}
Polynomial* plus_polynomial(Polynomial* P1, Polynomial* P2)
{
	Polynomial* list = create_polynomial();

	while (P1 != NULL && P2 != NULL)
	{
		if (P1->pow == P2->pow) {
			add_polynomial(&list, (P1->base + P2->base), P1->pow);
		}
		else {
			add_polynomial(&list, P1->base, P1->pow);
			add_polynomial(&list, P2->base, P2->pow);
		}

		P1 = P1->next;
		P2 = P2->next;

	}

	while (P1 != NULL) {
		add_polynomial(&list, P1->base, P1->pow);
		P1 = P1->next;
	}
	while (P2 != NULL) {
		add_polynomial(&list, P2->base, P2->pow);
		P2 = P2->next;
	}

	return list;

}
Polynomial* minus_polynomial(Polynomial* P1, Polynomial* P2) {

	Polynomial* list = create_polynomial();

	while (P1 != NULL && P2 != NULL)
	{
		if (P1->pow == P2->pow) {
			add_polynomial(&list, (P1->base - P2->base), P1->pow);
		}
		else {
			add_polynomial(&list, P1->base, P1->pow);
			add_polynomial(&list, (-P2->base), P2->pow);
		}

		P1 = P1->next;
		P2 = P2->next;

	}

	while (P1 != NULL) {
		add_polynomial(&list, P1->base, P1->pow);
		P1 = P1->next;
	}
	while (P2 != NULL) {
		add_polynomial(&list, (-P2->base), P2->pow);
		P2 = P2->next;
	}

	return list;


}
Polynomial* multyplay_polynomial(Polynomial* P1, int c) {
	Polynomial* list = create_polynomial();
	Polynomial* head = NULL;
	if (c == 0) {
		return list;
	}

	while (P1 != NULL) {
		add_polynomial(&list, ((P1->base)*c), P1->pow);
		if (head == NULL) {
			head = list;
		}
		P1 = P1->next;
	}
	return head;
}
int get_Power_polynomial(Polynomial* head) {
	if (head == NULL || head->base == 0 && head->pow == 0)
		return -1;

	if (head->next == NULL) {
		return head->pow;
	}
	else {
		while (head->next != NULL)
		{
			head = head->next;
		}
	}
	return head->pow;
}
void reset_power_polynomial(Polynomial* head) {

	if (head != NULL) {
		head->base = 0;
		head->pow = 0;
		remove_chain_memorry(head->next);
		head->next = NULL;
	}





}
void print_polynomial(Polynomial* head) {

	int counter = 0;
	while (head->next != NULL)
	{
		head = head->next;
	}


	while (head->prev != NULL)
	{

		if (counter == 0) {
			if (head->base > 0) {
				if (head->base == 1) {
					printf("x^%u ", head->pow);
				}
				else {
					printf("%.0lfx^%u ", head->base, head->pow);
				}
			}
			else
			{
				if (head->base == -1) {
					printf("- x^%u ", head->pow);
				}
				else {
					printf("- %.0lfx^%u ", head->base, head->pow);
				}
			}

		}
		else {
			if (head->base == 1) {
				printf("+x^%u ", head->pow);
			}
			else {
				if (head->base ==-1)
					printf("- x^%u ", head->pow);
				else {
					printf("%.0lfx^%u ", head->base, head->pow);

				}
			}
		}


		counter++;
		head = head->prev;
	}
	if (head->pow == 0) {
		if(head->base>0)
		printf("+%lf ", head->base);
		else
			printf("%lf ", head->base);

	}
	else {
		if(head->base>0)
		printf("+%.0lfx^%u ", head->base, head->pow);
	}



}

void remove_chain_memorry(Polynomial* head) {

	Polynomial* temp = NULL;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

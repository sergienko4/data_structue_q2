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
	Polynomial* prevT = NULL;
	Polynomial* nextT = NULL;

	if (base != 0) {

		if (temp->base == 0 && temp->pow == 0) {
			temp->base = base;
			temp->pow = pow;
			return;
		}

		if (temp->pow == pow) {

			if (temp->base + base != 0) {
				temp->base += base;
				return;
			}
			else {

				if ((*head)->next != NULL) {
					head = (*head)->next;
					free(temp);
				}
				else
				{
					reset_power_polynomial(temp);
				}
			}
		}
		else
		{
			if (temp->pow > pow) {
				linkChainNext(&temp, base, pow);
				*head = temp;
			}
			else
			{
				while (temp->next != NULL) {

					/*if (temp->pow == pow) {
						if (temp->base + base != 0) {
							temp->base += base;
							return;
						}
						else {
							prevT = temp->prev;
							nextT = temp->next;

							if (temp->prev != NULL) {
								prevT->next = nextT;
							}
							if (nextT->prev != NULL) {
								nextT->prev = prevT;
							}
							free(temp);
							return;
						}
					}*/

					if (temp->next->pow == pow && (temp->next->base + base != 0)) {
						temp->next->base += base;
						return;
					}

					else if (temp->next->pow == pow && (temp->next->base + base == 0))
					{
						nextT = temp->next;
						if (temp->next->next != NULL) {
							temp->next->next->prev = temp;
						}
						temp->next = temp->next->next;
						free(nextT);
						return;
					}

					if (temp->next->pow > pow && temp->pow < pow) {
						linkChainNext(&temp, base, pow);
					}
					temp = temp->next;
				}
				if (temp->pow < pow && temp->next == NULL) {
					prevT = temp->prev;
					linkChainNext(&temp, base, pow);
					if (prevT != NULL) {
						*head = prevT;
					}
					else {
						*head = temp;

					}
				}
			}
		}
	}
}
void linkChainNext(Polynomial** head, double base, unsigned int pow) {

	Polynomial* temp = NULL;
	Polynomial* temp1 = NULL;
	Polynomial* prevT = NULL;
	Polynomial* nextT = NULL;

	// set new chain
	Polynomial* newCain = create_polynomial();
	newCain->base = base;
	newCain->pow = pow;


	if ((*head)->base == 0 && (*head)->pow == 0) {
		(*head) = newCain;
		return;
		//return (*head);
	}
	if ((*head)->pow > newCain->pow) {
		newCain->next = (*head);
		(*head)->prev = newCain;
		*head = newCain;
		return;
		//return newCain;
	}

	if ((*head)->next == NULL) {
		(*head)->next = newCain;
		newCain->prev = (*head);
		return;
		//return (*head);                                                                  
	}
	temp = *head;
	while (temp->next != NULL && temp->next->pow < newCain->pow) {
		if (temp->next->pow < newCain->pow) {
			temp = temp->next;
		}
	}

	nextT = temp->next;
	newCain->next = nextT;

	if (nextT != NULL) {
		nextT->prev = newCain;
	}


	temp->next = newCain;
	newCain->prev = temp;

	/*newCain->prev = temp;
	newCain->next = temp1;
	if (temp1->prev != NULL) {
		temp1->prev = newCain;
	}*/
	//*head = temp;
	//return temp;


	//Polynomial* newCain = NULL;
	//Polynomial* helper = NULL;
	//// set new chain
	//newCain = create_polynomial();
	//newCain->base = base;
	//newCain->pow = pow;


	//newCain->prev = temp;
	//helper = temp->next;
	//if (helper != NULL) {
	//	helper->prev = newCain;
	//	newCain->next = helper;
	//}
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


	while (head != NULL)
	{

		if (head->base == 1 || head->base == -1) {
			if (head->next == NULL) {
				printf("x^%u ", head->pow);
			}
			else {
				printf("+x^%u ", head->pow);
			}
		}

		else if (head->base > 0) {
			printf("+%.0lfx^%u ", head->base, head->pow);

		}
		else {
			printf("-x^%u ", head->pow);

		}
		head = head->prev;
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

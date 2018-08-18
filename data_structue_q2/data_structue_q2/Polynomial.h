
typedef struct polynomial
{
	double base;
	unsigned int pow;
	struct polynomial *next;
	struct polynomial *prev;
}	Polynomial;

Polynomial* create_polynomial();
void add_polynomial(Polynomial** head, double base, unsigned int pow);
Polynomial* Plus_polynomial(Polynomial* P1, Polynomial* P2);
Polynomial* minus_polynomial(Polynomial* P1, Polynomial* P2);
Polynomial* multyplay_polynomial(Polynomial* P1, Polynomial* P2);
int get_Power_polynomial(Polynomial* head);
void remove_power_polynomial(Polynomial** head);
void Print_polynomial(Polynomial* head);
//echo command line arguments K&R pg 15
//https://www.codeproject.com/Questions/1205546/How-do-I-store-argv-command-line-inputs-in-an-arra
#include <stdlib.h>     /* atoi */
#include <stdio.h>
#include <ctype.h> //isdigit
#define NUMBER '0'
const int MAXNUM = 100;
int getch(void);
void ungetch(int);
int getop(char[]);
void push(double);
void pop(void); //K&R pg 76

int main(int argc, char *argv[])
{
	char array_of_char[MAXNUM];
	int type;
	double op2; // K&R pg 77. op2 needs new name.
	int i=0;

	for (i = 1; i < argc && i < MAXNUM; i++)
	{
		/*switch (type) 
		{
		case NUMBER:
			array_of_char[i] = atoi(argv[i]);
			break;
		default:
			printf("Problem: defaulted in switch");
			break;
		}
		*/
		//array_of_char[i] = atoi(argv[i]);
		array_of_char[i] = atoi(argv[i]);
		printf("%d ", array_of_char[i]);
	}	
	return 0;
}

//getop: next operator or numeric operand
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		; //skip white space

	s[1] = '\0'; //don't understand this part yet
	if (!isdigit(c) && c != '.')
		return c; //not a number
	i = 0;
	if (isdigit(c)) //collect integer part
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c!= EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100 
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0)? buf[--bufp]: getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

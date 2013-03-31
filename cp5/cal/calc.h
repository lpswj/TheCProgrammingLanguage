#define NUMBER '0'	/* signal that a number was found */
#define IDENTIFIER '1'

int getop(char s[]);
void push(double);
double pop(void);
double printop(void);
double printstack(void);
void copy(void);
void swap(void);
void clear(void);
void dealWithName(char s[]);
int getch(void);
void ungetch(int);


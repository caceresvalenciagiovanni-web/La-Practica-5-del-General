typedef struct Symbol { /* entrada en la tabla de símbolos */
char    *name;
short   type;   /* VAR, BLTIN, UNDEF */
union {
double val;	/* si es VAR */
double  (*ptr)(double);       /* si es BLTIN */
} u;
struct Symbol   *next;  /* para ligarse a otro */ } Symbol;
Symbol  *install(char *s, int t, double d);
Symbol  *lookup(char *s);

typedef union Datum {   /* tipo de la pila del intérprete */
double  val;
Symbol  *sym; } Datum; 

extern Datum pop();

typedef void (*Inst)(void);  /* instrucción de maquina */ 

#define STOP    (Inst) 0

extern	Inst prog[ ], *progp;
extern	Inst *code(Inst f);

extern	void eval(void);
extern	void add(void);
extern	void sub(void); 
extern	void mul(void); 
extern	void div(void); 
extern	void negate(void); 
extern	void power(void);
extern	void assign(void); 
extern	void bltin(void); 
extern	void varpush(void); 
extern	void constpush(void);
extern	void print(void);
extern	void pop1(void);

extern	void prexpr(void);
extern	void gt(void);
extern	void lt(void); 
extern	void eq(void); 
extern	void ge(void); 
extern	void le(void); 
extern	void ne(void); 
extern	void and(void); 
extern	void or(void);
extern	void not(void);
extern	void ifcode(void); 
extern	void whilecode(void);
void execute(Inst *p);
void execerror(char *s, char *t);

%{
	using namespace std;
	#include <iostream>
	#include <stdio.h>
	#include <string.h>

	int yylex();
    int yyparse();
	int yyerror(const char *msg);

    int EsteCorecta = 1;
	char msg[500];
    extern int yylineno;
	int bucla = 0;
	int conditie = -2;
	class TVAR
	{
		char* nume;
		int valoare;
		double val1;
		float val2;
		TVAR* next;
		int type;
		bool inBucla;
	  
		public:
			static TVAR* head;
			static TVAR* tail;

			TVAR(char* n, double v = -1, int type = 0, bool inBucla = 0);
			TVAR();
			int exists(char* n);
			void add(char* n, double v = -1, int type = 0);

			template <typename T>
			T getValue(char* n);

			int tip(char* n);
			void setValue(char* n, int v);
			void setValue(char* n, double v);
			void setValue(char* n, float v);
			void setBucla(char* n, bool inBucla);
			void printVars();
			void deleteNodesInBucla();
	};

	TVAR* TVAR::head;
	TVAR* TVAR::tail;

	TVAR::TVAR(char* n, double v, int type, bool inBucla)
	{
		this->nume = new char[strlen(n)+1];
		strcpy(this->nume,n);
		this->inBucla = inBucla;
		this->type = type;
		if (type == 0) 
			this->valoare = (int)v;
		else if (type == 1) 
			this->val1 = (double)v;
		else if (type == 2) 
			this->val2 = (float)v;
		this->next = NULL;
	}

	TVAR::TVAR()
	{
		TVAR::head = NULL;
		TVAR::tail = NULL;
	}
	
	int TVAR::exists(char* n)
	{
		TVAR* tmp = TVAR::head;
		while(tmp != NULL) 
		{ 
			if(strcmp(tmp->nume,n) == 0)
	      		return 1;
        	tmp = tmp->next;
	  	}
	  	return 0;
	}

    void TVAR::add(char* n, double v, int type)
	{
		TVAR* elem = new TVAR(n, v, type);
		if(head == NULL)
		{ 
			TVAR::head = TVAR::tail = elem;
		}
		else 
		{
			TVAR::tail->next = elem;
			TVAR::tail = elem;
		}
	}

	template <>
	int TVAR::getValue<int>(char* n) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0)
				return tmp->valoare;
			tmp = tmp->next;
		}
		return -1;
	}
	template <>
	double TVAR::getValue<double>(char* n) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0)
				return static_cast<double>(tmp->val1);
			tmp = tmp->next;
		}
			return -1.0;
	}
	template <>
	float TVAR::getValue<float>(char* n) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0)
				return static_cast<double>(tmp->val2);
			tmp = tmp->next;
		}
			return -1.0;
	}
	void TVAR::setValue(char* n, int v) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0) {
				tmp->valoare = v;
			}
			tmp = tmp->next;
		}
	}

	void TVAR::setValue(char* n, double v) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0) {
				tmp->val1 = v;
			}
			tmp = tmp->next;
		}
	}

	void TVAR::setValue(char* n, float v) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0) {
				tmp->val2 = v;
			}
			tmp = tmp->next;
		}
	}

	void TVAR::printVars()
	{
		cout<<"\nPrinting table of variables...\n";
		TVAR* tmp = TVAR::head;
		while(tmp != NULL)
		{
			if (tmp->type == 0) 
				cout<<tmp->nume<<"="<<tmp->valoare<<"\n";
			else if (tmp->type == 1) 
				cout<<tmp->nume<<"="<<tmp->val1<<"\n";
			else if (tmp->type == 2) 
				cout<<tmp->nume<<"="<<tmp->val2<<"\n";
			tmp = tmp->next;
		}	  
	}

	int TVAR::tip(char* n){
		TVAR* tmp = TVAR::head;
	    while(tmp != NULL)
	    {
			if(strcmp(tmp->nume, n) == 0)
			{
				if (tmp->type == 0) 
					return 0;
				else if (tmp->type == 1) 
					return 1;
				else if (tmp->type == 2) 
					return 2;
			}
			tmp = tmp->next;
	    }
		return 1;
	}

	void TVAR::deleteNodesInBucla() {
		TVAR* current = TVAR::head;
		TVAR* prev = NULL;
		bucla = 0;

		while (current != NULL)
		{
			if (current->inBucla)
			{
				if (prev == NULL)
				{
					TVAR::head = current->next;
				}
				else
				{
					prev->next = current->next;
				}
				delete[] current->nume;
				delete current;
				current = (prev == NULL) ? TVAR::head : prev->next;
			}
			else
			{
				prev = current;
				current = current->next;
			}
		}
		if (prev != NULL)
		{
			TVAR::tail = prev;
		}
	}

	void TVAR::setBucla(char* n, bool inBucla) {
		TVAR* tmp = TVAR::head;
		while (tmp != NULL) {
			if (strcmp(tmp->nume, n) == 0) {
				tmp->inBucla = inBucla;
				return;
			}
			tmp = tmp->next;
		}
	}

	TVAR* ts = NULL;
%}
//http://labs.cs.upt.ro/labs/lft/html/LFT07bis.htm#declaratii_C
//https://github.com/leonardolariu/c-interpreter/blob/master/compiler/calc.l

%code requires {
	typedef struct expressionInfo {
		const char *type;
		char *sir;
	    int ival;
	    float fval;
        double dval;
	} expressionInfo;
}

%union  { 
    char* sir;
	char* str;
	char* ss;
    int ival; 
    float fval;
	double dval;
	struct expressionInfo info;
}


%token TOK_PRINT TOK_READ TOK_ERROR TOK_GHILIMEA TOK_RETURN TOK_SINGLE TOK_MULTI
%token TOK_IF TOK_ELSE TOK_WHILE
%token TOK_INT TOK_DOUBLE TOK_FLOAT
%token <sir> TOK_ID TOK_FUNC
%token <str> STRING_LITERAL 
%token TOK_GT TOK_LT TOK_EQ TOK_GE TOK_LE
%token <ival> INT_VAL
%token <fval> FLOAT_VAL
%token <dval> DOUBLE_VAL
%type <info> rightSide expression operand termen
%type <ss> rel_op
%start S

%left '+' '-'
%left '*' '/'

%%
S : { printf("Corect\n"); }
	| I ';' S
	| statement S //{ ts->printVars(); }
	| comment S
	| functie S
    | TOK_ERROR { EsteCorecta = 0; }
    ;
I :	I declarare
    | I atribuire { ts->printVars(); }
    | I print
	| I read
	| I decl
	| I expression
	| print 	//{ printf("Printf\n"); }
	| read
	| atribuire //{ printf("Atribuire\n"); }
    | declarare //{ printf("Declarare\n"); }
	| expression {
		if (strcmp($1.type, "int") == 0) { //int
			cout<< $1.ival <<endl;
		}else if (strcmp($1.type, "double") == 0) { //double
			cout<< $1.dval <<endl;
		} else if (strcmp($1.type, "float") == 0) { //float
			cout<< $1.fval <<endl;
		}
	}
	| decl
    ;

comment: TOK_SINGLE
		| TOK_MULTI
		;

functie : TOK_INT TOK_FUNC parameter_list ')' '{' TOK_RETURN expression ';' '}'
		{ 
			ts->deleteNodesInBucla(); 
		} 
		| TOK_FLOAT TOK_FUNC parameter_list ')' '{' TOK_RETURN expression ';' '}'
		{ 
			ts->deleteNodesInBucla(); 
		}
		| TOK_DOUBLE TOK_FUNC parameter_list ')' '{' TOK_RETURN expression ';' '}'
		{ 
			ts->deleteNodesInBucla(); 
		}
		;

parameter_list: decl
				| parameter_list ',' decl
				;

decl : TOK_INT TOK_ID {
	if(ts != NULL)
		{
			if(ts->exists($2) == 0)
			{
				ts->add($2, -1, 0);
				cout<< $2 << "="<<ts->getValue<int>($2)<<endl;
			}
			else
			{
				sprintf(msg,"Eroare semantica: Declaratii multiple pentru variabila %s!", $2);
				yyerror(msg);
				YYERROR;
			}
		}
		else
		{
			ts = new TVAR();
			ts->add($2, -1, 0);
			cout<< $2 << "="<< ts->getValue<int>($2)<<endl;
		}
	 }
		| TOK_FLOAT TOK_ID {
			if(ts != NULL)
		{
			if(ts->exists($2) == 0)
			{
				ts->add($2, -1, 2);
				cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
			}
			else
			{
				sprintf(msg,"Eroare semantica: Declaratii multiple pentru variabila %s!", $2);
				yyerror(msg);
				YYERROR;
			}
		}
		else
		{
			ts = new TVAR();
			cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
		}
	  }
		| TOK_DOUBLE TOK_ID {
			if(ts != NULL)
		{
			if(ts->exists($2) == 0)
			{
				ts->add($2, -1, 1);
				cout<< $2 << "="<< ts->getValue<double>($2)<<endl;
			}
			else
			{
				sprintf(msg,"Eroare semantica: Declaratii multiple pentru variabila %s!", $2);
				yyerror(msg);
				YYERROR;
			}
		}
		else
		{
			ts = new TVAR();
			ts->add($2, -1, 1);
			cout<< $2 << "="<<  ts->getValue<double>($2)<<endl;
		}
	  }
		;

declarare :    TOK_INT TOK_ID '=' INT_VAL {
				if (conditie == -2 || conditie == 0 || conditie == 1){
					if(ts != NULL)
					{	
						if(ts->exists($2) == 0){
							ts->add($2, $4, 0);
							cout<< $2 << "="<<  ts->getValue<int>($2)<<endl;
						}
						else if(ts->exists($2) == 1)
						{
							ts->setValue($2, $4);
							cout<< $2 << "="<<  ts->getValue<int>($2)<<endl;
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
							yyerror(msg);
							YYERROR;
						}
						if(bucla == 1)
							ts->setBucla($2, true);
						else ts->setBucla($2, false);
					}
					else
					{
						ts = new TVAR();
						ts->add($2, $4, 0);
						cout<< $2 << "="<< ts->getValue<int>($2)<<endl;
						if(bucla == 1)
							ts->setBucla($2, true);
						else ts->setBucla($2, false);
					}
				}
				}
			|	TOK_FLOAT TOK_ID '=' FLOAT_VAL {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts != NULL)
					{	
						if(ts->exists($2) == 0){
							ts->add($2, $4, 2);
							cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
						}
						else if(ts->exists($2) == 1)
						{
							ts->setValue($2, $4);
							cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
							yyerror(msg);
							YYERROR;
						}
						if(bucla == 1)
							ts->setBucla($2, true);
						else ts->setBucla($2, false);
					}
					else
					{
						ts = new TVAR();
						ts->add($2, $4, 2);
						cout<< $2 << "="<<  ts->getValue<float>($2)<<endl;
						if(bucla == 1)
							ts->setBucla($2, true);
						else ts->setBucla($2, false);
					}
			}
			}
            |	TOK_DOUBLE TOK_ID '=' DOUBLE_VAL {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts != NULL)
					{	
						if(ts->exists($2) == 0){
							ts->add($2, $4, 1);
							cout<< $2 << "="<< ts->getValue<double>($2)<<endl;
						}
						else if(ts->exists($2) == 1)
						{
							ts->setValue($2, $4);
							cout<< $2 << "="<< ts->getValue<double>($2)<<endl;
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
							yyerror(msg);
							YYERROR;
						}
						if(bucla == 1)
							ts->setBucla($2, true);
						else ts->setBucla($2, false);
					}
					else
					{
						ts = new TVAR();
						ts->add($2, $4, 1);
						cout<< $2 << "="<<  ts->getValue<double>($2)<<endl;
						if(bucla == 1)
							ts->setBucla($2, true);
						else ts->setBucla($2, false);
					}
				}
			}
			| TOK_INT TOK_ID '=' '(' TOK_INT ')' TOK_ID{
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts->exists($2) == 0){
					if(ts->exists($7) == 0){
						printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $7);
					} else if(ts->exists($7) == 1){
						if (ts->tip($7) == 0) {//int
							int tmp = ts->getValue<int>($7);
							ts->add($2, tmp, 0);
							cout<< $2 << "="<< ts->getValue<int>($2)<<endl;
						}else if (ts->tip($7) == 1) {//double
							double tmp = ts->getValue<double>($7);
							int tmp1 = (int)tmp;
							ts->add($2, tmp1, 0);
							cout<< $2 << "="<< ts->getValue<int>($2)<<endl;
						}else if (ts->tip($7) == 2) {//float
							float tmp = ts->getValue<float>($7);
							int tmp1 = (int)tmp;
							ts->add($2, tmp1, 0);
							cout<< $2 << "="<< ts->getValue<int>($2)<<endl;
						}
					}
				} else {
					sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
					yyerror(msg);
					YYERROR;
				}
				if(bucla == 1)
					ts->setBucla($2, true);
				else ts->setBucla($2, false);
				}
			}
			| TOK_FLOAT TOK_ID '=' '(' TOK_FLOAT ')' TOK_ID{
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts->exists($2) == 0){
					if(ts->exists($7) == 0){
						printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $7);
					} else if(ts->exists($7) == 1){
						if (ts->tip($7) == 0) {//int
							int tmp = ts->getValue<int>($7);
							float tmp1 = (float)tmp;
							ts->add($2, tmp1, 2);
							cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
						}else if (ts->tip($7) == 1) {//double
							double tmp = ts->getValue<double>($7);
							float tmp1 = (float)tmp;
							ts->add($2, tmp1, 2);
							cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
						}else if (ts->tip($7) == 2) {//float
							float tmp = ts->getValue<float>($7);
							ts->add($2, tmp, 2);
							cout<< $2 << "="<< ts->getValue<float>($2)<<endl;
						}
					}
				} else {
					sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
					yyerror(msg);
					YYERROR;
				}
				if(bucla == 1)
					ts->setBucla($2, true);
				else ts->setBucla($2, false);
				}
			}
			| TOK_DOUBLE TOK_ID '=' '(' TOK_DOUBLE ')' TOK_ID{
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts->exists($2) == 0){
					if(ts->exists($7) == 0){
						printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $7);
					} else if(ts->exists($7) == 1){
						if (ts->tip($7) == 0) {//int
							int tmp = ts->getValue<int>($7);
							double tmp1 = (double)tmp;
							ts->add($2, tmp1, 1);
							cout<< $2 << "="<< ts->getValue<double>($2)<<endl;
						}else if (ts->tip($7) == 1) {//double
							double tmp = ts->getValue<double>($7);
							ts->add($2, tmp, 1);
							cout<< $2 << "="<< ts->getValue<double>($2)<<endl;
						}else if (ts->tip($7) == 2) {//float
							float tmp = ts->getValue<float>($7);
							double tmp1 = (double)tmp;
							ts->add($2, tmp1, 1);
							cout<< $2 << "="<< ts->getValue<double>($2)<<endl;
						}
					}
				} else {
					sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
					yyerror(msg);
					YYERROR;
				}
				if(bucla == 1)
					ts->setBucla($2, true);
				else ts->setBucla($2, false);
				}
			}
			| TOK_INT TOK_ID '=' TOK_FUNC INT_VAL ',' INT_VAL ')' {}
			| TOK_DOUBLE TOK_ID '=' TOK_FUNC TOK_DOUBLE ',' TOK_DOUBLE ')' {}
			| TOK_DOUBLE TOK_FLOAT '=' TOK_FUNC TOK_FLOAT ',' TOK_FLOAT ')' {}
			;

atribuire : 	TOK_ID '=' rightSide {
					if (conditie == -2 || conditie == 0 || conditie == 1){
					if(ts != NULL)
					{	
						if(ts->exists($1) == 1)
						{
							if (strcmp($3.type, "int") == 0) { //int
								ts->setValue($1, $3.ival);
								cout<< $1 << "="<< $3.ival <<endl;
							}else if (strcmp($3.type, "double") == 0) { //double
								ts->setValue($1, $3.dval);
								cout<< $1 << "="<<  $3.dval <<endl;
							} else if (strcmp($3.type, "float") == 0) { //float
								ts->setValue($1, $3.fval);
								cout<< $1 << "="<<  $3.fval <<endl;
							}
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $1);
							yyerror(msg);
							YYERROR;
						}
					}
				}
				}
		   		;
				
rightSide : 	TOK_ID '=' rightSide {
					if(ts != NULL)
					{	
						if(ts->exists($1) == 1)
						{
							if (strcmp($3.type, "int") == 0) { //int
								ts->setValue($1, $3.ival);
								cout<< $1 << "="<< $3.ival <<endl;
							}else if (strcmp($3.type, "double") == 0) { //double
								ts->setValue($1, $3.dval);
								cout<< $1 << "="<<  $3.dval <<endl;
							} else if (strcmp($3.type, "float") == 0) { //float
								ts->setValue($1, $3.fval);
								cout<< $1 << "="<<  $3.fval <<endl;
							}
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $1);
							yyerror(msg);
							YYERROR;
						}
					}
			 	}
		  | 	expression {
					if (strcmp($1.type, "int") == 0) { //int
						$$.type = "int";
						$$.ival = $1.ival;
					}else if (strcmp($1.type, "double") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval;
					} else if (strcmp($1.type, "float") == 0) { //float
						$$.type = "float";
						$$.fval = $1.fval;
					}
		  		}
		  ;
expression : 	expression '+' termen {
					if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) { //int
						$$.type = "int";
						$$.ival = $1.ival + $3.ival;
					} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "float") == 0) { //float
						$$.type = "float";
						$$.fval = $1.fval + $3.fval;
					} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "double") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval + $3.dval;
					} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "double") == 0) { //double
						$$.type = "double";
						$$.dval = $1.ival + $3.dval;
					} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "int") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval + $3.ival;
					} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "float") == 0) { //double
						$$.type = "float";
						$$.fval = $1.ival + $3.fval;
					} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "int") == 0) { //double
						$$.type = "float";
						$$.fval = $1.fval + $3.ival;
					} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "float") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval + $3.fval;
					} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "double") == 0) { //double
						$$.type = "float";
						$$.fval = $1.fval + $3.dval;
					} else if (strcmp($1.type, "string") == 0) //string
						printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
				}
		   | 	expression '-' termen {
					if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) { //int
						$$.type = "int";
						$$.ival = $1.ival - $3.ival;
					} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "float") == 0) { //float
						$$.type = "float";
						$$.fval = $1.fval - $3.fval;
					} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "double") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval - $3.dval;
					} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "double") == 0) { //double
						$$.type = "double";
						$$.dval = $1.ival - $3.dval;
					} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "int") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval - $3.ival;
					} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "float") == 0) { //double
						$$.type = "float";
						$$.fval = $1.ival - $3.fval;
					} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "int") == 0) { //double
						$$.type = "float";
						$$.fval = $1.fval - $3.ival;
					} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "float") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval - $3.fval;
					} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "double") == 0) { //double
						$$.type = "float";
						$$.fval = $1.fval - $3.dval;
					} else if (strcmp($1.type, "string") == 0) //string
						printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
				}
		   | 	termen {
					if (strcmp($1.type, "int") == 0) { //int
						$$.type = "int";
						$$.ival = $1.ival;
					}else if (strcmp($1.type, "double") == 0) { //double
						$$.type = "double";
						$$.dval = $1.dval;
					} else if (strcmp($1.type, "float") == 0) { //float
						$$.type = "float";
						$$.fval = $1.fval;
					}
		   		}
		   ;

termen : 	termen '*' operand {
				if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) { //int
					$$.type = "int";
					$$.ival = $1.ival * $3.ival;
				} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "float") == 0) { //float
					$$.type = "float";
					$$.fval = $1.fval * $3.fval;
				} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "double") == 0) { //double
					$$.type = "double";
					$$.dval = $1.dval * $3.dval;
				} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "double") == 0) { //double
					$$.type = "double";
					$$.dval = $1.ival * $3.dval;
				} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "int") == 0) { //double
					$$.type = "double";
					$$.dval = $1.dval * $3.ival;
				} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "float") == 0) { //double
					$$.type = "float";
					$$.fval = $1.ival * $3.fval;
				} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "int") == 0) { //double
					$$.type = "float";
					$$.fval = $1.fval * $3.ival;
				} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "float") == 0) { //double
					$$.type = "double";
					$$.dval = $1.dval * $3.fval;
				} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "double") == 0) { //double
					$$.type = "float";
					$$.fval = $1.fval * $3.dval;
				} else if (strcmp($1.type, "string") == 0) //string
					printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
			}

	   | 	termen '/' operand {
				if (strcmp($1.type, "int") == 0 && strcmp($3.type, "int") == 0) { //int
					$$.type = "int";
					if($3.ival == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {$$.ival = $1.ival / $3.ival;}
				} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "float") == 0) { //float
					$$.type = "float";
					if($3.fval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {$$.fval = $1.fval / $3.fval;}
				} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "double") == 0) { //double
					$$.type = "double";
					if($3.dval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {$$.dval = $1.dval / $3.dval;}
				} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "double") == 0) { //double
					$$.type = "double";
					if($3.dval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						$$.dval = $1.ival / $3.dval;
					}
				} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "int") == 0) { //double
					$$.type = "double";
					if($3.ival == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else { 
						$$.dval = $1.dval / $3.ival;
					}
				} else if (strcmp($1.type, "int") == 0 && strcmp($3.type, "float") == 0) { //double
					$$.type = "float";
					if($3.fval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else { 
						$$.fval = $1.ival / $3.fval;
					}
				} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "int") == 0) { //double
					$$.type = "float";
					if($3.ival == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						$$.fval = $1.fval / $3.ival;
					}
				} else if (strcmp($1.type, "double") == 0 && strcmp($3.type, "float") == 0) { //double
					$$.type = "double";
					if($3.fval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						$$.dval = $1.dval / $3.fval;
					}
				} else if (strcmp($1.type, "float") == 0 && strcmp($3.type, "double") == 0) { //double
					$$.type = "float";
					if($3.dval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						$$.fval = $1.fval / $3.dval;
					}
				} else if (strcmp($1.type, "string") == 0) //string
					printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
	   		}
	   | 	operand {
				if (strcmp($1.type, "int") == 0) { //int
					$$.type = "int";
					$$.ival = $1.ival;
				}else if (strcmp($1.type, "double") == 0) { //double
					$$.type = "double";
					$$.dval = $1.dval;
				} else if (strcmp($1.type, "float") == 0) { //float
					$$.type = "float";
					$$.fval = $1.fval;
				}
			}
	   ;

operand : 	TOK_ID {
				if(ts->exists($1) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $1);
				} else if(ts->exists($1) == 1){
					if (ts->tip($1) == 0) {//int
						$$.type = "int";
						$$.ival = ts->getValue<int>($1);
					}else if (ts->tip($1) == 1) {//double
						$$.type = "double";
						$$.dval = ts->getValue<double>($1);
					}else if (ts->tip($1) == 2) {//float
						$$.type = "float";
						$$.fval = ts->getValue<float>($1);
					}
				}
			}
		|  '(' TOK_INT ')' TOK_ID{
				if(ts->exists($4) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $4);
				} else if(ts->exists($4) == 1){
					if (ts->tip($4) == 0) {//int
						$$.type = "int";
						$$.ival = ts->getValue<int>($4);
					}else if (ts->tip($4) == 1) {//double
						$$.type = "int";//set tip int
						double tmp = ts->getValue<double>($4);
						int tmp1 = (int)tmp;
						$$.ival = tmp1;
					}else if (ts->tip($4) == 2) {//float
						$$.type = "int";//set tip int
						float tmp = ts->getValue<float>($4);
						int tmp1 = (int)tmp;
						$$.ival = tmp1;
					}
				}
		}
		|  '(' TOK_DOUBLE ')' TOK_ID{
				if(ts->exists($4) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $4);
				} else if(ts->exists($4) == 1){
					if (ts->tip($4) == 0) {//int
						$$.type = "double";
						int tmp = ts->getValue<int>($4);
						double tmp1 = (double)tmp;
						$$.dval = tmp1;
					}else if (ts->tip($4) == 1) {//double
						$$.type = "double";
						$$.dval = ts->getValue<double>($4);
					}else if (ts->tip($4) == 2) {//float
						$$.type = "double";
						float tmp = ts->getValue<float>($4);
						double tmp1 = (double)tmp;
						$$.dval = tmp1;
					}
				}
		}
		|  '(' TOK_FLOAT ')' TOK_ID{
				if(ts->exists($4) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, $4);
				} else if(ts->exists($4) == 1){
					if (ts->tip($4) == 0) {//int
						$$.type = "float";
						int tmp = ts->getValue<int>($4);
						float tmp1 = (float)tmp;
						$$.fval = tmp1;
					}else if (ts->tip($4) == 1) {//double
						$$.type = "float";
						double tmp = ts->getValue<double>($4);
						float tmp1 = (float)tmp;
						$$.fval = tmp1;
					}else if (ts->tip($4) == 2) {//float
						$$.type = "float";
						$$.fval = ts->getValue<float>($4);
					}
				}
		}
		| 	INT_VAL {
				$$.type = "int";
				$$.ival = $1;
			}
		|	FLOAT_VAL {
				$$.type = "float";
				$$.fval = $1;
			}
		|	DOUBLE_VAL {
				$$.type = "double";
				$$.dval = $1;
			}
		;

statement :  if_statement { 
				printf("Block-ul if este corect\n");
			}
			| while_statement { printf("Block-ul while este corect\n");}
			//| block { printf("Block-ul este corect\n"); }
			;

if_statement :
   TOK_IF '(' condition ')' action{
   }
   ;
//1 sau 0
//-1 nu executa nimeni
action : {if(conditie == 0) conditie = -1;} block 
		{
			if(conditie == 1) conditie = -1;
			else if(conditie == -1) conditie = 0;
		} optional_else{
			conditie = -2;
		}
		;

optional_else:
	TOK_ELSE block
	|
	;
while_statement :
   TOK_WHILE '(' condition ')' block
   ;
condition :
   operand rel_op operand{
		double tmp;
		if (strcmp($1.type, "int") == 0) { //int
			tmp = $1.ival;
		}else if (strcmp($1.type, "double") == 0) { //double
			tmp = $1.dval;
		} else if (strcmp($1.type, "float") == 0) { //float
			tmp = $1.fval;
		}
		//cout<< "a="<<tmp<<endl;
		double tmp1;
		if (strcmp($3.type, "int") == 0) { //int
			tmp1 = $3.ival;
		}else if (strcmp($3.type, "double") == 0) { //double
			tmp1 = $3.dval;
		} else if (strcmp($3.type, "float") == 0) { //float
			tmp1 = $3.fval;
		}
		//cout<< "tmp1="<<tmp1<<endl;
		if(strcmp($2, ">") == 0){
			if(tmp > tmp1)
				conditie = 1;
			else conditie = 0;
			//cout<<"conditie=" <<conditie<<endl;
		}else if (strcmp($2, "<") == 0) {
			if(tmp < tmp1)
				conditie = 1;
			else conditie = 0;
		}else if (strcmp($2, "=") == 0) {
			if(tmp == tmp1)
				conditie = 1;
			else conditie = 0;
		}else if (strcmp($2, ">=") == 0) {
			if(tmp >= tmp1)
				conditie = 1;
			else conditie = 0;
		}else if (strcmp($2, "<=") == 0) {
			if(tmp <= tmp1)
				conditie = 1;
			else conditie = 0;
		}
   }
   ;
block : '{' inside '}'
		{
			ts->deleteNodesInBucla();
			//ts->printVars();
		}
		;
inside :
	inside atribuire ';'
	| inside declarare ';'
	| inside print ';'
	| atribuire ';'
	| before declarare ';'
	| print ';'
	;
before :
		{
			bucla = 1;
		}
		;
rel_op :
   TOK_GT{
	 strcpy($$, ">");
   }
	| TOK_LT{
		strcpy($$, "<");
	}
	| TOK_EQ{
		strcpy($$, "=");
	}
	| TOK_GE{
		strcpy($$, ">=");
	}
	| TOK_LE{
		strcpy($$, "<=");
	}
   ;

print :	TOK_PRINT STRING_LITERAL //print "ceva";
		{
			if (conditie == -2 || conditie == 0 || conditie == 1)
				cout<< $2 <<endl;
		}
		| TOK_PRINT  operand//print a;
		{
			if (conditie == -2 || conditie == 0 || conditie == 1){
				if (strcmp($2.type, "int") == 0) //int
					cout<< $2.ival <<endl;
				else if (strcmp($2.type, "double") == 0)//double
					cout<< $2.dval <<endl;
				else if (strcmp($2.type, "float") == 0)//float
					cout<< $2.fval <<endl;
			}
		}
		| TOK_PRINT  STRING_LITERAL ',' operand//print "ceva", a;
		{
			if (conditie == -2 || conditie == 0 || conditie == 1){
				if (strcmp($4.type, "int") == 0) //int
					cout<< $2  << " " <<  $4.ival << endl;
				else if (strcmp($4.type, "double") == 0)//double
					cout<< $2  << " " <<  $4.dval << endl;
				else if (strcmp($4.type, "float") == 0)//float
					cout<< $2  << " " << $4.fval << endl;
			}
		}
		| TOK_PRINT  operand ','  STRING_LITERAL //print a, "ceva";
	  	{
			if (conditie == -2 || conditie == 0 || conditie == 1){
				if (strcmp($2.type, "int") == 0) //int
					cout<< $2.ival << " " << $4 << endl;
				else if (strcmp($2.type, "double") == 0)//double
					cout<< $2.dval << " " << $4 << endl;
				else if (strcmp($2.type, "float") == 0)//float
					cout<< $2.fval << " " << $4 << endl;
			}
		}
	  ;
read: TOK_READ TOK_ID 
	{
		if(ts != NULL)
		{	
			if(ts->exists($2) == 1)
			{
				if (ts->tip($2) == 0) { //int
					int tmp;
					cin >> tmp;
					ts->setValue($2, tmp);
					cout<< $2 << "="<< ts->getValue<int>($2) <<endl;
				}else if (ts->tip($2) == 1) { //double
					double tmp;
					cin >> tmp;
					ts->setValue($2, tmp);
					cout<< $2 << "="<< ts->getValue<double>($2) <<endl;
				} else if (ts->tip($2) == 2) { //float
					float tmp;
					cin >> tmp;
					ts->setValue($2, tmp);
					cout<< $2 << "="<< ts->getValue<float>($2) <<endl;
				}
			}
			else
			{
				sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", $2);
				yyerror(msg);
				YYERROR;
			}
		}
	}
	;
%%

int main()
{
	yyparse();
	
	if(EsteCorecta == 1)
	{
		cout<<"CORECT\n";	
	} else {
		cout<<"INCORECT\n";
	}

	return 0;
}

int yyerror(const char *msg)
{
	fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
	return 1;
}
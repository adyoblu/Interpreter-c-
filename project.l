%option noyywrap
%{
	#include "project.tab.h"
%}
%option yylineno

%%
"+"				{ return '+'; }
"-"				{ return '-'; }
"*"				{ return '*'; }
"/"				{ return '/'; }
"("				{ return '('; }
")"				{ return ')'; }
"{"             { return '{'; }
"}"             { return '}'; }
";"				{ return ';'; }
","             { return ','; }
"="				{ return '='; }
"if"            { return TOK_IF; }
"else"          { return TOK_ELSE; }
"while"         { return TOK_WHILE; }
">="            { return TOK_GE; }
"<="            { return TOK_LE; }
">"             { return TOK_GT; }
"<"             { return TOK_LT; }
"=="            { return TOK_EQ; }
"\""            { return TOK_GHILIMEA; }
"int"			{ return TOK_INT; }
"double"		{ return TOK_DOUBLE; }
"float"         { return TOK_FLOAT; }
"print"		    { return TOK_PRINT; }
"read"		    { return TOK_READ; }
"return"        { return TOK_RETURN; }
"//"[^"\n]*"\n" { return TOK_SINGLE; }
"/*"([^*]*|\*+[^*/])*"*/"   { return TOK_MULTI; }
\"[^"]*\"    { yylval.str = strdup(yytext + 1); yylval.str[strlen(yylval.str) - 1] = '\0'; return STRING_LITERAL; }
[0]|[1-9][0-9]*     {
                            yylval.ival = atoi(yytext); 
                            return INT_VAL;
                        }
"0"[.][0-9]+|[-]?[1-9][0-9]*[.][0-9]+f  {
                                            yylval.fval = atof(yytext); 
                                            return FLOAT_VAL;
                                        }                        
"0"[.][0-9]+|[-]?[1-9][0-9]*[.][0-9]+  {
                                            yylval.dval = atof(yytext); 
                                            return DOUBLE_VAL;
                                        }
[a-zA-Z][a-zA-Z0-9]*\(  {
                            yylval.sir = strdup(yytext);
                            return TOK_FUNC;
                        }
[a-zA-Z][a-zA-Z0-9]*    { 
                            yylval.sir = strdup(yytext); 
                            return TOK_ID;
                        }
\n              ;
[ \t]+          ;
\r?\n           ;
.				{ return TOK_ERROR; }
%%
/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "project.y"

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

#line 308 "project.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "project.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_PRINT = 3,                  /* TOK_PRINT  */
  YYSYMBOL_TOK_READ = 4,                   /* TOK_READ  */
  YYSYMBOL_TOK_ERROR = 5,                  /* TOK_ERROR  */
  YYSYMBOL_TOK_GHILIMEA = 6,               /* TOK_GHILIMEA  */
  YYSYMBOL_TOK_RETURN = 7,                 /* TOK_RETURN  */
  YYSYMBOL_TOK_SINGLE = 8,                 /* TOK_SINGLE  */
  YYSYMBOL_TOK_MULTI = 9,                  /* TOK_MULTI  */
  YYSYMBOL_TOK_IF = 10,                    /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 11,                  /* TOK_ELSE  */
  YYSYMBOL_TOK_WHILE = 12,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_INT = 13,                   /* TOK_INT  */
  YYSYMBOL_TOK_DOUBLE = 14,                /* TOK_DOUBLE  */
  YYSYMBOL_TOK_FLOAT = 15,                 /* TOK_FLOAT  */
  YYSYMBOL_TOK_ID = 16,                    /* TOK_ID  */
  YYSYMBOL_TOK_FUNC = 17,                  /* TOK_FUNC  */
  YYSYMBOL_STRING_LITERAL = 18,            /* STRING_LITERAL  */
  YYSYMBOL_TOK_GT = 19,                    /* TOK_GT  */
  YYSYMBOL_TOK_LT = 20,                    /* TOK_LT  */
  YYSYMBOL_TOK_EQ = 21,                    /* TOK_EQ  */
  YYSYMBOL_TOK_GE = 22,                    /* TOK_GE  */
  YYSYMBOL_TOK_LE = 23,                    /* TOK_LE  */
  YYSYMBOL_INT_VAL = 24,                   /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 25,                 /* FLOAT_VAL  */
  YYSYMBOL_DOUBLE_VAL = 26,                /* DOUBLE_VAL  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '*'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '{'  */
  YYSYMBOL_34_ = 34,                       /* '}'  */
  YYSYMBOL_35_ = 35,                       /* ','  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_S = 39,                         /* S  */
  YYSYMBOL_I = 40,                         /* I  */
  YYSYMBOL_comment = 41,                   /* comment  */
  YYSYMBOL_functie = 42,                   /* functie  */
  YYSYMBOL_parameter_list = 43,            /* parameter_list  */
  YYSYMBOL_decl = 44,                      /* decl  */
  YYSYMBOL_declarare = 45,                 /* declarare  */
  YYSYMBOL_atribuire = 46,                 /* atribuire  */
  YYSYMBOL_rightSide = 47,                 /* rightSide  */
  YYSYMBOL_expression = 48,                /* expression  */
  YYSYMBOL_termen = 49,                    /* termen  */
  YYSYMBOL_operand = 50,                   /* operand  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_if_statement = 52,              /* if_statement  */
  YYSYMBOL_action = 53,                    /* action  */
  YYSYMBOL_54_1 = 54,                      /* $@1  */
  YYSYMBOL_55_2 = 55,                      /* $@2  */
  YYSYMBOL_optional_else = 56,             /* optional_else  */
  YYSYMBOL_while_statement = 57,           /* while_statement  */
  YYSYMBOL_condition = 58,                 /* condition  */
  YYSYMBOL_block = 59,                     /* block  */
  YYSYMBOL_inside = 60,                    /* inside  */
  YYSYMBOL_before = 61,                    /* before  */
  YYSYMBOL_rel_op = 62,                    /* rel_op  */
  YYSYMBOL_print = 63,                     /* print  */
  YYSYMBOL_read = 64                       /* read  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    32,    29,    27,    35,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   278,   278,   279,   280,   281,   282,   283,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   304,
     307,   308,   311,   315,   319,   325,   326,   329,   351,   372,
     396,   430,   464,   498,   530,   562,   594,   595,   596,   599,
     627,   651,   664,   695,   726,   740,   772,   851,   865,   881,
     901,   921,   941,   945,   949,   955,   958,   963,   968,   969,
     968,   978,   979,   982,   985,  1028,  1035,  1036,  1037,  1038,
    1039,  1040,  1043,  1048,  1051,  1054,  1057,  1060,  1065,  1070,
    1081,  1092,  1104
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_PRINT",
  "TOK_READ", "TOK_ERROR", "TOK_GHILIMEA", "TOK_RETURN", "TOK_SINGLE",
  "TOK_MULTI", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_INT", "TOK_DOUBLE",
  "TOK_FLOAT", "TOK_ID", "TOK_FUNC", "STRING_LITERAL", "TOK_GT", "TOK_LT",
  "TOK_EQ", "TOK_GE", "TOK_LE", "INT_VAL", "FLOAT_VAL", "DOUBLE_VAL",
  "'+'", "'-'", "'*'", "'/'", "';'", "')'", "'{'", "'}'", "','", "'='",
  "'('", "$accept", "S", "I", "comment", "functie", "parameter_list",
  "decl", "declarare", "atribuire", "rightSide", "expression", "termen",
  "operand", "statement", "if_statement", "action", "$@1", "$@2",
  "optional_else", "while_statement", "condition", "block", "inside",
  "before", "rel_op", "print", "read", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-120)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    57,    -2,  -120,  -120,  -120,   -28,    -9,    46,   107,
      62,    16,  -120,  -120,  -120,   118,    25,    35,     8,     8,
    -120,  -120,  -120,    92,    85,  -120,     8,  -120,  -120,  -120,
    -120,  -120,     9,    21,  -120,    60,    60,    54,   124,    75,
      99,   124,   108,   124,    79,    67,    93,   120,  -120,   137,
     131,   138,     8,  -120,  -120,  -120,    92,  -120,  -120,  -120,
    -120,    60,    60,    60,    60,  -120,    60,   139,    87,   123,
     126,    63,   140,   143,   144,    22,  -120,   145,    -7,    42,
      10,    56,   125,  -120,    92,   147,   148,   149,  -120,    85,
      85,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
      60,  -120,   134,   142,  -120,   155,  -120,  -120,  -120,   136,
     124,   156,   158,  -120,   159,   141,  -120,   160,   146,    79,
    -120,  -120,  -120,  -120,  -120,   134,    37,  -120,   135,   150,
     169,  -120,   151,   152,   153,   170,   157,   171,  -120,  -120,
      16,   161,    55,   127,   162,   164,   165,    60,   168,   166,
     174,    60,   175,    60,   173,  -120,   178,   133,   179,  -120,
     167,   172,   176,   177,  -120,   180,  -120,    15,   181,   182,
    -120,    65,  -120,    90,   134,  -120,    54,    99,   108,  -120,
    -120,  -120,  -120,  -120,   163,  -120,  -120,   183,   184,  -120,
    -120,  -120,  -120
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     7,    20,    21,     0,     0,     0,     0,
       0,    48,    52,    53,    54,     0,     0,     0,     2,     2,
      19,    17,    16,    18,    44,    47,     2,    55,    56,    14,
      15,    48,    78,    79,    82,     0,     0,    27,     0,     0,
      29,     0,    28,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     2,    12,     8,     9,    13,    10,    11,     5,
       6,     0,     0,     0,     0,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    48,    39,    41,     0,     0,     0,     3,    42,
      43,    45,    46,    80,    81,    73,    74,    75,    76,    77,
       0,    58,     0,     0,    30,     0,    27,    29,    28,     0,
       0,     0,     0,    32,     0,     0,    31,     0,     0,     0,
      49,    50,    51,    64,    57,     0,    72,    63,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,    40,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    62,    69,     0,     0,     0,    65,
       0,     0,     0,     0,    71,     0,    33,     0,     0,     0,
      35,     0,    34,     0,     0,    60,     0,     0,     0,    67,
      66,    68,    70,    36,     0,    38,    37,     0,     0,    61,
      22,    24,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,   -11,  -120,  -120,  -120,   102,   -12,   -16,   -14,    77,
     -17,    89,     1,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
     185,  -119,  -120,  -120,  -120,   -13,   187
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    16,    17,    18,    19,    75,    20,    21,    22,    83,
      23,    24,    25,    26,    27,   124,   125,   154,   175,    28,
      69,   127,   142,   143,   100,    29,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,    54,    33,    55,    57,    53,   139,    59,    60,    35,
     112,     1,     2,     3,    34,    65,     4,     5,     6,   113,
       7,     8,     9,    10,    11,    48,    76,    84,    36,    76,
     114,    76,    12,    13,    14,   116,    68,    68,     1,     2,
       1,    88,    61,    62,    66,    15,   184,   117,    49,    50,
      51,    11,    44,   140,   109,   189,    67,   110,     1,    12,
      13,    14,    37,    38,    91,    92,    52,    93,   156,   157,
     158,   140,    15,    31,   115,    32,    31,   110,    42,    43,
     103,    12,    13,    14,    12,    13,    14,   104,   118,   159,
      71,   110,    61,    62,    15,    82,   187,    15,   131,    85,
     105,   123,    84,    12,    13,    14,    95,    96,    97,    98,
      99,    77,   141,   144,    63,    64,    15,    61,    62,    61,
      62,   188,    39,    40,    41,    86,   160,   163,   161,   162,
     167,    45,    46,    47,   171,    78,   173,    72,    73,    74,
     156,   157,   158,    79,    80,    81,    39,    40,    39,   177,
      89,    90,    87,    37,    42,   101,   106,    94,   102,   107,
     108,   119,   111,   120,   121,   122,   128,   126,   129,   130,
     145,   132,   133,   134,   135,   136,   147,   151,   153,   137,
     169,   166,   146,   168,   174,   150,   148,   149,   165,   152,
     170,   172,   155,   164,   176,   178,   138,   190,   179,     0,
       0,     0,     0,   180,    58,     0,     0,   181,   182,     0,
       0,     0,   183,   185,   186,     0,     0,   191,   192,     0,
       0,    70
};

static const yytype_int16 yycheck[] =
{
      17,    17,     1,    17,    17,    17,   125,    18,    19,    37,
      17,     3,     4,     5,    16,    26,     8,     9,    10,    26,
      12,    13,    14,    15,    16,     0,    38,    44,    37,    41,
      37,    43,    24,    25,    26,    25,    35,    36,     3,     4,
       3,    52,    27,    28,    35,    37,    31,    37,    13,    14,
      15,    16,    36,    16,    32,   174,    35,    35,     3,    24,
      25,    26,    16,    17,    63,    64,    31,    66,    13,    14,
      15,    16,    37,    16,    32,    18,    16,    35,    16,    17,
      17,    24,    25,    26,    24,    25,    26,    24,    32,    34,
      36,    35,    27,    28,    37,    16,    31,    37,   110,    32,
      37,   100,   119,    24,    25,    26,    19,    20,    21,    22,
      23,    36,   126,   126,    29,    30,    37,    27,    28,    27,
      28,    31,    15,    16,    17,    32,   142,   143,   142,   142,
     147,    13,    14,    15,   151,    36,   153,    13,    14,    15,
      13,    14,    15,    41,    36,    43,    15,    16,    15,    16,
      61,    62,    32,    16,    16,    32,    16,    18,    32,    16,
      16,    36,    17,    16,    16,    16,    24,    33,    13,    33,
      35,    15,    14,    14,    33,    15,     7,     7,     7,    33,
      14,    16,    32,    15,    11,    32,    35,    35,    24,    32,
      16,    16,    31,    31,    16,    16,   119,    34,    31,    -1,
      -1,    -1,    -1,    31,    17,    -1,    -1,    31,    31,    -1,
      -1,    -1,    32,    32,    32,    -1,    -1,    34,    34,    -1,
      -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     8,     9,    10,    12,    13,    14,
      15,    16,    24,    25,    26,    37,    39,    40,    41,    42,
      44,    45,    46,    48,    49,    50,    51,    52,    57,    63,
      64,    16,    18,    50,    16,    37,    37,    16,    17,    15,
      16,    17,    16,    17,    36,    13,    14,    15,     0,    13,
      14,    15,    31,    44,    45,    46,    48,    63,    64,    39,
      39,    27,    28,    29,    30,    39,    35,    35,    50,    58,
      58,    36,    13,    14,    15,    43,    44,    36,    36,    43,
      36,    43,    16,    47,    48,    32,    32,    32,    39,    49,
      49,    50,    50,    50,    18,    19,    20,    21,    22,    23,
      62,    32,    32,    17,    24,    37,    16,    16,    16,    32,
      35,    17,    17,    26,    37,    32,    25,    37,    32,    36,
      16,    16,    16,    50,    53,    54,    33,    59,    24,    13,
      33,    44,    15,    14,    14,    33,    15,    33,    47,    59,
      16,    46,    60,    61,    63,    35,    32,     7,    35,    35,
      32,     7,    32,     7,    55,    31,    13,    14,    15,    34,
      45,    46,    63,    45,    31,    24,    16,    48,    15,    14,
      16,    48,    16,    48,    11,    56,    16,    16,    16,    31,
      31,    31,    31,    32,    31,    32,    32,    31,    31,    59,
      34,    34,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    39,    39,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      41,    41,    42,    42,    42,    43,    43,    44,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      47,    47,    48,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    52,    54,    55,
      53,    56,    56,    57,    58,    59,    60,    60,    60,    60,
      60,    60,    61,    62,    62,    62,    62,    62,    63,    63,
      63,    63,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     2,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     9,     9,     9,     1,     3,     2,     2,     2,
       4,     4,     4,     7,     7,     7,     8,     8,     8,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     1,     4,
       4,     4,     1,     1,     1,     1,     1,     5,     0,     0,
       4,     2,     0,     5,     3,     3,     3,     3,     3,     2,
       3,     2,     0,     1,     1,     1,     1,     1,     2,     2,
       4,     4,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* S: %empty  */
#line 278 "project.y"
    { printf("Corect\n"); }
#line 1486 "project.tab.c"
    break;

  case 7: /* S: TOK_ERROR  */
#line 283 "project.y"
                { EsteCorecta = 0; }
#line 1492 "project.tab.c"
    break;

  case 9: /* I: I atribuire  */
#line 286 "project.y"
                  { ts->printVars(); }
#line 1498 "project.tab.c"
    break;

  case 18: /* I: expression  */
#line 295 "project.y"
                     {
		if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
			cout<< (yyvsp[0].info).ival <<endl;
		}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
			cout<< (yyvsp[0].info).dval <<endl;
		} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
			cout<< (yyvsp[0].info).fval <<endl;
		}
	}
#line 1512 "project.tab.c"
    break;

  case 22: /* functie: TOK_INT TOK_FUNC parameter_list ')' '{' TOK_RETURN expression ';' '}'  */
#line 312 "project.y"
                { 
			ts->deleteNodesInBucla(); 
		}
#line 1520 "project.tab.c"
    break;

  case 23: /* functie: TOK_FLOAT TOK_FUNC parameter_list ')' '{' TOK_RETURN expression ';' '}'  */
#line 316 "project.y"
                { 
			ts->deleteNodesInBucla(); 
		}
#line 1528 "project.tab.c"
    break;

  case 24: /* functie: TOK_DOUBLE TOK_FUNC parameter_list ')' '{' TOK_RETURN expression ';' '}'  */
#line 320 "project.y"
                { 
			ts->deleteNodesInBucla(); 
		}
#line 1536 "project.tab.c"
    break;

  case 27: /* decl: TOK_INT TOK_ID  */
#line 329 "project.y"
                      {
	if(ts != NULL)
		{
			if(ts->exists((yyvsp[0].sir)) == 0)
			{
				ts->add((yyvsp[0].sir), -1, 0);
				cout<< (yyvsp[0].sir) << "="<<ts->getValue<int>((yyvsp[0].sir))<<endl;
			}
			else
			{
				sprintf(msg,"Eroare semantica: Declaratii multiple pentru variabila %s!", (yyvsp[0].sir));
				yyerror(msg);
				YYERROR;
			}
		}
		else
		{
			ts = new TVAR();
			ts->add((yyvsp[0].sir), -1, 0);
			cout<< (yyvsp[0].sir) << "="<< ts->getValue<int>((yyvsp[0].sir))<<endl;
		}
	 }
#line 1563 "project.tab.c"
    break;

  case 28: /* decl: TOK_FLOAT TOK_ID  */
#line 351 "project.y"
                                   {
			if(ts != NULL)
		{
			if(ts->exists((yyvsp[0].sir)) == 0)
			{
				ts->add((yyvsp[0].sir), -1, 2);
				cout<< (yyvsp[0].sir) << "="<< ts->getValue<float>((yyvsp[0].sir))<<endl;
			}
			else
			{
				sprintf(msg,"Eroare semantica: Declaratii multiple pentru variabila %s!", (yyvsp[0].sir));
				yyerror(msg);
				YYERROR;
			}
		}
		else
		{
			ts = new TVAR();
			cout<< (yyvsp[0].sir) << "="<< ts->getValue<float>((yyvsp[0].sir))<<endl;
		}
	  }
#line 1589 "project.tab.c"
    break;

  case 29: /* decl: TOK_DOUBLE TOK_ID  */
#line 372 "project.y"
                                    {
			if(ts != NULL)
		{
			if(ts->exists((yyvsp[0].sir)) == 0)
			{
				ts->add((yyvsp[0].sir), -1, 1);
				cout<< (yyvsp[0].sir) << "="<< ts->getValue<double>((yyvsp[0].sir))<<endl;
			}
			else
			{
				sprintf(msg,"Eroare semantica: Declaratii multiple pentru variabila %s!", (yyvsp[0].sir));
				yyerror(msg);
				YYERROR;
			}
		}
		else
		{
			ts = new TVAR();
			ts->add((yyvsp[0].sir), -1, 1);
			cout<< (yyvsp[0].sir) << "="<<  ts->getValue<double>((yyvsp[0].sir))<<endl;
		}
	  }
#line 1616 "project.tab.c"
    break;

  case 30: /* declarare: TOK_INT TOK_ID '=' INT_VAL  */
#line 396 "project.y"
                                          {
				if (conditie == -2 || conditie == 0 || conditie == 1){
					if(ts != NULL)
					{	
						if(ts->exists((yyvsp[-2].sir)) == 0){
							ts->add((yyvsp[-2].sir), (yyvsp[0].ival), 0);
							cout<< (yyvsp[-2].sir) << "="<<  ts->getValue<int>((yyvsp[-2].sir))<<endl;
						}
						else if(ts->exists((yyvsp[-2].sir)) == 1)
						{
							ts->setValue((yyvsp[-2].sir), (yyvsp[0].ival));
							cout<< (yyvsp[-2].sir) << "="<<  ts->getValue<int>((yyvsp[-2].sir))<<endl;
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-2].sir));
							yyerror(msg);
							YYERROR;
						}
						if(bucla == 1)
							ts->setBucla((yyvsp[-2].sir), true);
						else ts->setBucla((yyvsp[-2].sir), false);
					}
					else
					{
						ts = new TVAR();
						ts->add((yyvsp[-2].sir), (yyvsp[0].ival), 0);
						cout<< (yyvsp[-2].sir) << "="<< ts->getValue<int>((yyvsp[-2].sir))<<endl;
						if(bucla == 1)
							ts->setBucla((yyvsp[-2].sir), true);
						else ts->setBucla((yyvsp[-2].sir), false);
					}
				}
				}
#line 1655 "project.tab.c"
    break;

  case 31: /* declarare: TOK_FLOAT TOK_ID '=' FLOAT_VAL  */
#line 430 "project.y"
                                                               {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts != NULL)
					{	
						if(ts->exists((yyvsp[-2].sir)) == 0){
							ts->add((yyvsp[-2].sir), (yyvsp[0].fval), 2);
							cout<< (yyvsp[-2].sir) << "="<< ts->getValue<float>((yyvsp[-2].sir))<<endl;
						}
						else if(ts->exists((yyvsp[-2].sir)) == 1)
						{
							ts->setValue((yyvsp[-2].sir), (yyvsp[0].fval));
							cout<< (yyvsp[-2].sir) << "="<< ts->getValue<float>((yyvsp[-2].sir))<<endl;
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-2].sir));
							yyerror(msg);
							YYERROR;
						}
						if(bucla == 1)
							ts->setBucla((yyvsp[-2].sir), true);
						else ts->setBucla((yyvsp[-2].sir), false);
					}
					else
					{
						ts = new TVAR();
						ts->add((yyvsp[-2].sir), (yyvsp[0].fval), 2);
						cout<< (yyvsp[-2].sir) << "="<<  ts->getValue<float>((yyvsp[-2].sir))<<endl;
						if(bucla == 1)
							ts->setBucla((yyvsp[-2].sir), true);
						else ts->setBucla((yyvsp[-2].sir), false);
					}
			}
			}
#line 1694 "project.tab.c"
    break;

  case 32: /* declarare: TOK_DOUBLE TOK_ID '=' DOUBLE_VAL  */
#line 464 "project.y"
                                                 {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts != NULL)
					{	
						if(ts->exists((yyvsp[-2].sir)) == 0){
							ts->add((yyvsp[-2].sir), (yyvsp[0].dval), 1);
							cout<< (yyvsp[-2].sir) << "="<< ts->getValue<double>((yyvsp[-2].sir))<<endl;
						}
						else if(ts->exists((yyvsp[-2].sir)) == 1)
						{
							ts->setValue((yyvsp[-2].sir), (yyvsp[0].dval));
							cout<< (yyvsp[-2].sir) << "="<< ts->getValue<double>((yyvsp[-2].sir))<<endl;
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-2].sir));
							yyerror(msg);
							YYERROR;
						}
						if(bucla == 1)
							ts->setBucla((yyvsp[-2].sir), true);
						else ts->setBucla((yyvsp[-2].sir), false);
					}
					else
					{
						ts = new TVAR();
						ts->add((yyvsp[-2].sir), (yyvsp[0].dval), 1);
						cout<< (yyvsp[-2].sir) << "="<<  ts->getValue<double>((yyvsp[-2].sir))<<endl;
						if(bucla == 1)
							ts->setBucla((yyvsp[-2].sir), true);
						else ts->setBucla((yyvsp[-2].sir), false);
					}
				}
			}
#line 1733 "project.tab.c"
    break;

  case 33: /* declarare: TOK_INT TOK_ID '=' '(' TOK_INT ')' TOK_ID  */
#line 498 "project.y"
                                                                   {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts->exists((yyvsp[-5].sir)) == 0){
					if(ts->exists((yyvsp[0].sir)) == 0){
						printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
					} else if(ts->exists((yyvsp[0].sir)) == 1){
						if (ts->tip((yyvsp[0].sir)) == 0) {//int
							int tmp = ts->getValue<int>((yyvsp[0].sir));
							ts->add((yyvsp[-5].sir), tmp, 0);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<int>((yyvsp[-5].sir))<<endl;
						}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
							double tmp = ts->getValue<double>((yyvsp[0].sir));
							int tmp1 = (int)tmp;
							ts->add((yyvsp[-5].sir), tmp1, 0);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<int>((yyvsp[-5].sir))<<endl;
						}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
							float tmp = ts->getValue<float>((yyvsp[0].sir));
							int tmp1 = (int)tmp;
							ts->add((yyvsp[-5].sir), tmp1, 0);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<int>((yyvsp[-5].sir))<<endl;
						}
					}
				} else {
					sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-5].sir));
					yyerror(msg);
					YYERROR;
				}
				if(bucla == 1)
					ts->setBucla((yyvsp[-5].sir), true);
				else ts->setBucla((yyvsp[-5].sir), false);
				}
			}
#line 1770 "project.tab.c"
    break;

  case 34: /* declarare: TOK_FLOAT TOK_ID '=' '(' TOK_FLOAT ')' TOK_ID  */
#line 530 "project.y"
                                                                       {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts->exists((yyvsp[-5].sir)) == 0){
					if(ts->exists((yyvsp[0].sir)) == 0){
						printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
					} else if(ts->exists((yyvsp[0].sir)) == 1){
						if (ts->tip((yyvsp[0].sir)) == 0) {//int
							int tmp = ts->getValue<int>((yyvsp[0].sir));
							float tmp1 = (float)tmp;
							ts->add((yyvsp[-5].sir), tmp1, 2);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<float>((yyvsp[-5].sir))<<endl;
						}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
							double tmp = ts->getValue<double>((yyvsp[0].sir));
							float tmp1 = (float)tmp;
							ts->add((yyvsp[-5].sir), tmp1, 2);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<float>((yyvsp[-5].sir))<<endl;
						}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
							float tmp = ts->getValue<float>((yyvsp[0].sir));
							ts->add((yyvsp[-5].sir), tmp, 2);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<float>((yyvsp[-5].sir))<<endl;
						}
					}
				} else {
					sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-5].sir));
					yyerror(msg);
					YYERROR;
				}
				if(bucla == 1)
					ts->setBucla((yyvsp[-5].sir), true);
				else ts->setBucla((yyvsp[-5].sir), false);
				}
			}
#line 1807 "project.tab.c"
    break;

  case 35: /* declarare: TOK_DOUBLE TOK_ID '=' '(' TOK_DOUBLE ')' TOK_ID  */
#line 562 "project.y"
                                                                         {
				if (conditie == -2 || conditie == 0 || conditie == 1){
				if(ts->exists((yyvsp[-5].sir)) == 0){
					if(ts->exists((yyvsp[0].sir)) == 0){
						printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
					} else if(ts->exists((yyvsp[0].sir)) == 1){
						if (ts->tip((yyvsp[0].sir)) == 0) {//int
							int tmp = ts->getValue<int>((yyvsp[0].sir));
							double tmp1 = (double)tmp;
							ts->add((yyvsp[-5].sir), tmp1, 1);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<double>((yyvsp[-5].sir))<<endl;
						}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
							double tmp = ts->getValue<double>((yyvsp[0].sir));
							ts->add((yyvsp[-5].sir), tmp, 1);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<double>((yyvsp[-5].sir))<<endl;
						}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
							float tmp = ts->getValue<float>((yyvsp[0].sir));
							double tmp1 = (double)tmp;
							ts->add((yyvsp[-5].sir), tmp1, 1);
							cout<< (yyvsp[-5].sir) << "="<< ts->getValue<double>((yyvsp[-5].sir))<<endl;
						}
					}
				} else {
					sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-5].sir));
					yyerror(msg);
					YYERROR;
				}
				if(bucla == 1)
					ts->setBucla((yyvsp[-5].sir), true);
				else ts->setBucla((yyvsp[-5].sir), false);
				}
			}
#line 1844 "project.tab.c"
    break;

  case 36: /* declarare: TOK_INT TOK_ID '=' TOK_FUNC INT_VAL ',' INT_VAL ')'  */
#line 594 "project.y"
                                                                              {}
#line 1850 "project.tab.c"
    break;

  case 37: /* declarare: TOK_DOUBLE TOK_ID '=' TOK_FUNC TOK_DOUBLE ',' TOK_DOUBLE ')'  */
#line 595 "project.y"
                                                                                       {}
#line 1856 "project.tab.c"
    break;

  case 38: /* declarare: TOK_DOUBLE TOK_FLOAT '=' TOK_FUNC TOK_FLOAT ',' TOK_FLOAT ')'  */
#line 596 "project.y"
                                                                                        {}
#line 1862 "project.tab.c"
    break;

  case 39: /* atribuire: TOK_ID '=' rightSide  */
#line 599 "project.y"
                                     {
					if (conditie == -2 || conditie == 0 || conditie == 1){
					if(ts != NULL)
					{	
						if(ts->exists((yyvsp[-2].sir)) == 1)
						{
							if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
								ts->setValue((yyvsp[-2].sir), (yyvsp[0].info).ival);
								cout<< (yyvsp[-2].sir) << "="<< (yyvsp[0].info).ival <<endl;
							}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
								ts->setValue((yyvsp[-2].sir), (yyvsp[0].info).dval);
								cout<< (yyvsp[-2].sir) << "="<<  (yyvsp[0].info).dval <<endl;
							} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
								ts->setValue((yyvsp[-2].sir), (yyvsp[0].info).fval);
								cout<< (yyvsp[-2].sir) << "="<<  (yyvsp[0].info).fval <<endl;
							}
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-2].sir));
							yyerror(msg);
							YYERROR;
						}
					}
				}
				}
#line 1893 "project.tab.c"
    break;

  case 40: /* rightSide: TOK_ID '=' rightSide  */
#line 627 "project.y"
                                     {
					if(ts != NULL)
					{	
						if(ts->exists((yyvsp[-2].sir)) == 1)
						{
							if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
								ts->setValue((yyvsp[-2].sir), (yyvsp[0].info).ival);
								cout<< (yyvsp[-2].sir) << "="<< (yyvsp[0].info).ival <<endl;
							}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
								ts->setValue((yyvsp[-2].sir), (yyvsp[0].info).dval);
								cout<< (yyvsp[-2].sir) << "="<<  (yyvsp[0].info).dval <<endl;
							} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
								ts->setValue((yyvsp[-2].sir), (yyvsp[0].info).fval);
								cout<< (yyvsp[-2].sir) << "="<<  (yyvsp[0].info).fval <<endl;
							}
						}
						else
						{
							sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[-2].sir));
							yyerror(msg);
							YYERROR;
						}
					}
			 	}
#line 1922 "project.tab.c"
    break;

  case 41: /* rightSide: expression  */
#line 651 "project.y"
                                   {
					if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
						(yyval.info).type = "int";
						(yyval.info).ival = (yyvsp[0].info).ival;
					}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[0].info).fval;
					}
		  		}
#line 1939 "project.tab.c"
    break;

  case 42: /* expression: expression '+' termen  */
#line 664 "project.y"
                                      {
					if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //int
						(yyval.info).type = "int";
						(yyval.info).ival = (yyvsp[-2].info).ival + (yyvsp[0].info).ival;
					} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //float
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).fval + (yyvsp[0].info).fval;
					} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).dval + (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).ival + (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).dval + (yyvsp[0].info).ival;
					} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).ival + (yyvsp[0].info).fval;
					} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).fval + (yyvsp[0].info).ival;
					} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).dval + (yyvsp[0].info).fval;
					} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).fval + (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[-2].info).type, "string") == 0) //string
						printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
				}
#line 1975 "project.tab.c"
    break;

  case 43: /* expression: expression '-' termen  */
#line 695 "project.y"
                                              {
					if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //int
						(yyval.info).type = "int";
						(yyval.info).ival = (yyvsp[-2].info).ival - (yyvsp[0].info).ival;
					} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //float
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).fval - (yyvsp[0].info).fval;
					} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).dval - (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).ival - (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).dval - (yyvsp[0].info).ival;
					} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).ival - (yyvsp[0].info).fval;
					} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).fval - (yyvsp[0].info).ival;
					} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[-2].info).dval - (yyvsp[0].info).fval;
					} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[-2].info).fval - (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[-2].info).type, "string") == 0) //string
						printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
				}
#line 2011 "project.tab.c"
    break;

  case 44: /* expression: termen  */
#line 726 "project.y"
                               {
					if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
						(yyval.info).type = "int";
						(yyval.info).ival = (yyvsp[0].info).ival;
					}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
						(yyval.info).type = "double";
						(yyval.info).dval = (yyvsp[0].info).dval;
					} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
						(yyval.info).type = "float";
						(yyval.info).fval = (yyvsp[0].info).fval;
					}
		   		}
#line 2028 "project.tab.c"
    break;

  case 45: /* termen: termen '*' operand  */
#line 740 "project.y"
                                   {
				if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //int
					(yyval.info).type = "int";
					(yyval.info).ival = (yyvsp[-2].info).ival * (yyvsp[0].info).ival;
				} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //float
					(yyval.info).type = "float";
					(yyval.info).fval = (yyvsp[-2].info).fval * (yyvsp[0].info).fval;
				} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "double";
					(yyval.info).dval = (yyvsp[-2].info).dval * (yyvsp[0].info).dval;
				} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "double";
					(yyval.info).dval = (yyvsp[-2].info).ival * (yyvsp[0].info).dval;
				} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
					(yyval.info).type = "double";
					(yyval.info).dval = (yyvsp[-2].info).dval * (yyvsp[0].info).ival;
				} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
					(yyval.info).type = "float";
					(yyval.info).fval = (yyvsp[-2].info).ival * (yyvsp[0].info).fval;
				} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
					(yyval.info).type = "float";
					(yyval.info).fval = (yyvsp[-2].info).fval * (yyvsp[0].info).ival;
				} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
					(yyval.info).type = "double";
					(yyval.info).dval = (yyvsp[-2].info).dval * (yyvsp[0].info).fval;
				} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "float";
					(yyval.info).fval = (yyvsp[-2].info).fval * (yyvsp[0].info).dval;
				} else if (strcmp((yyvsp[-2].info).type, "string") == 0) //string
					printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
			}
#line 2064 "project.tab.c"
    break;

  case 46: /* termen: termen '/' operand  */
#line 772 "project.y"
                                   {
				if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //int
					(yyval.info).type = "int";
					if((yyvsp[0].info).ival == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {(yyval.info).ival = (yyvsp[-2].info).ival / (yyvsp[0].info).ival;}
				} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //float
					(yyval.info).type = "float";
					if((yyvsp[0].info).fval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {(yyval.info).fval = (yyvsp[-2].info).fval / (yyvsp[0].info).fval;}
				} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "double";
					if((yyvsp[0].info).dval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {(yyval.info).dval = (yyvsp[-2].info).dval / (yyvsp[0].info).dval;}
				} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "double";
					if((yyvsp[0].info).dval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						(yyval.info).dval = (yyvsp[-2].info).ival / (yyvsp[0].info).dval;
					}
				} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
					(yyval.info).type = "double";
					if((yyvsp[0].info).ival == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else { 
						(yyval.info).dval = (yyvsp[-2].info).dval / (yyvsp[0].info).ival;
					}
				} else if (strcmp((yyvsp[-2].info).type, "int") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
					(yyval.info).type = "float";
					if((yyvsp[0].info).fval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else { 
						(yyval.info).fval = (yyvsp[-2].info).ival / (yyvsp[0].info).fval;
					}
				} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "int") == 0) { //double
					(yyval.info).type = "float";
					if((yyvsp[0].info).ival == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						(yyval.info).fval = (yyvsp[-2].info).fval / (yyvsp[0].info).ival;
					}
				} else if (strcmp((yyvsp[-2].info).type, "double") == 0 && strcmp((yyvsp[0].info).type, "float") == 0) { //double
					(yyval.info).type = "double";
					if((yyvsp[0].info).fval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						(yyval.info).dval = (yyvsp[-2].info).dval / (yyvsp[0].info).fval;
					}
				} else if (strcmp((yyvsp[-2].info).type, "float") == 0 && strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "float";
					if((yyvsp[0].info).dval == 0){
						sprintf(msg, "Eroare semantica: Impartire la zero!");
						yyerror(msg);
						YYERROR;
					} else {
						(yyval.info).fval = (yyvsp[-2].info).fval / (yyvsp[0].info).dval;
					}
				} else if (strcmp((yyvsp[-2].info).type, "string") == 0) //string
					printf("semantic error, line %d: undefined string operator '*'\n\n", yylineno);
	   		}
#line 2148 "project.tab.c"
    break;

  case 47: /* termen: operand  */
#line 851 "project.y"
                        {
				if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
					(yyval.info).type = "int";
					(yyval.info).ival = (yyvsp[0].info).ival;
				}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
					(yyval.info).type = "double";
					(yyval.info).dval = (yyvsp[0].info).dval;
				} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
					(yyval.info).type = "float";
					(yyval.info).fval = (yyvsp[0].info).fval;
				}
			}
#line 2165 "project.tab.c"
    break;

  case 48: /* operand: TOK_ID  */
#line 865 "project.y"
                       {
				if(ts->exists((yyvsp[0].sir)) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
				} else if(ts->exists((yyvsp[0].sir)) == 1){
					if (ts->tip((yyvsp[0].sir)) == 0) {//int
						(yyval.info).type = "int";
						(yyval.info).ival = ts->getValue<int>((yyvsp[0].sir));
					}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
						(yyval.info).type = "double";
						(yyval.info).dval = ts->getValue<double>((yyvsp[0].sir));
					}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
						(yyval.info).type = "float";
						(yyval.info).fval = ts->getValue<float>((yyvsp[0].sir));
					}
				}
			}
#line 2186 "project.tab.c"
    break;

  case 49: /* operand: '(' TOK_INT ')' TOK_ID  */
#line 881 "project.y"
                                         {
				if(ts->exists((yyvsp[0].sir)) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
				} else if(ts->exists((yyvsp[0].sir)) == 1){
					if (ts->tip((yyvsp[0].sir)) == 0) {//int
						(yyval.info).type = "int";
						(yyval.info).ival = ts->getValue<int>((yyvsp[0].sir));
					}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
						(yyval.info).type = "int";//set tip int
						double tmp = ts->getValue<double>((yyvsp[0].sir));
						int tmp1 = (int)tmp;
						(yyval.info).ival = tmp1;
					}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
						(yyval.info).type = "int";//set tip int
						float tmp = ts->getValue<float>((yyvsp[0].sir));
						int tmp1 = (int)tmp;
						(yyval.info).ival = tmp1;
					}
				}
		}
#line 2211 "project.tab.c"
    break;

  case 50: /* operand: '(' TOK_DOUBLE ')' TOK_ID  */
#line 901 "project.y"
                                            {
				if(ts->exists((yyvsp[0].sir)) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
				} else if(ts->exists((yyvsp[0].sir)) == 1){
					if (ts->tip((yyvsp[0].sir)) == 0) {//int
						(yyval.info).type = "double";
						int tmp = ts->getValue<int>((yyvsp[0].sir));
						double tmp1 = (double)tmp;
						(yyval.info).dval = tmp1;
					}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
						(yyval.info).type = "double";
						(yyval.info).dval = ts->getValue<double>((yyvsp[0].sir));
					}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
						(yyval.info).type = "double";
						float tmp = ts->getValue<float>((yyvsp[0].sir));
						double tmp1 = (double)tmp;
						(yyval.info).dval = tmp1;
					}
				}
		}
#line 2236 "project.tab.c"
    break;

  case 51: /* operand: '(' TOK_FLOAT ')' TOK_ID  */
#line 921 "project.y"
                                           {
				if(ts->exists((yyvsp[0].sir)) == 0){
					printf("line %d: variable nedeclarata'%s'\n\n", yylineno, (yyvsp[0].sir));
				} else if(ts->exists((yyvsp[0].sir)) == 1){
					if (ts->tip((yyvsp[0].sir)) == 0) {//int
						(yyval.info).type = "float";
						int tmp = ts->getValue<int>((yyvsp[0].sir));
						float tmp1 = (float)tmp;
						(yyval.info).fval = tmp1;
					}else if (ts->tip((yyvsp[0].sir)) == 1) {//double
						(yyval.info).type = "float";
						double tmp = ts->getValue<double>((yyvsp[0].sir));
						float tmp1 = (float)tmp;
						(yyval.info).fval = tmp1;
					}else if (ts->tip((yyvsp[0].sir)) == 2) {//float
						(yyval.info).type = "float";
						(yyval.info).fval = ts->getValue<float>((yyvsp[0].sir));
					}
				}
		}
#line 2261 "project.tab.c"
    break;

  case 52: /* operand: INT_VAL  */
#line 941 "project.y"
                                {
				(yyval.info).type = "int";
				(yyval.info).ival = (yyvsp[0].ival);
			}
#line 2270 "project.tab.c"
    break;

  case 53: /* operand: FLOAT_VAL  */
#line 945 "project.y"
                                  {
				(yyval.info).type = "float";
				(yyval.info).fval = (yyvsp[0].fval);
			}
#line 2279 "project.tab.c"
    break;

  case 54: /* operand: DOUBLE_VAL  */
#line 949 "project.y"
                                   {
				(yyval.info).type = "double";
				(yyval.info).dval = (yyvsp[0].dval);
			}
#line 2288 "project.tab.c"
    break;

  case 55: /* statement: if_statement  */
#line 955 "project.y"
                          { 
				printf("Block-ul if este corect\n");
			}
#line 2296 "project.tab.c"
    break;

  case 56: /* statement: while_statement  */
#line 958 "project.y"
                                          { printf("Block-ul while este corect\n");}
#line 2302 "project.tab.c"
    break;

  case 57: /* if_statement: TOK_IF '(' condition ')' action  */
#line 963 "project.y"
                                  {
   }
#line 2309 "project.tab.c"
    break;

  case 58: /* $@1: %empty  */
#line 968 "project.y"
         {if(conditie == 0) conditie = -1;}
#line 2315 "project.tab.c"
    break;

  case 59: /* $@2: %empty  */
#line 969 "project.y"
                {
			if(conditie == 1) conditie = -1;
			else if(conditie == -1) conditie = 0;
		}
#line 2324 "project.tab.c"
    break;

  case 60: /* action: $@1 block $@2 optional_else  */
#line 972 "project.y"
                               {
			conditie = -2;
		}
#line 2332 "project.tab.c"
    break;

  case 64: /* condition: operand rel_op operand  */
#line 985 "project.y"
                         {
		double tmp;
		if (strcmp((yyvsp[-2].info).type, "int") == 0) { //int
			tmp = (yyvsp[-2].info).ival;
		}else if (strcmp((yyvsp[-2].info).type, "double") == 0) { //double
			tmp = (yyvsp[-2].info).dval;
		} else if (strcmp((yyvsp[-2].info).type, "float") == 0) { //float
			tmp = (yyvsp[-2].info).fval;
		}
		//cout<< "a="<<tmp<<endl;
		double tmp1;
		if (strcmp((yyvsp[0].info).type, "int") == 0) { //int
			tmp1 = (yyvsp[0].info).ival;
		}else if (strcmp((yyvsp[0].info).type, "double") == 0) { //double
			tmp1 = (yyvsp[0].info).dval;
		} else if (strcmp((yyvsp[0].info).type, "float") == 0) { //float
			tmp1 = (yyvsp[0].info).fval;
		}
		//cout<< "tmp1="<<tmp1<<endl;
		if(strcmp((yyvsp[-1].ss), ">") == 0){
			if(tmp > tmp1)
				conditie = 1;
			else conditie = 0;
			//cout<<"conditie=" <<conditie<<endl;
		}else if (strcmp((yyvsp[-1].ss), "<") == 0) {
			if(tmp < tmp1)
				conditie = 1;
			else conditie = 0;
		}else if (strcmp((yyvsp[-1].ss), "=") == 0) {
			if(tmp == tmp1)
				conditie = 1;
			else conditie = 0;
		}else if (strcmp((yyvsp[-1].ss), ">=") == 0) {
			if(tmp >= tmp1)
				conditie = 1;
			else conditie = 0;
		}else if (strcmp((yyvsp[-1].ss), "<=") == 0) {
			if(tmp <= tmp1)
				conditie = 1;
			else conditie = 0;
		}
   }
#line 2379 "project.tab.c"
    break;

  case 65: /* block: '{' inside '}'  */
#line 1029 "project.y"
                {
			ts->deleteNodesInBucla();
			//ts->printVars();
		}
#line 2388 "project.tab.c"
    break;

  case 72: /* before: %empty  */
#line 1043 "project.y"
                {
			bucla = 1;
		}
#line 2396 "project.tab.c"
    break;

  case 73: /* rel_op: TOK_GT  */
#line 1048 "project.y"
         {
	 strcpy((yyval.ss), ">");
   }
#line 2404 "project.tab.c"
    break;

  case 74: /* rel_op: TOK_LT  */
#line 1051 "project.y"
                {
		strcpy((yyval.ss), "<");
	}
#line 2412 "project.tab.c"
    break;

  case 75: /* rel_op: TOK_EQ  */
#line 1054 "project.y"
                {
		strcpy((yyval.ss), "=");
	}
#line 2420 "project.tab.c"
    break;

  case 76: /* rel_op: TOK_GE  */
#line 1057 "project.y"
                {
		strcpy((yyval.ss), ">=");
	}
#line 2428 "project.tab.c"
    break;

  case 77: /* rel_op: TOK_LE  */
#line 1060 "project.y"
                {
		strcpy((yyval.ss), "<=");
	}
#line 2436 "project.tab.c"
    break;

  case 78: /* print: TOK_PRINT STRING_LITERAL  */
#line 1066 "project.y"
                {
			if (conditie == -2 || conditie == 0 || conditie == 1)
				cout<< (yyvsp[0].str) <<endl;
		}
#line 2445 "project.tab.c"
    break;

  case 79: /* print: TOK_PRINT operand  */
#line 1071 "project.y"
                {
			if (conditie == -2 || conditie == 0 || conditie == 1){
				if (strcmp((yyvsp[0].info).type, "int") == 0) //int
					cout<< (yyvsp[0].info).ival <<endl;
				else if (strcmp((yyvsp[0].info).type, "double") == 0)//double
					cout<< (yyvsp[0].info).dval <<endl;
				else if (strcmp((yyvsp[0].info).type, "float") == 0)//float
					cout<< (yyvsp[0].info).fval <<endl;
			}
		}
#line 2460 "project.tab.c"
    break;

  case 80: /* print: TOK_PRINT STRING_LITERAL ',' operand  */
#line 1082 "project.y"
                {
			if (conditie == -2 || conditie == 0 || conditie == 1){
				if (strcmp((yyvsp[0].info).type, "int") == 0) //int
					cout<< (yyvsp[-2].str)  << " " <<  (yyvsp[0].info).ival << endl;
				else if (strcmp((yyvsp[0].info).type, "double") == 0)//double
					cout<< (yyvsp[-2].str)  << " " <<  (yyvsp[0].info).dval << endl;
				else if (strcmp((yyvsp[0].info).type, "float") == 0)//float
					cout<< (yyvsp[-2].str)  << " " << (yyvsp[0].info).fval << endl;
			}
		}
#line 2475 "project.tab.c"
    break;

  case 81: /* print: TOK_PRINT operand ',' STRING_LITERAL  */
#line 1093 "project.y"
                {
			if (conditie == -2 || conditie == 0 || conditie == 1){
				if (strcmp((yyvsp[-2].info).type, "int") == 0) //int
					cout<< (yyvsp[-2].info).ival << " " << (yyvsp[0].str) << endl;
				else if (strcmp((yyvsp[-2].info).type, "double") == 0)//double
					cout<< (yyvsp[-2].info).dval << " " << (yyvsp[0].str) << endl;
				else if (strcmp((yyvsp[-2].info).type, "float") == 0)//float
					cout<< (yyvsp[-2].info).fval << " " << (yyvsp[0].str) << endl;
			}
		}
#line 2490 "project.tab.c"
    break;

  case 82: /* read: TOK_READ TOK_ID  */
#line 1105 "project.y"
        {
		if(ts != NULL)
		{	
			if(ts->exists((yyvsp[0].sir)) == 1)
			{
				if (ts->tip((yyvsp[0].sir)) == 0) { //int
					int tmp;
					cin >> tmp;
					ts->setValue((yyvsp[0].sir), tmp);
					cout<< (yyvsp[0].sir) << "="<< ts->getValue<int>((yyvsp[0].sir)) <<endl;
				}else if (ts->tip((yyvsp[0].sir)) == 1) { //double
					double tmp;
					cin >> tmp;
					ts->setValue((yyvsp[0].sir), tmp);
					cout<< (yyvsp[0].sir) << "="<< ts->getValue<double>((yyvsp[0].sir)) <<endl;
				} else if (ts->tip((yyvsp[0].sir)) == 2) { //float
					float tmp;
					cin >> tmp;
					ts->setValue((yyvsp[0].sir), tmp);
					cout<< (yyvsp[0].sir) << "="<< ts->getValue<float>((yyvsp[0].sir)) <<endl;
				}
			}
			else
			{
				sprintf(msg,"Eroare semantica: Variabila %s este utilizata fara sa fi fost declarata!", (yyvsp[0].sir));
				yyerror(msg);
				YYERROR;
			}
		}
	}
#line 2525 "project.tab.c"
    break;


#line 2529 "project.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1136 "project.y"


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

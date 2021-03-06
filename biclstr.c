
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "biclstr.pc"
};


static unsigned int sqlctx = 70987;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[4];
   unsigned int   sqhstl[4];
            int   sqhsts[4];
            void  *sqindv[4];
            int   sqinds[4];
   unsigned int   sqharm[4];
   unsigned int   *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,1,0,0,
5,0,0,1,0,0,32,99,0,0,0,0,0,1,0,
20,0,0,2,0,0,17,125,0,0,1,1,0,1,0,1,97,0,0,
39,0,0,2,0,0,20,134,0,0,1,1,0,1,0,3,32,0,0,
58,0,0,2,0,0,20,146,0,0,1,1,0,1,0,3,32,0,0,
77,0,0,2,0,0,45,170,0,0,0,0,0,1,0,
92,0,0,2,0,0,14,177,0,0,1,0,0,1,0,2,32,0,0,
111,0,0,2,0,0,15,203,0,0,0,0,0,1,0,
126,0,0,3,0,0,29,205,0,0,0,0,0,1,0,
141,0,0,2,0,0,17,222,0,0,1,1,0,1,0,1,97,0,0,
160,0,0,2,0,0,20,230,0,0,1,1,0,1,0,3,32,0,0,
179,0,0,2,0,0,20,240,0,0,1,1,0,1,0,3,32,0,0,
198,0,0,2,0,0,45,264,0,0,0,0,0,1,0,
213,0,0,2,0,0,14,273,0,0,1,0,0,1,0,2,32,0,0,
232,0,0,2,0,0,15,301,0,0,0,0,0,1,0,
247,0,0,4,0,0,29,303,0,0,0,0,0,1,0,
262,0,0,0,0,0,27,334,0,0,4,4,0,1,0,1,9,0,0,1,9,0,0,1,10,0,0,1,10,0,0,
293,0,0,6,59,0,1,338,0,0,0,0,0,1,0,
308,0,0,7,0,0,30,346,0,0,0,0,0,1,0,
};


#include "biclstr.h"

#define MAX_VNAME_LEN     30
#define MAX_INAME_LEN     30

#define vstrcpy( a, b ) \
(strcpy( a.arr, b ), a.len = strlen( a.arr ), a.arr)

#ifdef _WIN32
    /* This allows compilation on vs 2010 */ 
    #define _W64
#endif

static char *   USERID = NULL;
static char *   SQLSTMT = NULL;
static char *   ARRAY_SIZE = "10";
static char *   DB_NAME = NULL; //"biclstr";
static char *   DB_STRING = NULL; //"biclstr";
static char *   DB_USER = NULL; //"biclstr";
static char *   DB_PASS = NULL; //"Asdqwe123";

/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h 24-apr-2003.12:50:58 mkandarp Exp $ sqlca.h 
 */

/* Copyright (c) 1985, 2003, Oracle Corporation.  All rights reserved.  */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */
/* EXEC SQL INCLUDE sqlda;
 */ 
/*
 * $Header: sqlda.h 08-may-2007.05:58:33 ardesai Exp $ sqlda.h 
 */

/***************************************************************
*      The SQLDA descriptor definition                         *
*--------------------------------------------------------------*
*      VAX/3B Version                                          *
*                                                              *
* Copyright (c) 1987, 2007, Oracle. All rights reserved.  *
***************************************************************/


/* NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************
*/

/*  MODIFIED
    ardesai    05/08/07  - Bug[6037057] Undef Y
    apopat     05/08/02  - [2362423] MVS PE to make lines shorter than 79
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for sqlda
    lvbcheng   08/15/97 -  Move sqlda protos to sqlcpr.h
    lvbcheng   06/25/97 -  Move sqlda protos to this file
    jbasu      01/29/95 -  correct typo
    jbasu      01/27/95 -  correct comment - ub2->sb2
    jbasu      12/12/94 - Bug 217878: note this is an SOSD file
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_
#define SQLDA_ 1
 
#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif

#ifdef Y
 # undef Y
#endif
 
struct SQLDA {
  /* ub4    */ int        N; /* Descriptor size in number of entries        */
  /* text** */ char     **V; /* Ptr to Arr of addresses of main variables   */
  /* ub4*   */ int       *L; /* Ptr to Arr of lengths of buffers            */
  /* sb2*   */ short     *T; /* Ptr to Arr of types of buffers              */
  /* sb2**  */ short    **I; /* Ptr to Arr of addresses of indicator vars   */
  /* sb4    */ int        F; /* Number of variables found by DESCRIBE       */
  /* text** */ char     **S; /* Ptr to Arr of variable name pointers        */
  /* ub2*   */ short     *M; /* Ptr to Arr of max lengths of var. names     */
  /* ub2*   */ short     *C; /* Ptr to Arr of current lengths of var. names */
  /* text** */ char     **X; /* Ptr to Arr of ind. var. name pointers       */
  /* ub2*   */ short     *Y; /* Ptr to Arr of max lengths of ind. var. names*/
  /* ub2*   */ short     *Z; /* Ptr to Arr of cur lengths of ind. var. names*/
  };
 
typedef struct SQLDA SQLDA;
 
#endif

/* ----------------- */
/* defines for sqlda */
/* ----------------- */

#define SQLSQLDAAlloc(arg1, arg2, arg3, arg4) sqlaldt(arg1, arg2, arg3, arg4) 

#define SQLSQLDAFree(arg1, arg2) sqlclut(arg1, arg2) 





extern SQLDA *sqlald();
extern void   sqlclu();

static void die( char * msg )
{
    fprintf( stderr, "%s\n", msg );
    exit(1);
}

/*
    this array contains a default mapping
    I am using to constrain the
       lengths of returned columns.  It is mapping,
    for example, the Oracle
       NUMBER type (type code = 2) to be 45 characters
    long in a string.
*/

static int lengths[] =
{ -1, 0, 45, 0, 0, 0, 0, 0, 2000, 0, 0,
 18, 25, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 512, 2000 };


static void process_parms( argc, argv )
int    argc;
char *    argv[];
{
int    i;

    for( i = 1; i < argc; i++ )
    {
        if ( !strncmp( argv[i], "userid=", 7 ) )
              DB_USER = argv[i]+7;
        else
        if ( !strncmp( argv[i], "passwd=", 7 ) )
              DB_PASS = argv[i]+7;
        else
        if ( !strncmp( argv[i], "dbstring=", 9 ) )
              DB_STRING = argv[i]+9;
        else
        if ( !strncmp( argv[i], "arraysize=", 10 ) )
        {
			ARRAY_SIZE = argv[i]+10;
			iARRAY_SIZE = atoi(ARRAY_SIZE);
		}
        else
        {
            fprintf( stderr,
                    "usage: %s %s %s\n",
                     argv[0],
                    "userid=xxx passwd=yyy dbstring=zzz ",
                    "arraysize=<NN>\n" );
            exit(1);
        }
    }
    if ( DB_USER == NULL  || DB_PASS == NULL)
    {
        fprintf( stderr,
                "usage: %s %s %s\n",
                 argv[0],
				"userid=xxx passwd=yyy dbstring=zzz ",
                "arraysize=<NN>\n" );
        exit(1);
    }
}

static void sqlerror_hard()
{
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


    fprintf(stderr,"\nORACLE error detected:");
    fprintf(stderr,"\n% .70s \n", sqlca.sqlerrm.sqlerrmc);

    /* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    exit(1);
}

static void prepare_tpivot(int prep_fpivot)
{
SQLDA *    select_dp;
int		   i;
int        j;
int		   k = 0;
int		   col = 0;
int		   row = 0;
int        null_ok;
int		   last_fetch_count;
int        row_count = 0;
short      ind_value;
char *     char_ptr;
int        precision;
int        scale;
int        size = 10;


	SQLSTMT = "select head from (select (select to_char(count(*)) from movies where movieid<10) head, 0 rk from dual union all select to_char(userid) , row_number() over (partition by 'x' order by userid) rk from users) where rownum<30 order by rk";
    fprintf( stderr, "Unloading header '%s'\n", SQLSTMT );

    /* EXEC SQL WHENEVER SQLERROR DO sqlerror_hard(); */ 

    /* EXEC SQL PREPARE S FROM :SQLSTMT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)SQLSTMT;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}


    /* EXEC SQL DECLARE C CURSOR FOR S; */ 



    if ((select_dp = sqlald(size,MAX_VNAME_LEN,MAX_INAME_LEN)) == NULL )
        die( "Cannot allocate  memory for select descriptor." );

	select_dp->N = size;
	fprintf(stderr, "\n N na poczatku wynosi %d \n", select_dp->F);
    /* EXEC SQL DESCRIBE SELECT LIST FOR S INTO select_dp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )39;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)select_dp;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}


    if (!select_dp->F) 
		return NULL;

		fprintf(stderr, "\n N potem wynosi %d \n", select_dp->F);

    if (select_dp->F < 0)
    {
        size = -select_dp->F;
        sqlclu(select_dp);
        if ((select_dp = sqlald (size, MAX_VNAME_LEN, MAX_INAME_LEN)) == NULL)
        die("Cannot allocate  memory for descriptor.");
        /* EXEC SQL DESCRIBE SELECT LIST FOR S INTO select_dp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )58;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)select_dp;
        sqlstm.sqhstl[0] = (unsigned int  )0;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sqlerror_hard();
}


    }
    select_dp->N = select_dp->F;	
	for (i = 0; i < select_dp->N; i++)
		select_dp->I[i] = (short *) malloc(sizeof(short) * atoi(ARRAY_SIZE) );

	for (i = 0; i < select_dp->F; i++)
    {
        sqlnul (&(select_dp->T[i]),
                &(select_dp->T[i]), &null_ok);
		 if ( select_dp->T[i] < sizeof(lengths)/sizeof(lengths[0]) )
         {
            if ( lengths[select_dp->T[i]] )
                 select_dp->L[i]  = lengths[select_dp->T[i]];
            else select_dp->L[i] += 5;
        }
        else select_dp->L[i] += 5;

		select_dp->T[i] = 5;
		select_dp->V[i] = (char *) malloc(select_dp->L[i] * atoi(ARRAY_SIZE));

		for( j = MAX_VNAME_LEN-1; j > 0 && select_dp->S[i][j] == ' '; j--);
   }

	/* EXEC SQL OPEN C; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )77;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sqlerror_hard();
}



	tpivothead = (char **) malloc(sizeof(char *) * /*(29) */sqlca.sqlerrd[2]);
	k=0;

    for ( last_fetch_count = 0;;last_fetch_count = sqlca.sqlerrd[2] )
    {
        /* EXEC SQL FOR :iARRAY_SIZE FETCH C USING DESCRIPTOR select_dp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )iARRAY_SIZE;
        sqlstm.offset = (unsigned int  )92;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)select_dp;
        sqlstm.sqhstl[0] = (unsigned int  )0;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sqlerror_hard();
}


		tpivothead = (char **) realloc(tpivothead, sizeof(char *) * sqlca.sqlerrd[2]);

		for( j=0; j < sqlca.sqlerrd[2]-last_fetch_count; j++ )
        {
			k=j+last_fetch_count;
			tpivothead[k] = (char *)malloc(sizeof(char) * (lengths[2]+1));

            for (i = 0; i < select_dp->F; i++)
            {
                ind_value = *(select_dp->I[i]+j);
                char_ptr  = select_dp->V[i] + (j*select_dp->L[i]);
				strncpy(tpivothead[k], char_ptr ,strlen(char_ptr));
				tpivothead[k][strlen(char_ptr)]='\0';
            }
            row_count++;
          //  printf( "\n" );
        }
        if ( sqlca.sqlcode > 0 ) break;
    }

	for (j=0; j<=k; j++)
		fprintf(stderr, "tpivothead[%d] to '%s'\n",j, tpivothead[j]);

    sqlclu(select_dp);

    /* EXEC SQL CLOSE C; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )111;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}



    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )126;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}


    fprintf( stderr, "%d rows extracted\n", row_count );


// ------------------------------ UNLOADING DATA --------------------------- //
	
	cols=row_count-1;
	rows=atoi(tpivothead[0]);
	row_count = 0;


	SQLSTMT = "select m.movieid, u.userid, r.rating from (select * from users where userid<29) /*users*/ u cross join (select * from movies where movieid<10) /*movies*/ m left join ratings r on u.userid=r.userid and m.movieid=r.movieid order by 2, 1"; 

	fprintf( stderr, "Unloading data '%s'\n", SQLSTMT );

	fprintf(stderr, "\n cols %d	rows %d \n", cols, rows);
	/* EXEC SQL WHENEVER SQLERROR DO sqlerror_hard(); */ 

    /* EXEC SQL PREPARE S FROM :SQLSTMT; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )141;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)SQLSTMT;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}


    /* EXEC SQL DECLARE T CURSOR FOR S; */ 

	
    if ((select_dp = sqlald(size,MAX_VNAME_LEN,MAX_INAME_LEN)) == NULL )
        die( "Cannot allocate  memory for select descriptor." );

	select_dp->N = size;
	fprintf(stderr, "\n N wynosi %d \n", select_dp->N);
    /* EXEC SQL DESCRIBE SELECT LIST FOR S INTO select_dp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )160;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)select_dp;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}


    if (!select_dp->F) 
		return NULL;

    if (select_dp->F < 0)
    {
        size = -select_dp->F;
        sqlclu(select_dp);
        if ((select_dp = sqlald (size, MAX_VNAME_LEN, MAX_INAME_LEN)) == NULL)
        die("Cannot allocate  memory for descriptor.");
        /* EXEC SQL DESCRIBE SELECT LIST FOR S INTO select_dp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )179;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)select_dp;
        sqlstm.sqhstl[0] = (unsigned int  )0;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sqlerror_hard();
}


    }
    select_dp->N = select_dp->F;	
	for (i = 0; i < select_dp->N; i++)
		select_dp->I[i] = (short *) malloc(sizeof(short) * atoi(ARRAY_SIZE) );

	for (i = 0; i < select_dp->F; i++)
    {
        sqlnul (&(select_dp->T[i]),
                &(select_dp->T[i]), &null_ok);
		 if ( select_dp->T[i] < sizeof(lengths)/sizeof(lengths[0]) )
         {
            if ( lengths[select_dp->T[i]] )
                 select_dp->L[i]  = lengths[select_dp->T[i]];
            else select_dp->L[i] += 5;
        }
        else select_dp->L[i] += 5;

		select_dp->T[i] = 5;
		select_dp->V[i] = (char *) malloc(select_dp->L[i] * atoi(ARRAY_SIZE));

		for( j = MAX_VNAME_LEN-1; j > 0 && select_dp->S[i][j] == ' '; j--);
   }

	/* EXEC SQL OPEN T; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )198;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sqlerror_hard();
}



	tpivot = (int **) malloc(sizeof(int *) * /* sqlca.sqlerrd[2]*/ cols );
	for (i=0; i<cols; i++)
		tpivot[i]= (int *) malloc(sizeof(int *) * rows );

	k=0;
    for ( last_fetch_count = 0;;last_fetch_count = sqlca.sqlerrd[2] )
    {
        /* EXEC SQL FOR :iARRAY_SIZE FETCH T USING DESCRIPTOR select_dp; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )iARRAY_SIZE;
        sqlstm.offset = (unsigned int  )213;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (           int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (         void  *)select_dp;
        sqlstm.sqhstl[0] = (unsigned int  )0;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) sqlerror_hard();
}



		for( j=0; j < sqlca.sqlerrd[2]-last_fetch_count; j++ )
        {
			k=j+last_fetch_count;

            for (i = 0; i < select_dp->F; i++)
            {
                ind_value = *(select_dp->I[i]+j);
                char_ptr  = select_dp->V[i] + (j*select_dp->L[i]);
            }
            row_count++;

			tpivot[col][row]=atoi(char_ptr);
			fprintf(stderr, "\n row=%d	col=%d	 tpivot[%d][%d]=%d",row, col, row, col, tpivot[col][row]);
			
			row++;
			if ((row) % rows == 0)
			{
				col++;
				row=0;
			}
        }
        if ( sqlca.sqlcode > 0 ) break;
    }

    sqlclu(select_dp);

    /* EXEC SQL CLOSE T; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )232;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}



    /* EXEC SQL COMMIT WORK; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )247;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}


}



main( argc, argv )
int    argc;
char *    argv[];
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 

//VARCHAR  db_name[15];
/* VARCHAR  db_string[15]; */ 
struct { unsigned short len; unsigned char arr[15]; } db_string;

/* VARCHAR  db_user[15]; */ 
struct { unsigned short len; unsigned char arr[15]; } db_user;

/* VARCHAR  db_pass[15]; */ 
struct { unsigned short len; unsigned char arr[15]; } db_pass;

//VARCHAR   oracleid[50];
/* EXEC SQL END DECLARE SECTION; */ 

SQLDA    * select_dp;


    process_parms( argc, argv );

	fpivot = fopen("fpivot.txt","w+");

    /* Connect to ORACLE. */
	vstrcpy( db_string, DB_STRING);
	vstrcpy( db_user, DB_USER);
	vstrcpy( db_pass, DB_PASS);

    /* EXEC SQL WHENEVER SQLERROR DO sqlerror_hard(); */ 


	/* EXEC SQL CONNECT :db_user IDENTIFIED BY :db_pass; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )262;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&db_user;
 sqlstm.sqhstl[0] = (unsigned int  )17;
 sqlstm.sqhsts[0] = (         int  )17;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&db_pass;
 sqlstm.sqhstl[1] = (unsigned int  )17;
 sqlstm.sqhsts[1] = (         int  )17;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlstm.sqlcmax = (unsigned int )100;
 sqlstm.sqlcmin = (unsigned int )2;
 sqlstm.sqlcincr = (unsigned int )1;
 sqlstm.sqlctimeout = (unsigned int )0;
 sqlstm.sqlcnowait = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sqlerror_hard();
}

 // USING :db_string; 

	fprintf(stderr, "\nConnected to ORACLE as user: %s\n\n",DB_USER);

    /* EXEC SQL ALTER SESSION
    SET NLS_DATE_FORMAT = 'YYYY-MM-DD HH24:MI:SS'; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = 'YYYY-MM-DD HH24:MI:S\
S'";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )293;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}




	prepare_tpivot(1);


    /* Disconnect from ORACLE. */
    /* EXEC SQL COMMIT WORK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )308;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sqlerror_hard();
}



	fclose(fpivot);

    exit(0);
}


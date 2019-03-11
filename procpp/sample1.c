
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
  1,0,0,
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
static const struct sqlcxp sqlfpn =
{
    10,
    "sample1.pc"
};


static unsigned int sqlctx = 78451;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4242,873,0,0,
5,0,0,1,57,0,260,43,0,0,1,0,0,1,0,2,9,0,0,
24,0,0,2,0,0,288,49,0,0,0,0,0,1,0,
39,0,0,3,85,0,260,121,0,0,4,1,0,1,0,2,9,0,0,2,4,0,0,2,4,0,0,1,3,0,0,
};


/*
https://stackoverflow.com/questions/14615861/error-lnk2001-unresolved-reference-with-proc-code-with-visual-c
https://docs.oracle.com/cd/A57673_01/DOC/api/doc/PC_22/ch03a.htm
 *
 *  sample1.pc
 *
 *  Prompts the user for an employee number,
 *  then queries the emp table for the employee's
 *  name, salary and commission.  Uses indicator
 *  variables (in an indicator struct) to determine
 *  if the commission is NULL.
 *
 */
#include <unistd.h>

//#define SQLCA_STORAGE_CLASS extern
#include <sqlca.h>
#include <sqlda.h>
#include <sqlcpr.h>


#include "util.h"
#include "sample1.h"


//EXEC SQL INCLUDE SQLCA;
//EXEC SQL INCLUDE SQLDA;

//-------------------------------------------
/* Include the SQL Communications Area.
   You can use #include or EXEC SQL INCLUDE. 
*/

//-------------------------------------------
int testDate()
{
/* EXEC SQL BEGIN DECLARE SECTION ; */ 

	/* VARCHAR		V_SYSDATE[10+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } V_SYSDATE;

/* EXEC SQL END DECLARE SECTION ; */ 
	

	MemsetHost(V_SYSDATE);

	/* EXEC SQL SELECT TO_CHAR(SYSDATE,'RRRR-MM-DD') 
			INTO :V_SYSDATE 
		FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select TO_CHAR(SYSDATE,'RRRR-MM-DD') into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&V_SYSDATE;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
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
}



	if(sqlca.sqlcode == 1403) {
		fprintf(stderr, "날짜 추출이 불가능합니다.");
		/* EXEC SQL ROLLBACK WORK RELEASE; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


		return -1;
	} else if(sqlca.sqlcode < 0) {
		sql_error("조회 오류: ");
	}
	
	//V_SYSDATE.arr[V_SYSDATE.len] = '\0';
	
	printf(" V_SYSDATE=%s \n\n", V_SYSDATE.arr);

	return 0;
}

//-------------------------------------------
int sample1() 
{
/* EXEC SQL BEGIN DECLARE SECTION ; */ 

	/* Define constants for VARCHAR lengths. */
	#define     UNAME_LEN      20
	#define     PWD_LEN        40

	/* varchar can be in lower case also. */
	/*
	Define a host structure for the output values of a SELECT statement.
	*/
	struct {
		/* VARCHAR   emp_name[UNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } emp_name;

		float     salary;
		float     commission;
	} emprec;
	/* 
	Define an indicator struct to correspond to the host output struct. */
	struct
	{
		short     emp_name_ind;
		short     sal_ind;
		short     comm_ind;
	} emprec_ind;

	/*  Input host variable. */
	int         emp_number;
	int         total_queried;
/* EXEC SQL END DECLARE SECTION ; */ 


	char temp_char[32];


/* Register sql_error() as the error handler. */
	/* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--\n"); */ 


/* Loop, selecting individual employee's results */
	total_queried = 0;

    for (;;) {
	/* Break out of the inner loop when a 1403 ("No data found") condition occurs. */
		/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

		
		for (;;) {
            emp_number = 0;
            printf("\nEnter employee number (0 to quit): ");
			
		#ifdef __LINUX__
            fgets(temp_char, sizeof(temp_char), stdin);
		#else
			gets_s(temp_char);			
		#endif	
			
			
            emp_number = atoi(temp_char);
            if (emp_number == 0)
                break;

            /* EXEC SQL SELECT ename, sal, NVL(comm, 0)
                INTO :emprec INDICATOR :emprec_ind
                FROM EMP
                WHERE EMPNO = :emp_number
				; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 4;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "select ename ,sal ,NVL(comm,0) into :s1:s2 ,:s3:\
s4 ,:s5:s6   from EMP where EMPNO=:b2";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )39;
            sqlstm.selerr = (unsigned short)1;
            sqlstm.cud = sqlcud0;
            sqlstm.sqlest = (unsigned char  *)&sqlca;
            sqlstm.sqlety = (unsigned short)4352;
            sqlstm.occurs = (unsigned int  )0;
            sqlstm.sqhstv[0] = (unsigned char  *)&emprec.emp_name;
            sqlstm.sqhstl[0] = (unsigned long )22;
            sqlstm.sqhsts[0] = (         int  )0;
            sqlstm.sqindv[0] = (         short *)&emprec_ind.emp_name_ind;
            sqlstm.sqinds[0] = (         int  )0;
            sqlstm.sqharm[0] = (unsigned long )0;
            sqlstm.sqadto[0] = (unsigned short )0;
            sqlstm.sqtdso[0] = (unsigned short )0;
            sqlstm.sqhstv[1] = (unsigned char  *)&emprec.salary;
            sqlstm.sqhstl[1] = (unsigned long )sizeof(float);
            sqlstm.sqhsts[1] = (         int  )0;
            sqlstm.sqindv[1] = (         short *)&emprec_ind.sal_ind;
            sqlstm.sqinds[1] = (         int  )0;
            sqlstm.sqharm[1] = (unsigned long )0;
            sqlstm.sqadto[1] = (unsigned short )0;
            sqlstm.sqtdso[1] = (unsigned short )0;
            sqlstm.sqhstv[2] = (unsigned char  *)&emprec.commission;
            sqlstm.sqhstl[2] = (unsigned long )sizeof(float);
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&emprec_ind.comm_ind;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&emp_number;
            sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)0;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
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
            if (sqlca.sqlcode == 1403) break;
            if (sqlca.sqlcode < 0) sql_error("ORACLE error--\n");
}




/* Print data. */
            printf("\n\nEmployee\tSalary\t\tCommission\n");
            printf("--------\t------\t\t----------\n");
/* Null-terminate the output string data. */
            emprec.emp_name.arr[emprec.emp_name.len] = '\0';
            printf("%-8s\t%6.2f\t\t",
                emprec.emp_name.arr, emprec.salary);
            if (emprec_ind.comm_ind == -1)
                printf("NULL\n");
            else
                printf("%6.2f\n", emprec.commission);

            total_queried++;
        }  /* end inner for (;;) */
        if (emp_number == 0) break;
        printf("\nNot a valid employee number - try again.\n");
    } /* end outer for(;;) */

    printf("\n\nTotal rows returned was %d.\n", total_queried); 
    printf("\nG'day.\n\n\n");

	
	return 0;
}

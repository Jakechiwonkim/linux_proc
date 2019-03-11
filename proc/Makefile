
SHELL		= /usr/bin/sh
ECHO		= /usr/bin/echo
CC			= gcc
CXX			= g++
LDFLAGS		= 
PCC 		= $(ORACLE_HOME)/bin/proc
OFILES 		= main.o sample1.o
SERVER		= sample1
PROC_STAGE	= sample1.c


ORA_SUFFIX  =
ORALIB1    	= $(ORACLE_HOME)/lib$(ORA_SUFFIX)
ORALIB2    	= $(ORACLE_HOME)/plsql/lib$(ORA_SUFFIX)
ORALIB3    	= $(ORACLE_HOME)/network/lib$(ORA_SUFFIX)
ORA_INC     = $(ORACLE_HOME)/precomp/public
ORA_INC2    = $(ORACLE_HOME)/rdbms/demo
ORA_INC3    = $(ORACLE_HOME)/rdbms/public
ORA_INC4   	= $(ORACLE_HOME)/plsql/include
ORALIBS = -L$(ORALIB1) -lclntsh

LINKS   = $(DBGFLAG) $(LDFLAGS) $(ORALIBS) \
	-lnsl -lm -lpthread

ORA_LOGIN  = userid=SCOTT/TIGER@XE

PCCFLAGS = lines=no parse=none ireclen=yes \
	code=ansi_c MODE=ORACLE \
	UNSAFE_NULL=YES  DBMS=V7 \
	oreclen=yes hold_cursor=yes \
	maxopencursors=50 sqlcheck=SYNTAX \
	include=. include=$(ORA_INC) include=$(ORA_INC2) include=$(ORA_INC3) \
	define=__x86_64__ 

all : clean $(SERVER)

sample1.o : sample1.pc
	@$(ECHO) "--->C Compiling $(@F:.o=.pc) ..."
	$(ECHODO) $(PCC) $(PCCFLAGS) iname=$(@F:.o=.pc) oname=$(@F:.o=.c) 
	$(ECHODO) $(CC) -c $(CFLAGS) $(@F:.o=.c) -D_NOSORT -o $@ \
	-I . -I $(ORA_INC) -I $(ORA_INC2) -I $(ORA_INC3)

main.o : main.c
	$(ECHODO) $(CC) -c $(CFLAGS) $(@F:.o=.c) -o $@

clean:
	@$(ECHO) "--->Purging all objects and binaries"
	rm -f $(PROC_STAGE)
	rm -f *.o 
	rm -f $(SERVER)

$(SERVER) : $(OFILES)
	@$(ECHO) "========== Now Created =========="
	$(ECHODO) $(CC) -o $@ $(OFILES) $(LINKS)

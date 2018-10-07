
GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)
GCOV = -ftest-coverage -fprofile-arcs
VALGRIND = -g
CPPLINT = cpplint

G++_FLAGS = -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

ODIR=obj
LDIR =../lib

TEST_PROGRAM = Testa_Nlinhas
NAME_PROGRAM = Nlinhas

_DEPS = $(NAME_PROGRAM).h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(NAME_PROGRAM).o $(TEST_PROGRAM).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(TEST_PROGRAM): $(OBJ)
	$(CC) $(VALGRIND) -o $@ $(GCOV) $^ $(LD_FLAGS) $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(VALGRIND) -c -o $@ $(GCOV) $(G++_FLAGS) $< $(CFLAGS)
	
clean:
	rm -f $(ODIR)/*.* ../source/$(TEST_PROGRAM) core $(INCDIR)/*~
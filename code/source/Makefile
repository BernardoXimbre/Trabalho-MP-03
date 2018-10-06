
GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include

IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)
GCOV = -ftest-coverage -fprofile-arcs
VALGRIND = -g

G++_FLAGS = -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread

ODIR=obj
LDIR =../lib

TEST_NAME = testa_Nlinhas

_DEPS = Nlinhas.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Nlinhas.o Testa_Nlinhas.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(TEST_NAME): $(OBJ)
	$(CC) $(VALGRIND) -o $@ $(GCOV) $^ $(LD_FLAGS) $(CFLAGS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(VALGRIND) -c -o $@ $(GCOV) $(G++_FLAGS) $< $(CFLAGS) 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.* ../source/$(TEST_NAME) core $(INCDIR)/*~
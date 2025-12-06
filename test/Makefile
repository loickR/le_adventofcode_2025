PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

TARGET=target
HEADER=../include
HEADERS_TEST=../sources
SOURCES=sources
CXX=g++
CFLAGS=-std=c++17 -g -pg -ftest-coverage -fprofile-arcs -O0
EXEC=test.exe
LIB_DIR=../lib/
LIB=psyume
LIBS=-L$(LIB_DIR) -l$(LIB)
OBJ_DIR=../obj
OBJ_SRC+=$(OBJ_DIR)/Exercise1.o \
$(OBJ_DIR)/IExercise.o
OBJ_TEST+=$(OBJ_SRC) \
$(OBJ_DIR)/Exercise1Test.o \

all:	$(EXEC)

run:
	rm -f *.dylib
	cp $(LIB_DIR)/*.dylib .
	make clean
	make all
	./$(EXEC)

$(EXEC):	$(OBJ_TEST)
	$(CXX) $(CFLAGS) -o $@ $^  $(LIBS)
	cp $(LIB_DIR)/*.* .

$(OBJ_DIR)/%.o: $(SOURCES)/%.cpp
	$(CXX) -c $(CFLAGS) -I$(HEADERS_TEST) -I$(HEADER) -o $@ $<

clean:
	rm -f $(OBJ_DIR)/*Test.*
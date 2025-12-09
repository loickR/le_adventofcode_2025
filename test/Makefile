PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

TARGET=target
HEADER=../include
HEADERS_TEST=../sources
SOURCES=sources
CXX=g++
CFLAGS=-fprofile-arcs -std=c++17 -ftest-coverage -O0
EXEC=tests.exe
LIB_DIR=../lib/
LIB=psyume
LIBS=-L$(LIB_DIR) -l$(LIB)
OBJ_DIR=../obj
OBJ_SRC+=$(OBJ_DIR)/IExercise.o \
$(OBJ_DIR)/Exercise1.o \
$(OBJ_DIR)/Exercise2.o \
$(OBJ_DIR)/Exercise3.o
OBJ_TEST+=$(OBJ_SRC) \
$(OBJ_DIR)/Exercise1Test.o \
$(OBJ_DIR)/Exercise2Test.o \
$(OBJ_DIR)/Exercise3Test.o \
$(OBJ_DIR)/mainTest.o \


all:	$(EXEC)

run:
	make clean
	cp $(LIB_DIR)/*.dylib .
	make all
	./$(EXEC)

$(EXEC):	$(OBJ_TEST)
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBS)
	cp $(LIB_DIR)/*.* .

$(OBJ_DIR)/%.o: $(SOURCES)/%.cpp
	$(CXX) -c $(CFLAGS) -I$(HEADERS_TEST) -I$(HEADER) -o $@ $<

clean:
	rm -f *.dylib
	rm -f $(OBJ_DIR)/*Test.*
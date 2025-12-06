PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

ifeq (($OS), Windows_NT)
	DEL = del /S /F
	MOVE = move
else
	DEL = rm -rf
	MOVE = mv
endif

OBJ_DIR=obj
TARGET=target
HEADERS=include
SOURCES=sources
TEST_SOURCES=test/sources
CXX=g++
CFLAGS=-g -pg -fprofile-arcs -ftest-coverage -std=c++17 -Wall -ansi -O0
EXEC=yrco.exe
LIB_DIR=lib/
LIB=psyume
LIBS=-L$(LIB_DIR) -l$(LIB)
OBJS+=$(OBJ_DIR)/IExercise.o \
$(OBJ_DIR)/Exercise1.o \
$(OBJ_DIR)/Exercise2.o \
$(OBJ_DIR)/main.o \

all:	$(EXEC)

$(EXEC):	$(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^ $(LIBS)
	cp $(LIB_DIR)/*.* .

$(OBJ_DIR)/%.o:	$(SOURCES)/%.cpp
	$(CXX) -c $(CFLAGS) -I$(HEADERS) -o $@ $<

package:
	make clean
	make all

run:
	make package
	./$(EXEC)

directories:
	mkdir $(OBJ_DIR)
	mkdir $(TARGET)

clean:
	$(DEL) $(EXEC)
	$(DEL) pkg_yrco.tar
	$(DEL) $(OBJ_DIR)/*.*
	$(DEL) $(TARGET)/*.*

.PHONY: all mrproper clean
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
CXX=g++
CFLAGS=-g -pg -fprofile-arcs -ftest-coverage
LDFLAGS=-pg -fprofile-arcs -ftest-coverage
EXEC=yrco.exe
OBJS+=$(OBJ_DIR)/main.o \
$(OBJ_DIR)/IExercise.o \
$(OBJ_DIR)/Exercise1.o \


all:	$(EXEC)

$(EXEC):	$(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^
	$(MOVE) $(EXEC) target

$(OBJ_DIR)/%.o:	$(SOURCES)/%.cpp
	$(CXX) -c $(CFLAGS) -I$(HEADERS) -o $@ $<

package:
	$(DEL) pkg_yrco.tar
	make clean
	make all
	tar czfv pkg_yrco.tar target

directories:
	mkdir $(OBJ_DIR)
	mkdir $(TARGET)

clean:
	$(DEL) $(EXEC)
	$(DEL) pkg_yrco.tar
	$(DEL) $(OBJ_DIR)/*.*
	$(DEL) $(TARGET)/*.*

.PHONY: all clean
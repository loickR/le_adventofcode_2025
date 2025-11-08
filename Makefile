PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

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
	move  $(EXEC) target

$(OBJ_DIR)/%.o:	$(SOURCES)/%.cpp
	$(CXX) -c $(CFLAGS) -I$(HEADERS) -o $@ $<

package:
	del /S /F pkg_yrco.tar
	make clean
	make all
	tar czfv pkg_yrco.tar target

directories:
	mkdir $(OBJ_DIR)
	mkdir $(TARGET)

clean:
	del /S /F $(EXEC)
	del /S /F pkg_yrco.tar
	del /S /F $(OBJ_DIR)\*.o
	del /S /F $(TARGET)\*

.PHONY: all clean
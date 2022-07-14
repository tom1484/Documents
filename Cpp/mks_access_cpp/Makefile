FLAGS = 
LIBS = 

ROOT = .
SRC_PATH = $(ROOT)/src
BUILD_PATH = $(ROOT)/build
OBJS_PATH = $(BUILD_PATH)/objs

OBJS = main.o connection.o frame.o

SHELL_HACK := $(shell mkdir -p $(BUILD_PATH) $(OBJS_PATH))

main: $(OBJS)
	g++ -o $(BUILD_PATH)/main $(OBJS_PATH)/main.o \
		$(OBJS_PATH)/connection.o $(OBJS_PATH)/frame.o \
		$(LIBS)

main.o:
	g++ -c $(SRC_PATH)/main.cpp \
		-o $(OBJS_PATH)/main.o \
		$(LIBS)

connection.o:
	g++ -c $(SRC_PATH)/connection/connection.cpp \
		-o $(OBJS_PATH)/connection.o \
		$(LIBS)

frame.o:
	g++ -c $(SRC_PATH)/frame/frame.cpp \
		-o $(OBJS_PATH)/frame.o \
		$(LIBS)



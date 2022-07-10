# CFLAGS = -L/usr/local/lib -lcurlpp -lcurl -ljsoncpp
LIBS = $(shell pkg-config --libs curlpp jsoncpp)

SRC = src
DEPS = $(SRC)/libs

BUILD = build
OBJS = $(BUILD)/objs

executable: post.o connection.o
	g++ -o $(BUILD)/post $(OBJS)/post.o $(OBJS)/connection.o $(LIBS)

connection.o:
	g++ -c $(DEPS)/connection.cpp -o $(OBJS)/connection.o $(LIBS)

post.o:
	g++ -c $(SRC)/post.cpp -o $(OBJS)/post.o $(LIBS)


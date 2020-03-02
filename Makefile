UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
CC = clang++
CFLAGS = -std=c++11
LDFLAGS = -framework OpenGL
else
CC = g++
endif
LIBS = -lrealsense2 -lraylib

all:
	$(CC) $(CFLAGS) main.cpp -o main $(LDFLAGS) $(LIBS)

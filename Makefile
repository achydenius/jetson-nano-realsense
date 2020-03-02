UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
CC = clang++
CFLAGS = -std=c++11
LDFLAGS = -L/usr/local/Cellar/librealsense/2.32.1/lib
else
CC = g++
endif
LIBS = -lrealsense2

all:
	$(CC) $(CFLAGS) main.cpp -o main $(LDFLAGS) $(LIBS)

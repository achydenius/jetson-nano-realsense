UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
CC = clang++
CFLAGS = -std=c++11 -Wno-deprecated
LDFLAGS = -L/usr/local/Cellar/librealsense/2.32.1/lib -framework OpenGL
else
CC = g++
endif
LIBS = -lrealsense2 -lglfw

all:
	$(CC) $(CFLAGS) main.cpp -o main $(LDFLAGS) $(LIBS)

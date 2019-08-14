CC	 :=		g++
BUILD_FLAG = -g -std=c++11 -DUNICODE -D_UNICODE -mwindows -omain.exe

SOURCE	= 	main.cpp

build:
	$(CC) $(BUILD_FLAG) $(SOURCE)

all: build
	@echo "success"
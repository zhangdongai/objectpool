TARGET=objectpool

CC=g++

CPPFLAGS=-D__LINUX__ \
		-g 			 \
		-O0			 \
		-I./include    \
		-I./test    \
		-std=c++11	 \

LINKFALGS=-lgtest -lpthread

#CPPOBJS=$(shell find ./ -name "*.cpp" | awk -F".cpp" '{printf "%s.o\n", $$1}')
CPPOBJS=$(shell find ./ -name "*.cpp")

all:
	$(CC) $(CPPFLAGS) $(CPPOBJS) $(LINKFALGS) -o $(TARGET)

CCP = gcc
INCLS = -I./include/
LIBS = -lssl -lcrypto -lcurl

LIBSRC = $(shell find ./src -name '*.cpp')
OBJECTS = $(LIBSRC:.cpp=.o)
INCLUDES = $(shell find ./include/ -name '*.h')

all: libdtcplus.so

%.o: %.cpp ${INCLUDES}
	${CCP} -c -o $@ $< ${INCLS}

libdtcplus.so: ${OBJECTS}
	${CCP} --shared $< -o $@ ${LIBS} ${OBJECTS}

install:
	sudo cp libdtcplus.so /usr/local/lib/
	sudo cp -r include/* /usr/local/include/

clean:
	rm src/*.o
	rm opensc*
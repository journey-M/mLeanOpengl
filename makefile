CC=g++
CFLAGS= -g -Iinclude
BUILDDIR=./build
SRCDIR=./src
SRCFILES_C=$(wildcard ./src/*.c) 
SRCFILES_CPP=$(wildcard ./src/*.cpp)
OBJS_ORIGIN +=$(subst .cpp,.o, $(SRCFILES_CPP))
OBJS_ORIGIN +=$(subst .c,.o, $(SRCFILES_C))
OBJS +=$(BUILDDIR)/main.o  $(subst $(SRCDIR), $(BUILDDIR), $(OBJS_ORIGIN))

all: preper main
	
preper: 
	$(shell if [ ! -d build ]; then mkdir build ; fi;)

main : $(OBJS)
	@echo $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@  -lGL -lglfw -ldl 

$(BUILDDIR)/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(BUILDDIR)/main.o

$(BUILDDIR)/%.o: $(SRCDIR)/%.c 
	$(CC) $(CFLAGS) -o $@ -c $<

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $< 

info:
	@echo $(OBJS)

clean:
	rm main $(BUILDDIR)/*

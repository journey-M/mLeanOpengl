CC=g++
CFLAGS= -g
BUILDDIR=./build
SRCDIR=./src
SRCFILES_C=$(wildcard ./src/*.c) 
SRCFILES_CPP=$(wildcard ./src/*.cpp)
OBJS +=main.o
OBJS +=$(subst .cpp,.o, $(notdir $(SRCFILES_CPP)))
OBJS +=$(subst .c,.o, $(notdir $(SRCFILES_C)))

main :$(OBJS)
	echo $(OBJS)
	cd $(BUILDDIR) && $(CC) $(CFLAGS) $^ -o ../$@  -lGL -lglfw -ldl 

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o $(BUILDDIR)/main.o

%.o: $(SRCDIR)/%.c 
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$@ -c $<

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $(BUILDDIR)/$@ -c $< 

printInfo:
	echo $(OBJS)

clean:
	rm main $(BUILDDIR)/*

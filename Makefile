CC=gcc
DFLAGS=-ggdb -Wall -Wextra --std=c99 --pedantic
RFLAG=-O2
LIBS=`pkg-config --libs raylib`

SRCPATH=src
BUILDIR=build
BINPATH=$(BUILDIR)/medievo


.PHONY: clean release debug


debug: $(BINPATH)-debug
	gdb ./$(BINPATH)-debug

$(BINPATH)-debug: $(SRCPATH)/main.c
	mkdir -p $(BUILDIR)
	$(CC) $(DFLAGS) -o $(BINPATH)-debug $(SRCPATH)/main.c $(LIBS)


release: $(BINPATH)
	./$(BINPATH)

$(BINPATH): $(SRCPATH)/main.c
	mkdir -p $(BUILDIR)
	$(CC) $(RFLAGS) -o $(BINPATH) $(SRCPATH)/main.c $(LIBS)


clean:
	rm -rf $(BUILDIR)

# makefile para alg 2

CC     = gcc
CFLAGS = -Wall -Wextra -g -std=c99
LIB    = heap
LIB2 = ordenacao
BIN    = main


$(BIN):   $(BIN).o $(LIB).o $(LIB2).o
$(BIN).o: $(BIN).c $(LIB).h
$(LIB).o: $(LIB).c $(LIB).h
$(LIB2).o: $(LIB2).c $(LIB2).h
teste: $(BIN)
	./$(BIN)

valgrind: $(BIN)
	valgrind --leak-check=full --track-origins=yes ./$(BIN)

clean:
	rm -f *.o *~ $(BIN)
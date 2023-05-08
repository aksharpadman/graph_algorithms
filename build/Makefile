
TEST = test
DJIKSTRA = djikstra
PQUEUE = pqueue
BUILD = .


djikstra:clean
	g++ -Wall ../$(DJIKSTRA).cpp -o $(BUILD)/$(DJIKSTRA)

pqueue.o: 
	g++ -Wall -o -c  ../$(PQUEUE).cpp ../$(PQUEUE).h

libpqueue.a: pqueue.o 
	ar rcs libpqueue.a pqueue.o	

test: clean libpqueue.a
	g++ -Wall ../$(TEST).cpp ../$(PQUEUE).cpp  -o $(BUILD)/$(TEST) 

clean:
	rm -rf $(TEST) $(DJIKSTRA)
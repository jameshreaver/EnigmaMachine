enigma: $(wildcard *.cpp)
	g++  $^ -o enigma
	
clean:
	rm -rf enigma *.o

.PHONY: clean

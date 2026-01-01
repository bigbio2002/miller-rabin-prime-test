CXXFLAGS := -g -Wall -O1

all: miller-rabin-test mr-prime-demo

miller-rabin-test: main.o miller-rabin.o
	$(CXX) $(CXXFLAGS) -o $@ $^

mr-prime-demo: mr-prime.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f miller-rabin-test mr-prime-demo *.o

.PHONY: all clean

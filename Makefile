CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17 -O0 -g
LDFLAGS=$(CXXFLAGS)
OBJ=$(SRC:.cc=.o)

all:  test_htree test_hforest

test_htree: test_htree.o htree.o 
	$(CXX) $(LDFLAGS) -o $@ $^

test_hforest: test_hforest.o htree.o hforest.o

%.o: %.cc %.hh
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -c -o $@ $<

clean:
	rm -rf *.o test_htree test_hforest

test: all
	./test_htree
	./test_hforest

testT: test_htree
	./test_htree

testF: test_hforest
	./test_hforest

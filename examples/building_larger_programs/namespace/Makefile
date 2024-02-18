example: example.o function.o 
	g++ -o example function.o example.o

example.o: example.cpp vector.hpp length.hpp
	g++ -c example.cpp

function.o: function.cpp vector.hpp length.hpp
	g++ -c function.cpp

clean:
	rm *.o example

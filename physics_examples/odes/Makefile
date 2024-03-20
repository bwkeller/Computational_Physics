all: euler.out euler_converge.out picard_converge.out
	echo "Building all examples"

euler.out: euler.cpp
	g++ -o euler.out euler.cpp

euler_converge.out: euler_converge.cpp
	g++ -o euler_converge.out euler_converge.cpp

picard_converge.out: picard_converge.cpp
	g++ -O0 -g -o picard_converge.out picard_converge.cpp

all: euler.out euler_converge.out picard.out picard_converge.out pred_corr.out pc_converge.out
	echo "Building all examples"

euler.out: euler.cpp
	g++ -o euler.out euler.cpp

euler_converge.out: euler_converge.cpp
	g++ -o euler_converge.out euler_converge.cpp

picard.out: picard.cpp
	g++ -O0 -g -o picard.out picard.cpp
	
picard_converge.out: picard_converge.cpp
	g++ -o picard_converge.out picard_converge.cpp

pred_corr.out: pred_corr.cpp
	g++ -o pred_corr.out pred_corr.cpp

pc_converge.out: pc_converge.cpp
	g++ -o pc_converge.out pc_converge.cpp

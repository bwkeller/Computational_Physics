all: euler.out euler_converge.out picard.out picard_converge.out pred_corr.out pc_converge.out rk4.out rk4_converge.out rk2.out rk2_converge.out orbits.out rk4_energy.out ec_energy.out kdk_energy.out time_reverse.out shooting.out boundary.out
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

rk4.out: rk4.cpp
	g++ -o rk4.out rk4.cpp

rk4_converge.out: rk4_converge.cpp
	g++ -o rk4_converge.out rk4_converge.cpp

rk2.out: rk2.cpp
	g++ -o rk2.out rk2.cpp

rk2_converge.out: rk2_converge.cpp
	g++ -o rk2_converge.out rk2_converge.cpp

rk4_energy.out: rk4_energy.cpp
	g++ -O3 -o rk4_energy.out rk4_energy.cpp

orbits.out: orbits.cpp
	g++ -o orbits.out orbits.cpp

ec_energy.out: ec_energy.cpp
	g++ -O3 -o ec_energy.out ec_energy.cpp

kdk_energy.out: kdk_energy.cpp
	g++ -O3 -o kdk_energy.out kdk_energy.cpp

time_reverse.out: time_reverse.cpp
	g++ -O3 -o time_reverse.out time_reverse.cpp

shooting.out: shooting.cpp
	g++ -O3 -o shooting.out shooting.cpp

boundary.out: boundary.cpp
	g++ -O3 -o boundary.out boundary.cpp

all: diff.out diff_converge.out diff_central.out second_diff.out second_converge.out cancel.out diff_fivepoint.out
	echo "Building all examples"

diff.out: diff.cpp
	g++ -o diff.out diff.cpp

diff_converge.out: diff_converge.cpp
	g++ -o diff_converge.out diff_converge.cpp

diff_central.out: diff_central.cpp
	g++ -o diff_central.out diff_central.cpp

diff_fivepoint.out: diff_fivepoint.cpp
	g++ -o diff_fivepoint.out diff_fivepoint.cpp

second_diff.out: second_diff.cpp
	g++ -o second_diff.out second_diff.cpp

second_converge.out: second_converge.cpp
	g++ -o second_converge.out second_converge.cpp

cancel.out: cancel.cpp
	g++ -o cancel.out cancel.cpp

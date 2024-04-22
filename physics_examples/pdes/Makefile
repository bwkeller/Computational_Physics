default: ftcs.out upwind.out ftcs_diffusion.out poisson.out

ftcs.out: ftcs.cpp
	g++ ftcs.cpp -o ftcs.out

upwind.out: upwind.cpp
	g++ upwind.cpp -o upwind.out

ftcs_diffusion.out: ftcs_diffusion.cpp
	g++ -g ftcs_diffusion.cpp -o ftcs_diffusion.out

poisson.out: poisson.cpp
	g++ poisson.cpp -o poisson.out

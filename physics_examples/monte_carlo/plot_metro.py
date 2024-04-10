#!/usr/bin/env python3

import numpy as np
import matplotlib.pyplot as plt

def truefunc(x):
    return 6*np.exp(-4*(x+4)*(x+4)) + 2*np.exp(-0.2*(x+1)*(x+1)) + np.exp(-2*(x-5)*(x-5))

def truenorm():
    return np.sqrt(np.pi)*(6/np.sqrt(4) + 2/np.sqrt(0.2) + 1/np.sqrt(2))

if __name__ == "__main__":
    plt.plot(np.linspace(-10,10, 200), truefunc(np.linspace(-10,10, 200))/truenorm())
    try:
        data = np.loadtxt("metropolis.txt")
        plt.hist(data, bins=100, density=True, label='Metropolis Sample')
    except:
        pass
    plt.show()

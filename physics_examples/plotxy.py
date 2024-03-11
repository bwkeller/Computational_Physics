#!/usr/bin/env python3
import argparse
import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    plt.rcParams.update({'font.size': 14})
    parser = argparse.ArgumentParser(
            prog='plotxy',
            description='Simple tool to plot whitespace-separated text files',
            )
    parser.add_argument('filename')
    parser.add_argument('--labels', help='comma-separated labels')
    args = parser.parse_args()
    data = np.genfromtxt(args.filename)
    if args.labels == None:
        args.labels = 'Numerical,Analytic'
    for i in range(1,data.shape[1]):
        plt.plot(data[:,0], data[:,i], marker='.', linestyle='none', label=args.labels.split(',')[i-1])
    plt.legend()
    plt.show()

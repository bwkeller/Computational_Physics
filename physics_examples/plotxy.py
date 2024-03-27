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
    parser.add_argument('--lines', help='Draw lines', action=argparse.BooleanOptionalAction)
    parser.add_argument('--circle', help='Draw a unit circle', action=argparse.BooleanOptionalAction)
    args = parser.parse_args()
    data = np.genfromtxt(args.filename)
    if args.lines:
        ls = '-'
    else:
        ls='none'
    if args.labels == None:
        args.labels = 'Numerical,Analytic'
    for i in range(1,data.shape[1]):
        plt.plot(data[:,0], data[:,i], marker='.', linestyle=ls, label=args.labels.split(',')[i-1])
    if args.circle:
        plt.gca().add_patch(plt.Circle([0,0], fill=False, radius=1, color='r', zorder=10))
    plt.legend()
    plt.show()

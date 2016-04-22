# -*- coding: utf-8 -*-
import math
import random

random.seed(20160422)

class ASM:
    def __init__(self, n):
        pass # 空関数のときは必要


def demo():

    n = 100
    sigma = 0.7
    x = [0]*n
    w = [0.0]*n

    asm = ASM(n) # create a network. n: number of neurons.
    
    for i in range(0,n):
        x [i] = random.randint(0,1)
        w [i] = random.gauss(x[i],sigma)
        print x[i], w[i]


if __name__ == '__main__':

    demo()

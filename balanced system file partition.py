

#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'mostBalancedPartition' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY parent
#  2. INTEGER_ARRAY files_size
#
def helper(node, adjacent, files_size):  # here we are just creating helper fucntion to create Wghts to each node
    queue = [node] #making use of list of lists to create tree
    Wght = 0
    while queue:
        index = queue.pop()
        Wght += files_size[index]
        if index in adjacent:
            queue.extend(adjacent[index])
    return Wght
def mostBalancedPartition(parent, files_size):
    # Write your code here


    adjacent = {} #connected nodes
    Edge_nodes = []  # all the nodes are stored here
    for index, parnt in enumerate(parent):
        Edge_nodes.append((parnt, index))
        if parnt in adjacent:
            adjacent[parnt].append(index)
        else:
            adjacent[parnt] = [index]
    
    # print(adjacent, Edge_nodes) we are just checking if all the tree nodes are created correctly
    total_Wght = sum(files_size)
    min_diff = sum(files_size)
    for j in Edge_nodes:
        parnt,child = j
        adjacent[parnt].remove(child)
        w1 = helper(child, adjacent, files_size)
        min_diff = min(min_diff, abs(total_Wght - 2*w1))
        adjacent[parnt].append(child)

    return min_diff

if __name__ == '__main__':
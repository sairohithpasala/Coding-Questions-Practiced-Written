#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'getMinCost' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY crew_id
#  2. INTEGER_ARRAY job_id
#

def getMinCost(crew_id, job_id):
    # Write your code here
    crew_id.sort() #sorting the given list in ascending order
    job_id.sort() #sorting the given list in ascending order
    cost=0   # temporary variable to store the minimum distance so far
    if(len(crew_id)==len(job_id)): #checking if both the lists length are same
        for i in range(0,len(crew_id)):
            if job_id[i]>=crew_id[i]:
                cost+=(job_id[i]-crew_id[i])  #if job_id is greater than crew_id then do this
            elif job_id[i]<crew_id[i]:
                cost+=(crew_id[i]-job_id[i])#if crew_id is greater than job_id then do this
    return cost  #returns the minimum cost

if __name__ == '__main__':
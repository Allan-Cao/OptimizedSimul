from collections import Counter
import time
run = 1000000000
dice = 3
#datastore = []
import fastrand
def rollfast():
    return(fastrand.pcg32bounded(6)+1)
start=time.time()
file = open("thedata3.txt", "w+")
length = 0
_sum = 0

for trial in range(run):
    rolls = []
    for x in range(dice):
        rolls.append(rollfast())
    _sum+=(-1*((Counter(rolls)[rollfast()])-1))
    length += 1
    if(trial%10000==0):
        print(str(trial))
        file.write(str(_sum/length) + "\n")
        
file.close()
# SUPER OPTIMIZED FOR MOVING AVERAGE

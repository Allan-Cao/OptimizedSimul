import fastrand
from collections import Counter
import time
run = 1000000
dice = 3
datastore = []

def roll():
    return(fastrand.pcg32bounded(6)+1)
start=time.time()
for trial in range(run):
    if(trial%100000 == 0):
        print(str(trial))
    rolls = []
    wins = 0
    for x in range(dice):
        rolls.append(roll())
    datastore.append(-1*((Counter(rolls)[roll()])-1))

print("it took "+str(time.time()-start)+" seconds")
import pickle
pickle.dump(datastore, open( "data2.p", "wb" ) )
print("saved and all done")

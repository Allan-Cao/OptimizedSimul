from collections import Counter
import fastrand
def rollfast():
    return(fastrand.pcg32bounded(6)+1)
#file = open("data123.txt", "w+")

_sum = 0
trial=0
while True:
    trial+=1
    rolls = []
    for x in range(3):
        rolls.append(rollfast())
    count = Counter(rolls)[rollfast()]
    _sum+= -1*(count-1)
    if(trial%100000000==0):
        print(str(_sum/(trial+1))+" "+str(trial/1000000000)+" billion")

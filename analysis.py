import pickle
data = pickle.load( open( "data2.p", "rb" ) )
print(sum(data)/len(data))

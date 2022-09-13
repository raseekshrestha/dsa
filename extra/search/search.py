from operator import indexOf
from re import search
import time
import random
import matplotlib.pyplot as plt



def generateList(size,shuffle=True):
    randList = [i for i in range(size)]
    if shuffle:
        random.shuffle(randList)
    return (randList)





def sort(theList):
    theList.sort()
    return theList


def linearSearch(thelist,searchFor):
    for index,value in enumerate(thelist):
        if value == searchFor:
            return index
    return -1

def binarySearch(thelist,searchFor):
    low = 0
    high=len(thelist)-1
    while (low <= high):
        mid = int((low + high) /2)
        if thelist[mid] == searchFor:
            return mid,123
        if thelist[mid] > searchFor:
            high = mid - 1
        elif thelist[mid] < searchFor:
            low = mid + 1
    return -1


    


def timeIt(length,n=10,searchAlgo="LinearSearch"):
    '''returns average time required to search for the value from n random list'''
    print(f"this might take a while, n={n}")
    timeSum = 0
    times = []
    if searchAlgo == "LinearSearch":
        for i in range(n):
                mylist = generateList(length)
                initTime = time.time()
                index = linearSearch(mylist,searchFor=random.randint(0,length))
                finalTime = time.time() - initTime
                timeSum += finalTime
                times.append(finalTime)
        
    elif searchAlgo == "BinarySearch":
        for i in range(n):
            mylist = generateList(length,shuffle=False)
            initTime = time.time()
            index = binarySearch(mylist,searchFor=random.randint(0,length))
            finalTime = time.time() - initTime
            timeSum += finalTime
            times.append(finalTime)
    return (timeSum /n,times) 


sizeOfList = 50000
n= 10




timeTakenByBinary,timesBin = timeIt(sizeOfList,n=n,searchAlgo="BinarySearch")
timeTakenByLinear,timesLin = timeIt(sizeOfList,n=n,searchAlgo="LinearSearch")

print(f"binary = {timeTakenByBinary}")
print(f"linear = {timeTakenByLinear}")

# print('{:.6f}'.format(timeTakenByBinary))

plt.xlabel("n")
plt.ylabel("time required for searching")
plt.plot(timesBin,label="Binary Search")
plt.plot(timesLin,label="Linear Search")
plt.legend(loc="best")
plt.title(f"array size: {sizeOfList}")
# plt.xlim(0, 10)
# plt.ylim(0.000001,0.25)
plt.show()


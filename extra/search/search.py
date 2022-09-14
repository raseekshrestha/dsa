from operator import indexOf
from re import search
import time
import random
from turtle import color
import matplotlib.pyplot as plt



def generateList(size,shuffle=True,forBabal=False):
    randList = [i for i in range(size)]
    if forBabal:
        randList = random.sample(range(2*size),size)
        randList.sort()
    if shuffle:
        random.shuffle(randList)
    return (randList)







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
            return mid
        if thelist[mid] > searchFor:
            high = mid - 1
        elif thelist[mid] < searchFor:
            low = mid + 1
    return -1

def babalSearch(thelist,searchFor):
    low = 0;
    high = len(thelist)-1
    while (low <= high):
        index = int(low + (searchFor - thelist[low]) / (thelist[high] - thelist[low]) * (high - low))
        if thelist[index] == searchFor:
            return index
        if thelist[index] > searchFor:
            high = index - 1
        else:
            low = index + 1
    return -1



def timeIt(length,n=10,searchAlgo="LinearSearch"):
    '''returns average time required to search for the value from n random list'''
    print(f"{searchAlgo} : this might take a while, n={n}")
    times = []
    timeSum = 0
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
            # print(mylist)
            initTime = time.time()
            index = binarySearch(mylist,searchFor=random.randint(0,length))
            finalTime = time.time() - initTime
            timeSum += finalTime
            times.append(finalTime)
    elif searchAlgo == "BabalSearch":
        for i in range(n):
            mylist = generateList(length,shuffle=False,forBabal=True)
        
            initTime = time.time()
            index = babalSearch(mylist,random.choice(mylist))
    
            finalTime = time.time() - initTime
            timeSum += finalTime
            times.append(finalTime)
    return timeSum/length, times 


sizeOfList = 500000
n= 10






tBin,timesBin = timeIt(sizeOfList,n=n,searchAlgo="BinarySearch")
tLin,timesLin = timeIt(sizeOfList,n=n,searchAlgo="LinearSearch")
tBabal,timesBabal = timeIt(sizeOfList,n=n,searchAlgo="BabalSearch")
print(timesBin)
print(f"binary = {sum(timesBin)/len(timesBin)}")
print(f"linear = {sum(timesLin)/len(timesLin)}")
print(f"Babal = {tBabal}")


plt.xlabel("n")
plt.ylabel("time required for searching")
plt.plot(timesBin,label="Binary Search",color="red")
plt.plot(timesLin,label="Linear Search",color="green")
plt.plot(timesBabal,label="Babal Search",color="blue")
plt.legend()
plt.title(f"array size: {sizeOfList}")



# # plt.xlim(0, 10)
# # plt.ylim(0.000001,0.25)
plt.show()


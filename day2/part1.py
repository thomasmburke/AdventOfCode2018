from collections import Counter

doubles = 0
triples = 0
# Locks to stop from counting twice
doubleLock = False
tripleLock = False

with open('input.txt',mode='r') as f:
    for line in f:
        counts = Counter(line)
        for letter, freq in counts.items():
            if freq == 2 and not doubleLock:
                doubles += 1
                doubleLock = True
            if freq == 3 and not tripleLock:
                triples += 1
                tripleLock = True
            # if we have counted a double and a triple no need to search 
            # the rest of the line
            if tripleLock and doubleLock:
                break
        # reset the locks for the next loop
        tripleLock = doubleLock = False

print('doubles and triples: {0} {1}'.format(doubles, triples))
checkSum = doubles * triples
print(checkSum)

def find_repeat(freq=0):
    with open('input.txt', mode='r') as f:
        for line in f:
            freq += int(line)
            if freq in freqList:
                exit('duplicate frequency is {}'.format(freq))
            freqList.append(freq)
        else:
            find_repeat(freq=freq)
            print('calling find_repeat')


if __name__ == '__main__':
    freqList = [0]
    find_repeat()


freq = 0
with open('input.txt', mode='r') as f:
    for line in f.readlines():
        freq += int(line)
print(freq)

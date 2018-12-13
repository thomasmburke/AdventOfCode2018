def get_common_letters():
    # List to hold all processed ids
    itemList = []
    with open('input.txt',mode='r') as f:
        for line in f:
            # if this is the first line do nothing
            if not itemList:
                pass
            # Otherwise check against id list
            else:
                for item in itemList:
                    # counter for the number of misplaced characters in the id
                    misplacedChar = 0
                    # common letters between the two box ids
                    commonLetters = ''
                    for c1, c2 in zip(line, item):
                        if misplacedChar > 1:
                            break
                        elif c1 != c2:
                            misplacedChar += 1
                        else:
                            commonLetters += c1
                    if misplacedChar <= 1:
                        return commonLetters
                    else:
                        commonLetters = ''
                        misplacedChar = 0     
            # add the id to the list to be checked by the next line
            itemList.append(line)


if __name__ == '__main__':
    print(get_common_letters())

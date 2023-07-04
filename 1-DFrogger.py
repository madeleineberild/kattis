def readInput():
    with open('input.txt') as file:
        lines = file.readlines()
    return lines

def isDead():
    return true

def main():
    print("1-D Frogger (Easy)")

    lines = readInput()

    firstLine = lines[0].split(' ')
    secondLine = lines[1].split(' ')

    numberOfBoardSquares = int(firstLine[0])
    startingSquare = int(firstLine[1])
    magicNumber = int(firstLine[2])
    board = [int(n) for n in secondLine]
    fate = enumerate(('magic', 'left', 'right', 'cycle'))
    hops = 0



if __name__ == "__main__":
    main()



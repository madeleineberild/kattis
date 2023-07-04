print("1-D Frogger (Easy)")

with open('input.txt') as file:
    lines = file.readlines()

firstLine = lines[0].split(' ')
secondLine = lines[1].split(' ')

numberOfBoardSquares = int(firstLine[0])
startingSquare = int(firstLine[1])
magicNumber = int(firstLine[2])

board = [int(n) for n in secondLine]

fate = enumerate(('magic', 'left', 'right', 'cycle'))

hops = 0




from random import *

def getCard():
    cardList = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
    card = cardList[randint(0,12)]
    return card

def cardValue(x):
    if int(x) >= 2 and int(x) <= 10:
        return int(x)
    elif x == 'J' or x == 'Q' or x == 'K':
        return 10
    else:


def countValue():
    card1, card2 = getcard(), getcard()
    # while card1 == card2:
        # card2 = getcard()
    if card1 == 'A' or card2 == 'A':

    score = card1 + card2


def main():

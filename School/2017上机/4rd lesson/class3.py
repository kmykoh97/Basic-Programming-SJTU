# A redo of blackjack game using class

from random import *

class blackJack:

    def __init__(self):
        self.numberOfDeck = 2
        self.botList = []
        self.playerList = []
        self.cardDeckList = numberOfDeck * 4 * ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']

    def initialShuffleAndDistribute(self):
        shuffle(self.cardDeckList)
        self.botList.pop(0)
        self.playerList.pop(0)

    def getCard(self):
        shuffle(self.cardDeckList)
        self.

    def bot(self):

    def player(self):


def main():

main()

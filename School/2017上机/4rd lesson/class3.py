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
        self.pop(0)

    def cardValue(self, x):
        if x=='2' or x=='3' or x=='4' or x=='5' or x=='6' or x=='7' or x=='8' or x=='9' or x=='10':
            return int(x)
        elif x == 'J' or x == 'Q' or x == 'K':
            return 10
        else:
            return 11

    def bot(self):
        score = 0
        while score < 17:
            score = 0
            self.botList.getCard()
            print "Bot now have:", len(self.botList) * X
            for i in self.botList:
                score += cardValue(i)
            if score > 21:
                for i in cardList:
                    if i == 'A':
                        score -= 10

        return score

    def player(self):


def main():

main()

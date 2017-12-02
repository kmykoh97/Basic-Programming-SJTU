#Black Jack Card Game
#Created by MyKoh
#2017-12-2

# A redo of blackjack game using class

from random import *

class blackJack:

    def __init__(self, x):
        self.numberOfDeck = x
        self.botList = []
        self.playerList = []
        self.cardDeckList = self.numberOfDeck * 4 * ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']

    def initialShuffleAndDistribute(self):
        shuffle(self.cardDeckList)
        self.botList.append(self.cardDeckList.pop())
        self.botList.append(self.cardDeckList.pop())
        self.playerList.append(self.cardDeckList.pop())
        self.playerList.append(self.cardDeckList.pop())

    def getCard(self, other):
        shuffle(self.cardDeckList)
        other.append(self.cardDeckList.pop())

    def cardValue(self, x):
        if x=='2' or x=='3' or x=='4' or x=='5' or x=='6' or x=='7' or x=='8' or x=='9' or x=='10':
            return int(x)
        elif x == 'J' or x == 'Q' or x == 'K':
            return 10
        else:
            return 11

    def winCondition(self, x, y):
        if y > 21 or x > y:
            return 1
        elif x == y:
            return 'kmy so handsome'
        else:
            return 0

    def bot(self):
        score = 0
        while score < 17:
            score = 0
            self.getCard(self.botList)
            print "Dealer now have:", len(self.botList) * 'X'
            for i in self.botList:
                score += self.cardValue(i)
            if score > 21:
                for i in self.botList:
                    if i == 'A':
                        score -= 10
        return score

    def player(self):
        question = 'y'
        while question == 'y' or question == 'Y':
            print 'Haha, the cards u got are:', self.playerList
            question = raw_input('Do you want to draw another card? (y or n)')
            if question == 'y' or question == 'Y':
                self.getCard(self.playerList)
        print 'Lastly, your cards are:', self.playerList
        score = 0
        for i in self.playerList:
            score += self.cardValue(i)
        y = 0
        while score > 21 and y <= (len(self.playerList)-1):
            if self.playerList[y] == 'A':
                score -= 10
            y += 1
        return score

    def gameStart(self):
        while True:
            self.initialShuffleAndDistribute()
            print 'Your turn to draw card...'
            player1 = self.player()
            print "Dealer's turn to draw card..."
            dealer = self.bot()
            print "Dealer's card:", self.botList
            if self.winCondition(player1, dealer) == 0:
                print 'Player lost...'
            elif self.winCondition(player1, dealer) == 1:
                print 'Congratulations, player wins'
            else:
                print "This game is a draw. Let's have another game XD"
            self.botList = []
            self.playerList = []
            answer = raw_input("Do you want to play another game? (y or n)")
            if answer == 'n' or answer == 'N': break

def main():
    x = input('please insert number of card deck to use:')
    firstPlayer = blackJack(x)
    firstPlayer.gameStart()
    print 'Thank you for playing this game. Hope you enjoyed it'

main()

# Shangji Practice No 3
# Meng Yit Koh
# 517030990022

import random

# Function to distribute cards evenly:
def getCard():
    cardList = ['A', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K']
    card = cardList[random.randint(0,12)]
    return card

# Function to count points associated for each card('A' is initially counted as 11 points):
def cardValue(x):
    if x=='2' or x=='3' or x=='4' or x=='5' or x=='6' or x=='7' or x=='8' or x=='9' or x=='10':
        return int(x)
    elif x == 'J' or x == 'Q' or x == 'K':
        return 10
    else:
        return 11

# Testing:
# print cardValue('5')

# Function to play as human player:
def human():
    cardList = [getCard(), getCard()]
    question = 'y'
    while question == 'y':
        print 'Haha, the cards u got are:', cardList
        question = raw_input('Do you want to draw another card? (y or n)')
        if question == 'y':
            cardList += [getCard()]
    print 'Lastly, your cards are:', cardList
    score = 0
    for i in cardList:
        score += cardValue(i)
        y = 0
    while score > 21 and y <= (len(cardList)-1):
        if cardList[y] == 'A':
            score -= 10
        y += 1

    return score

# Testing:
# print human()

# Function to play as computer(bot):
def bot():
    cardList = [getCard()]
    score = 0
    while score < 17:
        score = 0
        cardList += [getCard()]
        print cardList
        for i in cardList:
            score += cardValue(i)
        if score > 21:
            for i in cardList:
                if i == 'A':
                    score -= 10

    return score

# Testing:
# print bot()

def main():
    # Introduction:
    print 'Hi, this is a game of BlackJack...Enjoy'
    # While loop to run main algorithm:
    while True:
        print "Dealer's turn to draw card..."
        dealer = bot()
        if dealer > 21:
            print 'Congratulations, player wins'
            continue
        print 'Your turn to draw card...'
        player = human()
        if player > 21:
            print 'Ops, dealer wins'
            continue
        if player >= dealer:
            print 'Congratulations, player wins'
        elif player == dealer:
            print 'This game is a draw'
        else:
            print 'Player lost...'
        a = raw_input('Do you want to play another game? (y or n)')
        if a != 'y':
            break
    print 'Thank you for playing this game. Hope you enjoyed it'

main()

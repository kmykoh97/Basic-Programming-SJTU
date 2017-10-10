#Words counter
#Created by MyKoh
#2017-10-13

def main():
    x = raw_input('Please insert words:')
    counter = 1
    for i in range(len(x)):
        if x[i] == ' ' and i != 0 and i != len(x)-1:
            counter += 1

    print "There are " + str(counter) + " words in your sentence"

main()

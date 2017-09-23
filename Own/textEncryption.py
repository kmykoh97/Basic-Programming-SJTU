#Text Encryption Project
#Created by MyKoh
#2017-09-24

words = raw_input("Please enter words in small letter you wish to encrypt")

#To encrypt to numbers in sequence ie: 'a' = 1
def textToNumberConversion():
    result = []
    for character in words:
        if character == 'a':
            result.append(1)
        elif character == 'b':
            result.append(2)
        elif character == 'c':
            result.append(3)
        elif character == 'd':
            result.append(4)
        elif character == 'e':
            result.append(5)
        elif character == 'f':
            result.append(6)
        elif character == 'g':
            result.append(7)
        elif character == 'h':
            result.append(8)
        elif character == 'i':
            result.append(9)
        elif character == 'j':
            result.append(10)
        elif character == 'k':
            result.append(11)
        elif character == 'l':
            result.append(12)
        elif character == 'm':
            result.append(13)
        elif character == 'n':
            result.append(14)
        elif character == 'o':
            result.append(15)
        elif character == 'p':
            result.append(16)
        elif character == 'q':
            result.append(17)
        elif character == 'r':
            result.append(18)
        elif character == 's':
            result.append(19)
        elif character == 't':
            result.append(20)
        elif character == 'u':
            result.append(21)
        elif character == 'v':
            result.append(22)
        elif character == 'w':
            result.append(23)
        elif character == 'x':
            result.append(24)
        elif character == 'y':
            result.append(25)
        elif character == 'z':
            result.append(26)
        elif character == ' ':
            result.append(100)
        else:
            result.append(int(character) + 30)
    print result

#To encrypt to ASCII codes
def textTOASCII():
    print "This program converts a textual message into a ASCII sequence"
    print "Here are the ASCII codes:"
    for character in words:
        print ord(character), # use comma to print all on one line.

textToNumberConversion()
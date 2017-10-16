

def nameToNumber():
    name = raw_input('Please insert your name:')
    a = []
    result = 0
    name = name.lower()
    for i in name:
        a.append(ord(i)-96)
    #print a

    for j in a:
        result += j

    print "The total addition of the alphabets' number is: " + str(result)

nameToNumber()
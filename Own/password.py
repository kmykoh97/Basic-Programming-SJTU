#Password Identifier Project
#Created by MyKoh
#2017-09-27

x = raw_input('Please insert your password:')
symbols = '_qwertyuiopalskdjfhgmznxbcvQWERTYUIOPLKJHGFDSAZXCVBNM'


alphabet = 'qwertyuiopasdfghjklzmxncbv'
def password():
    counter = 0
    if x[0] == '_':
        print 'correct heading'
        counter += 1
    elif x[0] in alphabet:
        print 'correct heading'
        counter += 1
    else:
        print 'Invalid heading'

    for i in range(1, len(x)):
        if x[i] not in symbols:
            print 'Invalid body'
        else:
            print 'valid body'
            counter += 1

    if counter == 2:
        print 'Valid'
    else:
        print 'Invalid'

    
password()
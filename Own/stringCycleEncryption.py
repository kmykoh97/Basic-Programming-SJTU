#A project to cycle and change the alphabets according to how much user wants
#Created by MyKoh
#2017-10-9

def stringCycleEncryption():
    initialList = []
    cycle = input('Please insert number of cycles:')
    stringRequest = raw_input('Please insert words needed to be encrypted:')
    for i in range(len(stringRequest)):
        if 65 <= ord(stringRequest[i]) + cycle <= 90 or 97 <= ord(stringRequest[i]) + cycle <= 122:
            initialList.append(chr(ord(stringRequest[i]) + cycle))
        elif ord(stringRequest[i]) + cycle > 122:
            initialList.append(chr(ord(stringRequest[i])+cycle-123+97))
        elif 91 <= ord(stringRequest[i]) + cycle <= 96:
            initialList.append(chr(ord(stringRequest[i])+cycle-91+65))
        elif ord(stringRequest[i]) == 32:
            initialList.append(' ')
        else:
            print 'Not valid'

    print ''.join(initialList)

stringCycleEncryption()
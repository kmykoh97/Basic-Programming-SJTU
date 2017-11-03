# Shangji Exercise No 3
# Meng Yit Koh 517030990022

def main():
    x = raw_input('Please input plain text:')
    print 'Encrypt:', ''.join(encrypt(x))#change returned list into string and print it out
    print 'Decrypt:', ''.join(decrypt(x))#change returned list into string and print it out
    

def encrypt(x):
    l = list(x)
    #First part:
    ini = 0
    for j in [8,7,3,4,9,6,2]:
        for i in range(ini,len(l),7):
            l[i] = (ord(l[i]) + j)
        ini += 1
    #Second part:
    for i in range(len(l)):
        if l[i] > 122:
            l[i] = 31 + (l[i] - 122)
    #Convert ASCII into string:
    for i in range(len(l)):
        l[i] = chr(l[i])

    return l

def decrypt(x):
    l = list(x)
    #Convert string into ASCII:
    for i in range(len(l)):
        l[i] = ord(l[i])
    #Second part:
    for i in range(len(l)):
        if 32 <= l[i] <= 40:
            l[i] = 122 - (l[i] - 31)
    #First part:
    ini = 0
    for j in [8,7,3,4,9,6,2]:
        for i in range(ini,len(l),7):
            l[i] = (l[i] - j)
        ini += 1
    #Convert ASCII into string:
    for i in range(len(l)):
        l[i] = chr(l[i])

    return l

#encrypt('wherewithal')
#decrypt('wherewithal')

main()

#Acronym Project
#Created by MyKoh
#2017-10-16

def acronym():
    x = raw_input('Please Insert: ')
    a = [x[0]]
    for i in range(len(x)):
        if x[i] == ' ':
            a.append(x[i+1])
    result = "".join(a)
    result = result.upper()

    for j in result:
        result = result.replace(' ', '')

    print result

acronym()
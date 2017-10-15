#A project to remove * in between strings and keep the beginning and end *
#Created by MyKoh
#2017-10-13

#wrong piece of code
def main():
    x = raw_input('Please insert:')
    for i in range(len(x)):
        if x[i] == '*':
            continue
        elif x[i] != '*':
            for j in range(i+1, len(x)):
                if x[j] == '*':
                    x = x.replace(x[j],'')
                
    print x

#main()
    
def main2():
    x = raw_input('Please insert:')
    i = 0
    j = -1
    for a in range(len(x)):
        if x[i] == '*':
            i += 1
        if x[j] == '*':
            j -= 1
    #x = x[i-1:j]
    #for x in x[i-1, j]:
        #if x[k] == '*':
    newx = x.replace('*', '')

    print x[:i] + newx + x[j+1:]

main2()



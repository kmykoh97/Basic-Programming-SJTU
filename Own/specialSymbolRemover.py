#A project to remove * in between strings and keep the beginning and end *
#Created by MyKoh
#2017-10-12

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


main()
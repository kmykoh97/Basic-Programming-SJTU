# Shangji Practice No 1
# Meng Yit Koh
# 517030990022

# compare 2 factor lists returned and choose the largest commmon factor
def main():
    x, y = input('Please insert positive integer:'), input('Please insert another positive integer:')
    factorsX, factorsY = factors(x), factors(y)
    HCFList = []
    for i in factorsX:
        for j in factorsY:
            if i == j:
                HCFList.append(i)
    HCF = max(HCFList)
    print 'HCF is:', HCF

# return a list of factors for given number
def factors(x):
    factorsList = []
    for i in range(1, x+1):
        if x % i == 0:
            factorsList.append(i)
    return factorsList

main()

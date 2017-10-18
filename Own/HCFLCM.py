#A program to find HCF, LCM
#Created by MyKoh
#2017-10-20

#Input: Integer a, b, c
#Output: HCF, LCM of a, b, c

def main():
    a, b, c = input('Please insert 3 numbers saparated by ,:')
    truthValue = True
    multipleA, multipleB, multipleC = 1, 1, 1
    newA, newB, newC = a, b, c
    while truthValue:
        newA = a * multipleA
        multipleA += 1
        while newB < newA:
            newB = b * multipleB
            multipleB += 1
        while newC < newA:
            newC= c * multipleC
            multipleC += 1
        
        if newA - newB == 0 and newA - newC == 0:
            truthValue = False

    print 'LCM is', str(newA)
        

   #alternative LCM: use lower number in that 3 and add 1 by 1 and if x % y== 0, lcm 
   #alternative: 3x for loops

main()
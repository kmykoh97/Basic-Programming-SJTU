#Project to generate a list of cube numbers added together to be same with numbers combined together
#Created by MyKoh
#2017-09-30

def cubeNumberEffect():
    for i in range(1,10):
        for j in range(10):
            for k in range(10):
                if i**3 + j**3 + k**3 == i*100 + j*10 + k:
                    print i*100 + j*10 + k

cubeNumberEffect()
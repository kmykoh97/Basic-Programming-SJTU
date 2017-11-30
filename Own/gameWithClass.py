# class gameMap:
#
#     def __init__(self, N):
#         self.N = N
#
#     def addAnimal(self, animal):
#
#     def printMap(self):
#
#
# class animals:
#
#     def __init__(self, life, x, y):
#         self.life = life
#         self.x = x
#         self.y = y
#
#     def moveTo(self, x, y):
#         differentX =
#
# class animalA()

class GameMap:

    def __init__(self,N):
        self.N = N
        animal_list = []

    def addAnimal(self,animal):
        animal_list.append(animal)

    def printMap(self):
        frame_origin = self.N*self.N * ['0']
        count = 0
        for i in range(len(frame_origin)):
            if i == self.y * 5 + self.x:
                frame_origin[i]= animal_list[]
                count += 1

        for j in range(len(frame_origin)):
            print frame_origin[j],
            if (j+1) % 5 == 0:
                print


class Animal:
    def __init__(self,life,x,y):
        self.life = life
        self.x = x
        self.y = y
        # list_x,list_y = [],[]
        # list_x.append(x)
        # list_y.append(y)

    def moveTo(self, x, y):
        differenceX = x - self.x
        differenceY = Y - self.y
        self.life = self.life - abs(differenceX)-abs(differenceY)

    def final(self):

        if self.life <= 0:


class AnimalA(Animal):
    type = ' A '
class AnimalB(Animal):
    type = ' B '
class AnimalC(Animal):
    type = ' C '

x = GameMap(9)
A1 = AnimalA(10,2,2)
B1 = AnimalB(4,5,1)
x.addAnimal(A1)
x.addAnimal(B1)
x.printMap()

A1.moveTo(5,1)
B1.moveTo(2,3)

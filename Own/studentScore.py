#Score gained by students
#Created by MyKoh
#2017-12-12

class studentScore:

    def __init__(self):
        # self.name = sName
        self.scoreList = []
        # self.english = english
        # self.maths = maths
        # self.physics = physics
        # self.chemistry = chemistry

    def addStudent(self, sName, scoreList):
        # sName = self.name
        self.english = scoreList[0]
        self.maths = scoreList[1]
        self.physics = scoreList[2]
        self.chemistry = scoreList[3]

    def printStudent(self, sName):
        if sName == self.name:
            print "%s = Engllish: %d, Mathematics: %d, Physics: %d, Chemistry: %d" % (self.name, self.english, self.maths, self.physics, self.chemistry)
        else:
            print 'Name not available!'

#     def printCurriculum(self, cName):
#         if cName == english:
#             print self.english
#         elif cName == maths:
#             print
#
#     def sAverageScore(self):
#         print (self.english + self.maths + self.physics + self.chemistry) / 4
#
#     def cAverageScore(self):
# def addStudent(nameInput, scoreList):
#     a = nameInput
#     b = scoreList[0]
#     c = scoreList[1]
#     d = scoreList[2]
#     e = scoreList[3]
Class = studentScore()
Class.addStudent('James', [2,2,2,2])
Class.addStudent('Ali', [100,100,100,100])
Class.addStudent('Abu', [5,6,7,8])
Class.addStudent('Retard', [0,0,0,0])
Class.printStudent('James')

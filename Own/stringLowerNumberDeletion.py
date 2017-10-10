#A project to change big letter strings to small and delete numbers then return them
#Created by MyKoh
#2017-10-10

def stringLowerNumberDeletion():
    userInsert = raw_input('Please insert:')
    for i in userInsert:
        if i in "1234567890":
            userInsert = userInsert.replace(i,'')
        
    print userInsert.lower()

stringLowerNumberDeletion()
class complex:

    def __init__(self, real, image):
        self.real = real
        self.image = image

    def square(self):
        a = self.real ** 2
        b = self.real * 2 * self.image
        c = self.image ** 2
        print a, "+", b, 'i', '-', c

    def add(self, real2, image2):
        a = self.real + real2
        b = self.image + image2
        print a, '+', b, 'i'

classInstance1 = complex(-2, 3)
classInstance1.square()
classInstance1.add(2, 3)

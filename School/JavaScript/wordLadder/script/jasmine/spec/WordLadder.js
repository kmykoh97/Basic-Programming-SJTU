describe("WordLadder", function() {
    var test;
 
    //This will be called before running each spec
    beforeEach(function() {
        test = new wordLadder();
    });
 
    describe("when these function are used: ", function(){
         
        //Spec for new word
        it("should be able to create new word based on word index and alphabet index given", function() {
            expect(test.newWord("word", 0, 1)).toEqual("bord");
        });
        
        //Spec for new word
        it("should be able to detect wrong index", function() {
            expect(test.newWord("word", -1, 1)).toEqual("bword");
        });

        //Spec for mpushing in stack
        it("should be able to push into stack and create a list", function() {
            expect(test.stackPush("test1", "test2")).toEqual(["test1", "test2"]);
        });
 
        //Spec for testing dictionary
        it("should be able to use dictionary to find word", function() {
            expect(test.dictionary("test")).toEqual(true);
        });

        //Spec for testing dictionary
        it("should be able to detect unavailable words", function() {
            expect(test.dictionary("noword")).toEqual(false);
        });
         
        //Spec for testing prototype of word ladder main block
        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("yoke", "yows");
            }).toThrowError(Error);
        });

        //Spec for printing
        it("should be able to print ladder in appropriate form", function() {
            expect(test.print(["a", "b", "c"])).toEqual("c -> b -> a");
        });



        /*
        Additional specs
        */
        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("apa", "khabar");
            }).toThrowError(Error);
        });

        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("i", "love");
            }).toThrowError(Error);
        });

        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("none", "nani");
            }).toThrowError(Error);
        });

        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("destroy", "destroyer");
            }).toThrowError(Error);
        });

        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("a", "e");
            }).toThrowError(Error);
        });

        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("??", ".");
            }).toThrowError(Error);
        });

        it("should be able to give appropriate stack of words", function() {
            expect(function() {
                test.ladder("??", "!@");
            }).toThrowError(Error);
        });

        it("should be able to display error when same words used", function() {
            expect(function() {
                test.ladder(">>", ">>");
            }).toThrowError(Error);
        });

        it("should be able to display error when same words used", function() {
            expect(function() {
                test.ladder("i", "i");
            }).toThrowError(Error);
        });

        it("should be able to display error when same words used", function() {
            expect(function() {
                test.ladder("apple", "apple");
            }).toThrowError(Error);
        });
         
    });
});
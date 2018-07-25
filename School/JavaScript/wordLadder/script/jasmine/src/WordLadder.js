wordLadder = function() {};
 
wordLadder.prototype.newWord = function(word, i, j) {
    var alphabet = "abcdefghijklmnopqrstuvwxyz";

    var newWord = word.substring(0, i) + alphabet[j] + word.substring(i + 1);

    return newWord;
}
 
wordLadder.prototype.stackPush = function(word1, word2) {
    var newStack = [];

    newStack.push(word1);
    newStack.push(word2);

    return newStack;
}
 
wordLadder.prototype.dictionary = function(word) {
    var dictionary = new Set();
    dictionary.add("cat").add("dog").add("cot").add("dot").add("test");

    return dictionary.has(word);
}

// implement word ladder using breath first search
wordLadder.prototype.ladder = function (word1, word2)
{
    var dictionary = new Set();
    dictionary.add("yoke").add("yowe").add("yows");

    // declarations
    var usedWords = new Set(); // set of used words
    var temp = []; // stack acts as first stack in qs
    var qs = new Queue(); // stack in queue to store all possible ladder
    var current = []; // act as main stack in calculation later

    temp.push(word1);
    qs.enqueue(temp);

    while (!qs.isEmpty()) {
        current = qs.dequeue();
        var currentWord = current[current.length - 1];
        for (var i = 0; i < currentWord.length; i++) {
            var alphabet = "abcdefghijklmnopqrstuvwxyz";

            for (var j = 0; j < alphabet.length; j++) {
                var newWord = currentWord.substring(0, i) + alphabet[j] + currentWord.substring(i + 1);

                if (!usedWords.has(newWord) && dictionary.has(newWord)) {
                    if (newWord == word2) {
                        current.push(newWord);
                        while (!qs.isEmpty()) { // if successful, make original qs empty to prevent further loop
                            qs.dequeue();
                        }
                        break;
                    } else {
                        usedWords.add(newWord);
                        var newStack = current.slice(0);
                        newStack.push(newWord);
                        qs.enqueue(newStack); // create new branch of possible solution as queue of stack
                        usedWords.add(newWord);
                    }
                }
            }
        }
    }
    
    return current;
}

wordLadder.prototype.print = function(stack) {
    var result = "";

    var count = stack.length;
    for (var i = 0; i < count - 1; ++i) {
        var k = stack.pop();
        result += k + " -> ";
    }
    var k = stack.pop();
    result += k;
    
    return result;
}

// var Jasmine = require('jasmine');
// var jasmine = new Jasmine();

// jasmine.onComplete(function(passed) {
//     if(passed) {
//         console.log('All specs have passed');
//     }
//     else {
//         console.log('At least one spec has failed');
//     }
// });
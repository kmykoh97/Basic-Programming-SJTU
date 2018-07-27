// implement word ladder using breath first search
function wordLadder(word1, word2, dictionary)
{
    // declarations
    var usedWords = new Set(); // set of used words
    var temp = []; // stack acts as first stack in qs
    var qs = new Queue(); // stack in queue to store all possible ladder
    var current = []; // act as main stack in calculation later

    temp.push(word1);
    qs.enqueue(temp);
    dictionary[word1] = 1;
    var tempList = new Array(); // new array to store words changed to 1 in dictionary to restore them later
    tempList.push(word1);

    while (!qs.isEmpty()) {

        // take the front queue of stack as current stack to perform algorithm then remove the stack already taken by current
        current = qs.dequeue();
        var currentWord = current[current.length - 1]; // start with the topmost string of current stack

        for (var i = 0; i < currentWord.length; i++) {
            var alphabet = "abcdefghijklmnopqrstuvwxyz";

            for (var j = 0; j < alphabet.length; j++) {
                var newWord = currentWord.substring(0, i) + alphabet[j] + currentWord.substring(i + 1);

                if (dictionary.hasOwnProperty(newWord) && dictionary[newWord] != 1) {
                    if (newWord == word2) {
                        current.push(newWord);

                        while (!qs.isEmpty()) { // if successful, make original qs empty to prevent further loop
                            qs.dequeue();
                        }
                        break;

                    } else {
                        // perform required copying and formation of new stack for BFS
                        var newStack = current.slice(0); // deep copy
                        newStack.push(newWord);
                        qs.enqueue(newStack); // create new branch of possible solution as queue of stack
                        tempList.push(newWord);

                        // deals with dictionary and used words set
                        usedWords.add(newWord);
                        dictionary[newWord] = 1;
                    }
                }
            }
        }
    }

    var count = current.length;
    if (current[0] != word1 || current[count-1] != word2) {
        for (var i = 0; i < count; i++) {
            current.pop();
        }
    }

    // reset dictionary's value
    for (var i = 0; i < tempList.length; i++) {
        dictionary[tempList[i]] = 0;
    }
    tempList = [];
    
    return current;
}
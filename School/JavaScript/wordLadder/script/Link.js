// function to display result
function reportResult(input)
{
    document.getElementById("display").innerHTML = input;
}

// starts the word ladder
function launch()
{
    // begin by pulling up the contents of the words
    var endWord = document.getElementById("first").value.trim().toLowerCase();
    var startWord = document.getElementById("second").value.trim().toLowerCase();

    // make sure both words in same length
    if (startWord.length !== endWord.length) {
        reportResult("Both words must have the same length!");
        return;
    }

    var ladder = wordLadder(startWord, endWord, words);

    // if no match, shows error
    if (ladder.length === 0) {
        reportResult("No ladder found from " + endWord + " to " + startWord);
    } else { // otherwise, print the ladder
        printLadder(ladder);
    }
}

// function to print ladder appropriately 
function printLadder(stack)
{
    var result = "";

    var count = stack.length;
    for (var i = 0; i < count - 1; ++i) {
        var k = stack.pop();
        result += k + " -> ";
    }
    var k = stack.pop();
    result += k;
    reportResult(result);
}
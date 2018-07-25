# Word Ladder

### Introduction  
To begin our study of graph algorithms let’s consider the following puzzle called a word ladder. Transform the word “FOOL” into the word “SAGE”. In a word ladder puzzle you must make the change occur gradually by changing one letter at a time. At each step you must transform one word into another word, you are not allowed to transform a word into a non-word. The word ladder puzzle was invented in 1878 by Lewis Carroll, the author of Alice in Wonderland. The following sequence of words shows one possible solution to the problem posed above.
```
FOOL
POOL
POLL
POLE
PALE
SALE
SAGE
```

### How to run
From vscode:
    Open the project folder using vscode then press f5 from the editor. Configuration to run the project using debugger has been writen.
From folder:
    Double click index.html If possible, please use Chrome Browser to open the file as all testing has been done in Chrome and NodeJs v8 engine(which is the same as Chrome JS engine).

### How to test  
All configurations have been set. Just double click SpecRunner.html - Shortcut located on main project page. Testing codes are writen in .script\jasmine\spec\WordLadder.js  

### Implementing BFS  

Queue
```JavaScript
Refers to Queue.js

/*After creating a queue, the enqueue and dequeue functions can be used to add items to the end of the queue and remove them from the front:*/

// create a new queue
var queue = new Queue();
// enqueue an item
queue.enqueue('item');
// dequeue an item
var item = queue.dequeue();

/*The peek function can be used to inspect the item at the front of the queue without dequeuing it:*/

// get the item at the front of the queue
var item = queue.peek();
// determine the number of items in the queue
var length = queue.getLength();
// determine whether the queue is empty
var isEmpty = queue.isEmpty();
```

Stack
```JavaScript
var stack = [];
stack.push(2); // stack is now [2]
stack.push(3); // stack is now [2, 3]
var i = stack.pop(); // stack is now [2]
alert(i); // displays 3
```

### Using libraries

using Jquery
```JavaScript
import https://code.jquery.com/jquery-3.3.1.min.js
OR
> npm install jquery
```

using Jasmine
```
download from https://jasmine.github.io/pages/getting_started.html
```

By Meng Yit Koh  
517030990022  
Shanghai Jiao Tong University  
SE112  
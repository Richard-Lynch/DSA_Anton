#Overview
##Aim
* practical knowledge of standard data structures and algorithms

##Calendar and Schedule
* 3 lectures + 1 tutorial + 1 lab per week
* Put times here when confirmed
* About ~8 assignments
* First week free?

Week Starting | Topics | Assignment
--------------|--------|-----------
date          | topics        | memory refresher
date          | topics        | memory refresher
date          | topics        | stacks/queues/lists
date          | topics        | stacks/queues/lists
date          | topics        | trees and graphs
date          | topics        | trees and graphs
date          | topics        | sorting
date          | topics        | sorting
date          | reading week  | searching
date          | topics        | searching
date          | topics        | hashing
date          | topics        | hashing
date          | review        | 
date          | exam break    | -


##Contents
* Structured types. Array, list, tree, and graph algorithms.
* Hash tables. Dynamic data structures. Abstract data types.
* Lots of practical lab work and skill development.

##Outcomes
1. know a complement of data structures and algorithms
2. understand which are more appropriate for given project
3. implement both efficiently
4. discuss size and computational cost and complexity of different approaches
5. strong code and analytical habits and code simiplification
6. able to employ a variety of profiling, debugging, and optimisation tools

##Good Habits
* Maintain a `my_name.c` set of utility data structures and functions.
* Build up a folder of test/experiment/demo projects e.g. on GitHub.
* Make time to practice 30mins-1hr per day, always.
* Read experts' code. Find their GitHub accounts etc. Ask. Steal their tricks.
* Work on projects with other people.

##Discussion Questions
* what is the fundamental task of a computer program?

* fundamental task of a computer program
  - transform data from input form to output form
  - algorithms formalise ordered transformation steps
  - data is structured by us to
    - help algorithm
    - represent input or output formats
    - make it easier to understand
    - perform better w/respect to computer hardware

* what are current graduates bad at?
  - interviews
  - computer science fundamentals
  - understanding hardware
  - low-level programming techniques
  - data

* why?
  - very broad range of software development skills
  - risk of very thin layer (not deep enough knowledge)
  - over-engineering
  - post-dot com era abstraction/"top-down" thinking
  - dependent on libraries/frameworks/stacks made by others
  - hours of experience

* goals of course
  1. beef up low-level programming competency
  2. practical knowledge of fundamental DS&A
  3. knowing /when/ and /why/ to introduce complexity
  4. finding the simplest solution
  5. formal analysis techniques
  6. optimisation and practical tools

-------------------------------------------------------

Refreshing C Programming
------------------------
* role of language, compiler, linker
* basic program structure
* headers, c files conventions, pragma, no code in header
* C99 (ignoring C++ for now)
* good habits, using blocks rather than lots of tiny functions
* memory allocation and deallocation
* pointers are not arrays
* pointers and addresses, dereferencing chains
* memory size and stride
* reading and writing
* structs
* copying memory using memcpy()
* debugging, backtraces, finding leaks
* inline functions
* profiling
* timers

First assignment/lab
--------------------
- self-assessment survey
- setting up compile environment with C
- memory allocation and looping over arrays
  + timers and simple analysis
- formal report/summary of program
- .c file
- grading rubrik similar to berkeley's

##Arrays

* sequential memory (each item has an address sizeof() bytes after the previous one)
* easy to write and access with an integer index. this is equiv of &first + sizeof() * i
* .: trivial to iterate over in a loop
* each array item can be POD (including a pointer) or a struct
* has a maximum size when inside a function (depends on computer and OS) - try it, find out how much
(on the stack)
* when a global it is store in static memory (similar to heap) and is essentially unlimited
* can be multi-dimensional (but multi-dimension arrays just flatten to 1d in memory)
* multi-dimensional arrays usually add confusion/hide data order which is unhelpful (why?)
* fixed length (although language extensions and libraries have dynamic or resizeable arrays)
* this should be your go-to option for 99% of cases (reasons why?)
* most complex data structures can be flattened into an array if you think about it hard enough
* dynamic memory allocation (on the heap) closely resembles an array but they are not exactly the same
* the computer is designed _at the hardware level_ to process sequential memory like arrays _most_ efficiently
* do you know how to find out and print the memory address values from e.g. every index of a 2d array?

##Dynamic Memory

* can allocate 1 item, or a whole block of them (like an array)
* if using a block then can be iterated over like an array
* can be initialised to 0 or some number with `calloc()`
* not fixed size. can be allocated using a variable after the program has started.
* e.g. user wants to write an image and chooses the dimensions and bits per pixel
* can also be resized later `realloc()`
* riskier than plain arrays because can introduce leaks
* allocation and deallocation are not free (don't do allocation or freeing inside a loop if poss)
* you can allocate a big pool at program start and then give subsequent requests bits of that
* if you need more resize the pool later
* pools can be freed when context ends (then you know all leaks are cleared)
* array of structs vs struct of arrays
* short story: helpful but C/C++ don't provide good tracking/accounting tools
* languages with automatic garbage collection introduce major performance problems
* best solution: know what's happening, know how and when to stimulate alloc/free events, create your own managers
* don't allow libraries or tools to have control over memory allocation or freeing.

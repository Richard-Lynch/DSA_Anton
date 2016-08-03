# Data Structures & Algorithms
notes, demos, slides
work in progress

## Demos

Some sort of visual demos of different ideas in action.
Is WebGL a good tool to do this? Or would it be better to have some exemplar C code and Makefiles etc...

folder | description
------ | -----------
linked_lists | building a simple linked list in C99
stacks | description
queues | description
lists | description
general_trees | description
binary_trees | description
binary_search_trees | description
sets_bags_graphs | description
traversing_graphs | description
sorting | description
hashing | description
classic_algorithms | description
cache_misses | description

## Practical Exercises Ideas

* Getting all the tools set up properly, especially the basic ones.
* Basic data structures. Arrays, matrices (2d arrays). Memory layouts.
* Fundamentals of memory, addresses, pointers. Heap and stack.
* Searching
* Sorting e.g. write a ... algorithm
* Measuring and estimating different peformance and cost aspects
* Good coding habits learned by measuring hidden-ish costs of bad ones.

If assignments write output to an image file...simple data transformation,
I/O, and visualise output of e.g. search algorithms. Can turn into a .gif.

## Twitter Responses

["hey programming professionals! what do you wish graduates knew about data structures and algorithms? i'm making a new course. please RT."](https://twitter.com/capnramses/status/752905320326950912)

* *the practical application of the concept that I am learning*. - Jitesh Mulchandani ‏@mjitesh  Jul 12
* *i wish they knew the difference between data/algos that fit in L1$, in L2$, L3$, RAM, HDD, cloud* - bmcnett ‏@bmcnett  Jul 12
* *I agree with everyone else that my exp with data structs was memorising for interviews; focus on playing around with stuff to actually get an understanding of benefits, pitfalls, etc. Get people to make mistakes! Also cache coherency :)* Kevin (Caoimhín) ‏@GamedevKevin  Jul 12
* *I saw a talk by Mike Acton recently about what he wished new game engine programmers knew. I will try to find the link.* -David Rappo ‏@DavidRappo  Jul 12
* *Are you planning to cover concurrent data structures and algorithms in your new course?* - David Rappo ‏@DavidRappo  Jul 12
* *Access patterns & cache effects, perf. wrt set size, memory usage, what to use and when, think about complexity vs maintenance* - Keith O'Conor ‏@keithoconor  Jul 12
* *How to measure how much time / space something takes and not just showing me the first solution they found on StackOverflow.* - Zachary Snow ‏@smack0007  Jul 12
* *Seriously, just getting them to use big-O thinking for more than just passing your test would be a win.* Sean W. ‏@sean_of_w  Jul 12
* *That when you write nested loops, I cringe before rewriting your code because production fell over.* Sean W. ‏@sean_of_w  Jul 12
* *Also: That most database indexes are really just clever binary trees, and thus have binary-tree performance* Sean W. ‏@sean_of_w  Jul 12 characteristics.
* *That you need more data structures than just "array" and "brand X database server."* Sean W. ‏@sean_of_w  Jul 12
* *Algorithmic analysis and Big-O most important.*
Stephen Oman ‏@stephen_oman  Jul 12

##Resources

Some good books and websites with good animations or demonstrations.

* Amit Patel - http://www.redblobgames.com/
* David Galles of USFCA - https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
* Keith O'Conor's slides from talks at TCD - http://www.fragmentbuffer.com/publications/
* Valgrind - http://valgrind.org/
* Cachegrind manual - http://valgrind.org/docs/manual/cg-manual.html 
   * a good cache-miss example for L1 (next to registers) is traversing a matrix by column with power-of-two rows

##Tools

* Compilers/linkers: GCC, MinGW, Clang, MS cl
* Debuggers: GDB, LLDB, MSVS
* Visual interfaces: Visual Studio Code, Visual Studio, etc. etc.
* Profiling and perf: `perf stat ./my_prog` (some CPUs need explicit `perf stat -B -e cache-references,cache-misses,cycles,instructions,branches,faults,migrations sleep 5`), `/usr/bin/time -v ./my_prog`, `valgrind ./my_prog`, `valgrind --tool=cachegrind ./my_prog`, gprof, top, sysmons, high-precision timers in code, Intel VTune and PCM, AMD CodeAnalyst and CodeXL, MS Visual Studio Profiler.
* Static analysis: scan-build
* turning on `-fsanitize=address` and `-fsanitize=leak` etc. might be helpful

#Assignment 0, First lab (draft)

##Purpose of Assignment and Lab

* refresh C programming basics
  * basic compiler skills
  * loops
  * dynamic memory allocation
  * pointers and addresses
  * functions
* ensure that you can log in/submit work etc.
* create a useful data visualisation tool

##Deliverables

* A pdf containing your final output image and a brief summary of your solution
* Your .c file (with your name and date in a comment in the top).
* Do not submit IDE project/solution files, or the compiled binary.

Please do not compress these into a .zip - it's harder for the demonstrators to
open in the web system.

##Instructions

Complete the self-assessment survey first.

You are to write a simple C program that allocates some memory, manipulate that
memory using built-in functions and your own loops, and then visualise that
memory by writing it out to an image file. We will not be using C++ memory
allocation (the `new` keyword) for this assignment - we want to dig deeper. We
won't be using any third-party libraries.

###Part 1

Set up an environment to compile a simple C "Hello World" type program. You
may use any compiler/IDE software. The labs should have at least gcc (GNU C
Compiler) on the command line and Visual Studio.
Use either the `malloc()` or `calloc()` function to allocate an array of bytes to store your image.
You may define a width and height variable for your image size.
Each pixel in your image requires 3 bytes - one for each of the red, green, and
blue channels, respectively.
The unsigned char data type is a good representation of 1 byte in C.
Use the `memset()` function to clear the entire image to white.
Use `free()` to deallocate the memory before the program exits. Note that on exit
our leaked memory will be automatically freed, but it's a good habit.

###Part 2

PPM is a very simple image format that can viewed by most image-viewing
software, and can be written as an ASCII text file.

It should have the declaration:

    void write_ppm(const unsigned char* image_data, int w, int h);

Where w and h are a width and height, respectively, in pixels. image_data is an
array of bytes that you will create in memory, containing the colours of each
pixel.

The specification for the format may be found at http://netpbm.sourceforge.net/doc/ppm.html
You may use the binary version of PPM (P6) if you want but I suggest that the ASCII
version is better to start with (P3).

Your function should occupy less than 20 lines of code.

Use the function to write your block of image memory out to a file. Open it
in an image viewer or paint program.

##Part 3

Write a loop or loops to draw a diagonal line from one corner of the image to
another.
Write this image to a file.
You may need to tell your image viewing software to disable anti-aliasing/blurring
to see the pixels clearly.

##Comments, Suggestions

* If this is easy, good. If not, ask for help - you may need to schedule some
practice time!
* If your program crashes with a segfault it almost certainly means that you
are accessing memory outside the bounds of what you have allocated. Did you
remember that each pixel needs 3 bytes of memory?
* Compilers usually look at file extensions to determine if they should compile
in C or C++ mode. i.e. main.c, rather than main.cpp.
* If your solution is over 50 lines of code, think about simplifying it.
* Have a good grasp of C memory functions; `malloc()`, `calloc()`, `free()`,
`memset()`, `memcpy()` etc. and other basic C functions; `assert()` file I/O etc.
* You may have to look up these functions to find out which header file to use;
e.g. malloc() is in stdlib.h but memcpy() is in string.h.
* On Unix-derived operating systems you can type `man memcpy` etc. To get a
manual page for that function. There are good websites too; cprogramming.com,
cplusplus.com.
* I usually prefer C to C++ and set my compiler to build in C99 mode, which is
friendlier to work with. Visual Studio doesn't have excellent C99 support last
time I checked.
* For a nice library to write to other formats of image look for [stb_image_write](https://github.com/nothings/stb/blob/master/stb_image_write.h)
* If you write images out in a sequence with numbered filenames you can turn them
into a .gif or movie file.

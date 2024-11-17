# cbintxt v0.1

`cbintxt` is an application that converts text files into C source files that can be linked to and compiled.
This allows for text files to be linked into a C program at compile-time, and the text file included in the compiled binary. 

Without `cbintxt`, the file must be accessed at runtime with `fopen`, which requires error-checking to ensure the file exists and was opened correctly. This is error-prone; if the file is deleted or the executable is moved, your program won't work.

To use `cbintxt`, compile it with CMake and run it with the following arguments:

`cbintxt <output> <input> ...`

`<output>` arguments are a filename, without the extension. (The .c or .h is added automatically for you.) The files that `cbintxt` creates will be named `<output>.h` and `<output>.c`.

You can put as many `<input>` arguments as you'd like. Each of them is a text file you'd like to turn into a .c file. In future these will be compiled into different functions in the same .c/.h file, but currently the text in them is just concatenated.

Once the .c and .h files have been created, you can #include them in your project like you would any other file. (Don't forget add them to your build system!).

Future versions of `cbintxt` will have better documentation (and CMake will be configured in a better way). This works for what I need it to do, though, and I'm really busy, so I don't know when I'll get around to that.

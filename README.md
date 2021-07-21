# BrainF-ck-Interpreter

An interpreter for the BrainF-ck language written in C++. The default 8 commands are the syntax. All other characters
can be used as a comment, since they are ignored. Each cell is an integer (4 bytes) instead of the single byte to allow
for bigger numbers.

Compile using CMakeLists.txt and use the following command to run:

```
BrainF_ck_Interpreter.exe helloworld.b 256
```

The two arguments required are the source file, and the number of cells.

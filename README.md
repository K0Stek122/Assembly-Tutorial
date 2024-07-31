This project is a supplementary to the tutorial that i host at [My Blog](https://themindpalace.bearblog.dev/assembly-pt-1-the-absolute-basics-of-assembly/).
Although it can be used on its own since it has enough comments.
If you want to do this on your own, This is the order of the projects, from simplest to most complex:
1. int_arithmetic
2. bitwise_logical_ops
3. shift_ops

## Compilation
To compile any of the projects you can do the following:
First, compile .asm with nasm:
`nasm -f win32 --prefix _ -o (assemblyObjectOutput).o (assemblyfile).asm`
Then, link with the corresponding cpp file:
`g++ -m32 assemblyObject.o cppFile.cpp -o output.exe`
## Return-oriented programming


#### Presentation

1. Introduction
    * What is return-oriented programming?
    * Before we begin...
    * Examples
    * History

2. Return-oriented programming in a nutshell
    * x86 crash course
    * Stack buffer overflow
    * Gadgets

3. Demonstration
    * ROPgadget – a ROP compiler
    * Stupid vulnerable program
    * Showtime!

4. Countermeasures
    * ASLR and PIE
    * Stack canaries and shadow stacks
    * CFI and ROPdefender

5. Conclusion



#### Demonstration

The [demo](https://github.com/haggl/return-oriented-programming/tree/master/demo) directory contains a working example program a `Makefile`, which automates generation and execution of a suitable exploit.



#### License

<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-sa/3.0/88x31.png" /></a><br />This work</span> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/deed.en_US">Creative Commons Attribution-ShareAlike 3.0 Unported License</a>.

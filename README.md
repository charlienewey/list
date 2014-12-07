list
====

A simple, high-performance linked-list data structure written in C.
Inspiration drawn from [David Muto's blog post](http://pseudomuto.com/development/2013/05/02/implementing-a-generic-linked-list-in-c/).

Build
=====

For development version (with debug symbols and all warnings turned on):
```bash
make dev
```

For production version (no debug symbols, more optimisations):
```
make prod
```

Usage
=====

You can include the linked list in your project by either:
* Compiling the code to a shared library (using the Makefile) and linking it in
* Including the `.c` and `.h` files directly in your project

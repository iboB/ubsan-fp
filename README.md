
# ubsan-fp
A false positive in the undefined behavior sanitizer

## Repro steps

* Have a shared library which exports a type `argument`
    * In this example this library is `core`
* Have another shared library which produces a function pointer to a function which takes `argument` as an argument
	* In this example this library is `other` through the function `get_fptr`
* In a third library or an executable get the function pointer and invoke it
* Receive a false positive undefined behavior error from ubsan:

```
executable.cpp:5:5: runtime error: call to function (unknown) through pointer to incorrect function type 'void (*)(argument *)'
(libotherlib.so+0x9e0): note: (unknown) defined here
SUMMARY: UndefinedBehaviorSanitizer: executable.cpp:5:5 in
```

## Checked invariants

* How I produce the pointer doesn't seem to matter. I get the same error with a static free function and a captureless lambda.
* `argument` needs to be defined in a shared library which is not the one that produces the function pointer. If we move the definition and export of `argument` to `other` there is no error from ubsan
* Whether the definition of `argument` is available to the call site (executable) doesn't seem to matter. I get the same error with or without including `corelib.hpp`

This is ademonstration of incomplete types in C.

	Useful for encapsulation of data. You basically hide the implementation
of the object data from the user of your interface.  

	Because in your header file you forward declare a pointer to the structure
that you define in your source file, every module that includes your header
does not have access to your structure fields. Modules include only the pointer
to your structure, so they do not need to know the size of the structure 
(all pointers are the same size) in order to compile. This also means that you
are free to modify your structure in any way and only your module needs to 
recompile.
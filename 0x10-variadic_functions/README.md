Variadic Functions:
These are functions that take a variable (indefinite) number and type
of arguments. They are in an almost similar manner to ordinary functions
except that an ellipsis is added at the end of the arguments list to 
signify an unknown number of optional arguments of unknown type.

stdarg.h provides the facilities that facilitate existence of these kind of functions.
The facilities include a data type, va_list and macros tThe macros include:
va_start - which initializes the arguments list
va_args - gets the next optional argument in the list
va_end - clears the initialized va_list
va_copy - available starting C99, can copy the va_list to another 'list'

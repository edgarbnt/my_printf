Epitech Project: my_printf

Duo project, my duo : [Enzo Dubeaurepaire](github.com/EnzoDubeaurepaire)

Task Description:

Your assignment involves re-implementing the printf function from the C library in accordance with the C99 standard. 
The prototype of your function should mirror that of the printf function. 
However, you are not required to handle the printf buffer in the C library.

Your implementation should support all printf formatting flags except for the following optional ones:

    Management of float or double types
    Management of the %n flag
    Handling of " * ", " ' ", and " I " (capital i) flags

Additionally, you are required to introduce two new formatting flags:

    %b: This flag should print unsigned numbers in binary base.
    %S: This flag should print a character string similar to %s. However, non-printable characters (ASCII value strictly less than 32 or greater than or equal to 127) must be represented by a backslash followed by the character’s value in octal base.

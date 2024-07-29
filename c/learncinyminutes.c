#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv) {
    // print output using printf, for "print formatted"
    // %d is an integer, \n is a newline
    printf("%d\n", 0);  // => prints 0

    // take input using scanf
    // '&' is used to define the (memory) location
    // where we want to store the input value
    int input;
    printf(">>> Enter an int: ");
    int temp = scanf("%d", &input);
    printf("%d\n", temp);

    ///////////////////////////////////////
    // Types
    ///////////////////////////////////////

    // Compilers that are not C99-compliant require that variables MUST be
    // declared at the top of the current block scope.
    // Compilers that ARE C99-compliant allow declarations near the point where
    // the value is used.
    // For the sake of the tutorial, variables are declared dynamically under
    // C99-compliant standards.

    // ints are usually 4 bytes (use the `sizeof` operator to check)
    int x_int = 0;

    // shorts are usually 2 bytes (use the `sizeof` operator to check)
    short x_short = 0;

    // chars defined as the smallest addressable unit for a processor
    // this is usually 1 byte, but for some systems it can be more
    char x_char = 0;
    char y_char = 'y';  // char literals are quoted with ''

    // longs are often 4 to 8 bytes; long longs are guaranteed to be at least 8 bytes
    long x_long = 0;
    long long x_long_long = 0;

    // floats are usually 32-bit floating-point numbers
    float x_float = 0.0f;   // 'f' suffix here denotes floating point literal

    // doubles are usually 64-bit floating-point numbers
    double x_double = 0.0;  // real numbers without any suffixes are doubles

    // integer types may be unsigned (greater than or equal to zero)
    unsigned short ux_short;
    unsigned int ux_int;
    unsigned long long ux_long_long;

    // chars inside single quotes are integers in machine's character set
    '0';    // => 48 in the ASCII character set
    'A';    // => 65 in the ASCII character set

    // sizeof(T) gives you the size of a variable with type T in bytes
    // sizeof(obj) gives you the size of the expression (variable, literal, etc.)
    printf("the size of an int is %zu bytes\n", sizeof(int));    // => 4 (on most machines with 4-byte words)

    // if the argument of the `sizeof` operator is an expression, then its argument is not
    // evaluated (except VLAs (see below))
    // the value it yields in this case is a compile-time constant
    int a = 1;
    // size_t is an unsigned integer type of at least 2 bytes used to represent the size of an object
    size_t size = sizeof(a++);  // a++ is not evaluated
    printf("sizeof(a++) = %zu where a = %d\n", size, a);
    // prints "sizeof(a++) = 4 where a = 1" (on a 32-bit architecture)\

    // arrays must be initialized with a concarete size
    char my_char_array[20]; // this array occupies 1 * 20 = 20 bytes
    int my_int_array[20];   // this array occupies 4 * 20 = 80 bytes

    // you can initialize an array of twenty ints that all equal 0 thusly:
    int my_array[20] = {0};
    // where the "{0}" part is called an "array initializer"
    // all elements (if any) past the ones in the initializer are initialized to 0:
    int my_other_array[5] = {1, 2};
    // so now my_other_array now has five elements, all but the first two of which are 0:
    // [1, 2, 0, 0, 0]
    // NOTE: you get away without explicity declaring the size of the array  IF you initialize the
    // array on the same line
    int my_little_array[] = {0};
    // NOTE: when not declaring the size, the size of the array is the number of elements in the
    // initializer. With "{0}", my_little_array is now of size one: [0]
    // to evaluate the size of the array at run-time, divide its byte size by the byte size of
    // its element type:
    size_t my_array_size = sizeof(my_array) / sizeof(my_array[0]);
    printf("the size of my_array is %zu bytes where my_array[0] = %d\n", my_array_size, my_array[0]);
    // WARNING: you should evaluate the size *before* you begin passing the array to functions
    // (see later discussion) because arrays get "downgraded" to raw pointers when they are passed
    // to functions (so the statement above will produce the wrong result inside the function)

    // indexing an array is like other languages -- or, rather, other languages are like C
    printf("%d\n", my_array[1]);

    // arrays are mutable; it's just memory!
    my_array[1] = 2;
    printf("%d\n", my_array[1]);    // => 2

    // in C99 (and as an optional feature in C11), variable-length arrays (VLAs) can be declared
    // as well. the size of such an array need not be a compile time constant
    printf(">>> Enter the array size: ");
    int array_size;
    temp = fscanf(stdin, "%d", &array_size);
    int var_length_array[array_size];
    printf("sizeof array = %zu\n", sizeof var_length_array);

    // example:
    // > enter the array size: 10
    // > sizeof array = 40

    // strings are just arrays of chars terminated by a NULL (0x00) byte, represented in
    // strings as the special character '\0'. (we don't have to include the NULL by in
    // string literals; the compiler inserts it at the end of the array for us)
    char a_string [20] = "This is a string";
    printf("%s\n", a_string);

    printf("%d\n", a_string[16]);   // => 0
    // i.e., byte #17 is 0 (as are 18, 19, and 20)

    // if we have characters between signle quotes, that's a character literal.
    // it's of type `int` and *not* `char` (for historical reasons)
    int cha = 'a';  // fine
    char chb = 'a'; // fine too (implicit conversion from int to char)

    // multi-dimensional arrays:
    int multi_array[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0}
    };
    // access elements
    int array_int = multi_array[0][2];  // => 3

    ///////////////////////////////////////
    // Operators
    ///////////////////////////////////////

    // shorthands for multiple declarations:
    int i1 = 1, i2 = 2;
    float f1 = 1.0, f2 = 2.0;

    int b, c;
    b = c = 0;

    // arithmetic straightforward
    printf("i1 = %d, i2 = %d\n", i1, i2);
    printf("i1 + i2 = %d\n", i1 + i2);  // => 3
    printf("i1 - i2 = %d\n", i1 - i2);  // => -1
    printf("i1 * i2 = %d\n", i1 * i2);  // => 2
    printf("i1 / i2 = %d\n", i1 / i2);  // => 0 (0.5, but truncated towards 0)

    // you need to cast at least one integer to float to get a floating-point result
    printf("(float)i1 / i2 = %f\n", (float)i1 / i2);    // => 0.5f
    printf("i1 / (double)i2 = %f\n", i1 / (double)i2);  // => 0.5f
    printf("f1 = %f, f2 = %f\n", f1, f2);
    printf("f1 / f2 = %f\n", f1 / f2);  // => 0.5, plus or minus epsilon

    // floating-point numbers are defined by IEEE 754, thus cannot store perfectly exact
    // values. For instance, the following does not produce expected results because
    // 0.1 might actually be 0.099999999999 inside the computer, and 0.3 might be stored as
    // 0.300000000001
    printf("(0.1 + 0.1 + 0.1) != 0.3 => %s\n", (0.1 + 0.1 + 0.1) != 0.3 ? "true" : "false");
    // and it is not associative due to reasons mentioned above
    int result = 1 + (1e123 - 1e123) != (1 + 1e123) - 1e123;
    printf("1 + (1e123 - 1e123) != (1 + 1e123) - 1e123 => %s\n", result ? "true" : "false");
    // this notation is scientific notion for numbers: 1e123 = 1 * 10^123

    // it is important to note that most all systems have used IEEE 754 to represent floating points.
    // even python, used for scientific computing, eventually calls C which uses IEEE 754. it is
    // mentioned this way not to indicate that this is a poor implementation, but instead as a
    // warning that when doing floating-point comparisons, a little bit of error (epsilon) needs
    // to be considered

    // modulo is there as well, but be careful if arguments are negative
    printf("11 %% 3 = %d\n", 11 % 3);   // => 2 as 11 = 2 + 3*x (x=3)
    printf("(-11) %% 3 = %d\n", (-11) % 3); // => -2, as one would expect
    printf("11 %% (-3) = %d\n", 11 % (-3)); // => 2 and not -2, and it's quite conterintuitive

    // comparison operators are probably familiar, but there is no Boolean type in C. We use ints
    // instead. (C99 introduced the _Bool type provided in stdbool.h)
    // 0 is false, anything else is true (the comparison operators always yield 0 or 1)
    printf("3 == 2 = %s\n", 3 == 2 ? "true" : "false");
    printf("3 != 2 = %s\n", 3 != 2 ? "true" : "false");
    printf("3 > 2 = %s\n", 3 > 2 ? "true" : "false");
    printf("3 < 2 = %s\n", 3 < 2 ? "true" : "false");
    printf("3 <= 2 = %s\n", 3 <= 2 ? "true" : "false");
    printf("3 >= 2 = %s\n", 3 >= 2 ? "true" : "false");

    return 0;
}
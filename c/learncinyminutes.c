#include <stdlib.h>

#include <stdio.h>

#include <string.h>

int main(int argc, char** argv) {
    // print output using printf, for "print formatted"
    // %d is an integer, \n is a newline
    printf("%d\n", 0); // => prints 0

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
    char y_char = 'y'; // char literals are quoted with ''

    // longs are often 4 to 8 bytes; long longs are guaranteed to be at least 8 bytes
    long x_long = 0;
    long long x_long_long = 0;

    // floats are usually 32-bit floating-point numbers
    float x_float = 0.0f; // 'f' suffix here denotes floating point literal

    // doubles are usually 64-bit floating-point numbers
    double x_double = 0.0; // real numbers without any suffixes are doubles

    // integer types may be unsigned (greater than or equal to zero)
    unsigned short ux_short;
    unsigned int ux_int;
    unsigned long long ux_long_long;

    // chars inside single quotes are integers in machine's character set
    '0'; // => 48 in the ASCII character set
    'A'; // => 65 in the ASCII character set

    // sizeof(T) gives you the size of a variable with type T in bytes
    // sizeof(obj) gives you the size of the expression (variable, literal, etc.)
    printf("the size of an int is %zu bytes\n", sizeof(int)); // => 4 (on most machines with 4-byte words)

    // if the argument of the `sizeof` operator is an expression, then its argument is not
    // evaluated (except VLAs (see below))
    // the value it yields in this case is a compile-time constant
    int a = 1;
    // size_t is an unsigned integer type of at least 2 bytes used to represent the size of an object
    size_t size = sizeof(a++); // a++ is not evaluated
    printf("sizeof(a++) = %zu where a = %d\n", size, a);
    // prints "sizeof(a++) = 4 where a = 1" (on a 32-bit architecture)\

    // arrays must be initialized with a concarete size
    char my_char_array[20]; // this array occupies 1 * 20 = 20 bytes
    int my_int_array[20]; // this array occupies 4 * 20 = 80 bytes

    // you can initialize an array of twenty ints that all equal 0 thusly:
    int my_array[20] = {
        0
    };
    // where the "{0}" part is called an "array initializer"
    // all elements (if any) past the ones in the initializer are initialized to 0:
    int my_other_array[5] = {
        1,
        2
    };
    // so now my_other_array now has five elements, all but the first two of which are 0:
    // [1, 2, 0, 0, 0]
    // NOTE: you get away without explicity declaring the size of the array  IF you initialize the
    // array on the same line
    int my_little_array[] = {
        0
    };
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
    printf("%d\n", my_array[1]); // => 2

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
    char a_string[20] = "This is a string";
    printf("%s\n", a_string);

    printf("%d\n", a_string[16]); // => 0
    // i.e., byte #17 is 0 (as are 18, 19, and 20)

    // if we have characters between signle quotes, that's a character literal.
    // it's of type `int` and *not* `char` (for historical reasons)
    int cha = 'a'; // fine
    char chb = 'a'; // fine too (implicit conversion from int to char)

    // multi-dimensional arrays:
    int multi_array[2][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 0}
    };
    // access elements
    int array_int = multi_array[0][2]; // => 3

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
    printf("i1 + i2 = %d\n", i1 + i2); // => 3
    printf("i1 - i2 = %d\n", i1 - i2); // => -1
    printf("i1 * i2 = %d\n", i1 * i2); // => 2
    printf("i1 / i2 = %d\n", i1 / i2); // => 0 (0.5, but truncated towards 0)

    // you need to cast at least one integer to float to get a floating-point result
    printf("(float)i1 / i2 = %f\n", (float)i1 / i2); // => 0.5f
    printf("i1 / (double)i2 = %f\n", i1 / (double)i2); // => 0.5f
    printf("f1 = %f, f2 = %f\n", f1, f2);
    printf("f1 / f2 = %f\n", f1 / f2); // => 0.5, plus or minus epsilon

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
    printf("11 %% 3 = %d\n", 11 % 3); // => 2 as 11 = 2 + 3*x (x=3)
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

    // C is not Python - comparisons do NOT chain
    // WARNING: the line below will compile, but it means `(0 < a) < 2`
    // This expressions is always true because (0 < a) could be either 1 or 0
    // In this case it's 1, because (0 < 1)
    int between_0_and_2 = 0 < a < 2;
    printf("0 < a < 2 => %s\n", between_0_and_2 ? "true" : "false");
    // Instead use:
    between_0_and_2 = 0 < a && a < 2;
    printf("0 < a && a < 2 => %s\n", between_0_and_2 ? "true" : "false");

    // Logic works on ints
    printf("!3 => %d\n", !3);
    printf("!0 => %d\n", !0);
    printf("1 && 1 => %d\n", 1 && 1);
    printf("0 && 1 => %d\n", 0 && 1);
    printf("0 || 1 => %d\n", 0 || 1);
    printf("0 || 0 => %d\n", 0 || 0);

    // Conditional ternary expression ( ? : )
    int e = 5;
    int f = 10;
    int z = (e > f) ? e : f;
    printf("e = %d, f = %d\n", e, f);
    printf("z = (e > f) ? e : f => %d\n", z); // => 10 "if e > f return e, else return f."

    // Increment and decrement operators:
    int j = 0;
    int s = j++; // Return j THEN increase j. (s = 0, j = 1)
    s = ++j; // Increase j THEN return j. (s = 2, j = 2)
    // same with j-- and --j
    printf("j = %d, s = %d\n", j, s);
    printf("s = j++ => %d\n", s);

    // Bitwise operators!
    ~0x0F; // => 0xFFFFFFF0 (bitwise negation, "1's complement", example result for 32-bit int)
    0x0F & 0xF0; // => 0x00 (bitwise AND)
    0x0F | 0xF0; // => 0xFF (bitwise OR)
    0x04 ^ 0x0F; // => 0x0B (bitwise XOR)
    0x01 << 1; // => 0x02 (bitwise left shift (by 1))
    0x02 >> 1; // => 0x01 (bitwise right shift (by 1))
    printf("~0xF0 => %#08X\n", ~0x0F);
    printf("0x0F & 0xF0 => %#08X\n", 0x0F & 0xF0);
    printf("0x0F | 0xF0 => %#08X\n", 0x0F | 0xF0);
    printf("0x04 ^ 0x0F => %#08X\n", 0x04 ^ 0x0F);
    printf("0x01 << 1 => %#08X\n", 0x01 << 1);
    printf("0x02 >> 1 => %#08X\n", 0x02 >> 1);

    // Be careful when shifting signed integers - the following are undefined:
    // - shifting into the sign bit of a signed integer (int a = 1 << 31)
    // - left-shifting a negative number (int a = -1 << 2)
    // - shifting by an offset which is >= the width of the type of the LHS:
    //   int a = 1 << 32; // UB if int is 32 bits wide

    ///////////////////////////////////////
    // Control Structures
    ///////////////////////////////////////

    if (0) {
        printf("I am never run\n");
    }
    else if (0) {
        printf("I am also never run\n");
    }
    else {
        printf("I print\n");
    }

    // While loops exist
    int ii = 0;
    while (ii < 10) { // ANY value less than ten is true.
        printf("%d, ", ii++); // ii++ increments ii AFTER using its current value.
    } // => prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "

    printf("\n");

    int kk = 0;
    do {
        printf("%d, ", kk);
    } while (++kk < 10); // ++kk increments kk BEFORE using its current value.
    // => prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "

    printf("\n");

    // For loops too
    int jj;
    for (jj = 0; jj < 10; jj++) {
        printf("%d, ", jj);
    } // => prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "

    printf("\n");

    // *****NOTES*****:
    // Loops and Functions MUST have a body. If no body is needed:
    int i;
    for (i = 0; i <= 5; i++) {
        ; // use semicolon to act as the body (null statement)
    }
    // Or
    for (i = 0; i <= 5; i++);

    // branching with multiple choices: switch()
    switch (a) {
    case 0: // labels need to be integral *constant* expressions (such as enums)
        printf("Hey, 'a' equals 0!\n");
        break; // if you don't break, control flow falls over labels
    case 1:
        printf("Huh, 'a' equals 1!\n");
        break;
        // Be careful - without a "break", execution continues until the
        // next "break" is reached.
    case 3:
    case 4:
        printf("Look at that.. 'a' is either 3, or 4\n");
        break;
    default:
        // if `some_integral_expression` didn't match any of the labels
        fputs("Error!\n", stderr);
        exit(-1);
        break;
    }

    // Using "goto" in C
    // typedef enum { false, true } bool;
    typedef enum { false, true } bool;
    // C before C99 doesn't have bool as a data type
    bool disaster = false;
    // int i, j;
    for (i = 0; i < 100; ++i) {
        for (j = 0; j < 100; ++j) {
            if ((i + j) >= 150) {
                disaster = true;
            }
            if (disaster) goto error;
        }
    }

error: // this is a label that you can "jump" to with "goto error;"
    printf("Error occurred at i = %d & j = %d\n", i, j);

    // https://ideone.com/GuPhd6
    // this will print out "Error occurred at i = 51 & j = 99."

    // it is generally considered bad practice to do so, except if
    // you really know what you are doing. See
    // https://en.wikipedia.org/wiki/Spaghetti_code#Meaning


    ///////////////////////////////////////
    // Typecasting
    ///////////////////////////////////////

    // Every value in C has a type, but you can cast one value into another type
    // if you want (with some constraints).

    int x_hex = 0x01; // You can assign vars with hex literals
    // binary is not in the standard, but allowed by some
    // compilers (x_bin = 0b0010010110)

    // Casting between types will attempt to preserve their numeric values
    printf("%d\n", x_hex); // => Prints 1
    printf("%d\n", (short)x_hex); // => Prints 1
    printf("%d\n", (char)x_hex); // => Prints 1

    // If you assign a value greater than a types max val, it will rollover
    // without warning.
    printf("%d\n", (unsigned char)257); // => 1 (Max char = 255 if char is 8 bits long)

    // For determining the max value of a `char`, a `signed char` and an `unsigned char`,
    // respectively, use the CHAR_MAX, SCHAR_MAX and UCHAR_MAX macros from <limits.h>

    // Integral types can be cast to floating-point types, and vice-versa.
    printf("%f\n", (double)100); // %f always formats a double...
    printf("%f\n", (float)100); // ...even with a float.
    printf("%d\n", (char)100.0);

    ///////////////////////////////////////
    // Pointers
    ///////////////////////////////////////

    // a pointer is a variable declared to store a memory address. Its declaration will
    // also tell you the type of data it points to. You can retrieve the memory address
    // of your variables, then mess with them

    int x = 0;
    printf("%p\n", (void*)&x); // use  & to retrieve the address of a variable
    // (%p formats an object pointer of the type void*)
    // => prints some address in memory

    // pointers start with * in their declaration
    int* px, not_a_pointer; // px is a pointer to an int
    px = &x; // stores the address of x in px
    printf("%p\n", (void*)px); // => prints some address in memory
    printf("%zu, %zu\n", sizeof(px), sizeof(not_a_pointer));
    // => prints "8, 4" on a typical 64-bit system

    // to retrieve the value at the address a pointer is pointing to, put a * in front
    // to dereference it.
    // NOTE: yes, it may be confusing that '*' is used for _both_ declaring a pointer
    // and dereferencing it
    printf("%d\n", *px);

    // you can also change the value the pointer is pointing to. we'll have to wrap the
    // dereference in parentheses because ++ has a higher precedence than *
    (*px)++; // increment the value px is pointing to by 1
    printf("%d\n", *px); // => prints 1
    printf("%d\n", x); // => prints 1

    // arrays are a good way to allocate a contiguous block of memory
    int x_array[20]; // declares array of size 20 (cannot change size)
    int xx;
    for (xx = 0; xx < 20; xx++) {
        x_array[xx] = 20 - xx;
    } // initialize x_array to 20, 19, 18, ..., 2, 1

    // declare a pointer of type int and initialize it to point to x_array
    int* x_ptr = x_array;
    // x_ptr now points to the first element in array (the integer 20). this works because
    // arrays often decay into pointers to their first element. for example, when an array
    // is passed to a function or is assigned to a pointer, it decays into (implicityly
    // converted to) a pointer.
    // EXCEPTIONS: when the array is the argument of the `&` (address-of) operator:
    int arr[10];
    int (*ptr_to_arr)[10] = &arr; // &arr is NOT of type `int*`!

    return 0;
}
# Coding Style

We are using [Astyle](http://astyle.sourceforge.net/astyle.html) tools to format the code.

To check coding style on all sources of the project:

``` bash
./tools/coding_style/check.sh
```

To apply coding style on a file:

``` bash
./tools/coding_style/format.sh <source>
```

The **check** is done in the continus build **travis** with a ninja target: **check-coding-style**.

``` bash
ninja check-coding-style
```

## Brace Style Options

Opening braces are broken from function definitions only. The opening braces are attached to everything else.
> --style=stroustrup

**One True Brace Style** uses linux braces and adds braces to unbraced one line conditional statements.
> --style=otbs

``` c
int Foo(bool isBar)
{
    if (isFoo) {
        bar();
        return 1;
    } else {
        return 0;
    }
}
```

## Indent

Indent with 2 spaces.
> --ident=spaces=2

``` c
/* '.' is a space here */
if (is_bar) {
..foo();
}
```

Indent **switch** blocks.
> --indent-switches

``` c
/* original */
switch (foo)
{
case 1:

/* becomes */
switch (foo)
{
  case 1:
```

Indent preprocessor blocks
> --ident-preproc-block


``` c
/* original */
#ifdef FOO
#include <foo.h>
#endif

/* becomes */
#ifdef FOO
 #include <foo.h>
#endif
```

Indent comments
> --ident-col1-comments

``` c
/* original */
void Foo()
{
// comment
  if (isFoo)

/* becomes */
void Foo()
{
  // comment
  if (isFoo)
```

## Padding

Insert space padding around operations and commas.
> --pad-oper

``` c
/* original */
if (foo==2)
  a=bar((b-c)*a,d--);

/* becomes */
if (foo == 2)
  a = bar((b - c) * a, d--);
```

Insert space padding between a heeadr and the following paren.
> --pad-header

``` c
/* original */
if(isFoo((a+2), b))

/* becomes */
if (isFoo((a+2), b))
```

Delete empty lines within a function or method.
> --delete-empty-lines

Attach a pointer or reference operator to variable name (right).
>--align-pointer=name

``` c
/* original */
char* foo1;
/* becomes */
char *foo1;
```

## Formatting 

> --max-code-length=100
> --break-after-logical

``` c
/* original */
if (thisVariable1 == thatVariable1 || thisVariable2 == thatVariable2 || thisVariable3 == thatVariable3)
    bar();

/* becomes */
if (thisVariable1 == thatVariable1
        || thisVariable2 == thatVariable2
        || thisVariable3 == thatVariable3)
    bar();
```


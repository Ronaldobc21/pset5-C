# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

It is a sick pulmonary that bring about infection.

TODO

## According to its man page, what does `getrusage` do?

 Returns resource usage measures. Example RUSAGE_SELF.

TODO

## Per that same man page, how many members are in a variable of type `struct rusage`?

 We got two variables: rusage before, after.

TODO

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

These are references for calculating the time before and after of the response to give on the code.
TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

It is useful for go across each word in the dictionary so It can find it.

TODO

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

fgetc  = gets the next character from the specified stream and advances the position indicator for the stream.
fscanf = reads formatted input from a stream.
%s     = is a string of characters.

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Because a value is needed that is invariable and is declared once for each run of the program.
constant mean Constant variables are variables that, when initialized, can’t change their value

TODO

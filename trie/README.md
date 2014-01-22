TRIE
----

This program demos the usage of a Trie data structure. Please look up the working of a Trie [here](http://en.wikipedia.org/wiki/Trie "Trie").

In this program, we have a corpus file that contains ~3300 unique words repeating randomly totalling to 11000 words, They are inserted into a Trie data structure and finally, a count of each word's frequency is output.

>**user@host:trie $** make trie
>
>cc     trie.c   -o trie
>
>**user@host:trie $** time ./trie < corpus.txt | wc -l
>
>3363
>
>real    0m0.080s
>
>user    0m0.108s
>
>sys     0m0.015s

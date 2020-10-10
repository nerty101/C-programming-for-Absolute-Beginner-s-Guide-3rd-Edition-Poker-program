# C-programming-for-Absolute-Beginner-s-Guide-3rd-Edition-Poker-program

For me this is a long and complicated program and I have been unable to get it to compile.

Here are the error messages (using gcc on Linux Mint 18)

------

PokerABG.c:20:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
PokerABG.c: In function ‘main’:
PokerABG.c:79:15: warning: implicit declaration of function ‘analyzeHand’ [-Wimplicit-function-declaration]
    winnings = analyzeHand(ranksinHand, suitsinHand);
               ^
PokerABG.c:88:4: warning: ‘return’ with no value, in function returning non-void
    return;
    ^
PokerABG.c: In function ‘getFinalHand’:
PokerABG.c:237:23: error: subscripted value is neither array nor pointer nor vector
         suit = getSuit[i];
                       ^
PokerABG.c:238:23: error: subscripted value is neither array nor pointer nor vector
         rank = getRank[i];
                       ^
PokerABG.c: In function ‘analyzeHand’:
PokerABG.c:312:25: error: ‘ranksinHand’ undeclared (first use in this function)
     for (; rank < 13 && ranksinHand[rank]; rank++)
                         ^
PokerABG.c:312:25: note: each undeclared identifier is reported only once for each function it appears in
PokerABG.c:383:1: error: expected declaration or statement at end of input
 }
 ^
-------

Any help is greatly appreciated...


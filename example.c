aand, aAnd, Aand, Aand
output as:
AAnd
Aand
aAnd
aand


./stringsorter “thing stuff otherstuff blarp”
blarp
otherstuff
stuff
thing

./stringsorter “thing1stuff3otherstuff,blarp”
blarp
otherstuff
stuff
thing


Capitals:
All Capital letters are sorted to come 'before' any lowercase letter.
e.g.: "Zam borp nUtter butter" should be sorted as:
Zam
nUtter
borp
butter

Duplicates:
Maintain all duplicates.
e.g.: "Frobozz blab brop Frobozz" should be sorted as:
Frobozz
Frobozz
blab
brop

Sequential Delimiters:
Ignore sequential delimiters.
e.g.: "hello out there" and "hello10293810293out*0192^there10091" should both be sorted as:
hello
out
there

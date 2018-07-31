# SRI

Simple rule/fact based engine. 

To compile and run, simply enter "make"

Add facts like so:
Father(Allen,Margret)
Mother(Margret,Robert)
Mother(Margret,Bob)

Add rules like so:
GrandFather($X,$Y):- AND Father($X,$Z) Parent($Z,$Y)
GrandMother($X,$Y):- AND Mother($X,$Z) Mother($Z,$Y)
GrandMother($X,$Y):- AND Mother($X,$Z) Father($Z,$Y)

A query is an attempt to inference a rule of a fact. For instance, using the above
KB and RB, here are some query examples and their corresponding substitutions:
Father($X,$Y)
X: Roger, Y:John
X:Roger, Y:Albert
X:Allen, Y:Margret

For pipelining operators:

GrandFather($A,$B)
First part:
Father ($A,$Z)
A:Roger, Z:John
A:Roger, Z:Albert
A:Allen, Z:Margret

Second Part: we then substitute with all the Z in the Parent rule.
Parent($Z,$B)
Parent(John,$B) → Empty
Parent(Albert,$B) → Empty
Parent(Margret,$B) → B:Robert B: Bob

This returns:
A:Margret, B: Robert
A:Margret, B: Bob

Also you can do filtering on queries, for example:
GrandFather($A,Robert)
A:Margret




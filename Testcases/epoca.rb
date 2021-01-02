def klets(diggema) print(diggema) end
klets(a=5)
klets    =             a
klets(a)
print(klets)
print(klets(klets(klets)))
undef klets
print(klets)
print(klets(klets)) #error
klets(klets) #error
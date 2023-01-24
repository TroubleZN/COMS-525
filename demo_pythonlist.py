a = []

a.append(1)
print(a)
a.append("asd")
print(a)

a.clear()
print(a)

b = a.copy()
print(a, b)

b.append(1)
print(a, b)

print(a.count(1))

a.append(1)
print(a.count(1))

a = [1, 2, 3]
b = [123, 222, 323]
a.extend(b)

print(a)

print(a.index(222))
print(a.index(3))



# append(), clear(), copy(), count(), extend(), index(),
# insert(), pop(), remove(), reverse(), sort().


''''
List test:
append(), clear(), copy(), count(), extend(), index(),
insert(), pop(), remove(), reverse(), sort().
'''

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

a.insert(2, -10)
print(a)

a.pop()
print(a)

a.pop(0)
print(a)

a.remove(2)
print(a)
a.remove(123)
print(a)

a.reverse()
print(a)

a.sort()
print(a)



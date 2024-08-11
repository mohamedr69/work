name = "mohamed"
age = 36
rank = 10

print("My name is: "+name)

#print("My name is: "+name + "and my age is: " + age)
print("My name is: %s and my age: %d" %(name,age))

print("My name is: %s and my age: %d and my Rank: %f" %(name,age,rank))

#---------------new-------------------------

print("My name is: {}".format("MOhamed"))
print("My name is: {} and my age: {}".format(name,age))


print("My name is: {:s} and my age: {:d} and my Rank: {:f}".format(name,age,rank))

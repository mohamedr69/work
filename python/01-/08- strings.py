#--------------
# -- strings --
#
#
#--------------

myString = 'This is Single quote'
myString2 = "This is Double quote"

print(myString)
print(myString2)

myString3 = """First
second
third
"""

myString4 = '''first
second
third'''

print(myString3)
print(myString4)


# indexing 

myStr = "I love python"

print(myStr[0])
print(myStr[-1])

# slicing 
# [start:End] End not included 
# [start:end:steps]

print(myStr[8:11])
print(myStr[:11])
print(myStr[0:])
print(myStr[:])

print(myStr[0::2])
print(myStr[::1])

# methods 1 
# len() built in function 
a = "I love python"
print(len(a))
#----------------------------------------
# strip() rstrip() lstrip()
a = "  I Love Python   "
print(a.strip())
print(a.rstrip())
print(a.lstrip())
a = "####I Love # Python   "

print(a.strip("#"))
print(a.rstrip("#"))
print(a.lstrip("#"))

# title() upper case after digits and in the bigning 

b = "i love 2d Graphics and 3d techonlogy"
print(b.title())

# captalize 
b = "i love 2d Graphics and 3d techonlogy"
print(b.capitalize())

#zfill

c,d,e = "1","11","111"

print(c)
print(d)
print(e)

print(c.zfill(3))
print(d.zfill(3))
print(e.zfill(3))

# upper()

name = "mohamed" 
print(name.upper())
# lower()
name = "MOHAMED" 
print(name.lower())


# split() rsplit()
a = "I love python"
print(a.split()) # convert into list empty == space

a = "I-love-python"
print(a.split("-"))

a = "I-love-python"
print(a.split("-",1))


a = "I-love-python"
print(a.rsplit("-",1))

# center()

e = "mohamed"
print(e.center(11)) # spaces
print(e.center(11,"$"))

# count()--> find

f = "mohamed ramadan"
print(f.count("m"))

print(f.count("m",0,7)) # from index 0 to 7

# swapcase()

g = "I Love Python"
h = "i lOVE pYTHON"
print(g.swapcase())
print(h.swapcase())

# starts with

g = "I Love Python"
print(g.startswith("I"))
print(g.startswith("P",7,12))

#endswith()

g = "I Love Python"
print(g.endswith("n"))
print(g.endswith("n",0,5))

#index(substring,start,end)

a = "I love Python"
print(a.index("P"))
# print(a.index("P",0,5))
#find(substring,st,end)


a = "I love Python"
print(a.find("P",0,5)) #-1

# rjust() ljust()

c = "mohamed"
print(c.rjust(10,"#")) 
print(c.ljust(10,"#")) 

# splitline in list

a = """first line
second line
third line"""

print(a.splitlines())

#expand tabs

g = "Hello \t World \t Love"
print(g.expandtabs(20))

#istitle()

one = "I Love Python And 3G"
print(one.istitle())

#isspcae()

two = " "
print(two.isspace())

# islower()

three = "i love python"

print(three.islower())

#isIdentifer()

four = "mohamed"
five = "mohamed--"

print(five.isidentifier())

#isalpha()

x = "AaaaaBbbbb"
print(x.isalpha())

#isalpha


x = "AaaaaBbbbb123"
print(x.isalnum())

#replace(old,new,count)

a = "Hello One Two Three One One"
print(a.replace("One","1"))
print(a.replace("One","1",1))

#join(Itrable)
myList = ["mohamed","ramadan"]
print("-".join(myList))
print(type("-".join(myList))) #str





















 







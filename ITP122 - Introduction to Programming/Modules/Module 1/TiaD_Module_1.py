print ("Welcome to Python! ")

name = input ("My name is > ")

address = input ("Where do you live? > ")

contact = input ("What's your contact number? > ")

print('\n')
print (" ----------Summary---------- ") 
print ("Name : " + name)
print ("Location: " + address)
print ("Contact:" + contact)
print (" --------------------------- ")
print('\n'*2)


# Addition, Multiplication, Subtraction & Division
print ("ADDITION : Enter 2 intergers to add together.")
x = input("Type a number. > ")
y = input("Type another number. > ")
a = int(x) + int(y)
print("Summary: ", x, " + ", y, " = ", a)
print('\n')

# Subtraction
print ("SUBTRACTION : Enter 2 intergers. ")
e = input("Type a number. > ")
f = input("Type another number. > ")
b = int(e) - int(f)
print("Summary: ", e, " + ", f, " = ", b)
print('\n')

# Multiplication
print ("MULTIPLICATION : Enter 2 intergers. ")
g = input("Type a number. > ")
h = input("Type another number. > ")
c = int(g) * int(h)
print("Summary: ", g, " * ", h, " = ", c)
print('\n')

# Division
print ("DIVISION : Enter 2 intergers. ")
i = input("Type a number. > ")
j = input("Type another number. > ")

# If input integer is larger than the second number switch them and divide, else leave as is
if i > j:
    d = int(j) / int(i)
else :
    d = int(i) / int(j)

print("Summary: ", i, " / ", j, " = ", d)
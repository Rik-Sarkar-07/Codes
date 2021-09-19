import math
a = 30
b = 20
c = 4.56
d = "Hello It is Python"
print(d)
print(c)
print(math.floor(c))
print(int(c))
k = a+b+c
print('Hello Brothers')
print('The Summation Result is => ', k)
print('The Summation Result is => ', int(k))
print('The Type of the data is = ', type(k))
print('The Type of the data is = ', type(d))
## Take input from user
x = int(input('Enter a number[x] = '))
y = int(input('Enter next number [y] = '))
z = math.pow(x,y)
print('x^y = ', int(z))
## It is like array
item = {1,2,3,4,5,6,7,8,9,10,'Python'}
print('Print the items', item)

list = {1,3,56,7,9,6,4,0}
print('Print the list', list)

dict = {}
dict['virat'] = 100
dict['dhoni'] = 150
dict['Rohit'] = 120
print(dict.get('virat'))
print(dict.items())
print(dict.keys())

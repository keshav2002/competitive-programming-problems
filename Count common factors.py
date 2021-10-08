
@@ -0,0 +1,99 @@
 # Python3 implementation of program 

import math 

# Map to store the count of each
# prime factor of a 

ma = {}

# Function that calculate the count of 
# each prime factor of a number 

def primeFactorize(a):



    sqt = int(math.sqrt(a))

    for i in range(2, sqt, 2):

        cnt = 0



        while (a % i == 0): 

            cnt += 1

            a /= i



        ma[i] = cnt



    if (a > 1):

        ma[a] = 1


# Function to calculate all common
# divisors of two given numbers 
# a, b --> input integer numbers 

def commDiv(a, b):



    # Find count of each prime factor of a 

    primeFactorize(a)



    # stores number of common divisors 

    res = 1



    # Find the count of prime factors 

    # of b using distinct prime factors of a 

    for key, value in ma.items():

        cnt = 0



        while (b % key == 0):

            b /= key

            cnt += 1



        # Prime factor of common divisor 

        # has minimum cnt of both a and b 

        res *= (min(cnt, value) + 1)



    return res


# Driver code    

a = 12

b = 24


print(commDiv(a, b))

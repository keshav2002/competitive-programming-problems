'''
Problem Statement : Happy Number
Link : https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3284/
score : accepted
'''

class Solution:
    def isHappy(self, n: int) -> bool:
        number = n
        available_answers = []
        while True:
            sum_of_digit_square = 0
            while number!=0:
                digit = int(number%10)
                sum_of_digit_square = sum_of_digit_square + (digit**2)
                number = int(number/10)
            if sum_of_digit_square==1:
                return True
            elif sum_of_digit_square in available_answers:
                return False
            else:
                available_answers.append(sum_of_digit_square)
            number = sum_of_digit_square


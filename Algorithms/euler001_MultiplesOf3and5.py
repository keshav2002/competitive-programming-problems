#!/usr/bin/env python3
# euler001_MultiplesOf3and5.py
# Question Link: https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem


def sum_range(n, m):
    x = m // n
    return n * x * (x + 1) // 2


for _ in range(int(input())):
    n = int(input()) - 1
    three = sum_range(3, n)
    five = sum_range(5, n)
    fifteen = sum_range(15, n)
    print(three + five - fifteen)

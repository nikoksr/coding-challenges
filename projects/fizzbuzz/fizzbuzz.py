#!/usr/bin/env python

def fizzbuzz(start, end, fizz, buzz):
    for counter in range(start, end + 1):
        if counter % fizz == 0 and counter % buzz == 0:
            print("fizzbuzz")
        elif counter % fizz == 0:
            print("fizz")
        elif counter % buzz == 0:
            print("buzz")
        else:
            print("{counter}".format(counter=counter))

if __name__ == '__main__':
    fizzbuzz(1, 100, 3, 5)

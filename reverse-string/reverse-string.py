#!/usr/bin/env python


def reverse_string(some_string):
    string_length = len(some_string)
    reversed_string = ""

    for counter in range(string_length - 1, 0 - 1, -1):
        reversed_string += some_string[counter]

    print("{}".format(reversed_string))

if __name__ == '__main__':
    reverse_string("")

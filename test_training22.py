from __future__ import print_function
# date: 08/07/13
# username: kostua16
# name: Konstantin Leontiev
# description: a basic examples with std python types
__author__ = 'Konstanin Leontiev'
__copyright__ = "Copyright 2013, Konstanin Leontiev"
__credits__ = ["Konstanin Leontiev"]
__license__ = "GPL"
__version__ = "1.0.1"
__email__ = "kostua16@gmail.com"
__status__ = "Development"

def simple_lists():
    """
    Show simple examples with list in python.

    Example:
    ........
        simple_lists()
    To-Do:
    .......
        add examples with dictionary
    """
    # example 1
    test = [3, 2, 1, 4, 5]
    print(test)
    # example 2
    test.append(6)
    print(test)
    # example 3
    test.remove(6)
    print(test)
    # example 4
    test.pop()
    print(test)
    # example 5
    test.sort()
    print(test)
    # example 6
    test2 = [i * i for i in test]
    print(test2)
    # example 7
    test3 = [i for i in range(10, 60) if int(str(i)[1]) > 6]
    print(test3)


def simple_files():
    """
    Show simple examples with files in python.

    Example:
    ........
        simple_files()
    To-Do:
    .......
        add examples with other file types
    """
    # example 1, shows how to write to file
    with open("test.txt", mode='w') as f:
        f.write("Hello,my name is " + __author__ + "\n")
        f.write("Bye!\n")
        # example 2, shows how to read file
    with open("test.txt", mode='r') as f:
        for line in f:
            print(line)
        # example 3, shows how to append to  file
    with open("test.txt", mode='a') as f:
        f.write("append by " + __author__ + "\n")


if __name__ == '__main__':
    print("Simples with list")
    simple_lists()
    print("Simples with files")
    simple_files()
__author__ = 'kostua'



def simple_lists():
    """
    show simple examples witch list in python
    """
    #example 1
    test=[3,2,1,4,5]
    print(test)
    #example 2
    test.append(6)
    print(test)
    #example 3
    test.remove(6)
    print(test)
    #example 4
    test.pop()
    print(test)
    #example 5
    test.sort()
    print(test)
    #example 6
    test2=[ i*i for i in test ]
    print(test2)
    #example 7
    test3=[ i for i in range(10,60) if int(str(i)[1])>6]
    print(test3)

if __name__ == '__main__':
    simple_lists()
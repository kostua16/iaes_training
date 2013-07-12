from __future__ import print_function
# date: 12/07/13
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

from traits.api import String, HasTraits, on_trait_change


class test(HasTraits):
    """
    Show example with events from traits.api
    """
    teststr = String("hello world")

    def Change(self, newstr):
        """
        Shanges teststr to new value
        Args:
            newstr = string
        """
        self.teststr = newstr

    def _teststr_changed(self,name,old,new):
        """
        Shows changes from testrt when it's value changed using specially-named handler
        Args:
            name = string # name of trait
            old = string # old value
            new = string # new value
        """
        print('_teststr_changed:')
        print('name=', name)
        print('old=', old)
        print('new=', new)
        print('^_teststr_changed')

    @on_trait_change('teststr')
    def changed(self, obj, name, new):
        """
        Shows changes from testrt when it's value changed using special decorator
        Args:
            obj = object # self class
            name = string # name of trait
            new = string # new value
        """
        print('on_trait_change:')
        print('obj=', obj)
        print('name=', name)
        print('new=', new)
        print('^on_trait_change')


if __name__ == '__main__':
    app = test()
    while True:
        test = raw_input("teststr=")
        if test == 'exit':
            break
        app.Change(test)
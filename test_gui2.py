__author__ = 'kostua'

from traits.api import HasTraits, Float, Button
from traitsui.api import Item, Group, View, HGroup, VGroup


class test_gui(HasTraits):
    """
    Shows Simple calculator gui
    Args:
        calculating values need to be Float
    """
    a = Float()
    b = Float()
    r = Float()
    plus = Button(label='+')
    minus = Button(label='-')
    multi = Button(label='*')
    sub = Button(label='/')

    values = VGroup(Item('a', label='First'),
                    Item('b', label='Second'),
                    Item('r', label='Result'),
                    label='Data',
                    show_border=True)

    buttons = HGroup(Item('plus', show_label=False),
                     Item('minus', show_label=False),
                     Item('multi', show_label=False),
                     Item('sub', show_label=False),
                     label='Buttons',
                     show_border=True)

    main_gr = Group(values, buttons)

    view = View(main_gr,
                title='Simple calulator')

    def _plus_fired(self):
        """
        Runs: result=a+b
        """
        self.r = self.a + self.b

    def _minus_fired(self):
        """
        Runs: result=a-b
        """
        self.r = self.a - self.b

    def _multi_fired(self):
        """
        Runs: result=a*b
        """
        self.r = self.a * self.b

    def _sub_fired(self):
        """
        Runs: result=a/b
        On exceptions: result=0.0
        """
        try:
            self.r = self.a / self.b
        except Exception:
            self.r = 0.0



if __name__ == "__main__":
    """
    simple code starter: runs code if it's main file
    """
    v=test_gui()
    v.configure_traits()



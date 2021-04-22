y = 3
def sub1():
    a = 7
    y = 9
    z = 11
    def sub2():
        global y
        a = 6
        y = 15
        z = 19
        def sub3():
            nonlocal a
            a = 19
            b = 21
            z = 23
            def sub4():
                nonlocal b
                a = 8
                y = 4
                z = 10
# http://www.drdobbs.com/open-source/the-new-asyncio-module-in-python-34-even/240168401

def createGenerator():
#{
    for i in range(3):
        yield i * i
#}


def generator_example():
#{
    mygen = (x * x for x in range(3))
    for i in mygen:
    #{
        print (i)
    #}

    mygen = createGenerator()
    for i in mygen:
    #{
        print (i)
    #}   
#}


def caching_function(val, x=[]):
#{
    x.append(val)
    print (x)    
#}


def passing_args(x):
#{
    x += 1;
    print ('passing_args : int : {}'.format(x))
#}


def passing_args_list(x):
#{
    if x:
    #{
        x.append(7)
        print ('list : {}'.format(x))
    #}    
#}

def foo2(foo):
#{
    def wrapper():
    #{
        print ('wrapper')
        foo()
    #}

    return wrapper
#}


@foo2
def foo():
#{
    print ('foo')
#}

def main():
#{
    #generator_example()
    caching_function(5)
    caching_function(6)
    caching_function(7, list())
    caching_function(8)
    #x = 5
    #passing_args(x)
    #print ('int : {}'.format(x))
    #x = [ 5 , 6 ]
    #passing_args_list(x)
    #print ('list : {}'.format(x))
    #foo()
#}


if __name__ == '__main__':
    main()

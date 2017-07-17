# https://docs.python.org/2/library/unittest.html

import unittest

def fun(x):
#{
    return x + 1;    
#}

class MyTest(unittest.TestCase):	
    def test_first(self):
        self.assertEqual(fun(3), 4)

if __name__ == '__main__':
    unittest.main()
	#suite = unittest.TestLoader().loadTestsFromTestCase(MyTest)
	#unittest.TextTestRunner(verbosity=2).run(suite)
	

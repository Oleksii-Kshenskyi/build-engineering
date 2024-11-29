from lib.pysort import pysort, random_i64
import unittest

class TestPysort(unittest.TestCase):
    def test_standard_case(self):
        v1 = [5, 6, 4, 1, 88, 3]
        v2 = [4, 3, 2, 1]
        v3 = [100, 2, 4, 645, 5, 11, 465, 1, 10, 44, 7, 2]
        v1_expected = sorted(v1)
        v2_expected = sorted(v2)
        v3_expected = sorted(v3)

        self.assertEqual(v1_expected, pysort(v1))
        self.assertEqual(v2_expected, pysort(v2))
        self.assertEqual(v3_expected, pysort(v3))
    
    def test_handles_empty_vec(self):
        empty_expected = []
        self.assertEqual(empty_expected, pysort([]))

    def test_sorts_random_big_vec(self):
        l = [random_i64() for _ in range(10000)]
        l_expected = sorted(l)
        self.assertEqual(l_expected, pysort(l))

    def test_raises_on_wrong_arg_type(self):
        self.assertRaises(TypeError, pysort, "KEKW")
        self.assertRaises(TypeError, pysort, {})
        self.assertRaises(TypeError, pysort, 3.4)

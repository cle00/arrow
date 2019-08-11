#include "gtest/gtest.h"
#include "arrow/scalar.h"
#include "arrow/python/platform.h"

#define GTEST_COUT std::cerr << "[          ] [ INFO ] >>>> "


std::string pprint(PyObject* obj)
{
    PyObject* str_exc_type = PyObject_ASCII(obj); // Now a unicode object
    PyObject* pyStr = PyUnicode_AsEncodedString(str_exc_type, "utf-8", "Error ~");
    return PyBytes_AS_STRING(pyStr);
}

TEST(JCTest, FirstTest) {
    int64_t test_int = 35;
    auto out = arrow::Int64Scalar(test_int);
    ASSERT_EQ(35, out.value);

    PyObject* val = PyLong_FromLong(6568381);

    GTEST_COUT << pprint(val) << std::endl;

}

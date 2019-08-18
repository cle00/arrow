#include "gtest/gtest.h"
#include "arrow/scalar.h"
#include "arrow/status.h"
#include "arrow/python/python_to_arrow.h"
#include "arrow/util/logging.h"
#include "arrow/testing/gtest_util.h"

#define GTEST_COUT std::cerr << "[          ] [ INFO ] >>>> "

std::string pprint(PyObject* obj)
{
    PyObject* str_exc_type = PyObject_ASCII(obj); // Now a unicode object
    PyObject* pyStr = PyUnicode_AsEncodedString(str_exc_type, "utf-8", "Error ~");
    return PyBytes_AS_STRING(pyStr);
}

TEST(Test, FirstTest) {
    std::shared_ptr<arrow::Scalar> out;
    PyObject* val = PyLong_FromLong(6568381);

    GTEST_COUT << pprint(val) << std::endl;
    arrow::Status aa = arrow::py::ConvertPyObject(val, &out);
    GTEST_COUT << out->type << std::endl;
}

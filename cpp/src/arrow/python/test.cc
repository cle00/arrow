#include "gtest/gtest.h"
#include "arrow/scalar.h"
#include "arrow/status.h"
#include "arrow/python/python_to_arrow.h"
#include "arrow/util/logging.h"
#include "arrow/testing/gtest_util.h"
#include "arrow/python/inference.h"

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

    std::shared_ptr<arrow::DataType> real_type;

    arrow::Status aa = arrow::py::InferArrowTypeSingleton(val, nullptr, false, &real_type);
    // GTEST_COUT << aa << std::endl;
    
    // GTEST_COUT << real_type -> ToString() << std::endl; 

    arrow::Status ab = arrow::py::GetDataType(real_type, &out);

    // GTEST_COUT << out -> type << std::endl;

    GTEST_COUT << pprint(val) << std::endl;
    arrow::Status ac = arrow::py::ConvertPyObject(val, &out);
    GTEST_COUT << out->type->ToString() << std::endl;
    auto int64_v = std::static_pointer_cast<arrow::Int64Scalar>(out);
    GTEST_COUT << int64_v->value << std::endl; 

}

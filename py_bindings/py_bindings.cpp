#include <pybind11/pybind11.h>
#include "Modem.h"

namespace py = pybind11;


PYBIND11_MODULE(Modem, m){
py::class_<Modem>(m,"Modem")
.def(py::init<const std::string&, unsigned int>())
.def("connect", &Modem::connect)
.def("disconnect", &Modem::disconnect)
.def("get_manuf_id", &Modem::get_manuf_id)
.def("get_model_id", &Modem::get_model_id)
.def("get_revision", &Modem::get_revision)
.def("get_serial_number", &Modem::get_serial_number);
}
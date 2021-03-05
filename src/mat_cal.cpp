#include<iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)
using namespace std;
namespace py = pybind11;

class mat_cal {

	public:

        mat_cal(){}

		bool check_add(vector<vector<int>> a, vector<vector<int>> b) {
			int n1 = (int)a.size(), m1 = (int)a[0].size(), n2 = (int)b.size(), m2 = (int)b[0].size();
			if(n1 != n2 || m1 != m2) return false;
			else return true;
		}
		
		vector<vector<int>> add(vector<vector<int>> a, vector<vector<int>> b) {
			int n = (int)a.size(), m = (int)a[0].size();
			vector<vector<int>> res(n, vector<int>(m, 0));
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					res[i][j] = a[i][j] + b[i][j];
				}
			}	
			return res;
		}
		
		bool check_mul(vector<vector<int>> a, vector<vector<int>> b) {
			int n1 = (int)a.size(), m1 = (int)a[0].size(), n2 = (int)b.size(), m2 = (int)b[0].size();
			if(m1 != n2) return false;
			else return true;
		}
		
		vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
			int n1 = (int)a.size(), m1 = (int)a[0].size(), n2 = (int)b.size(), m2 = (int)b[0].size();
			vector<vector<int>> res(n1, vector<int>(m2, 0));
			for(int i = 0; i < n1; i++) {
				for(int j = 0; j < m2; j++) {
					for(int k = 0; k < m1; k++) res[i][j] += a[i][k] * b[k][j]; 
				}
			}
			return res;
		}
		
};


PYBIND11_MODULE(example, m) {
    py::class_<mat_cal>(m, "mat_cal")
        .def(py::init<>())
        .def("check_add", &mat_cal::check_add)
        .def("add", &mat_cal::add)
        .def("check_mul", &mat_cal::check_mul)
        .def("mul", &mat_cal::mul);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
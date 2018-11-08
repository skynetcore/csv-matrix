#ifndef _CSVMATRIX_LOGGER_H_
#define _CSVMATRIX_LOGGER_H_

#include "csv-matrix_common.h"


#define CSVM_DEBUG 0
#define CSVM_WARN  1
#define CSVM_INFO  2
#define CSVM_ERROR 3
#define CSVM_FATAL 4


#define csvmatrix_debug(msg, ...) csvmatrix_log(CSVM_DEBUG, msg, ##__VA_ARGS__)
#define csvmatrix_error(msg, ...) csvmatrix_log(CSVM_ERROR, msg, ##__VA_ARGS__)
//#define csv-matrixinfo printf

extern void csvmatrix_log(int level, const char* msg, ...);


#endif

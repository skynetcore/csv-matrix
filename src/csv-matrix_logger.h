/*
 * Copyright (C) 2018 Derric Lyns [derriclyns@gmail.com]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

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

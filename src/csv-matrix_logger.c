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

#include "csv-matrix_logger.h"
#define MAX_LOG_LINE_LEN 256


void csvmatrix_log(int level, const char* msg, ...) {
    va_list args;
    char logString[MAX_LOG_LINE_LEN] = {'\0'};


    va_start(args, msg);
    /* C11: chars beyond (MAX_LOG_LINE_LEN - 1) are discarded, and a null character is appended at the end */
    int truncatedChars = vsnprintf(logString, MAX_LOG_LINE_LEN, msg, args);
    va_end(args);

    printf("%s", logString);
}

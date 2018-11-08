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

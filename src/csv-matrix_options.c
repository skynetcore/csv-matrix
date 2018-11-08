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

#include "csv-matrix_options.h"
#include "csv-matrix_logger.h"
#include "csv-matrix_common.h"


char* csvmatrix_get_filename(char *filename) {
    char *token;
    char delim = '=';
    int size_of_filename = strlen(filename);
    int itr = 0;
    int loc = 0;

    do {
        if(delim == filename[itr]) {
            printf("found \n");
            loc = itr + 1;
            break;
        }
        itr++;
    } while(filename[itr]!='\0');

    //allocate memory
    int char_count = size_of_filename-loc;
    int char_size = sizeof(char)*char_count;
    token = (char*)malloc(char_size);

    itr=0;
    //copy
    do {
        token[itr]=filename[loc];
        itr++;
        loc++;
    } while(filename[loc]!= '\0');

    return token;
}


int csvmatrix_check_filename(char* filename) {
    int ret = 0;
    char *filetoken = "--filename=";
    if(!(strncmp(filetoken, filename, strlen(filetoken)))) {
        ret = 1;
    }

    return ret;
}


/**
 * @brief           Parse command-line style options
 *
 * @param[in]       argc  The count of command line arguments
 * @param[in]       argv  The actual command line arguments
 * @param[in,out]   opts  Pointer to a speedtest_opts_t variable
 *
 * @return          bool indicating success or failure/error
 */


int ParseOptions(int argc, char** argv, csvmatrix* matrix) {
    int itr = 0;
    if (argc < 2) {
        csvmatrix_error("no parameters provided \n");
        exit(0);
    }

    //[operation]
    if (!strcmp(argv[1],"create")) {
        matrix->op = FILE_CREATE;
        csvmatrix_debug("operation create \n");
    } else if (!strcmp(argv[1], "update")) {
        matrix->op = FILE_UPDATE;
        csvmatrix_debug("operation update \n");
    } else if (!strcmp(argv[1], "delete")) {
        matrix->op = FILE_DELETE;
        csvmatrix_debug("operation delete \n");
    } else {
        csvmatrix_error("incorrect operation paramater. please check the syntax \n");
        exit(0);
    }

    int prima_check = 0;

    //[operation params]
    for (itr=2; itr<argc; itr++) {
        if(csvmatrix_check_filename(argv[itr])) {
            prima_check = 1;
            matrix->filename = csvmatrix_get_filename(argv[itr]);
            csvmatrix_debug("filename = %s \n", matrix->filename);
        }
    }

    //decide
    if (!prima_check) {
        csvmatrix_error("filename not specified \n");
        exit(0);
    }
}

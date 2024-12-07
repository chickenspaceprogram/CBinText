// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef CBINTXT_FILE_HANDLING_H
#define CBINTXT_FILE_HANDLING_H

#include <stdio.h>
#include <stdbool.h>

// output_file_loc should be the position of the output file, if specified, or -1.
// returns NULL if an error occurred somewhere, otherwise returns a pointer to the array of files
// sets num_input_files to the number of input files
FILE **open_files(int argc, char **argv, int *num_input_files);

// opens input file, returns NULL and closes all the files if opening fails
FILE *open_input_file(FILE **files, int file_index, char *name);

// returns true if names were successfully malloc'ed and set, false if not.
bool set_output_filenames(char **out_h, char **out_c, char *name);

// returns true if files were successfully opened, false if not.
bool open_output_files(FILE **out_h, FILE **out_c, char *out_name_h, char *out_name_c);

void close_files(FILE **files, int num_files);

void put_name_caps(FILE *out, char *name);

void print_date(FILE *out);

void print_time(FILE *out);

void print_comment(FILE *out);

void print_header_file(FILE *out, char *name);

void print_c_file(FILE *out, FILE **in, char *name, int num_inputs);

#endif
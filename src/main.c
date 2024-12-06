// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "argparse.h"
#include "tokenize.h"
#include "file-handling.h"
#include <stdio.h>

// kinda bloated main fn but oh well
int main(int argc, char **argv) {
    int num_input_files, out_name_len;
    FILE *out_h, *out_c, **in;
    char *out_name_h, *out_name_c;
    bool out_is_stdout = true;

    if (get_help_version(argc, argv)) {
        return 0;
    }

    if (argc < 2) {
        fprintf(stderr, "Error: incorrect arguments. Try `cbintxt --help` if you need it.\n");
        return 1;
    }

    if (!set_output_filenames(&out_name_h, &out_name_c, argv[1])) {
        fprintf(stderr, "Error: could not allocate memory. Try running the program again.\n");
        return 1;
    }

    if (!open_output_files(&out_h, &out_c, out_name_h, out_name_c)) {
        free(out_name_h);
        free(out_name_c);
        return 1;
    }

    in = open_files(argc, argv, &num_input_files);
    if (in == NULL) {
        fclose(out_h);
        fclose(out_c);
        free(out_name_c);
        free(out_name_h);
        return 1;
    }

    print_header_file(out_h, argv[1]);
    print_c_file(out_c, in, argv[1], num_input_files);

    close_files(in, num_input_files);
    free(out_name_c);
    free(out_name_h);
    fclose(out_h);
    fclose(out_c);
    free(in);
    in = NULL;

    return 0;

}

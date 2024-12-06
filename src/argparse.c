// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.


#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "help.h"
#include "argparse.h"

#define HELP_SHORT "-h"
#define HELP_LONG "--help"

#define VERSION_SHORT "-v"
#define VERSION_LONG "--version"

// this is kinda a bad way to this but i'm lazy and it works
int get_arg_index(int argc, char **argv, char *short_form, char *long_form, int chk_start) {
    for (int i = chk_start; i < argc; ++i) {
        if (strcmp(argv[i], short_form) == 0 || strcmp(argv[i], long_form) == 0) {
            return i;
        }
    }
    return -1;
}

bool get_help_version(int argc, char **argv) {
    if (argc == 1 || get_arg_index(argc, argv, HELP_SHORT, HELP_LONG, 1) != -1) {
        help(stdout);
	return true;
    }

    if (get_arg_index(argc, argv, VERSION_SHORT, VERSION_LONG, 1) != -1) {
        fprintf(stderr, "cbintxt v0.2\n");
        // can dogfood a version msg later
        return true;
    }
    return false;
}


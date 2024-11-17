// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "argparse.h"

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
    if (argc == 1 || check_for_arg(argc, argv, HELP_SHORT, HELP_LONG, 1) != -1) {
        fprintf(stderr, "help here\n");
        // can dogfood a help msg later
        return true;
    }

    if (check_for_arg(argc, argv, VERSION_SHORT, VERSION_LONG, 1) != -1) {
        fprintf(stderr, "version here\n");
        // can dogfood a version msg later
        return true;
    }
    return false;
}
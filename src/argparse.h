// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef CBINTXT_ARGPARSE_H
#define CBINTXT_ARGPARSE_H

#include <stdbool.h>

#define HELP_SHORT "-h"
#define HELP_LONG "--help"

#define VERSION_SHORT "-v"
#define VERSION_LONG "--version"


// returns the index of the first occurrence of an arg if the user included a `short_form` or `long_form` arg, -1 if not.
// chk_start is the index at which to start checking
int get_arg_index(int argc, char **argv, char *short_form, char *long_form, int chk_start);

// prints help/version messages, returns true if one was printed, and false otherwise
bool get_help_version(int argc, char **argv);

#endif

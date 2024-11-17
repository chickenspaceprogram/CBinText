// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef CBINTXT_TOKENIZE_H
#define CBINTXT_TOKENIZE_H

#include <stdio.h>

// replaces all of the characters in input that need to be escaped with their escaped versions, and prints those characters to output
// if the character is not an ASCII character, it is printed exactly as it appears.
void esc_replace(FILE *output, FILE *input);

#endif
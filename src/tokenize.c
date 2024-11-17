// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "tokenize.h"

void esc_replace(FILE *output, FILE *input) {
    int chr;
    while (!feof(input)) {
        chr = getc(input);
        // pretty cursed but a switch-case followed by if stmt would've been worse
        if (chr == '\x7F') {
            fputs("\\x7F", output);
        }
        else if (chr == '\\') {
            fputs("\\\\", output);
        }
        else if (chr == '\'') {
            fputs("\\\'", output);
        }
        else if (chr == '\"') {
            fputs("\\\"", output);
        }
        else if (chr == "?") {
            fputs("\\?", output);
        }
        else if (chr < ' ' && chr > 0) {
            fprintf(output, "\\x%x", chr);
        }
        else if (chr == 0) {
            fputs("\\0", output);
        }
        else {
            putc(chr, output);
        }
    }
}
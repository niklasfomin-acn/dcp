#!/usr/bin/env bash

# The following comments should help you get started:
# - Bash is flexible. You may use functions or write a "raw" script.
#
# - Complex code can be made easier to read by breaking it up
#   into functions, however this is sometimes overkill in bash.
#
# - You can find links about good style and other resources
#   for Bash in './README.md'. It came with this exercise.
#
#   Example:
#   # other functions here
#   # ...
#   # ...
#
acronym() {
    name=$1
    acronym=$(echo "$1" | tr -d "'" | tr -c 'a-zA-Z' '\n' | cut -c1 | tr 'a-z' 'A-Z' | tr -d '\n') 
    echo "$acronym"

}

acronym "$1"
#!/bin/bash

# Get the input file name from the command-line argument
input_file=$1

# Run pycodestyle and count errors
pycodestyle $input_file > /dev/null 2>&1
pycodestyle_count=$?

# Run pylint and count errors
pylint $input_file > /dev/null 2>&1
pylint_count=$?

# Run pydocstyle and count errors
pydocstyle $input_file > /dev/null 2>&1
pydocstyle_count=$?

# Compute the total number of errors
total_errors=$((pycodestyle_count + pylint_count + pydocstyle_count))

# Print the total number of errors
echo "Total number of errors: $total_errors"

#!/usr/bin/env bash

# Parse build.log to extract errors and warnings
# Output to debug.err.log and debug.warn.log

# Check if build.log exists
if [ ! -f build.log ]; then
    echo "build.log not found. Run test-pkgbuild.sh first."
    exit 1
fi

# Extract lines containing "error" (case insensitive) into debug.err.log
grep -i "error" build.log > debug.err.log

# Extract lines containing "warning" (case insensitive) into debug.warn.log
grep -i "warning" build.log > debug.warn.log

echo "Parsing complete. Check debug.err.log and debug.warn.log."
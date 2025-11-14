#!/bin/bash

# Build script for C++ OOP examples
# This script compiles all the example programs

echo "Building C++ OOP Examples..."
echo "=============================="

# Compiler and flags
CXX=g++
CXXFLAGS="-std=c++11 -Wall -Wextra"

# Array of source files (without .cpp extension)
programs=("student" "inheritance_polymorphism" "advanced_oop" "composition_aggregation")

# Compile each program
success_count=0
fail_count=0

for prog in "${programs[@]}"; do
    echo -n "Compiling ${prog}.cpp ... "
    if $CXX $CXXFLAGS -o "${prog}" "${prog}.cpp" 2>/dev/null; then
        echo "SUCCESS"
        ((success_count++))
    else
        echo "FAILED"
        ((fail_count++))
    fi
done

echo "=============================="
echo "Build Summary:"
echo "  Successful: $success_count"
echo "  Failed: $fail_count"
echo "=============================="

if [ $fail_count -eq 0 ]; then
    echo "All programs compiled successfully!"
    echo ""
    echo "To run the examples:"
    for prog in "${programs[@]}"; do
        echo "  ./${prog}"
    done
else
    echo "Some programs failed to compile. Please check the errors above."
    exit 1
fi

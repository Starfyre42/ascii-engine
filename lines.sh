#!/bin/sh

find src -type f \( -name "*.h" -o -name "*.cpp" \) -exec cat {} \; | wc -l
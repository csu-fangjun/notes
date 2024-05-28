#!/usr/bin/env bash

g++ -c -fPIC -o a.o a.cc
g++ -shared -o libfoo.dylib ./a.o
ls -lh
nm libfoo.dylib


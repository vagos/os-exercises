#!/bin/bash

rm -r ex1/build
rm -r ex2/build
rm -r ex3/build
rm -r ex-xv6/build

make -C ex1
cp ex1/build/main.pdf pdfs/OS_Exercise_1.pdf

make -C ex2
cp ex2/build/main.pdf pdfs/OS_Exercise_2.pdf

make -C ex3
cp ex3/build/main.pdf pdfs/OS_Exercise_3.pdf

make -C ex-xv6
cp ex-xv6/build/system-call.pdf pdfs/OS_Exercise_XV6_1.pdf
cp ex-xv6/build/scheduler.pdf pdfs/OS_Exercise_XV6_2.pdf

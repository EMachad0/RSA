#!/bin/bash
for i in {32..100..4};
do 
    echo "test $i";
    for j in {1..100}
        do
            ./a.out ./main.cpp -t -b --sz $i;
        done
done > time_testing/time_break_log.txt
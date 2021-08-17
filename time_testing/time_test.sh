#!/bin/bash
for i in 32 64 128 256 512 1024 2048;
do 
    echo "test $i";
    for j in {1..10}
        do
            ./a.out ./main.cpp -t --sz $i;
        done
done > time_testing/time_test_log.txt
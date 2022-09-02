#!/bin/bash
for i in {1..50}
do
	./philo 5 601 200 200 3 | grep -A 2 -e enough -e died
done

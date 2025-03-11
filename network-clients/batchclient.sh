#!/bin/bash

for i in $(seq 100)
do
	echo "open sesame" | ./client &
done

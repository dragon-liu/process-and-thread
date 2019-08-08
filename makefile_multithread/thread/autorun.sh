#!/bin/bash

if test $# -ne 2
then
  echo "Invalid parameter, the parameters are end,num_of_thread."
  exit
fi

./edit $1 $2

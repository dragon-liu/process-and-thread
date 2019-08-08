#! /bin/bash
if [ $# -eq 0 ]
then
    make
    dos2unix autorun.sh #在windows下写的，直接在Linux环境下运行会报错syntax error:unexpected end of file
else
    make clean
    make
    dos2unix autorun.sh
fi

#! /bin/bash
read s
if [ ${s:0:1} = ${s:1:1} ] && [ ${s:0:1} = ${s:2:1} ]; then
    echo "Won"
else
    echo "Lost"
fi
#!/bin/bash

LabSD=8

echo ""
echo "=============== BUILDING LAB $LabSD ==============="
echo ""

make build

make run &> /dev/null

echo ""
echo "=============================================="

echo ""
echo "=============== CHECKING LAB $LabSD ==============="
echo ""

points8=(3.0 3.0 3.0 3.0)

ref_path=Ref/Lab$LabSD
out_path=Out/Lab$LabSD

ref_ext=".ref"
out_ext=".out"

it=0
grade="5.0"
max_grade="5.0"
labPoints="points$LabSD"

for ref_file in $(ls $ref_path/ 2> /dev/null | xargs -n1 basename); do
    test=$(echo $ref_file | cut -d'.' -f1)
    out_file="$test$out_ext"
    current_task_score=points$LabSD[$it]
    max_grade=$(bc <<< $(echo "$max_grade + ${!current_task_score}"))

    ls $out_path/$out_file &> /dev/null
    if [ $? -gt 0 ]; then
        echo "Could not find $out_file .................... FAILED 0.0/${!current_task_score}"
    else
        if [ "$(diff -bBZ $ref_path/$ref_file $out_path/$out_file)" != "" ]; then
            echo "$test .................... FAILED 0.0/${!current_task_score}"
        else
            echo "$test .................... PASSED ${!current_task_score}/${!current_task_score}"
        fi
    fi

    it=$((it+1))

done

make clean > /dev/null
rm -f $out_path/*

echo ""
#!/bin/bash

work_dir=$PWD
pmem_dir=/mnt/pmem1/

if [ -f "$pmem_dir/test.io" ]; then
	rm $pmem_dir/test.io
	sync
	sleep 1
fi

$work_dir/628835 $pmem_dir/test.io
sync
echo
diff -u $work_dir/test1.txt $work_dir/test2.txt

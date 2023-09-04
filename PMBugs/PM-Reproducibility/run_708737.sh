#!/bin/bash

PMEM_DEV=/dev/pmem0

blockdev --setro $PMEM_DEV
val1=`blockdev --getro $PMEM_DEV`
#val1=`echo $?`

if [ "$val1" -eq "1" ]; then
	echo "$PMEM_DEV set to read-only mode"
fi
sleep 1

echo "Executing:  blockdev --rereadpt $PMEM_DEV"
blockdev --rereadpt $PMEM_DEV
sleep 1

echo "Check if read-only is reset"
val1=`blockdev --getro $PMEM_DEV`
#val1=`echo $?`
if [ "$val1" -eq "0" ]; then
        echo "Read-only mode not set on $PMEM_DEV"
else
	echo "$PMEM_DEV set to read-only mode"
fi

Test Case 628835: 
	Used v4.10 kernel

	Step 1: Configure namespace in fsdax mode (/dev/pmem0)
	Step 2: Create ext4 (mkfs.ext4 /dev/pmem0)
	Step 3: Mount with DAX option (mount -o dax /dev/pmem0 /mnt/pmem0)
	Step 4: Compile 628835.c (gcc 628835.c -o 628835)
	Step 5: Execute run_628835.sh
	Step 6: If files ./test1.txt and ./test2.txt contains no data then the test is successfull

Test Case 651043:
	Kernel version used: 4.13-rc3
	
	Step 1: Compile hello.c (gcc hello.c -o hello)
	Step 2: Create ext4 (mkfs.ext4 /dev/pmem0)
        Step 3: Mount with DAX option (mount -o dax /dev/pmem0 /mnt/pmem0)
	Step 4: Copy executable to mount directory (cp hello /mnt/pmem0/)
	Step 5: Unmount (umount /dev/pmem0)
	Step 6: Mount as readonly (mount -o dax,ro /dev/pmem0 /mnt/pmem0)
	Step 7: Run executable on pmem device (cd /mnt/pmem0 && ./hello)
		- The program should report "Segmentation Fault"

Test Case 895052:
	Kernel version used: 5.8
	Works on real hardware

	Step 1: mkfs.ext4 -F -O inline_data /dev/pmem1
	Step 2: mount /dev/pmem1 /mnt
	Step 3: echo 'test' >/mnt/file
	Step 4: lsattr -l /mnt/file
	Step 5: chattr +x /mnt/file (use latest e2fsprogs (> 1.48))
	Step 6: lsattr -v /mnt/file
	Step 7: umount /dev/pmem1
	Step 8: mount /dev/pmem1 /mnt
	Step 9: cat /mnt/file
		- This should result in "cat: /mnt/file: Numerical result out of range"

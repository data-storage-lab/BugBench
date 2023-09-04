# DrChecker+

Step1: compile kerenl drviers with wllvm

Step2: compile Dr.Checker+
```
    cd llvm_analysis
    ./build.sh
```

Step3: run Dr.Checker+ with compiled persistent memeory driver modules in the Linux kerenl

```
cd <repo_dir>/llvm_analysis/MainAnalysisPasses/build_dir/SoundyAliasAnalysis
# running the dr.checker pass
opt -load ./libSoundyAliasAnalysis.so -dr_checker -toCheckFunction="hidraw_ioctl" -functionType="IOCTL" -outputFile="hidraw_ioctl.drcheck.json" /home/drchecker/33.2.A.3.123/llvm_bc_out/drivers/hid/llvm_link_final/final_to_check.bc
```



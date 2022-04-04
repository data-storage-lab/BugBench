# BugBench<sup>k</sub> 

This repository contains real-world bug cases curated by Data Storage Lab @ISU and studied in our research projects. Depending on the projects, we may perform a variety of analysis on the bug cases including characterization, reproducibility experiments, bug detection, failure diagnosis, etc. We hope that our efforts and the resulting dataset will inspire follow-up research in the communities and help measure and improve system reliability in general.

About the name: BugBench<sup>k</sup>  was inspired by the classic paper "[BugBench: Benchmarks for Evaluating Bug Detection Tools](http://opera.ucsd.edu/paper/63-lu.pdf)" by Shan Lu et. al. which describes a set of bugs in user-level applications. The "<sup>k</sup>" denotes the fact that most bug cases curated in BugBench<sup>k</sup> are kernel-level bugs.  

## Persistent Memory Bugs in the Linux Kernel ##

The "PMBugs" folder contains the dataset studied in our paper "[A Study of Persistent Memory Bugs in the Linux Kernel](https://dl.acm.org/doi/pdf/10.1145/3456727.3463783)", which was published in the Proceedings of the 14th ACM International Systems and Storage Conference ([SYSTOR](https://www.systor.org/2021/index.html)), 2021.

XXX

## Benchmarking for Observability ##

The "Observability" folder contains the dataset studied in our paper "[Benchmarking for Observability: The Case of Diagnosing Storage Failures](https://www.ece.iastate.edu/~mai/docs/papers/2021TBench-Debug.pdf)", which was published in BenchCouncil Transactions on Benchmarks, Standards and Evaluation ([TBench](https://www.benchcouncil.org/index.html)), 2021.

XXXWe used the dataset to measure the debugging observability of two general debugging tools: FTrace and PANDA.

The folder contains two files:
- Manual file: how to run and use each image.
- Link file: due to storage limits, it is unavailable to upload images to current repository. The link shows how to get images.


## Contact ##
Om R. Gatla (ogatla@iastate.edu), 
Duo Zhang (duozhang@iastate.edu).



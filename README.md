# BugBench<sup>k</sup> 

This repository contains real-world bug cases curated by Data Storage Lab@ISU and studied in our research projects. Depending on the projects, we may perform a variety of analysis on the bug cases including characterization of bug patterns, reproducibility experiments, bug detection, failure diagnosis, etc. We hope that our efforts and the resulting datasets can inspire follow-up research in the community and help improve system reliability in general.

About the Name: BugBench<sup>k</sup>  was inspired by the classic work "[BugBench: Benchmarks for Evaluating Bug Detection Tools](http://opera.ucsd.edu/paper/63-lu.pdf)" by Shan Lu et. al. which characterizes a set of bugs in user-level applications. The "<sup>k</sup>" denotes the fact that the initial set of bug cases curated in BugBench<sup>k</sup> were kernel-level bugs.  

BugBench<sup>k</sup> Publications:

- "[On the Reproducibility of Bugs in File-System Aware Storage Applications](https://ieeexplore.ieee.org/document/9925445)", 
Duo Zhang, Tabassum Mahmud, Om Rameshwar Gatla, Runzhou Han, Yong Chen, and Mai Zheng,
Proceedings of the 16th IEEE International Conference On Networking, Architecture, and Storage ([NAS](http://www.nas-conference.org/NAS-2022/)), 2022.

- "[A Study of Persistent Memory Bugs in the Linux Kernel](https://dl.acm.org/doi/pdf/10.1145/3456727.3463783)",
Duo Zhang, Om R. Gatla, Wei Xu, and Mai Zheng,
Proceedings of the 14th ACM International Systems and Storage Conference ([SYSTOR](https://www.systor.org/2021/index.html)), 2021.

- "[Benchmarking for Observability: The Case of Diagnosing Storage Failures](https://www.sciencedirect.com/science/article/pii/S2772485921000065)", 
Duo Zhang and Mai Zheng,
BenchCouncil Transactions on Benchmarks, Standards and Evaluation ([TBench](https://www.benchcouncil.org/index.html)), 2021.

## Persistent Memory Bugs in the Linux Kernel ##

The "PMBugs" folder contains the dataset studied in our paper "[A Study of Persistent Memory Bugs in the Linux Kernel](https://dl.acm.org/doi/pdf/10.1145/3456727.3463783)", which was published in the Proceedings of the 14th ACM International Systems and Storage Conference ([SYSTOR](https://www.systor.org/2021/index.html)), 2021.

By analyzing 1,350 PM related kernel patches in depth, we derive multiple insights in terms of PM patch categories, PM bug patterns, consequences, and fix
strategies. We hope our results could contribute to the development of effective PM bug detectors and robust PM-based systems.

## Benchmarking for Observability ##

The "Tbench" folder contains the dataset information studied in our paper "[Benchmarking for Observability: The Case of Diagnosing Storage Failures](https://www.ece.iastate.edu/~mai/docs/papers/2021TBench-Debug.pdf)", which was published in BenchCouncil Transactions on Benchmarks, Standards and Evaluation ([TBench](https://www.benchcouncil.org/index.html)), 2021.

Our dataset was used to measure the debugging observability of two general debugging tools: FTrace and PANDA.

Images Link: https://drive.google.com/drive/folders/1rgx6tB4iXAW8oomnIZTHGCeoUPJPup3R?usp=sharing

## FSAppBugs ##
The "FSAppBugs""[On the Reproducibility of Bugs in File-System Aware Storage Applications](https://ieeexplore.ieee.org/document/9925445)", which was published in the 16th IEEE International Conference On Networking, Architecture, and Storage ([NAS](http://www.nas-conference.org/NAS-2022/)), 2022.

By analyzing 59 bug cases from 4 representative applications in depth, we derive multiple insights in terms of general bug patterns, triggering
conditions, and implications for building effective tools (e.g., bug detection, debugging, provenance tracking). We hope that our results could contribute to the development of robust FS-aware storage applications.

(will be available soon)

## Contact ##
Om R. Gatla (ogatla@iastate.edu), 
Duo Zhang (duozhang@iastate.edu).



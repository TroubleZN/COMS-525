#!/bin/bash

# Copy/paste this job script into a text file and submit with the command:
#    sbatch thefilename
# job standard output will go to the file slurm-%j.out (where %j is the job ID)

#SBATCH --time=00:15:00   # walltime limit (HH:MM:SS)
#SBATCH --nodes=1   # number of nodes
#SBATCH --ntasks-per-node=36   # 36 processor core(s) per node 
#SBATCH --mem=4G   # maximum memory per node
#SBATCH --job-name="CS525"

# LOAD MODULES, INSERT CODE, AND RUN YOUR PROGRAMS HERE

./main.exe 2 10000 > output2.txt
./main.exe 4 10000 > output4.txt
./main.exe 8 10000 > output8.txt
./main.exe 16 10000 > output16.txt
./main.exe 32 10000 > output32.txt

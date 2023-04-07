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

module load intel
{
    mpirun -np 2 ./main.exe 1600000
    mpirun -np 4 ./main.exe 1600000 
    mpirun -np 8 ./main.exe 1600000 
    mpirun -np 16 ./main.exe 1600000 
    mpirun -np 32 ./main.exe 1600000 
} > output.data

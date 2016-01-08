#!/bin/sh
#PBS -N test
#PBS -q hpcintro
#PBS -l walltime=2:00
#PBS -l nodes=1:ppn=32
#PBS -o $PBS_JOBNAME.out
#PBS -e $PBS_JOBNAME.err
#PBS -M tntr@dtu.dk
#PBS -m a

# PBS -o $PBS_JOBNAME.$PBS_JOBID.out
# PBS -e $PBS_JOBNAME.$PBS_JOBID.err


cd $PSB_O_WORKDIR

echo Run, done.

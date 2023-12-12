#!/bin/bash

# EXE :
EXE=./2


np=1
n=1000

echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=2
n=1000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=4
n=1000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=1
n=5000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"


np=2
n=5000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=4
n=5000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=1
n=10000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"


np=2
n=10000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=4
n=10000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=1
n=100000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"


np=2
n=100000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=4
n=100000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"


np=1
n=1000000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"


np=2
n=1000000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"

np=4
n=1000000
echo "nProc:${np}, nums:${n}"
mpirun -np ${np} ${EXE} ${n}
echo "======================"


